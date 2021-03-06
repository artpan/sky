
int tile_feature_size_padding_init(
                           int tile_dat_type,
						   int tile_size_x_1,
						   int tile_size_y_1,
						   int tile_size_x_2,
						   int tile_size_y_2,
						   int tile_size_x_3,
						   int tile_size_y_3,
						   int tile_size_x_4,
						   int tile_size_y_4,
						   int tile_size_x_5,
						   int tile_size_y_5,
						   int tile_size_x_6,
						   int tile_size_y_6,
						   int tile_size_x_7,
						   int tile_size_y_7,
						   int tile_size_x_8,
						   int tile_size_y_8,
						   int tile_size_x_9,
						   int tile_size_y_9,
						   int tile_num_x_c,
						   int tile_num_y_c,
						   int padding_t,
						   int padding_b,
						   int padding_l,
						   int padding_r,
                           int len_dat_stride_norm_1     ,
                           int num_dat_stride_norm_1     ,
                           int len_dat_stride_last_1     ,
                           int num_dat_stride_last_1     ,
                           int len_dat_stride_norm_2     ,
                           int num_dat_stride_norm_2     ,
                           int len_dat_stride_last_2     ,
                           int num_dat_stride_last_2     ,
                           int len_dat_stride_norm_3     ,
                           int num_dat_stride_norm_3     ,
                           int len_dat_stride_last_3     ,
                           int num_dat_stride_last_3     ,
                           int len_dat_stride_norm_4     ,
                           int num_dat_stride_norm_4     ,
                           int len_dat_stride_last_4     ,
                           int num_dat_stride_last_4     ,
                           int len_dat_stride_norm_5     ,
                           int num_dat_stride_norm_5     ,
                           int len_dat_stride_last_5     ,
                           int num_dat_stride_last_5     ,
                           int len_dat_stride_norm_6     ,
                           int num_dat_stride_norm_6     ,
                           int len_dat_stride_last_6     ,
                           int num_dat_stride_last_6     ,
                           int len_dat_stride_norm_7     ,
                           int num_dat_stride_norm_7     ,
                           int len_dat_stride_last_7     ,
                           int num_dat_stride_last_7     ,
                           int len_dat_stride_norm_8     ,
                           int num_dat_stride_norm_8     ,
                           int len_dat_stride_last_8     ,
                           int num_dat_stride_last_8     ,	
                           int len_dat_stride_norm_9     ,
                           int num_dat_stride_norm_9     ,
                           int len_dat_stride_last_9     ,
                           int num_dat_stride_last_9     ,						   						   
                           int *cnt_num_dat_tile         ,
                           int *feature_x                ,
                           int *feature_y                ,
						   int dilated_x                 ,
						   int dilated_y                 ,
 						   int *tile_padding_t           ,
						   int *tile_padding_b           ,
						   int *tile_padding_l           ,
						   int *tile_padding_r           ,  
                           int *len_dat_stride_norm      ,
                           int *num_dat_stride_norm      ,
                           int *len_dat_stride_last      ,
                           int *num_dat_stride_last      							   
						   );
						   
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
);						   
						   
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
int *c2cmac_wt_vld,
int **c2cmac_wt
);				

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
);

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
);