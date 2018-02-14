//-----------------------------------------  conv_cal --------------------------------------------------------//
int fc_cal(
// inner var
int cnt_tile_num_wt_output_kernel,
int tile_num_wt_output_kernel,
int cnt_cbuf_dat_address,
int cnt_cbuf_wt_address,
//dla parameter
int num_stride_output_kernel,
int num_engine,
int num_input_folding,
//input data
int **cbuf ,
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
int cnt_num_input_folding =0;
int flag_engine =0          ;

while(1){
	if(cnt_tile_num_wt_output_kernel == 0){
		break;
	}
	else{
// normal stide 		
	    for(cnt_num_input_folding=0; cnt_num_input_folding<num_input_folding; cnt_num_input_folding++ ){
// weight read 
            if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
                for(i=0;i<cnt_tile_num_wt_output_kernel;i++){
                     incr_addr_wt = num_input_folding * (tile_num_wt_output_kernel - cnt_tile_num_wt_output_kernel)
                                  + num_input_folding * i
                                  + cnt_num_input_folding;   
					 sc2cbuf_wt_req[*cnt_sc2cbuf_wt_req] = cnt_cbuf_wt_address+incr_addr_wt;
					 for(j=0;j<1024;j++){
                         c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
					 }
					 (*cnt_c2cmac_wt)++;
				}
            } 
            else{
                for(i=0;i<num_stride_output_kernel;i++){
                      incr_addr_wt = num_input_folding * (tile_num_wt_output_kernel - cnt_tile_num_wt_output_kernel)
                                   + num_input_folding * i
                                   + cnt_num_input_folding;   
					  sc2cbuf_wt_req[*cnt_sc2cbuf_wt_req] = cnt_cbuf_wt_address+incr_addr_wt;									   
					  for(j=0;j<1024;j++){
                          c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
					  }
					  (*cnt_c2cmac_wt)++; 
				}
            } 							

// feature read
            incr_addr_dat = (cnt_num_input_folding) / num_engine;
		    sc2cbuf_dat_req[*cnt_sc2cbuf_dat_req] = cnt_cbuf_dat_address + incr_addr_dat;
			for(j=0;j<1024;j++){
                tmp[j] = cbuf[cnt_cbuf_dat_address + incr_addr_dat][j];
			}
            switch(num_engine){
			    case 1 : 
			    {
			    	     for(i=0;i<1024;i++){
			    	         c2cmac_dat[*cnt_c2cmac_dat][i] = tmp[i];
			    		 }
			    		 break;
			    }
			    case 2 :  
			    {
			    	     for(i=flag_engine*512; i<(flag_engine+1)*512; i++){
			    			 for(j=0;j<2;j++){
			    				 c2cmac_dat[*cnt_c2cmac_dat][(j-flag_engine)*512+i] = tmp[i];
			    			 }
			    		 }
                         if(flag_engine==2-1){
			    			 flag_engine = 0;
			    		 }
			    		 else{
			    			 flag_engine = flag_engine + 1;
			    		 }
			    		 break;
			    }
			    case 4 :  
			    {
			    	     for(i=flag_engine*256; i<(flag_engine+1)*256; i++){
			    			 for(j=0;j<4;j++){
			    				 c2cmac_dat[*cnt_c2cmac_dat][(j-flag_engine)*256+i] = tmp[i];
			    			 }
			    		 }
                         if(flag_engine==4-1){
			    			 flag_engine = 0;
			    		 }
			    		 else{
			    			 flag_engine = flag_engine + 1;
			    		 }
			    		 break;
			    }
			    case 8 : 
			    {
			    	     for(i=flag_engine*128; i<(flag_engine+1)*128; i++){
			    			 for(j=0;j<8;j++){
			    				 c2cmac_dat[*cnt_c2cmac_dat][(j-flag_engine)*128+i] = tmp[i];
			    			 }
			    		 }
                         if(flag_engine==8-1){
			    			 flag_engine = 0;
			    		 }
			    		 else{
			    			 flag_engine = flag_engine + 1;
			    		 }
			    		 break;
			    }									
			    default:  
				{
						for(i=0;i<1024;i++){
						     c2cmac_dat[*cnt_c2cmac_dat][i] = tmp[i];
						}
						break;
					}																										
				}            
            (*cnt_c2cmac_dat)++;		
	        }

            if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
               cnt_tile_num_wt_output_kernel = 0 ;				
			}
            else{
               cnt_tile_num_wt_output_kernel = cnt_tile_num_wt_output_kernel - num_stride_output_kernel	;			
			}		
	}

}

	return 1;
}