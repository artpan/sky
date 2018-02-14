#include "../header/csc_func.h"
int csc_func(
//  config register
 	int len_dat_stride_norm_1        ,
    int num_dat_stride_norm_1        ,
    int len_dat_stride_last_1        ,
    int num_dat_stride_last_1        ,
	int len_dat_stride_norm_2        ,
    int num_dat_stride_norm_2        ,
    int len_dat_stride_last_2        ,
    int num_dat_stride_last_2        ,
	int len_dat_stride_norm_3        ,
    int num_dat_stride_norm_3        ,
    int len_dat_stride_last_3        ,
    int num_dat_stride_last_3        ,
	int len_dat_stride_norm_4        ,
    int num_dat_stride_norm_4        ,
    int len_dat_stride_last_4        ,
    int num_dat_stride_last_4        ,
	int len_dat_stride_norm_5        ,
    int num_dat_stride_norm_5        ,
    int len_dat_stride_last_5        ,
    int num_dat_stride_last_5        ,
	int len_dat_stride_norm_6        ,
    int num_dat_stride_norm_6        ,
    int len_dat_stride_last_6        ,
    int num_dat_stride_last_6        ,
	int len_dat_stride_norm_7        ,
    int num_dat_stride_norm_7        ,
    int len_dat_stride_last_7        ,
    int num_dat_stride_last_7        ,
	int len_dat_stride_norm_8        ,
    int num_dat_stride_norm_8        ,
    int len_dat_stride_last_8        ,
    int num_dat_stride_last_8        ,
	int len_dat_stride_norm_9        ,
    int num_dat_stride_norm_9        ,
    int len_dat_stride_last_9        ,
    int num_dat_stride_last_9        ,
    int index_enable                 ,
    int index_width                  ,
    int f_pingpong                   ,
//	int feature_size_x	             ,
//	int feature_size_y	             ,
	int kernel_size_x	             ,
	int kernel_size_y	             ,
	int kernel_stride_x	             ,
	int kernel_stride_y	             ,
	int padding_t	                 ,
	int padding_b	                 ,
	int padding_l	                 ,
	int padding_r	                 ,
	int padding_x	                 ,
	int padding_y	                 ,
	int dilated_x	                 ,
	int dilated_y	                 ,
	int input_channel	             ,
	int output_channel	             ,
	int computation_type	         ,
	int num_engine	                 ,
	int cbuf_dat0_address	         ,
	int cbuf_dat1_address	         ,
	int cbuf_wt0_address	         ,
	int cbuf_wt1_address	         ,
	int tile_dat_type	             ,
	int num_wt_tile	                 ,
	int compute_data_precision	     ,
	int compute_weight_precision	 ,											
  	int tile_num_wt_output_kernel	 ,
	int num_stride_output_kernel	 ,
	int num_input_folding	         ,
	int tile_size_x_1	             ,
	int tile_size_y_1	             ,
	int tile_size_x_2	             ,
	int tile_size_y_2	             ,
	int tile_size_x_3	             ,
	int tile_size_y_3	             ,
	int tile_size_x_4	             ,
	int tile_size_y_4	             ,
	int tile_size_x_5	             ,
	int tile_size_y_5	             ,
	int tile_size_x_6	             ,
	int tile_size_y_6	             ,
	int tile_size_x_7	             ,
	int tile_size_y_7	             ,
	int tile_size_x_8	             ,
	int tile_size_y_8	             ,
	int tile_size_x_9	             ,
	int tile_size_y_9	             ,
	int tile_num_x_c	             ,
	int tile_num_y_c	             ,
//  loop counter                  ,
    int *cnt_num_dat_tile          ,
	int *cnt_num_wt_tile           ,
	int *flag_cbuf_pingpong_dat    ,
	int *flag_cbuf_pingpong_wt     ,
//  data in
    //int cbuf2csc_wt_ready       ,
    //int cbuf2csc_dat_ready      ,
    int **cbuf                    ,
//  data out
    int *sc2cbuf_wt_req           ,
	int *sc2cbuf_wt_vld           ,
    int *sc2cbuf_dat_req          ,
	int *sc2cbuf_dat_vld          ,
	//int c2cmac_req                ,
    int **c2cmac_wt                ,
	int *c2cmac_wt_vld             ,
    int **c2cmac_dat               ,
    int *c2cmac_dat_vld
	)
	
{
// inital some counter 	
//    int flag_cbuf_pingpong_dat        = 0;
//    int flag_cbuf_pingpong_wt         = 0;
    int cnt_cbuf_wt_address           = cbuf_wt0_address;	
	int cnt_cbuf_dat_address          = cbuf_dat0_address;	
//	int cnt_num_wt_tile               = 0;
//	int cnt_num_dat_tile              = 0;
	int cnt_tile_num_wt_output_kernel = tile_num_wt_output_kernel;
    int num_dat_tile            ;
//    int cnt_input_kernel_num  ;
    int process_end             ;

    int tile_padding_t                  ;
    int tile_padding_b                  ;
    int tile_padding_l                  ;
    int tile_padding_r                  ;
    int feature_x                       ;
    int feature_y                       ;
    int len_dat_stride_norm             ;
    int len_dat_stride_last             ;
    int num_dat_stride_norm             ;
    int num_dat_stride_last             ;

    int i                               ;
    int cnt_c2cmac_wt              =0   ;
    int cnt_c2cmac_dat             =0   ;
    int cnt_sc2cbuf_dat_req        =0   ;
	int cnt_sc2cbuf_wt_req         =0   ;








	
// tile_dat_type for num_dat_tile	
    switch(tile_dat_type){
		case 0 : { num_dat_tile = 1;  break;}
		case 1 : { num_dat_tile = 2;  break;}
		case 2 : { num_dat_tile = 2;  break;}
		case 3 : { num_dat_tile = 4;  break;}
		case 4 : { num_dat_tile = (2 + tile_num_x_c) * 2;  break;}
		case 5 : { num_dat_tile = (2 + tile_num_y_c) * 2;  break;}
		case 6 : { num_dat_tile = (2 + tile_num_x_c) * (2 + tile_num_y_c);  break;}
		default: { num_dat_tile = 1;  break;}
	}

	
////	input kernel num under different precision
//	if(compute_data_precision <= 4)
//		cnt_input_kernel_num = cbuf_width/compute_data_precision;
//	else
//		cnt_input_kernel_num = 512;
	
	


    while(1){
 tile_feature_size_padding_init(
                               tile_dat_type             ,
	    					   tile_size_x_1             ,
	    					   tile_size_y_1             ,
	    					   tile_size_x_2             ,
	    					   tile_size_y_2             ,
	    					   tile_size_x_3             ,
	    					   tile_size_y_3             ,
	    					   tile_size_x_4             ,
	    					   tile_size_y_4             ,
	    					   tile_size_x_5             ,
	    					   tile_size_y_5             ,
	    					   tile_size_x_6             ,
	    					   tile_size_y_6             ,
	    					   tile_size_x_7             ,
	    					   tile_size_y_7             ,
	    					   tile_size_x_8             ,
	    					   tile_size_y_8             ,
	    					   tile_size_x_9             ,
	    					   tile_size_y_9             ,
							   tile_num_x_c              ,
							   tile_num_y_c              ,
	    					   padding_t                 ,
	    					   padding_b                 ,
	    					   padding_l                 ,
	    					   padding_r                 ,
                               len_dat_stride_norm_1     ,
                               num_dat_stride_norm_1     ,
                               len_dat_stride_last_1     ,
                               num_dat_stride_last_1     ,
                               len_dat_stride_norm_2     ,
                               num_dat_stride_norm_2     ,
                               len_dat_stride_last_2     ,
                               num_dat_stride_last_2     ,
                               len_dat_stride_norm_3     ,
                               num_dat_stride_norm_3     ,
                               len_dat_stride_last_3     ,
                               num_dat_stride_last_3     ,
                               len_dat_stride_norm_4     ,
                               num_dat_stride_norm_4     ,
                               len_dat_stride_last_4     ,
                               num_dat_stride_last_4     ,
                               len_dat_stride_norm_5     ,
                               num_dat_stride_norm_5     ,
                               len_dat_stride_last_5     ,
                               num_dat_stride_last_5     ,
                               len_dat_stride_norm_6     ,
                               num_dat_stride_norm_6     ,
                               len_dat_stride_last_6     ,
                               num_dat_stride_last_6     ,
                               len_dat_stride_norm_7     ,
                               num_dat_stride_norm_7     ,
                               len_dat_stride_last_7     ,
                               num_dat_stride_last_7     ,
                               len_dat_stride_norm_8     ,
                               num_dat_stride_norm_8     ,
                               len_dat_stride_last_8     ,
                               num_dat_stride_last_8     ,	
                               len_dat_stride_norm_9     ,
                               num_dat_stride_norm_9     ,
                               len_dat_stride_last_9     ,
                               num_dat_stride_last_9     ,								   
                               cnt_num_dat_tile          ,
                               &feature_x                ,
                               &feature_y                ,
						       padding_x                 ,
						       padding_y                 ,
 	    					   &tile_padding_t           ,
	    					   &tile_padding_b           ,
	    					   &tile_padding_l           ,
	    					   &tile_padding_r           ,  
                               &len_dat_stride_norm      ,
                               &num_dat_stride_norm      ,
                               &len_dat_stride_last      ,
                               &num_dat_stride_last      							   
	    					   );


 switch(computation_type){
            case 0 : 
	        {
	        	conv_cal(
                // inner var
                cnt_tile_num_wt_output_kernel,
                cnt_cbuf_dat_address,
                cnt_cbuf_wt_address,
                tile_padding_t,
                tile_padding_b,
                tile_padding_l,
                tile_padding_r,
                padding_x,
                padding_y,
                //dla paramter
                feature_x,
                feature_y,				
                kernel_size_y,
                kernel_size_x,
                kernel_stride_y,
                kernel_stride_x,
                dilated_x,
                dilated_y,
                num_dat_stride_norm,
                len_dat_stride_norm,
                num_dat_stride_last,
                len_dat_stride_last,
				num_input_folding,
                num_stride_output_kernel,
                num_engine,
                //input data				
                cbuf,
				&cnt_sc2cbuf_dat_req,
				&cnt_sc2cbuf_wt_req ,
				&cnt_c2cmac_dat     ,
			    &cnt_c2cmac_wt      ,
                //output data
				sc2cbuf_dat_vld,
                sc2cbuf_dat_req,
				sc2cbuf_wt_vld,
                sc2cbuf_wt_req,
				c2cmac_dat_vld,
                c2cmac_dat,
				c2cmac_wt_vld,
                c2cmac_wt
                );
				break;
	        }
            case 1 : 
	        {
                fc_cal(
                // inner var
                cnt_tile_num_wt_output_kernel,
                tile_num_wt_output_kernel,
                cnt_cbuf_dat_address,
                cnt_cbuf_wt_address,
                //dla parameter
                num_stride_output_kernel,
                num_engine,
                num_input_folding,
                //input data
                cbuf ,
                &cnt_sc2cbuf_dat_req   ,
                &cnt_sc2cbuf_wt_req    ,
                &cnt_c2cmac_dat        ,
                &cnt_c2cmac_wt         ,
                //output data
                sc2cbuf_dat_req,
                sc2cbuf_wt_req,
                c2cmac_dat_vld,
                c2cmac_dat,
                c2cmac_wt_vld,
                c2cmac_wt
                );
	        }
            case 2 : 
	        {
                image_input_cal(
                // inner var
                cnt_tile_num_wt_output_kernel,
                cnt_cbuf_dat_address,
                cnt_cbuf_wt_address,
                //dla parameter
                num_stride_output_kernel,
                num_input_folding,
                len_dat_stride_last,
                tile_num_wt_output_kernel,
                //input data
                cbuf,
                &cnt_sc2cbuf_dat_req   ,
                &cnt_sc2cbuf_wt_req    ,
                &cnt_c2cmac_dat        ,
                &cnt_c2cmac_wt         ,
                //output data
                sc2cbuf_dat_req,
                sc2cbuf_wt_req,
                c2cmac_dat_vld,
                c2cmac_dat,
                c2cmac_wt_vld,
                c2cmac_wt
                );


            //    image_input_cal(
            //    // inner var
            //    cnt_tile_num_wt_output_kernel,
            //    cnt_cbuf_dat_address,
            //    cnt_cbuf_wt_address,
            //    //dla parameter
            //    num_stride_output_kernel,
            //    num_input_folding,
            //    //input data
            //    &cbuf,
            //    //output data
            //    &sc2cbuf_dat_req,
            //    &sc2cbuf_wt_req,
            //    &&c2cmac_dat,
            //    &&c2cmac_wt
            //    );
	        }
            default :
	        {	
	        //	conv_cal(
            //    // inner var
            //    cnt_tile_num_wt_output_kernel,
            //    cnt_cbuf_dat_address,
            //    cnt_cbuf_wt_address,
            //    padding_t,
            //    padding_b,
            //    padding_l,
            //    padding_r,
            //    padding_x,
            //    padding_y,
            //    //dla paramter
            //    kernel_size_y,
            //    kernel_size_x,
            //    kernel_stride_y,
            //    kernel_stride_x,
            //    dilated_x,
            //    dilated_y,
            //    num_dat_stripe_norm,
            //    len_dat_stride_norm,
            //    num_dat_stripe_last,
            //    len_dat_stride_last,
            //    num_stride_output_kernel,
            //    num_engine,
            //    //input data
            //    &cbuf,
            //    //output data
            //    &sc2cbuf_dat_req,
            //    &sc2cbuf_wt_req,
            //    &&c2cmac_dat,
            //    &&c2cmac_wt
            //    );
	        }		
	    }
	
		    process_end = tile_countdown(
                           f_pingpong,
                           cbuf_dat0_address,	
                           cbuf_dat1_address,
                           cbuf_wt0_address,
                           cbuf_wt1_address,	
                           num_dat_tile,	
                           num_wt_tile,
                           cnt_num_dat_tile,
                           cnt_num_wt_tile,
                           &cnt_cbuf_dat_address,
                           &cnt_cbuf_wt_address,
                           flag_cbuf_pingpong_dat,	
                           flag_cbuf_pingpong_wt
                           );
		

		   if(process_end==1){
		        break;			
		   } 

        


       }

    
		
		
		
		
	return 1;
}
