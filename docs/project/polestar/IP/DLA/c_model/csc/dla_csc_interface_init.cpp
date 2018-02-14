#include <malloc.h>

int dla_csc_interface_init(
//config parameter
int para_tile_dat_type           ,
int para_num_dat_stride_norm_1   ,
int para_len_dat_stride_norm_1   ,
int para_num_dat_stride_last_1   ,
int para_len_dat_stride_last_1   ,
int para_num_dat_stride_norm_2   ,
int para_len_dat_stride_norm_2   ,
int para_num_dat_stride_last_2   ,
int para_len_dat_stride_last_2   ,
int para_num_dat_stride_norm_3   ,
int para_len_dat_stride_norm_3   ,
int para_num_dat_stride_last_3   ,
int para_len_dat_stride_last_3   ,
int para_num_dat_stride_norm_4   ,
int para_len_dat_stride_norm_4   ,
int para_num_dat_stride_last_4   ,
int para_len_dat_stride_last_4   ,
int para_num_dat_stride_norm_5   ,
int para_len_dat_stride_norm_5   ,
int para_num_dat_stride_last_5   ,
int para_len_dat_stride_last_5   ,
int para_num_dat_stride_norm_6   ,
int para_len_dat_stride_norm_6   ,
int para_num_dat_stride_last_6   ,
int para_len_dat_stride_last_6   ,
int para_num_dat_stride_norm_7   ,
int para_len_dat_stride_norm_7   ,
int para_num_dat_stride_last_7   ,
int para_len_dat_stride_last_7   ,
int para_num_dat_stride_norm_8   ,
int para_len_dat_stride_norm_8   ,
int para_num_dat_stride_last_8   ,
int para_len_dat_stride_last_8   ,
int para_num_dat_stride_norm_9   ,
int para_len_dat_stride_norm_9   ,
int para_num_dat_stride_last_9   ,
int para_len_dat_stride_last_9   ,
int para_tile_num_x_c             ,
int para_tile_num_y_c             ,
int para_tile_num_wt_output_kernel,
int para_num_stride_output_kernel ,
int para_num_wt_tile              ,
int para_computation_type         ,
int para_num_input_folding        ,
int para_kernel_size_y            ,
int para_kernel_size_x            ,
//constant 
int c2cmac_dat_width              ,
int c2cmac_wt_width               ,
//return depth
int *c2cmac_wt_depth               ,
int *c2cmac_dat_depth              ,
int *sc2cbuf_wt_req_depth          ,
int *sc2cbuf_dat_req_depth                       
){


int num_dat_tile          ;
int cnt_sum_wt_stride     ;
int cnt_sum_dat           ;
int cnt_round_wt          ;



int sc2cbuf_wt_vld_depth  ;
int sc2cbuf_dat_vld_depth ;

int i;



// tile_dat_type for num_dat_tile	
    switch(para_tile_dat_type){
		case 0 : {
			      num_dat_tile = 1;
                  cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1;
				  break;} 
		case 1 : { num_dat_tile = 2;
			      cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + para_num_dat_stride_norm_2+para_num_dat_stride_last_2;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2; 
			      break;}
		case 2 : { num_dat_tile = 2;
			      cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + para_num_dat_stride_norm_1+para_num_dat_stride_last_2;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2; 
			      break;}
		case 3 : { num_dat_tile = 3;
				  cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + para_num_dat_stride_norm_2+para_num_dat_stride_last_2
				  					+ para_num_dat_stride_norm_3+para_num_dat_stride_last_3
									+ para_num_dat_stride_norm_4+para_num_dat_stride_last_4;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_3 + para_num_dat_stride_last_1*para_len_dat_stride_last_3 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_4 + para_num_dat_stride_last_1*para_len_dat_stride_last_4; 
			      break;}
		case 4 : { num_dat_tile = (2 + para_tile_num_x_c) * 2;
				  cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + (para_num_dat_stride_norm_2+para_num_dat_stride_last_2) * para_tile_num_x_c
				  					+ para_num_dat_stride_norm_3+para_num_dat_stride_last_3
									+ para_num_dat_stride_norm_4+para_num_dat_stride_last_4
				  					+ (para_num_dat_stride_norm_5+para_num_dat_stride_last_5) * para_tile_num_x_c
									+ para_num_dat_stride_norm_6+para_num_dat_stride_last_6;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2) * para_tile_num_x_c 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_3 + para_num_dat_stride_last_1*para_len_dat_stride_last_3 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_4 + para_num_dat_stride_last_1*para_len_dat_stride_last_4 	
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_5 + para_num_dat_stride_last_1*para_len_dat_stride_last_5) * para_tile_num_x_c 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_6 + para_num_dat_stride_last_1*para_len_dat_stride_last_6; 	
			      break;}
		case 5 : { num_dat_tile = (2 + para_tile_num_y_c) * 2; 
				  cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + para_num_dat_stride_norm_2+para_num_dat_stride_last_2
				  					+ (para_num_dat_stride_norm_3+para_num_dat_stride_last_3) * para_tile_num_y_c
									+ (para_num_dat_stride_norm_4+para_num_dat_stride_last_4) * para_tile_num_y_c
				  					+ para_num_dat_stride_norm_5+para_num_dat_stride_last_5
									+ para_num_dat_stride_norm_6+para_num_dat_stride_last_6;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2 
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_3 + para_num_dat_stride_last_1*para_len_dat_stride_last_3) * para_tile_num_y_c 
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_4 + para_num_dat_stride_last_1*para_len_dat_stride_last_4) * para_tile_num_y_c 	
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_5 + para_num_dat_stride_last_1*para_len_dat_stride_last_5
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_6 + para_num_dat_stride_last_1*para_len_dat_stride_last_6; 
			      break;}
		case 6 : { num_dat_tile = (2 + para_tile_num_x_c) * (2 + para_tile_num_y_c);  
				  cnt_sum_wt_stride = para_num_dat_stride_norm_1+para_num_dat_stride_last_1 
					                + (para_num_dat_stride_norm_2+para_num_dat_stride_last_2) * para_tile_num_x_c
				  					+ para_num_dat_stride_norm_3+para_num_dat_stride_last_3
									+ (para_num_dat_stride_norm_4+para_num_dat_stride_last_4) * para_tile_num_y_c
				  					+ (para_num_dat_stride_norm_5+para_num_dat_stride_last_5) * para_tile_num_x_c * para_tile_num_y_c 
				  					+ (para_num_dat_stride_norm_6+para_num_dat_stride_last_6) * para_tile_num_y_c 
									+ para_num_dat_stride_norm_7+para_num_dat_stride_last_7
				  					+ (para_num_dat_stride_norm_8+para_num_dat_stride_last_8)  * para_tile_num_x_c
									+ para_num_dat_stride_norm_9+para_num_dat_stride_last_9;
                  cnt_sum_dat = para_num_dat_stride_norm_1*para_len_dat_stride_norm_1 + para_num_dat_stride_last_1*para_len_dat_stride_last_1
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_2 + para_num_dat_stride_last_1*para_len_dat_stride_last_2) * para_tile_num_x_c 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_3 + para_num_dat_stride_last_1*para_len_dat_stride_last_3
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_4 + para_num_dat_stride_last_1*para_len_dat_stride_last_4 ) * para_tile_num_y_c	
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_5 + para_num_dat_stride_last_1*para_len_dat_stride_last_5) * para_tile_num_x_c * para_tile_num_y_c 
					          + (para_num_dat_stride_norm_1*para_len_dat_stride_norm_6 + para_num_dat_stride_last_1*para_len_dat_stride_last_6) * para_tile_num_y_c 
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_7 + para_num_dat_stride_last_1*para_len_dat_stride_last_7 	
					          +(para_num_dat_stride_norm_1*para_len_dat_stride_norm_8 + para_num_dat_stride_last_1*para_len_dat_stride_last_8)  * para_tile_num_x_c
					          + para_num_dat_stride_norm_1*para_len_dat_stride_norm_9 + para_num_dat_stride_last_1*para_len_dat_stride_last_9; 
			      break;}
		default: { num_dat_tile = 1;  
			      break;}
	}
    
	if(para_tile_num_wt_output_kernel%para_num_stride_output_kernel==0){
		cnt_round_wt = (para_tile_num_wt_output_kernel/para_num_stride_output_kernel)*para_num_wt_tile;
	}
	else{
        cnt_round_wt = (para_tile_num_wt_output_kernel/para_num_stride_output_kernel+1)*para_num_wt_tile;
	}

switch(para_computation_type){ 
case 0 : 
	{ 
    *c2cmac_wt_depth = cnt_sum_wt_stride*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;
    *sc2cbuf_wt_req_depth = cnt_sum_wt_stride*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;
    *c2cmac_dat_depth = cnt_sum_dat*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile;
    *sc2cbuf_dat_req_depth = cnt_sum_dat*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile;
    break;
	}
case 1 :
	{ 
    *c2cmac_wt_depth = para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;
    *sc2cbuf_wt_req_depth = para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile; 
    *c2cmac_dat_depth = para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile; 
    *sc2cbuf_dat_req_depth = para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile; 
	break;
	}
case 2:
	{
    *c2cmac_wt_depth = para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;   
    *sc2cbuf_wt_req_depth = para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;
    *c2cmac_dat_depth = para_len_dat_stride_last_1*cnt_round_wt*para_num_wt_tile*num_dat_tile;
    *sc2cbuf_dat_req_depth = para_len_dat_stride_last_1*cnt_round_wt*para_num_wt_tile*num_dat_tile; 
	break;
	}
default:
	{ 
    *c2cmac_wt_depth = cnt_sum_wt_stride*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile; 
    *sc2cbuf_wt_req_depth = cnt_sum_wt_stride*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*para_tile_num_wt_output_kernel*para_num_wt_tile*num_dat_tile;
    *c2cmac_dat_depth = cnt_sum_dat*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile;
    *sc2cbuf_dat_req_depth = cnt_sum_dat*para_kernel_size_x*para_kernel_size_y*para_num_input_folding*cnt_round_wt*para_num_wt_tile*num_dat_tile;
	break;
	}
}

return 1;
}