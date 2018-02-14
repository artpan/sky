#include "smmu.h"
#include "cache.h"


unsigned int pgtable_base = 0x80100000;//size = 4096 entry *4KB = 16KB; the pagetable base address must be aliged to 31:14 bit
void set_section (unsigned int pgtable_base, unsigned int entry, unsigned int section, enum dcache_option option)
{
		unsigned int *page_table =(unsigned int*) pgtable_base;
		unsigned int value;
		
		value = (section<<MMU_SECTION_SHIFT);
		value = |otpion;
		page_table [entry] = value;
}


void arm_smmu_tlb_sync(void)
{
		write_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_sTLBGSYNC,0);
		wile(read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_sTLBGSTATUS)&sTLBGSTATUS_GSACTIVE)
		{
			serial_puts(1,"wait...\n");
		}
}

void ceva_pagetable_setup(viod)
{
		unsigned int 	i;
		unsigned int	mem_start		=	0x0;
		unsigned int 	mem_size		=	0xFFFFFFFF;
		unsigned int 	sect_base_1	=	0xA00;
		unsigned int	sect_base_2	=	0x900;
		
		for (i	=	mem_start >>	20;	i <(mem_start >>20)+(mem_size>>20);i++)
		{
				if(0x900<=i&&i<=0x902)
					{
							set_section(pgtable_base,i,sect_base_1++,DCACHE_WRITEALLOC);
					}
				else if(0xA00<=i&&i<=0xA02)
					{
							set_section(pgtable_base,i,sect_base_2++,DCACHE_WRITEALLOC);
					}
				else
					{
						set_section (pgtable_base,i,i,DCACHE_WRITETHROUGH);
						//set_section (pgtable_base,i,i,DCACHE_WRITEBACK);
						//set_section (pgtable_base,i,i,DCACHE_WRITEALLOC);
					}
		}
		
}

void ceva_smmu_init(void)
{
		int tmp=0,i=0;
		int num_smr=0,pagesize=0,num_page=0,num_cb=0;
		int	cb_base=0,gr1_base=0;
		
#define ARM_SMMU_CB(n)	(cb_base+(n)*pagesize)

		//Do not init if device is enabled.
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_sCR0);
		if(tmp & sCR0_CLIENTED ==0)
			{		
				serial_puts(1,"SMMU busy...\n");
				return;
			}
			
		//Get the num of smrs
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_ID0);
		num_smr	= tmp & ID0_NUMSMRG_MASK;
		
		//Get pagesize
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_ID1);
		if(tmp & ID1_PAGESIZE)
				pagesize = 0x1000;//64KB
		else
				pagesize = 0x1000;//4KB
				
		//Get the number of Context Banks		
		num_cb = tmp & ID1_NUMCB_MASK;
		
		//Calculate cb_base
		num_page = 1 << ( ((tmp>>ID1_NUMPAGENDXB_SHIFT)& ID1_NUMPAGENDXB_MASK)+1); //2^ (PAGENDX+1)
		cb_base = ARM_SMMU_BASE + num_page * pagesize;
		
		//Set ACTR
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_sACR);
		tmp &= ~ARM_SMMU_ACR_CACHE_LOCK;
		tmp |= ARM_SMMU_ACR_SMTNMB_THBEN;
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_sACR,tmp);
		
		//clear all global faults
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_sGRSR);
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_sGFSR,tmp);//write '1' to clear the bit
		
		//clea all SMR and S2CR, not do it, just keep the default value
		
		//invalidate all TLBs
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_TLBIALLH,0);
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_TLBIALLNSNH,0);
		
		
		//Stream ID match SMRs: MSB5bit = 0/1/2 for TBU 0/1/2
		tmp = 0;
		tmp |= SMR_VALID;//id=0
		tmp &= (~SMR_MASK_MASK<<SMR_MASK_SHIFT);//clear mask
		tmp |= 0x3FF << SMR_MASK_SHIFT;//only use bit 14-10 to match
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_SMR(0),tmp);
		
		tmp |= (0x1<<10);//id=1 ; bit 10
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_SMR(1),tmp);
		
		tmp &= (SMR_ID_MASK<<SMR_ID_SHIFT);//clear ID
		tmp |= (0x1<<11);//id=2 ; bit 11
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_SMR(2),tmp);
		
		//S2CR reg
		tmp = read_reg32(ARM_SMMU_BASE+ARM_SMMU_GR0_S2CR(0));
		tmp = tmp & ~(S2CR_TYPE_MASK<<S2CR_TYPE_SHIFT) | S2CR_TYPE_TRANS;
		tmp &= (~S2CR_CBNDX_MASK);//CB 0
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_S2CR(0),tmp);
		tmp |= 0x1;//CB 1
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_S2CR(1),tmp);
		tmp &= (~S2CR_CBNDX_MASK);//CB 2
		tmp |= 0x2;
		write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_S2CR(2),tmp);
		
		//set context bank attr ,type = 01 (stage 1 with stage 2 bypass)
		for (i=0;i<3;i++)
		{
				//clear fault status
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_SCTLR,0);
				tmp = read_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_FSR);
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_FSR,tmp);
				
				gr1_bass = ARM_SMMU_BASE + 1 * pagesize;
				tmp = read_reg32(gr1_base + ARM_SMMU_GR1_CBAR(i));
				tmp &= ~(CBAR_TYPE_MASK << CBAR_TYPE_SHIFT);
				tmp |= CBAR_TYPE_S1_TRANS_S2_BYPASS;
				tmp |= CBAR_S1_MEMATTR_WB << CBAR_S1_MEMATTR_SHIFT;
				tmp |= CMAR_BPSHCFG_OUTERSH << CBAR_BPSHCFG_OUTERSH_SHIFT;//shared mem attr
				write_reg32(gr1_base + ARM_SMMU_GR1_CBAR(i),tmp);
				
				//set TTBR0 ,keep attr default , only set base addr
				tmp = read_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBR0);
				tmp |= (int) pgtable_base & (TTBR_ADDR_MASK << TTBR_ADDR_SHIFT);
				//set page table attribute IRGN RGN NOS S
				tmp |= 0x4A;
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBR0,tmp);
				
				//set TCR and TCR2
				tmp = read_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBCR);
				tmp |= (0x1 <<14);
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBCR,tmp);
				
				tmp = read_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBCR2);
				tmp |= (0x1 <<14);
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_TTBCR2,tmp);
		
				//enable MMU
				tmp = read_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_SCTLR);
				tmp |= (0x2 <<28);
				write_reg32(ARM_SMMU_CB(i) + ARM_SMMU_CB_SCTLR,tmp | SCTRL_M | SCTLR_CFIE | SCTLR_CFRE);//enable MMU for this CB		
		}	
		
				//translation type : not bypass , stage 1
				tmp = read_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_sCR0);
				//enable fault report
				tmp |= (sCR0_GFRE | sCR0_GFIE | sCR0_GCFGFRE | sCR0_GCFGFIE);
				
				//disable TLB broadcasting
				tmp |= (sCR0_VMIDPNE | sCR0_PTM);
				
				//enable client access, but bypass when no mapping is found
				//tmp &= ~(sCR0_CLIENTPD | sCR0_ISFCFG);
				
				//disbale forced broadcasting
				tmp &= ~sCR0_FB;
				
				//Don't upgrade barriers
				tmp &= ~(sCR0_BSU_MASK << sCR0_BSU_SHIFT);
				tmp &= ~sCR0_STALLD;
				
				//push the button
				arm_smmu_tlb_sync();
				
				write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_sCR0,(tmp & (~sCR0_CLIENTPD)));
				//Non-secure
				tmp = read_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_NSCR0);
				tmp |= sCR0_GFRE | sCR0_GFIE | sCR0_GCFGFRE | sCR0_GCFGFIE ;
				tmp &= ~sCR0_STALLD;
				write_reg32(ARM_SMMU_BASE + ARM_SMMU_GR0_NSCR0,(tmp & (~sCR0_CLIENTPD)));
				
}