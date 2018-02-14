#include "dla_func.h"
#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//parameter
//cdma
//  config register
const int para_conv                               =1  ;
const int para_f_pingpong                         =1  ;
const int para_cbuf_dat0_address                  =0  ;
const int para_cbuf_dat1_address                  =256;
const int para_cbuf_wt0_address                   =512;
const int para_cbuf_wt1_address                   =768;
const int para_ddr_dat_address                    =1000;
const int para_ddr_wt_address                     =0  ;
const int para_ddr_wt_size_norm                   =16*9*(1024/8);	
const int para_ddr_wt_size_last                   =16*9*(1024/8);	
const int para_num_wt_tile                        =2  ;
const int para_num_adding_zero_input_channel_cdma =0  ;
const int para_tile_dat_type                      =1  ;
const int para_tile_size_x_1_no_extend            =7  ;
const int para_tile_size_y_1_no_extend            =7  ;
const int para_tile_size_x_2_no_extend            =7  ;
const int para_tile_size_y_2_no_extend            =7  ;	
const int para_tile_size_x_3_no_extend            =0  ;
const int para_tile_size_y_3_no_extend            =0  ;
const int para_tile_size_x_4_no_extend            =0  ;
const int para_tile_size_y_4_no_extend            =0  ;
const int para_tile_size_x_5_no_extend            =0  ;
const int para_tile_size_y_5_no_extend            =0  ;
const int para_tile_size_x_6_no_extend            =0  ;
const int para_tile_size_y_6_no_extend            =0  ;	
const int para_tile_size_x_7_no_extend            =0  ;
const int para_tile_size_y_7_no_extend            =0  ;	
const int para_tile_size_x_8_no_extend            =0  ;
const int para_tile_size_y_8_no_extend            =0  ;	
const int para_tile_size_x_9_no_extend            =0  ;
const int para_tile_size_y_9_no_extend            =0  ;		
const int para_tile_num_x_c                       =0  ;
const int para_tile_num_y_c                       =0  ;	
const int para_ddr_size_input_channel             =1024/8;	
 
const int para_extend_dat_type_1_num_1_r          =1;
const int para_extend_dat_type_1_num_2_l          =1;
 
const int para_extend_dat_type_2_num_1_b          =0;
const int para_extend_dat_type_2_num_2_t          =0;	
     
const int para_extend_dat_type_3_num_1_b          =0;
const int para_extend_dat_type_3_num_1_r          =0;			
const int para_extend_dat_type_3_num_2_b          =0;
const int para_extend_dat_type_3_num_2_l          =0;	
const int para_extend_dat_type_3_num_3_t          =0;
const int para_extend_dat_type_3_num_3_r          =0;	
const int para_extend_dat_type_3_num_4_t          =0;
const int para_extend_dat_type_3_num_4_l          =0;	
     
const int para_extend_dat_type_4_num_1_b          =0;
const int para_extend_dat_type_4_num_1_r          =0;			
const int para_extend_dat_type_4_num_2_b          =0;
const int para_extend_dat_type_4_num_2_l          =0;	
const int para_extend_dat_type_4_num_2_r          =0;
const int para_extend_dat_type_4_num_3_b          =0;	
const int para_extend_dat_type_4_num_3_l          =0;
const int para_extend_dat_type_4_num_4_t          =0;		
const int para_extend_dat_type_4_num_4_r          =0;
const int para_extend_dat_type_4_num_5_t          =0;			
const int para_extend_dat_type_4_num_5_l          =0;
const int para_extend_dat_type_4_num_5_r          =0;	
const int para_extend_dat_type_4_num_6_t          =0;
const int para_extend_dat_type_4_num_6_l          =0;	
     
const int para_extend_dat_type_5_num_1_b          =0;
const int para_extend_dat_type_5_num_1_r          =0;			
const int para_extend_dat_type_5_num_2_b          =0;
const int para_extend_dat_type_5_num_2_l          =0;	
const int para_extend_dat_type_5_num_3_t          =0;
const int para_extend_dat_type_5_num_3_b          =0;	
const int para_extend_dat_type_5_num_3_r          =0;
const int para_extend_dat_type_5_num_4_t          =0;		
const int para_extend_dat_type_5_num_4_b          =0;
const int para_extend_dat_type_5_num_4_l          =0;			
const int para_extend_dat_type_5_num_5_t          =0;
const int para_extend_dat_type_5_num_5_r          =0;	
const int para_extend_dat_type_5_num_6_t          =0;
const int para_extend_dat_type_5_num_6_l          =0;	
     
const int para_extend_dat_type_6_num_1_b          =0;
const int para_extend_dat_type_6_num_1_r          =0;			
const int para_extend_dat_type_6_num_2_b          =0;
const int para_extend_dat_type_6_num_2_l          =0;	
const int para_extend_dat_type_6_num_2_r          =0;
const int para_extend_dat_type_6_num_3_b          =0;	
const int para_extend_dat_type_6_num_3_l          =0;
const int para_extend_dat_type_6_num_4_t          =0;		
const int para_extend_dat_type_6_num_4_b          =0;
const int para_extend_dat_type_6_num_4_r          =0;			
const int para_extend_dat_type_6_num_5_t          =0;
const int para_extend_dat_type_6_num_5_b          =0;	
const int para_extend_dat_type_6_num_5_l          =0;
const int para_extend_dat_type_6_num_5_r          =0;	
const int para_extend_dat_type_6_num_6_t          =0;
const int para_extend_dat_type_6_num_6_b          =0;	
const int para_extend_dat_type_6_num_6_l          =0;
const int para_extend_dat_type_6_num_7_t          =0;		
const int para_extend_dat_type_6_num_7_r          =0;
const int para_extend_dat_type_6_num_8_t          =0;			
const int para_extend_dat_type_6_num_8_l          =0;
const int para_extend_dat_type_6_num_8_r          =0;	
const int para_extend_dat_type_6_num_9_t          =0;
const int para_extend_dat_type_6_num_9_l          =0;	
     
const int para_address_incr_dat_type_0_num_1      =0;
const int para_address_incr_dat_type_1_num_1      =896;
const int para_address_incr_dat_type_1_num_2      =896;
const int para_address_incr_dat_type_2_num_1      =0;
const int para_address_incr_dat_type_2_num_2      =0;
const int para_address_incr_dat_type_3_num_1      =0;
const int para_address_incr_dat_type_3_num_2      =0;   
const int para_address_incr_dat_type_3_num_3      =0;  
const int para_address_incr_dat_type_3_num_4      =0;
const int para_address_incr_dat_type_4_num_1      =0;
const int para_address_incr_dat_type_4_num_2      =0;   
const int para_address_incr_dat_type_4_num_3      =0;  
const int para_address_incr_dat_type_4_num_4      =0;
const int para_address_incr_dat_type_4_num_5      =0;  
const int para_address_incr_dat_type_4_num_6      =0;
const int para_address_incr_dat_type_5_num_1      =0;
const int para_address_incr_dat_type_5_num_2      =0;   
const int para_address_incr_dat_type_5_num_3      =0;  
const int para_address_incr_dat_type_5_num_4      =0;
const int para_address_incr_dat_type_5_num_5      =0;  
const int para_address_incr_dat_type_5_num_6      =0;
const int para_address_incr_dat_type_6_num_1      =0;
const int para_address_incr_dat_type_6_num_2      =0;   
const int para_address_incr_dat_type_6_num_3      =0;  
const int para_address_incr_dat_type_6_num_4      =0;
const int para_address_incr_dat_type_6_num_5      =0;  
const int para_address_incr_dat_type_6_num_6      =0;
const int para_address_incr_dat_type_6_num_7      =0;
const int para_address_incr_dat_type_6_num_8      =0;  
const int para_address_incr_dat_type_6_num_9      =0;






// memory 
const int cbuf_depth = 2048;
const int cbuf_width = 1024; 
const int ddr_depth  = 100000;
const int ddr_width  = 8;
int **ddr               ; //ddr or on-chip sram
int **cbuf              ; // cbuf



int main(){

int cnt_num_dat_tile          = 0;
int cnt_num_wt_tile           = 0;
int cnt_ddr_wt_address        = 0;
int cnt_ddr_dat_start_address = 0;
int flag_end                  = 0; 

//variable
int i;
int j;
//initial ddr mem
ddr = (int **)malloc(ddr_depth * sizeof(int *));
for(i=0;i<ddr_depth;i++){
	ddr[i] = (int *)malloc(ddr_width *sizeof(int));
}
cbuf = (int **)malloc(cbuf_depth * sizeof(int *));
for(i=0;i<cbuf_depth;i++){
	cbuf[i] = (int *)malloc(cbuf_width *sizeof(int));
}
for(i=0;i<ddr_depth;i++){
	for(j=0;j<ddr_width;j++){
		ddr[i][j] = i;
	}
}



//  para conv
if(para_conv==1){
	        while(1){	
                   flag_end = cdma_func(
                                       //  config register
                                       	para_f_pingpong                ,
                                        para_cbuf_dat0_address         ,
                                        para_cbuf_dat1_address         ,
                                        para_cbuf_wt0_address          ,
                                        para_cbuf_wt1_address          ,
                                       	para_ddr_dat_address           ,
                                       	para_ddr_wt_address            ,
                                       	para_ddr_wt_size_norm          ,	
                                        para_ddr_wt_size_last          ,	
                                       	para_num_wt_tile               ,
                                       	para_num_adding_zero_input_channel_cdma ,
                                       	para_tile_dat_type             ,
                                        para_tile_size_x_1_no_extend   ,
                                        para_tile_size_y_1_no_extend   ,
                                        para_tile_size_x_2_no_extend   ,
                                        para_tile_size_y_2_no_extend   ,	
                                        para_tile_size_x_3_no_extend   ,
                                        para_tile_size_y_3_no_extend   ,
                                        para_tile_size_x_4_no_extend   ,
                                        para_tile_size_y_4_no_extend   ,
                                        para_tile_size_x_5_no_extend   ,
                                        para_tile_size_y_5_no_extend   ,
                                        para_tile_size_x_6_no_extend   ,
                                        para_tile_size_y_6_no_extend   ,	
                                        para_tile_size_x_7_no_extend   ,
                                        para_tile_size_y_7_no_extend   ,	
                                        para_tile_size_x_8_no_extend   ,
                                        para_tile_size_y_8_no_extend   ,	
                                        para_tile_size_x_9_no_extend   ,
                                        para_tile_size_y_9_no_extend   ,		
                                        para_tile_num_x_c              ,
                                        para_tile_num_y_c              ,	
                                        para_ddr_size_input_channel    ,	
                                       	
                                       	para_extend_dat_type_1_num_1_r,
                                       	para_extend_dat_type_1_num_2_l,
                                       	
                                       	para_extend_dat_type_2_num_1_b,
                                       	para_extend_dat_type_2_num_2_t,	
                                       	    
                                       	para_extend_dat_type_3_num_1_b,
                                       	para_extend_dat_type_3_num_1_r,			
                                       	para_extend_dat_type_3_num_2_b,
                                       	para_extend_dat_type_3_num_2_l,	
                                       	para_extend_dat_type_3_num_3_t,
                                       	para_extend_dat_type_3_num_3_r,	
                                       	para_extend_dat_type_3_num_4_t,
                                       	para_extend_dat_type_3_num_4_l,	
                                       	    
                                       	para_extend_dat_type_4_num_1_b,
                                       	para_extend_dat_type_4_num_1_r,			
                                       	para_extend_dat_type_4_num_2_b,
                                       	para_extend_dat_type_4_num_2_l,	
                                       	para_extend_dat_type_4_num_2_r,
                                       	para_extend_dat_type_4_num_3_b,	
                                       	para_extend_dat_type_4_num_3_l,
                                       	para_extend_dat_type_4_num_4_t,		
                                       	para_extend_dat_type_4_num_4_r,
                                       	para_extend_dat_type_4_num_5_t,			
                                       	para_extend_dat_type_4_num_5_l,
                                       	para_extend_dat_type_4_num_5_r,	
                                       	para_extend_dat_type_4_num_6_t,
                                       	para_extend_dat_type_4_num_6_l,	
                                            
                                       	para_extend_dat_type_5_num_1_b,
                                       	para_extend_dat_type_5_num_1_r,			
                                       	para_extend_dat_type_5_num_2_b,
                                       	para_extend_dat_type_5_num_2_l,	
                                       	para_extend_dat_type_5_num_3_t,
                                       	para_extend_dat_type_5_num_3_b,	
                                       	para_extend_dat_type_5_num_3_r,
                                       	para_extend_dat_type_5_num_4_t,		
                                       	para_extend_dat_type_5_num_4_b,
                                       	para_extend_dat_type_5_num_4_l,			
                                       	para_extend_dat_type_5_num_5_t,
                                       	para_extend_dat_type_5_num_5_r,	
                                       	para_extend_dat_type_5_num_6_t,
                                       	para_extend_dat_type_5_num_6_l,	
                                            
                                       	para_extend_dat_type_6_num_1_b,
                                       	para_extend_dat_type_6_num_1_r,			
                                       	para_extend_dat_type_6_num_2_b,
                                       	para_extend_dat_type_6_num_2_l,	
                                       	para_extend_dat_type_6_num_2_r,
                                       	para_extend_dat_type_6_num_3_b,	
                                       	para_extend_dat_type_6_num_3_l,
                                       	para_extend_dat_type_6_num_4_t,		
                                       	para_extend_dat_type_6_num_4_b,
                                       	para_extend_dat_type_6_num_4_r,			
                                       	para_extend_dat_type_6_num_5_t,
                                       	para_extend_dat_type_6_num_5_b,	
                                       	para_extend_dat_type_6_num_5_l,
                                       	para_extend_dat_type_6_num_5_r,	
                                       	para_extend_dat_type_6_num_6_t,
                                       	para_extend_dat_type_6_num_6_b,	
                                       	para_extend_dat_type_6_num_6_l,
                                       	para_extend_dat_type_6_num_7_t,		
                                       	para_extend_dat_type_6_num_7_r,
                                       	para_extend_dat_type_6_num_8_t,			
                                       	para_extend_dat_type_6_num_8_l,
                                       	para_extend_dat_type_6_num_8_r,	
                                       	para_extend_dat_type_6_num_9_t,
                                       	para_extend_dat_type_6_num_9_l,	
                                            
                                        para_address_incr_dat_type_0_num_1,	
                                       	para_address_incr_dat_type_1_num_1,	
                                        para_address_incr_dat_type_1_num_2,	
                                       	para_address_incr_dat_type_2_num_1,	
                                       	para_address_incr_dat_type_2_num_2,	
                                       	para_address_incr_dat_type_3_num_1,	
                                       	para_address_incr_dat_type_3_num_2,	   
                                       	para_address_incr_dat_type_3_num_3,	  
                                       	para_address_incr_dat_type_3_num_4,
                                       	para_address_incr_dat_type_4_num_1,	
                                       	para_address_incr_dat_type_4_num_2,	   
                                       	para_address_incr_dat_type_4_num_3,	  
                                       	para_address_incr_dat_type_4_num_4,
                                       	para_address_incr_dat_type_4_num_5,	  
                                       	para_address_incr_dat_type_4_num_6,
                                       	para_address_incr_dat_type_5_num_1,	
                                       	para_address_incr_dat_type_5_num_2,	   
                                       	para_address_incr_dat_type_5_num_3,	  
                                       	para_address_incr_dat_type_5_num_4,
                                       	para_address_incr_dat_type_5_num_5,	  
                                       	para_address_incr_dat_type_5_num_6,	
                                       	para_address_incr_dat_type_6_num_1,	
                                       	para_address_incr_dat_type_6_num_2,	   
                                       	para_address_incr_dat_type_6_num_3,	  
                                       	para_address_incr_dat_type_6_num_4,
                                       	para_address_incr_dat_type_6_num_5,	  
                                       	para_address_incr_dat_type_6_num_6,
                                       	para_address_incr_dat_type_6_num_7,
                                       	para_address_incr_dat_type_6_num_8,	  
                                       	para_address_incr_dat_type_6_num_9,
                                        //  loop counter                  
                                        &cnt_num_dat_tile          ,
                                       	&cnt_num_wt_tile           ,
                                        &cnt_ddr_wt_address        ,
                                        &cnt_ddr_dat_start_address ,	                                       
                                        //  data in
                                        ddr                        ,                
                                        //  data out
                                        cbuf   
                                       	);
                   if(flag_end == 1){
    			       break; 
    			    }
				   //while(1){
                   //         flag_csc = csc_func();
				   //
                   //         cmac_func();
                   //         //para sdp						   
    			   //         if(para_sdp){
    			   //            sdp_func();
    			   //         }
		           //         //para pdp						   
    			   //         if(para_pdp){
    			   //            pdp_func();
    			   //         }
		           //         //para reshape					   
    			   //         if(para_reshape){
    			   //            reshape();
    			   //         }
				   //		if(flag_csc == 1){
				   //           break;
				   //         }
				   //         }
    			   //}
    }

	}
else{
    // while(1){
    //     //para sdp		
    //     if(para_sdp){
    //     	flag_end=sdp_func();
	// 	}
	// 	//para pdp	
	//     if(para_pdp){
	//     	flag_end=pdp_func();
	//     }
	// 	//para reshape
    //     if(para_reshape){
    //     	flag_end=reshape_func();
    //     }
	// 	//flag end
	// 	if(flag_end == 1){
    // 	    break; 
    // 	}
    // }
}
 
     // debug//
           FILE *fp;
	       //dat
	       fp = fopen("cbuf.txt","w");
           fprintf(fp,"hello world!\n");
	       for(i=0;i<cbuf_depth;i++){
	           fprintf(fp,"cbuf[%d]=%d\n",i,cbuf[i][0]);
	       }
	       fclose(fp);
	       //cmac
	       fp = fopen("ddr.txt","w");
           fprintf(fp,"hello world!\n");
	       for(i=0;i<ddr_depth;i++){
	           fprintf(fp,"ddr[%d]=%d\n",i,ddr[i][0]);
	       }
	       fclose(fp);
	       //cbuf
		   fprintf(fp,"work done!\n");
	       system("pause");








}

