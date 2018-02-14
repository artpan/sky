int tile_countdown(
int f_pingpong,
int cbuf_dat0_address,	
int cbuf_dat1_address,
int cbuf_wt0_address,
int cbuf_wt1_address,	
int num_dat_tile,	
int num_wt_tile,
int *cnt_num_dat_tile,
int *cnt_num_wt_tile,
int *cnt_cbuf_dat_address,
int *cnt_cbuf_wt_address,
int *flag_cbuf_pingpong_dat,	
int *flag_cbuf_pingpong_wt
){
	
	if(f_pingpong == 1){
        (*cnt_num_dat_tile)++;
        if(*flag_cbuf_pingpong_dat==0){
           *cnt_cbuf_dat_address = cbuf_dat1_address;
		   *flag_cbuf_pingpong_dat = 1;
		}
        else{
           *cnt_cbuf_dat_address = cbuf_dat0_address;
		   *flag_cbuf_pingpong_dat = 0;		   
		}
        if(*cnt_num_dat_tile == num_dat_tile){
			(*cnt_num_wt_tile)++;
            (*cnt_num_dat_tile)=0;
            if(*flag_cbuf_pingpong_wt==0){
                *cnt_cbuf_wt_address = cbuf_wt1_address;
				*flag_cbuf_pingpong_wt = 1;
			}
            else{
                *cnt_cbuf_wt_address = cbuf_wt0_address;
				*flag_cbuf_pingpong_wt = 0;				
			}
            if(*cnt_num_wt_tile == num_wt_tile){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	else{
        (*cnt_num_wt_tile)++;
        if(*flag_cbuf_pingpong_wt==0){
           *cnt_cbuf_wt_address = cbuf_wt1_address;
		   *flag_cbuf_pingpong_wt = 1;
		}
        else{
           *cnt_cbuf_wt_address = cbuf_wt0_address;
		   *flag_cbuf_pingpong_wt = 0;		   
		}
		if(*cnt_num_wt_tile == num_wt_tile){
            (*cnt_num_dat_tile)++;
            *cnt_num_wt_tile=0;
            if(*flag_cbuf_pingpong_dat==0){
               *cnt_cbuf_dat_address = cbuf_dat1_address;
		       *flag_cbuf_pingpong_dat = 1;			   
			}
            else{
               *cnt_cbuf_dat_address = cbuf_dat0_address;
		       *flag_cbuf_pingpong_dat = 0;				
			}
            if(*cnt_num_dat_tile == num_dat_tile){
				return 1;
			}
            else{
				return 0;
			}				
		}
		else{
			return 0;
		}
		
		
		
		
	}
	
	
}