#include "header/dla_func.h"
#include "header/csc_func.h"
#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//parameter
//cdma
//  config register
const int para_conv                               =1  ;
const int para_f_pingpong                         =0  ;
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
const int para_tile_dat_type                      =0  ;
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

//csc 
//  config register
const int para_len_dat_stride_norm_1     =16;
const int para_num_dat_stride_norm_1     =2;
const int para_len_dat_stride_last_1     =17;
const int para_num_dat_stride_last_1     =1;
const int para_len_dat_stride_norm_2     =0;
const int para_num_dat_stride_norm_2     =0;
const int para_len_dat_stride_last_2     =0;
const int para_num_dat_stride_last_2     =0;
const int para_len_dat_stride_norm_3     =0;
const int para_num_dat_stride_norm_3     =0;
const int para_len_dat_stride_last_3     =0;
const int para_num_dat_stride_last_3     =0;
const int para_len_dat_stride_norm_4     =0;
const int para_num_dat_stride_norm_4     =0;
const int para_len_dat_stride_last_4     =0;
const int para_num_dat_stride_last_4     =0;
const int para_len_dat_stride_norm_5     =0;
const int para_num_dat_stride_norm_5     =0;
const int para_len_dat_stride_last_5     =0;
const int para_num_dat_stride_last_5     =0;
const int para_len_dat_stride_norm_6     =0;
const int para_num_dat_stride_norm_6     =0;
const int para_len_dat_stride_last_6     =0;
const int para_num_dat_stride_last_6     =0;
const int para_len_dat_stride_norm_7     =0;
const int para_num_dat_stride_norm_7     =0;
const int para_len_dat_stride_last_7     =0;
const int para_num_dat_stride_last_7     =0;
const int para_len_dat_stride_norm_8     =0;
const int para_num_dat_stride_norm_8     =0;
const int para_len_dat_stride_last_8     =0;
const int para_num_dat_stride_last_8     =0;
const int para_len_dat_stride_norm_9     =0;
const int para_num_dat_stride_norm_9     =0;
const int para_len_dat_stride_last_9     =0;
const int para_num_dat_stride_last_9     =0;
const int para_index_enable              =0;
const int para_index_width               =0;
//const int para_f_pingpong                =0;
const int para_kernel_size_x	         =3;
const int para_kernel_size_y	         =3;
const int para_kernel_stride_x	         =1;
const int para_kernel_stride_y	         =1;
const int para_padding_t	             =0;
const int para_padding_b	             =0;
const int para_padding_l	             =0;
const int para_padding_r	             =0;
const int para_padding_x	             =0;
const int para_padding_y	             =0;
const int para_dilated_x	             =0;
const int para_dilated_y	             =0;
const int para_input_channel	         =128;
const int para_output_channel	         =32;
const int para_computation_type	         =0;
const int para_num_engine	             =1;
//const int para_cbuf_dat0_address	     =0;
//const int para_cbuf_dat1_address	     =0;
//const int para_cbuf_wt0_address	         =0;
//const int para_cbuf_wt1_address	         =0;
//const int para_tile_dat_type	         =0;
//const int para_num_wt_tile	             =0;
const int para_compute_data_precision	 =8;
const int para_compute_weight_precision	 =8;									
const int para_tile_num_wt_output_kernel =16;
const int para_num_stride_output_kernel	 =16;
const int para_num_input_folding	     =1;
const int para_tile_size_x_1	         =7;
const int para_tile_size_y_1	         =7;
const int para_tile_size_x_2	         =0;
const int para_tile_size_y_2	         =0;
const int para_tile_size_x_3	         =0;
const int para_tile_size_y_3	         =0;
const int para_tile_size_x_4	         =0;
const int para_tile_size_y_4	         =0;
const int para_tile_size_x_5	         =0;
const int para_tile_size_y_5	         =0;
const int para_tile_size_x_6	         =0;
const int para_tile_size_y_6	         =0;
const int para_tile_size_x_7	         =0;
const int para_tile_size_y_7	         =0;
const int para_tile_size_x_8	         =0;
const int para_tile_size_y_8	         =0;
const int para_tile_size_x_9	         =0;
const int para_tile_size_y_9	         =0;
//const int para_tile_num_x_c	             =0;
//const int para_tile_num_y_c	             =0;



// memory 
const int cbuf_depth = 2048;
const int cbuf_width = 1024; 
const int ddr_depth  = 100000;
const int ddr_width  = 8;
const int c2cmac_dat_width = 1024;
const int c2cmac_wt_width  = 1024;
int c2cmac_wt_depth        = 0;
int c2cmac_dat_depth       = 0;
int sc2cbuf_wt_req_depth   = 0;
int sc2cbuf_dat_req_depth  = 0;

int **ddr               ; //ddr or on-chip sram
int **cbuf              ; //cbuf
int *csc2cbuf_wt_req    ; //csc wt address req for cbuf
int *csc2cbuf_dat_req   ; //csc dat address req for cbuf
int **c2cmac_wt         ; //csc to cmac wt
int **c2cmac_dat        ; //csc to cmac dat
int *c2cmac_wt_vld      ;
int *c2cmac_dat_vld     ;
int *sc2cbuf_wt_req     ; //csc to cbuf wt address request   
int *sc2cbuf_dat_req    ; //csc to cbuf dat address request   
int *sc2cbuf_wt_req_vld     ;   
int *sc2cbuf_dat_req_vld    ; 

int main(){

int cnt_num_dat_tile_cdma          = 0;
int cnt_num_wt_tile_cdma           = 0;
int cnt_ddr_wt_address_cdma        = 0;
int cnt_ddr_dat_start_address_cdma = 0;
int flag_end_cdma                  = 0; 
int cnt_num_dat_tile_csc           = 0;
int cnt_num_wt_tile_csc            = 0;
int flag_cbuf_pingpong_dat_csc     = 0;
int flag_cbuf_pingpong_wt_csc      = 0;
int flag_end_csc                   = 0;
//variable
int i;
int j;
//initial ddr mem



    dla_csc_interface_init(
    //config parameter
    para_tile_dat_type           ,
    para_num_dat_stride_norm_1   ,
    para_len_dat_stride_norm_1   ,
    para_num_dat_stride_last_1   ,
    para_len_dat_stride_last_1   ,
    para_num_dat_stride_norm_2   ,
    para_len_dat_stride_norm_2   ,
    para_num_dat_stride_last_2   ,
    para_len_dat_stride_last_2   ,
    para_num_dat_stride_norm_3   ,
    para_len_dat_stride_norm_3   ,
    para_num_dat_stride_last_3   ,
    para_len_dat_stride_last_3   ,
    para_num_dat_stride_norm_4   ,
    para_len_dat_stride_norm_4   ,
    para_num_dat_stride_last_4   ,
    para_len_dat_stride_last_4   ,
    para_num_dat_stride_norm_5   ,
    para_len_dat_stride_norm_5   ,
    para_num_dat_stride_last_5   ,
    para_len_dat_stride_last_5   ,
    para_num_dat_stride_norm_6   ,
    para_len_dat_stride_norm_6   ,
    para_num_dat_stride_last_6   ,
    para_len_dat_stride_last_6   ,
    para_num_dat_stride_norm_7   ,
    para_len_dat_stride_norm_7   ,
    para_num_dat_stride_last_7   ,
    para_len_dat_stride_last_7   ,
    para_num_dat_stride_norm_8   ,
    para_len_dat_stride_norm_8   ,
    para_num_dat_stride_last_8   ,
    para_len_dat_stride_last_8   ,
    para_num_dat_stride_norm_9   ,
    para_len_dat_stride_norm_9   ,
    para_num_dat_stride_last_9   ,
    para_len_dat_stride_last_9   ,
    para_tile_num_x_c             ,
    para_tile_num_y_c             ,
    para_tile_num_wt_output_kernel,
    para_num_stride_output_kernel ,
    para_num_wt_tile              ,
    para_computation_type         ,
    para_num_input_folding        ,
    para_kernel_size_y            ,
    para_kernel_size_x            ,
//constant 
    c2cmac_dat_width              ,
    c2cmac_wt_width               ,
//return depth
    &c2cmac_wt_depth               ,
    &c2cmac_dat_depth              ,
    &sc2cbuf_wt_req_depth          ,
    &sc2cbuf_dat_req_depth              
    );
//ddr
ddr = (int **)malloc(ddr_depth * sizeof(int *));
for(i=0;i<ddr_depth;i++){
	ddr[i] = (int *)malloc(ddr_width *sizeof(int));
}
//cbuf
cbuf = (int **)malloc(cbuf_depth * sizeof(int *));
for(i=0;i<cbuf_depth;i++){
	cbuf[i] = (int *)malloc(cbuf_width *sizeof(int));
}
//c2cmac_wt
c2cmac_wt = (int **)malloc(c2cmac_wt_depth * sizeof(int *));
for(i=0;i<c2cmac_wt_depth;i++){
	c2cmac_wt[i] = (int *)malloc(c2cmac_wt_width * sizeof(int));
}
//c2cmac_wt_vld
c2cmac_wt_vld = (int *)malloc(c2cmac_wt_depth * sizeof(int ));
//c2cbuf_wt_req    
sc2cbuf_wt_req = (int *)malloc(sc2cbuf_wt_req_depth * sizeof(int ));
//c2cbuf_wt_vld
sc2cbuf_wt_req_vld = (int *)malloc(sc2cbuf_wt_req_depth * sizeof(int ));
//c2cmac_dat   
c2cmac_dat = (int **)malloc(c2cmac_dat_depth * sizeof(int *));
for(i=0;i<c2cmac_dat_depth;i++){
	c2cmac_dat[i] = (int *)malloc(c2cmac_dat_width *sizeof(int));
}
//c2cmac_dat_vld
c2cmac_dat_vld = (int *)malloc(c2cmac_dat_depth * sizeof(int ));
//sc2cbuf_dat_req
sc2cbuf_dat_req = (int *)malloc(sc2cbuf_dat_req_depth * sizeof(int ));
//sc2cbuf_dat_req_vld
sc2cbuf_dat_req_vld = (int *)malloc(sc2cbuf_dat_req_depth * sizeof(int ));





// init ddr for test
for(i=0;i<ddr_depth;i++){
	for(j=0;j<ddr_width;j++){
		ddr[i][j] = i;
	}
}




//  para conv
if(para_conv==1){
	        while(1){
				   if(flag_end_cdma == 1){
    			       break; 
    			   }
                   flag_end_cdma = cdma_func(
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
                                        &cnt_num_dat_tile_cdma          ,
                                       	&cnt_num_wt_tile_cdma           ,
                                        &cnt_ddr_wt_address_cdma        ,
                                        &cnt_ddr_dat_start_address_cdma ,	                                       
                                        //  data in
                                        ddr                        ,                
                                        //  data out
                                        cbuf   
                                       	);

				   while(1){
                            flag_end_csc = csc_func(
                                                         //  config register
                                                     	para_len_dat_stride_norm_1        ,
                                                        para_num_dat_stride_norm_1        ,
                                                        para_len_dat_stride_last_1        ,
                                                        para_num_dat_stride_last_1        ,
                                                    	para_len_dat_stride_norm_2        ,
                                                        para_num_dat_stride_norm_2        ,
                                                        para_len_dat_stride_last_2        ,
                                                        para_num_dat_stride_last_2        ,
                                                    	para_len_dat_stride_norm_3        ,
                                                        para_num_dat_stride_norm_3        ,
                                                        para_len_dat_stride_last_3        ,
                                                        para_num_dat_stride_last_3        ,
                                                    	para_len_dat_stride_norm_4        ,
                                                        para_num_dat_stride_norm_4        ,
                                                        para_len_dat_stride_last_4        ,
                                                        para_num_dat_stride_last_4        ,
                                                    	para_len_dat_stride_norm_5        ,
                                                        para_num_dat_stride_norm_5        ,
                                                        para_len_dat_stride_last_5        ,
                                                        para_num_dat_stride_last_5        ,
                                                    	para_len_dat_stride_norm_6        ,
                                                        para_num_dat_stride_norm_6        ,
                                                        para_len_dat_stride_last_6        ,
                                                        para_num_dat_stride_last_6        ,
                                                    	para_len_dat_stride_norm_7        ,
                                                        para_num_dat_stride_norm_7        ,
                                                        para_len_dat_stride_last_7        ,
                                                        para_num_dat_stride_last_7        ,
                                                    	para_len_dat_stride_norm_8        ,
                                                        para_num_dat_stride_norm_8        ,
                                                        para_len_dat_stride_last_8        ,
                                                        para_num_dat_stride_last_8        ,
                                                    	para_len_dat_stride_norm_9        ,
                                                        para_num_dat_stride_norm_9        ,
                                                        para_len_dat_stride_last_9        ,
                                                        para_num_dat_stride_last_9        ,
                                                        para_index_enable                 ,
                                                        para_index_width                  ,
                                                        para_f_pingpong                   ,
                                                    	//para_feature_size_x	             ,
                                                    	//para_feature_size_y	             ,
                                                    	para_kernel_size_x	             ,
                                                    	para_kernel_size_y	             ,
                                                    	para_kernel_stride_x	             ,
                                                    	para_kernel_stride_y	             ,
                                                    	para_padding_t	                 ,
                                                    	para_padding_b	                 ,
                                                    	para_padding_l	                 ,
                                                    	para_padding_r	                 ,
                                                    	para_padding_x	                 ,
                                                    	para_padding_y	                 ,
                                                    	para_dilated_x	                 ,
                                                    	para_dilated_y	                 ,
                                                    	para_input_channel	             ,
                                                    	para_output_channel	             ,
                                                    	para_computation_type	         ,
                                                    	para_num_engine	                 ,
                                                    	para_cbuf_dat0_address	         ,
                                                    	para_cbuf_dat1_address	         ,
                                                    	para_cbuf_wt0_address	         ,
                                                    	para_cbuf_wt1_address	         ,
                                                    	para_tile_dat_type	             ,
                                                    	para_num_wt_tile	                 ,
                                                    	para_compute_data_precision	     ,
                                                    	para_compute_weight_precision	 ,											
                                                      	para_tile_num_wt_output_kernel	 ,
                                                    	para_num_stride_output_kernel	 ,
                                                    	para_num_input_folding	         ,
                                                    	para_tile_size_x_1	             ,
                                                    	para_tile_size_y_1	             ,
                                                    	para_tile_size_x_2	             ,
                                                    	para_tile_size_y_2	             ,
                                                    	para_tile_size_x_3	             ,
                                                    	para_tile_size_y_3	             ,
                                                    	para_tile_size_x_4	             ,
                                                    	para_tile_size_y_4	             ,
                                                    	para_tile_size_x_5	             ,
                                                    	para_tile_size_y_5	             ,
                                                    	para_tile_size_x_6	             ,
                                                    	para_tile_size_y_6	             ,
                                                    	para_tile_size_x_7	             ,
                                                    	para_tile_size_y_7	             ,
                                                    	para_tile_size_x_8	             ,
                                                    	para_tile_size_y_8	             ,
                                                    	para_tile_size_x_9	             ,
                                                    	para_tile_size_y_9	             ,
                                                    	para_tile_num_x_c	             ,
                                                    	para_tile_num_y_c	             ,
                                                    //  loop counter                  ,
                                                        &cnt_num_dat_tile_csc          ,
                                                    	&cnt_num_wt_tile_csc           ,
                                                    	&flag_cbuf_pingpong_dat_csc    ,
                                                    	&flag_cbuf_pingpong_wt_csc     ,
                                                    //  data in
                                                        //int cbuf2csc_wt_ready       ,
                                                        //int cbuf2csc_dat_ready      ,
                                                        cbuf                    ,
                                                    //  data out
                                                        sc2cbuf_wt_req           ,
                                                    	sc2cbuf_wt_req_vld       ,
                                                        sc2cbuf_dat_req          ,
                                                    	sc2cbuf_dat_req_vld      ,
                                                    	//int c2cmac_req            ,
                                                        c2cmac_wt                ,
                                                    	c2cmac_wt_vld             ,
                                                        c2cmac_dat               ,
                                                        c2cmac_dat_vld           
                                            	);
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
    			   }
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
		   
		   
		   
	       //ddr
	       fp = fopen("ddr.txt","w");
	       for(i=0;i<ddr_depth;i++){
	           fprintf(fp,"ddr[%d]=%d\n",i,ddr[i][0]);
	       }
	       fclose(fp);		   
		   
	       //cbuf
	       fp = fopen("cbuf.txt","w");
	       for(i=0;i<cbuf_depth;i++){
	           fprintf(fp,"cbuf[%d]=%d\n",i,cbuf[i][0]);
	       }
	       fclose(fp);
		   
	       //c2cmac_dat
	       fp = fopen("c2cmac_dat.txt","w");
	       for(i=0;i<c2cmac_dat_depth;i++){
	           fprintf(fp,"c2cmac_dat[%d]=%d\n",i,c2cmac_dat[i][0]);
	       }
	       fclose(fp);
		   
	       //c2cmac_wt
	       fp = fopen("c2cmac_wt.txt","w");
	       for(i=0;i<c2cmac_wt_depth;i++){
	           fprintf(fp,"c2cmac_wt[%d]=%d\n",i,c2cmac_wt[i][0]);
	       }
	       fclose(fp);		   
		   
		   
	       //watermark
		   fprintf(fp,"work done!\n");
	       system("pause");








}

