#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//-----------------------------------------  conv_cal --------------------------------------------------------//
int conv_cal(
// inner var
int cnt_tile_num_wt_output_kernel,
int cnt_cbuf_dat_address,
int cnt_cbuf_wt_address,
int padding_t,
int padding_b,
int padding_l,
int padding_r,
int padding_x,
int padding_y,
//dla paramter
int feature_x,
int feature_y,
int kernel_size_y,
int kernel_size_x,
int kernel_stride_y,
int kernel_stride_x,
int dilated_x,
int dilated_y,
int num_dat_stride_norm,
int len_dat_stride_norm,
int num_dat_stride_last,
int len_dat_stride_last,
int num_input_folding,
int num_stride_output_kernel,
int num_engine,
//input data
int **cbuf ,
int *cnt_sc2cbuf_dat_req   ,
int *cnt_sc2cbuf_wt_req    ,
int *cnt_c2cmac_dat        ,
int *cnt_c2cmac_wt         ,
//output data
int *sc2cbuf_dat_vld,
int *sc2cbuf_dat_req,
int *sc2cbuf_wt_vld,
int *sc2cbuf_wt_req,
int	*c2cmac_dat_vld,
int **c2cmac_dat,
int	*c2cmac_wt_vld,
int **c2cmac_wt
){


int incr_addr_wt                 ;
int incr_addr_dat                ;
int i                            ;
int j                            ;
int cnt_feature_x                ;
int cnt_feature_y                ;
int tmp[1024]                    ;
int feature_point                ;
int cnt_kernel_size_y            ;
int cnt_kernel_size_x            ;
int cnt_num_input_folding        ;
int cnt_len_dat_stride_norm      ;
int cnt_num_dat_stride_norm      ;
int cnt_len_dat_stride_last      ;
int cnt_num_dat_stride_last      ;
int flag_engine =0               ;





while(1){
	if(cnt_tile_num_wt_output_kernel == 0){
		break;
	}
	else{
// normal stide 		
	    for(cnt_num_dat_stride_norm=0; cnt_num_dat_stride_norm<num_dat_stride_norm; cnt_num_dat_stride_norm++ ){
			for(cnt_kernel_size_y=0; cnt_kernel_size_y<kernel_size_y; cnt_kernel_size_y++){
				for(cnt_kernel_size_x=0; cnt_kernel_size_x<kernel_size_x; cnt_kernel_size_x++){
					for(cnt_num_input_folding=0; cnt_num_input_folding<num_input_folding; cnt_num_input_folding++){
                        //----- feature begin -----// 
					    //feature from cbuf to cmac
						   for(cnt_len_dat_stride_norm=0; cnt_len_dat_stride_norm<len_dat_stride_norm; cnt_len_dat_stride_norm++){
							   feature_point = cnt_len_dat_stride_norm + cnt_num_dat_stride_norm * len_dat_stride_norm;
							   cnt_feature_y = feature_point * kernel_stride_y/feature_x;
							   cnt_feature_x = feature_point * kernel_stride_x%feature_x;
							   if((cnt_feature_y - padding_t + cnt_kernel_size_y*dilated_y)<0 || (cnt_feature_y  - padding_b + cnt_kernel_size_y *dilated_y)>(feature_y-1) ){
                                   for(i=0;i<1024;i++){
								       c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								   }
								   (*cnt_c2cmac_dat)++;
								   continue;
							   }
                               else if( (cnt_feature_x - padding_l+cnt_kernel_size_x*dilated_x)<0 || (cnt_feature_x - padding_r + cnt_kernel_size_x *dilated_x)>(feature_x-1) ){
                                        for(i=0;i<1024;i++){
								            c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								        }
								        (*cnt_c2cmac_dat)++;
								        continue;
							   }
                                    else if(padding_x!=0 || padding_y!=0){
                                             if( ((cnt_feature_y - padding_t + cnt_kernel_size_y*dilated_y)%padding_y)!=0 || (cnt_feature_x - padding_l + cnt_kernel_size_x*dilated_x)%padding_x!=0){
                                                 for(i=0;i<1024;i++){
								                     c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								                 }
								                 (*cnt_c2cmac_dat)++;
								                 continue;
											 }
                                             else{
                                                  incr_addr_dat = ((cnt_feature_y*dilated_y-padding_t+cnt_kernel_size_y)*feature_x*num_input_folding / padding_y
                                                                    + (cnt_feature_x*dilated_x-padding_l+cnt_kernel_size_x)*num_input_folding / padding_x
                                                                    + cnt_num_input_folding) / num_engine ;
											      sc2cbuf_dat_req[*cnt_c2cmac_dat] = cnt_cbuf_dat_address + incr_addr_dat;
												  for(i=0;i<1024;i++){
                                                      tmp[i] = cbuf[cnt_cbuf_dat_address + incr_addr_dat][i];
												  }
																											 
												 
											 }																									
									}
                                        else{
                                               incr_addr_dat = ((cnt_feature_y*dilated_y-padding_t+cnt_feature_y)*feature_x*num_input_folding
                                               + (cnt_feature_x*dilated_x-padding_l+cnt_feature_x)*num_input_folding
                                               + cnt_num_input_folding) / num_engine;
											   sc2cbuf_dat_req[*cnt_c2cmac_dat] = cnt_cbuf_dat_address + incr_addr_dat;					
											   for(i=0;i<1024;i++){
                                                   tmp[i] = cbuf[cnt_cbuf_dat_address + incr_addr_dat][i];
											   }											   	
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
                        //----- feature end   -----// 

                      


						
                        //----- weight begin -----// 						   
						//weight from cbuf to cmac
                           if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
                               for(i=0;i<cnt_tile_num_wt_output_kernel;i++){
                                   incr_addr_wt = num_input_folding * kernel_size_x * kernel_size_y * i
                                                + num_input_folding*(kernel_size_x*cnt_kernel_size_y + cnt_kernel_size_x)
                                                + cnt_num_input_folding;   
								   sc2cbuf_wt_req[*cnt_c2cmac_wt] = cnt_cbuf_wt_address+incr_addr_wt;
								   for(j=0;j<1024;j++){
                                       c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
								   }
								   (*cnt_c2cmac_wt)++;
                               } 
						   }
                           else{
                               for(i=0;i<num_stride_output_kernel;i++){
                                   incr_addr_wt = num_input_folding * kernel_size_x * kernel_size_y * i
                                                + num_input_folding*(kernel_size_x*cnt_kernel_size_y + cnt_kernel_size_x)
                                                + cnt_num_input_folding;    
								   sc2cbuf_wt_req[*cnt_c2cmac_wt] = cnt_cbuf_wt_address+incr_addr_wt;
								   for(j=0;j<1024;j++){
                                       c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
								   }
								   (*cnt_c2cmac_wt)++;
                               } 								   
						   }

				    	//----- weight end -----//
					
					}
				}
			}
		}		

// last stide 		
        for(cnt_num_dat_stride_last=0; cnt_num_dat_stride_last<num_dat_stride_last; cnt_num_dat_stride_last++ ){
			for(cnt_kernel_size_y=0; cnt_kernel_size_y<kernel_size_y; cnt_kernel_size_y++){
				for(cnt_kernel_size_x=0; cnt_kernel_size_x<kernel_size_x; cnt_kernel_size_x++){
					for(cnt_num_input_folding=0; cnt_num_input_folding<num_input_folding; cnt_num_input_folding++){
                        //----- feature begin -----// 
					    //feature from cbuf to cmac
						   for(cnt_len_dat_stride_last=0; cnt_len_dat_stride_last<len_dat_stride_last; cnt_len_dat_stride_last++){
							   feature_point = cnt_len_dat_stride_last + num_dat_stride_norm * len_dat_stride_norm;
							   cnt_feature_y = feature_point * kernel_stride_y/feature_x;
							   cnt_feature_x = feature_point * kernel_stride_x%feature_x;
							   if((cnt_feature_y - -padding_t + cnt_kernel_size_y*dilated_y) <0 || (cnt_feature_y - padding_b + cnt_kernel_size_y *dilated_y)> (feature_y-1) ){
                                   for(i=0;i<1024;i++){
								       c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								   }
								   (*cnt_c2cmac_dat)++;
								   continue;
							   }
                               else if( (cnt_feature_x - padding_l + cnt_kernel_size_x*dilated_x) <0 || (cnt_feature_x - padding_r + cnt_kernel_size_x *dilated_x)> (feature_x-1) ){
                                       for(i=0;i<1024;i++){
								           c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								       }
								       (*cnt_c2cmac_dat)++;
								       continue;
							   }
                                    else if(padding_x!=0 || padding_y!=0){
                                             if( ((cnt_feature_y - padding_t + cnt_kernel_size_y*dilated_y)%padding_y)!=0 || ((cnt_feature_x - padding_l + cnt_kernel_size_x*dilated_x)%padding_x)!=0){
                                                 for(i=0;i<1024;i++){
								                     c2cmac_dat[*cnt_c2cmac_dat][i] = 0;
								                 }
								                 (*cnt_c2cmac_dat)++;
								                 continue;
											 }
                                             else{
                                                  incr_addr_dat = ((cnt_feature_y*dilated_y-padding_t+cnt_feature_y)*feature_x*num_input_folding / padding_y
                                                                    + (cnt_feature_x*dilated_x-padding_l+cnt_feature_x)*num_input_folding / padding_x
                                                                    + cnt_num_input_folding) / num_engine ;
												  sc2cbuf_dat_req[*cnt_c2cmac_dat] = cnt_cbuf_dat_address + incr_addr_dat;
												  for(i=0;i<1024;i++){
                                                      tmp[i] = cbuf[cnt_cbuf_dat_address + incr_addr_dat][i];	
												  }											 												 
											 }									
										
										
									}
                                        else{
                                               incr_addr_dat = ((cnt_feature_y*dilated_y-padding_t+cnt_feature_y)*feature_x*num_input_folding
                                               + (cnt_feature_x*dilated_x-padding_l+cnt_feature_x)*num_input_folding
                                               + cnt_num_input_folding) / num_engine;
											   sc2cbuf_dat_req[*cnt_c2cmac_dat] = cnt_cbuf_dat_address + incr_addr_dat;
											   for(i=0;i<1024;i++){
												   tmp[i] = cbuf[cnt_cbuf_dat_address + incr_addr_dat][i];
											   }
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
                        //----- feature end   -----// 




						
                        //----- weight begin -----// 						   
						//weight from cbuf to cmac
                           if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
                               for(i=0;i<cnt_tile_num_wt_output_kernel;i++){
                                   incr_addr_wt = num_input_folding * kernel_size_x * kernel_size_y * i
                                                + num_input_folding*(kernel_size_x*cnt_kernel_size_y + cnt_kernel_size_x)
                                                + cnt_num_input_folding;     
								   sc2cbuf_wt_req[*cnt_c2cmac_wt] = cnt_cbuf_wt_address+incr_addr_wt;
								   for(j=0;j<1024;j++){
                                       c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
								   }
								   (*cnt_c2cmac_wt)++;
	                                printf("%d\n",num_stride_output_kernel);
                               } 

						   }
                           else{
                               for(i=0;i<num_stride_output_kernel;i++){
                                   incr_addr_wt = num_input_folding * kernel_size_x * kernel_size_y * i
                                                + num_input_folding*(kernel_size_x*cnt_kernel_size_y + cnt_kernel_size_x)
                                                + cnt_num_input_folding;    
								   sc2cbuf_wt_req[*cnt_c2cmac_wt] = cnt_cbuf_wt_address+incr_addr_wt;
								   for(j=0;j<1024;j++){
                                       c2cmac_wt[*cnt_c2cmac_wt][j] = cbuf[cnt_cbuf_wt_address+incr_addr_wt][j]; 
								   }
								   (*cnt_c2cmac_wt)++;
                               } 
				   
						   }
				    	//----- weight end -----//
					
					}
				}
			}

		}		
		if(cnt_tile_num_wt_output_kernel < num_stride_output_kernel){
            cnt_tile_num_wt_output_kernel = 0;
		}
		else{
            cnt_tile_num_wt_output_kernel = cnt_tile_num_wt_output_kernel - num_stride_output_kernel;
		}
		
		}			
		incr_addr_wt = num_input_folding * kernel_size_x * kernel_size_y * num_stride_output_kernel;
		cnt_cbuf_wt_address = cnt_cbuf_wt_address + incr_addr_wt;					
	}
	
	i = 0;
	
	
	return 1;
}