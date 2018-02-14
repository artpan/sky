//-----------------------------------------  conv_cal --------------------------------------------------------//
int image_input_cal(
// inner var
int cnt_tile_num_wt_output_kernel,
int cnt_cbuf_dat_address,
int cnt_cbuf_wt_address,
//dla parameter
int num_stride_output_kernel,
int num_input_folding,
int len_dat_stride_last,
int tile_num_wt_output_kernel,
//input data
int **cbuf,
int *cnt_sc2cbuf_dat_req   ,
int *cnt_sc2cbuf_wt_req    ,
int *cnt_c2cmac_dat        ,
int *cnt_c2cmac_wt         ,
//output data
int *sc2cbuf_dat_req,
int *sc2cbuf_wt_req,
int *c2cmac_dat_vld,
int **c2cmac_dat,
int *c2cmac_wt_vld,
int **c2cmac_wt
){


int incr_addr_wt            ;
int incr_addr_dat           ;
int i                       ;
int j                       ;
int tmp[1024]               ;
int cnt_len_dat_stride_last ;

while(1){
	if(cnt_tile_num_wt_output_kernel == 0){
		break;
	}
	else{
// weight read 
        if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
            for(i=0;i<cnt_tile_num_wt_output_kernel;i++){
              incr_addr_wt = (tile_num_wt_output_kernel-cnt_tile_num_wt_output_kernel)  +  i ; 
			  sc2cbuf_wt_req[*cnt_sc2cbuf_wt_req] = cnt_cbuf_wt_address+incr_addr_wt;
			  for(j=0;j<1024;j++){
                  c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j];
			  }
			  (*cnt_c2cmac_wt)++;
            }			
		}
 
        else{
            for(i=0;i<num_stride_output_kernel;i++){
              incr_addr_wt = (tile_num_wt_output_kernel - cnt_tile_num_wt_output_kernel)  +  i;
			  sc2cbuf_wt_req[*cnt_sc2cbuf_wt_req] = cnt_cbuf_wt_address+incr_addr_wt;
			  for(j=0;j<1024;j++){
                  c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j];
			  }
			  (*cnt_c2cmac_wt)++;
            }
		}			
// feature read
        for(cnt_len_dat_stride_last = 0; cnt_len_dat_stride_last<len_dat_stride_last; cnt_len_dat_stride_last ++){
			incr_addr_dat = cnt_len_dat_stride_last; 
			sc2cbuf_dat_req[*cnt_sc2cbuf_dat_req] = cnt_cbuf_dat_address+incr_addr_dat;
			for(j=0;j<1024;j++){
                c2cmac_dat[*cnt_c2cmac_dat][j] = cbuf[cnt_cbuf_dat_address+incr_addr_dat][j];
			}
			(*cnt_c2cmac_dat)++;
		}			
//---------------
        if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
            cnt_tile_num_wt_output_kernel = 0;			
		}
        else{
            cnt_tile_num_wt_output_kernel = cnt_tile_num_wt_output_kernel - num_stride_output_kernel;			
		}
			
	    }		
		
	}
	
	
	return 1;
}