int cdma_func(
//  config register
	int f_pingpong                ,
    int cbuf_dat0_address         ,
    int cbuf_dat1_address         ,
    int cbuf_wt0_address          ,
    int cbuf_wt1_address          ,
	int ddr_dat_address           ,
	int ddr_wt_address            ,
	int ddr_wt_size_norm          ,	
    int ddr_wt_size_last          ,	
	int num_wt_tile               ,
	int num_adding_zero_input_channel_cdma ,
	int tile_dat_type             ,
    int tile_size_x_1_no_extend   ,
    int tile_size_y_1_no_extend   ,
    int tile_size_x_2_no_extend   ,
    int tile_size_y_2_no_extend   ,	
    int tile_size_x_3_no_extend   ,
    int tile_size_y_3_no_extend	  ,
    int tile_size_x_4_no_extend   ,
    int tile_size_y_4_no_extend	  ,
    int tile_size_x_5_no_extend   ,
    int tile_size_y_5_no_extend	  ,
    int tile_size_x_6_no_extend   ,
    int tile_size_y_6_no_extend   ,	
    int tile_size_x_7_no_extend   ,
    int tile_size_y_7_no_extend   ,	
    int tile_size_x_8_no_extend   ,
    int tile_size_y_8_no_extend   ,	
    int tile_size_x_9_no_extend   ,
    int tile_size_y_9_no_extend   ,		
    int tile_num_x_c              ,
    int tile_num_y_c              ,	
    int ddr_size_input_channel    ,	
	
	int extend_dat_type_1_num_1_r,
	int extend_dat_type_1_num_2_l,
	
	int extend_dat_type_2_num_1_b,
	int extend_dat_type_2_num_2_t,	
	
	int extend_dat_type_3_num_1_b,
	int extend_dat_type_3_num_1_r,			
	int extend_dat_type_3_num_2_b,
	int extend_dat_type_3_num_2_l,	
	int extend_dat_type_3_num_3_t,
	int extend_dat_type_3_num_3_r,	
	int extend_dat_type_3_num_4_t,
	int extend_dat_type_3_num_4_l,	
	
	int extend_dat_type_4_num_1_b,
	int extend_dat_type_4_num_1_r,			
	int extend_dat_type_4_num_2_b,
	int extend_dat_type_4_num_2_l,	
	int extend_dat_type_4_num_2_r,
	int extend_dat_type_4_num_3_b,	
	int extend_dat_type_4_num_3_l,
	int extend_dat_type_4_num_4_t,		
	int extend_dat_type_4_num_4_r,
	int extend_dat_type_4_num_5_t,			
	int extend_dat_type_4_num_5_l,
	int extend_dat_type_4_num_5_r,	
	int extend_dat_type_4_num_6_t,
	int extend_dat_type_4_num_6_l,	

	int extend_dat_type_5_num_1_b,
	int extend_dat_type_5_num_1_r,			
	int extend_dat_type_5_num_2_b,
	int extend_dat_type_5_num_2_l,	
	int extend_dat_type_5_num_3_t,
	int extend_dat_type_5_num_3_b,	
	int extend_dat_type_5_num_3_r,
	int extend_dat_type_5_num_4_t,		
	int extend_dat_type_5_num_4_b,
	int extend_dat_type_5_num_4_l,			
	int extend_dat_type_5_num_5_t,
	int extend_dat_type_5_num_5_r,	
	int extend_dat_type_5_num_6_t,
	int extend_dat_type_5_num_6_l,	

	int extend_dat_type_6_num_1_b,
	int extend_dat_type_6_num_1_r,			
	int extend_dat_type_6_num_2_b,
	int extend_dat_type_6_num_2_l,	
	int extend_dat_type_6_num_2_r,
	int extend_dat_type_6_num_3_b,	
	int extend_dat_type_6_num_3_l,
	int extend_dat_type_6_num_4_t,		
	int extend_dat_type_6_num_4_b,
	int extend_dat_type_6_num_4_r,			
	int extend_dat_type_6_num_5_t,
	int extend_dat_type_6_num_5_b,	
	int extend_dat_type_6_num_5_l,
	int extend_dat_type_6_num_5_r,	
	int extend_dat_type_6_num_6_t,
	int extend_dat_type_6_num_6_b,	
	int extend_dat_type_6_num_6_l,
	int extend_dat_type_6_num_7_t,		
	int extend_dat_type_6_num_7_r,
	int extend_dat_type_6_num_8_t,			
	int extend_dat_type_6_num_8_l,
	int extend_dat_type_6_num_8_r,	
	int extend_dat_type_6_num_9_t,
	int extend_dat_type_6_num_9_l,	

    int address_incr_dat_type_0_num_1,	
	int address_incr_dat_type_1_num_1,	
    int address_incr_dat_type_1_num_2,	
	int address_incr_dat_type_2_num_1,	
	int address_incr_dat_type_2_num_2,	
	int address_incr_dat_type_3_num_1,	
	int address_incr_dat_type_3_num_2,	   
	int address_incr_dat_type_3_num_3,	  
	int address_incr_dat_type_3_num_4,
	int address_incr_dat_type_4_num_1,	
	int address_incr_dat_type_4_num_2,	   
	int address_incr_dat_type_4_num_3,	  
	int address_incr_dat_type_4_num_4,
	int address_incr_dat_type_4_num_5,	  
	int address_incr_dat_type_4_num_6,
	int address_incr_dat_type_5_num_1,	
	int address_incr_dat_type_5_num_2,	   
	int address_incr_dat_type_5_num_3,	  
	int address_incr_dat_type_5_num_4,
	int address_incr_dat_type_5_num_5,	  
	int address_incr_dat_type_5_num_6,	
	int address_incr_dat_type_6_num_1,	
	int address_incr_dat_type_6_num_2,	   
	int address_incr_dat_type_6_num_3,	  
	int address_incr_dat_type_6_num_4,
	int address_incr_dat_type_6_num_5,	  
	int address_incr_dat_type_6_num_6,
	int address_incr_dat_type_6_num_7,
	int address_incr_dat_type_6_num_8,	  
	int address_incr_dat_type_6_num_9,
//  loop counter                  
    int *cnt_num_dat_tile          ,
	int *cnt_num_wt_tile           ,
    int *cnt_ddr_wt_address        ,
    int *cnt_ddr_dat_start_address ,	

//  data in
    int **ddr                      ,                
//  data out
    int **cbuf   
	)
{

int num_dat_tile              ;
int all_feature_x             ;
int all_feature_y             ;


int cnt_cbuf_wt_address       ;
int cnt_cbuf_dat_address      ;
int cnt_ddr_dat_address       ;
int cnt_ddr_wt_size           ;
int tmp[128][8]               ;
int extend_t                  ;
int extend_b                  ;
int extend_l                  ;
int extend_r                  ;
int tile_size_x               ;
int tile_size_y               ;
int cnt_address_incr_dat      ;
int len_x                     ;
int len_y                     ;
int i                         ;
int j                         ;
int k                         ;
int l                         ;
int m                         ;
int p                         ;
int q                         ;




switch(tile_dat_type){
case 0: {     
	          num_dat_tile = 1;
              all_feature_x  = tile_size_x_1_no_extend;
              all_feature_y  = tile_size_y_1_no_extend;
			  break;
		}
case 1: {
	          num_dat_tile = 2;
              all_feature_x  = tile_size_x_1_no_extend + tile_size_x_2_no_extend;
              all_feature_y  = tile_size_y_1_no_extend; 
			  break;
		}
case 2: {
	          num_dat_tile = 2;
              all_feature_x  = tile_size_x_1_no_extend;
              all_feature_y  = tile_size_y_1_no_extend + tile_size_y_2_no_extend; 
			  break;
		}
case 3: {
	          num_dat_tile = 4;
              all_feature_x  = tile_size_x_1_no_extend+ tile_size_y_2_no_extend;
              all_feature_y  = tile_size_y_1_no_extend + tile_size_y_2_no_extend; 
			  break;
		}
case 4: {
	          num_dat_tile = (2 + tile_num_x_c) * 2;
              all_feature_x  = tile_size_x_1_no_extend+ tile_size_x_2_no_extend*tile_num_x_c+tile_size_x_3_no_extend;
              all_feature_y  = tile_size_y_1_no_extend+ tile_size_y_4_no_extend; 
			  break;
		} 
case 5: {
	          num_dat_tile = (2 + tile_num_y_c) * 2;
              all_feature_x  = tile_size_x_1_no_extend+ tile_size_x_2_no_extend;
              all_feature_y  = tile_size_y_1_no_extend+ tile_size_y_3_no_extend*tile_num_y_c+tile_size_y_5_no_extend; 
			  break;
		}
case 6: {
              num_dat_tile = (2 + tile_num_x_c) * (2 + tile_num_y_c);
              all_feature_x  =  tile_size_x_1_no_extend+ tile_size_x_2_no_extend*tile_num_x_c+tile_size_x_3_no_extend; 
              all_feature_y  = tile_size_y_1_no_extend+ tile_size_y_4_no_extend*tile_num_y_c+tile_size_y_7_no_extend; 
			  break;
		}
default:{
              num_dat_tile = 1; 
              all_feature_x  = tile_size_x_1_no_extend;
              all_feature_y  = tile_size_y_1_no_extend; break;
		}
}



if(f_pingpong == 1){
/*-------------------------------------------------------------*/
/*                                                             */
/*                feature pingpong first                       */
/*                                                             */
/*-------------------------------------------------------------*/	
	while(1){
	    if(*cnt_num_wt_tile == num_wt_tile){
			return 1;
			break;
		}
		/*-------------------------------*/
		/*       wt pingpong 1 stage     */
		/*-------------------------------*/
        //switch wt address
        if(*cnt_num_wt_tile == 0){
            *cnt_ddr_wt_address  = ddr_wt_address  ;
		}	
		if(*cnt_num_wt_tile%2==0){
			cnt_cbuf_wt_address = cbuf_wt0_address;
		}
		else{
			cnt_cbuf_wt_address = cbuf_wt1_address;
		}
		//switch wt size
		if(*cnt_num_wt_tile == num_wt_tile - 1){
			cnt_ddr_wt_size = ddr_wt_size_last;
		}
		else{
			cnt_ddr_wt_size = ddr_wt_size_norm;
		}			
		//transfer weight from ddr to cbuf
		k=0;			
		for(i=0;i<cnt_ddr_wt_size;i++){
            for(j=0;j<8;j++){
                tmp[k][j]=ddr[*cnt_ddr_wt_address][j];
            }
            if(k==127){
               k=0;
               for(p=0;p<128;p++){
                   for(q=0;q<8;q++){
                      cbuf[cnt_cbuf_wt_address][q+p*8]=tmp[p][q];
                   }
               } 
               cnt_cbuf_wt_address++;  
            }
            else{
                k++;
            }
            (*cnt_ddr_wt_address)++;
        }			
		/*----------------------------------*/
		/*       dat pingpong 2 stage       */
		/*----------------------------------*/	
		while(1){
			// when dat tile ends, wt tile ++
	        if(*cnt_num_dat_tile == num_dat_tile){
				(*cnt_num_wt_tile)++;
				*cnt_num_dat_tile=0;				
		    	break;
		    }
            if(*cnt_num_dat_tile == 0){
                *cnt_ddr_dat_start_address = ddr_dat_address ;				
		    }			
            //switch dat address				
			if(*cnt_num_dat_tile%2==0){
				cnt_cbuf_dat_address = cbuf_dat0_address;
			}
			else{
				cnt_cbuf_dat_address = cbuf_dat1_address;
			}
			//prepare extra feature loading, prepare start ddr address 		
			switch(tile_dat_type){
				case 0:
				{
					extend_t = 0;
                    extend_b = 0;
                    extend_l = 0;
                    extend_r = 0;
					tile_size_x = tile_size_x_1_no_extend; 
					tile_size_y = tile_size_y_1_no_extend; 						
					cnt_address_incr_dat = address_incr_dat_type_0_num_1;
					break;
				}
				case 1:
				{
					if(*cnt_num_dat_tile==0)
					{
                         extend_t = 0;
                         extend_b = 0;
                         extend_l = 0;
                         extend_r = extend_dat_type_1_num_1_r;
						 tile_size_x = tile_size_x_1_no_extend; 
					     tile_size_y = tile_size_y_1_no_extend; 
                         cnt_address_incr_dat = address_incr_dat_type_1_num_1;
					}
                    else
					{
                         extend_t = 0;
                         extend_b = 0;
                         extend_l = extend_dat_type_1_num_2_l;
                         extend_r = 0;
						 tile_size_x = tile_size_x_2_no_extend; 
					     tile_size_y = tile_size_y_2_no_extend; 							 
                         cnt_address_incr_dat = address_incr_dat_type_1_num_2;
					}
					break;
					
				}
				case 2:
				{
					if(*cnt_num_dat_tile==0)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_2_num_1_b;
                        extend_l = 0;
                        extend_r = 0;
						tile_size_x = tile_size_x_1_no_extend; 
					    tile_size_y = tile_size_y_1_no_extend; 							
                        cnt_address_incr_dat = address_incr_dat_type_2_num_1;
					}
                    else{
                        extend_t = extend_dat_type_2_num_2_t;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = 0;
						tile_size_x = tile_size_x_2_no_extend; 
					    tile_size_y = tile_size_y_2_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_2_num_2;
					}
					break;
				}
				case 3:
				{
					switch(*cnt_num_dat_tile)
					{
                        case 0: 
						{
							    extend_t = 0;
                                extend_b = extend_dat_type_3_num_1_b;
                                extend_l = 0;
                                extend_r = extend_dat_type_3_num_1_r;
						        tile_size_x = tile_size_x_1_no_extend; 
					            tile_size_y = tile_size_y_1_no_extend; 										
                                cnt_address_incr_dat = address_incr_dat_type_3_num_1;
								break;
						}
                        case 1: 
						{       
						        extend_t = 0;
                                extend_b = extend_dat_type_3_num_2_b;
                                extend_l = extend_dat_type_3_num_2_l;
                                extend_r = 0;
						        tile_size_x = tile_size_x_2_no_extend; 
					            tile_size_y = tile_size_y_2_no_extend; 										
                                cnt_address_incr_dat = address_incr_dat_type_3_num_2;
								break;
						}
                        case 2: 
						{       
						        extend_t = extend_dat_type_3_num_3_t;
                                extend_b = 0;
                                extend_l = 0;
                                extend_r = extend_dat_type_3_num_3_r;
						        tile_size_x = tile_size_x_3_no_extend; 
					            tile_size_y = tile_size_y_3_no_extend; 										
                                cnt_address_incr_dat = address_incr_dat_type_3_num_3;
								break;
						}
                        case 3: 
						{       
						        extend_t = extend_dat_type_3_num_4_t;
                                extend_b = 0;
                                extend_l = extend_dat_type_3_num_4_l;
                                extend_r = 0;
						        tile_size_x = tile_size_x_4_no_extend; 
					            tile_size_y = tile_size_y_4_no_extend; 										
                                cnt_address_incr_dat = address_incr_dat_type_3_num_4;
								break;
						}									
					}
                    break;						
				}
				case 4:
				{
					if(*cnt_num_dat_tile==0)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_4_num_1_b;
                        extend_l = 0;
                        extend_r = extend_dat_type_4_num_1_r;
						tile_size_x = tile_size_x_1_no_extend; 
					    tile_size_y = tile_size_y_1_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_4_num_1;
					}
                    else if(*cnt_num_dat_tile <tile_num_x_c+1 && *cnt_num_dat_tile >0)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_4_num_2_b;
                        extend_l = extend_dat_type_4_num_2_l;
                        extend_r = extend_dat_type_4_num_2_r;
						tile_size_x = tile_size_x_2_no_extend; 
					    tile_size_y = tile_size_y_2_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_4_num_2;
					}		
                    else if(*cnt_num_dat_tile == tile_num_x_c+1)
					{
                            extend_t = 0;
                            extend_b = extend_dat_type_4_num_3_b;
                            extend_l = extend_dat_type_4_num_3_l;
                            extend_r = 0;
						    tile_size_x = tile_size_x_3_no_extend; 
					        tile_size_y = tile_size_y_3_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_4_num_3;
					}				
                    else if(*cnt_num_dat_tile==tile_num_x_c+2)
					{
                            extend_t = extend_dat_type_4_num_4_t;
                            extend_b = 0;
                            extend_l = 0;
                            extend_r = extend_dat_type_4_num_4_r;
						    tile_size_x = tile_size_x_4_no_extend; 
					        tile_size_y = tile_size_y_4_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_4_num_4;
					}
                    else if(*cnt_num_dat_tile < tile_num_x_c+1+tile_num_x_c+2 && *cnt_num_dat_tile >tile_num_x_c+2)
					{
                            extend_t = extend_dat_type_4_num_5_t;
                            extend_b = 0;
                            extend_l = extend_dat_type_4_num_5_l;
                            extend_r = extend_dat_type_4_num_5_r;
						    tile_size_x = tile_size_x_5_no_extend; 
					        tile_size_y = tile_size_y_5_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_4_num_5;
					}
                    else if(*cnt_num_dat_tile==tile_num_x_c+1+tile_num_x_c+2)
					{
                            extend_t = extend_dat_type_4_num_6_t;
                            extend_b = 0;
                            extend_l = extend_dat_type_4_num_6_l;
                            extend_r = 0;
						    tile_size_x = tile_size_x_6_no_extend; 
					        tile_size_y = tile_size_y_6_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_4_num_6;
					}				
                    else
					{   
					        extend_t = 0;
                            extend_b = 0;
                            extend_l = 0;
                            extend_r = 0;
						    tile_size_x = tile_size_x_1_no_extend; 
					        tile_size_y = tile_size_y_1_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_4_num_1;
					}
                    break;						
		        }
				case 5:
				{
					if(*cnt_num_dat_tile==0)
					{
                            extend_t = 0;
                            extend_b = extend_dat_type_5_num_1_b;
                            extend_l = 0;
                            extend_r = extend_dat_type_5_num_1_r;
						    tile_size_x = tile_size_x_1_no_extend; 
					        tile_size_y = tile_size_y_1_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_1;
					}
                    else if(*cnt_num_dat_tile==1)
					{
                            extend_t = 0;
                            extend_b = extend_dat_type_5_num_2_b;
                            extend_l = extend_dat_type_5_num_2_l;
                            extend_r = 0;
						    tile_size_x = tile_size_x_2_no_extend; 
					        tile_size_y = tile_size_y_2_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_2;
					}		
                    else if( (*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==0 )
					{
                            extend_t = extend_dat_type_5_num_3_t;
                            extend_b = extend_dat_type_5_num_3_b;
                            extend_l = 0;
                            extend_r = extend_dat_type_5_num_3_r;
						    tile_size_x = tile_size_x_3_no_extend; 
					        tile_size_y = tile_size_y_3_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_3;
					}				
                    else if((*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==1)
					{
                            extend_t = extend_dat_type_5_num_4_t;
                            extend_b = extend_dat_type_5_num_4_b;
                            extend_l = extend_dat_type_5_num_4_l;
                            extend_r = 0;
						    tile_size_x = tile_size_x_4_no_extend; 
					        tile_size_y = tile_size_y_4_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_4;
					}
                    else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1) )
					{
                            extend_t = extend_dat_type_5_num_5_t;
                            extend_b = 0;
                            extend_l = 0;
                            extend_r = extend_dat_type_5_num_5_r;
						    tile_size_x = tile_size_x_5_no_extend; 
					        tile_size_y = tile_size_y_5_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_5;
					}
                    else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1)+1 )
					{
                            extend_t = extend_dat_type_5_num_6_t;
                            extend_b = 0;
                            extend_l = extend_dat_type_5_num_6_l;
                            extend_r = 0;
						    tile_size_x = tile_size_x_6_no_extend; 
					        tile_size_y = tile_size_y_6_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_6;
					}	
                    else
					{       
				            extend_t = 0;
                            extend_b = 0;
                            extend_l = 0;
                            extend_r = 0;
						    tile_size_x = tile_size_x_1_no_extend; 
					        tile_size_y = tile_size_y_1_no_extend; 									
                            cnt_address_incr_dat = address_incr_dat_type_5_num_1;
					}
					break;
				}
				case 6:
				{
	                if(*cnt_num_dat_tile=0)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_6_num_1_b;
                        extend_l = 0;
                        extend_r = extend_dat_type_6_num_1_r;
						tile_size_x = tile_size_x_1_no_extend; 
					    tile_size_y = tile_size_y_1_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_1;
					}
                    else if(*cnt_num_dat_tile < tile_num_x_c+1 && *cnt_num_dat_tile >0)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_6_num_2_b;
                        extend_l = extend_dat_type_6_num_2_l;
                        extend_r = extend_dat_type_6_num_2_r;
						tile_size_x = tile_size_x_2_no_extend; 
					    tile_size_y = tile_size_y_2_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_2;
					}
                    else if(*cnt_num_dat_tile==tile_num_x_c+1)
					{
                        extend_t = 0;
                        extend_b = extend_dat_type_6_num_3_b;
                        extend_l = extend_dat_type_6_num_3_l;
                        extend_r = 0;
						tile_size_x = tile_size_x_3_no_extend; 
					    tile_size_y = tile_size_y_3_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_3;
					}
                    else if(*cnt_num_dat_tile==tile_num_x_c+2)
					{
                        extend_t = extend_dat_type_6_num_4_t;
                        extend_b = extend_dat_type_6_num_4_b;
                        extend_l = 0;
                        extend_r = extend_dat_type_6_num_4_r;
						tile_size_x = tile_size_x_4_no_extend; 
					    tile_size_y = tile_size_y_4_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_4;
					}
                    else if(*cnt_num_dat_tile>tile_num_x_c+2 && 
					        *cnt_num_dat_tile<(tile_num_x_c+2)*(tile_num_y_c+1) && 
                            *cnt_num_dat_tile % (tile_num_x_c+2)!=0 && 
                            (*cnt_num_dat_tile-1)%(tile_num_x_c+2)!=0)
					{
                        extend_t = extend_dat_type_6_num_5_t;
                        extend_b = extend_dat_type_6_num_5_b;
                        extend_l = extend_dat_type_6_num_5_l;
                        extend_r = extend_dat_type_6_num_5_r;
						tile_size_x = tile_size_x_5_no_extend; 
					    tile_size_y = tile_size_y_5_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_5;
					}
                    else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1)-1 )
					{
                        extend_t = extend_dat_type_6_num_6_t;
                        extend_b = extend_dat_type_6_num_6_b;
                        extend_l = extend_dat_type_6_num_6_l;
                        extend_r = 0;
						tile_size_x = tile_size_x_6_no_extend; 
					    tile_size_y = tile_size_y_6_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_6;
					}		
                    else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1) )
					{
                        extend_t = extend_dat_type_6_num_7_t;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = extend_dat_type_6_num_7_r;
						tile_size_x = tile_size_x_7_no_extend; 
					    tile_size_y = tile_size_y_7_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_7;
					}	
                    else if(*cnt_num_dat_tile > (tile_num_x_c+2)*(tile_num_y_c+1) && 
                            *cnt_num_dat_tile < (tile_num_x_c+2)*(tile_num_y_c+2)-1)
					{
                        extend_t = extend_dat_type_6_num_8_t;
                        extend_b = 0;
                        extend_l = extend_dat_type_6_num_8_l;
                        extend_r = extend_dat_type_6_num_8_r;
						tile_size_x = tile_size_x_8_no_extend; 
					    tile_size_y = tile_size_y_8_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_8;
					}	
                    else if(*cnt_num_dat_tile = (tile_num_x_c+2)*(tile_num_y_c+2)-1)
					{
                        extend_t = extend_dat_type_6_num_9_t;
                        extend_b = 0;
                        extend_l = extend_dat_type_6_num_9_l;
                        extend_r = 0;
						tile_size_x = tile_size_x_9_no_extend; 
					    tile_size_y = tile_size_y_9_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_9;
					}
                    else
					{
                        extend_t = 0;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = 0;
						tile_size_x = tile_size_x_1_no_extend; 
					    tile_size_y = tile_size_y_1_no_extend; 								
                        cnt_address_incr_dat = address_incr_dat_type_6_num_1;
					}		
                    break;
				}
				default:
				{
					extend_t = 0;
                    extend_b = 0;
                    extend_l = 0;
                    extend_r = 0;
					tile_size_x = tile_size_x_1_no_extend; 
					tile_size_y = tile_size_y_1_no_extend; 							
					cnt_address_incr_dat = address_incr_dat_type_0_num_1;
					break;						
				}
			}
		//transfer data from ddr to cbuf
        cnt_ddr_dat_address = *cnt_ddr_dat_start_address -(extend_l+extend_t*all_feature_y)*ddr_size_input_channel ;
        len_y = extend_t + extend_b + tile_size_y ;
        len_x = extend_l + extend_r + tile_size_x ;

        for(i=0;i<len_y;i++)
		{
            for(j=0;j<len_x ;j++){
                m=0;
                for(k=0;k<ddr_size_input_channel;k++){
                           for(l=0;l<8;l++){
                               tmp[m][l]=ddr[cnt_ddr_dat_address][l];
                           }
                           cnt_ddr_dat_address++;
                           if(m==127){
                               for(p=0;p<128;p++){
                                   for(q=0;q<8;q++){
                                       cbuf[cnt_cbuf_dat_address][q+p*8]=tmp[p][q];
                                   }
                               }
                               cnt_cbuf_dat_address++;
                               m=0;
                           }                  
                           else{
                               m++;
                           }
                }
                for(k=0;k<num_adding_zero_input_channel_cdma;k++){
                           for(l=0;l<8;l++){
                               tmp[m][l]=0;
                               }
                              if(m==127){
                               for(p=0;p<128;p++){
                                   for(q=0;q<8;q++){
                                       cbuf[cnt_cbuf_dat_address][q+p*8]=tmp[p][q];
                                   }
                               }
                               cnt_cbuf_dat_address++;
                               m=0;
                           }                  
                           else{
                               m++;
                           }
                }
                
            }
            cnt_ddr_dat_address = cnt_ddr_dat_address+ddr_size_input_channel *(all_feature_x-len_x);  
        }
		(*cnt_num_dat_tile)++;	
		*cnt_ddr_dat_start_address = cnt_address_incr_dat + *cnt_ddr_dat_start_address;				
		}				           			
	}
}
//       dat pingpong first    end                           //
else{
	while(1){
		/*----------------------------------*/
        /*       dat pingpong 1 stage       */
        /*----------------------------------*/	
        if(*cnt_num_dat_tile == num_dat_tile){
			return 1;
            break;
        }
        if(*cnt_num_dat_tile == 0){
            *cnt_ddr_dat_start_address = ddr_dat_address ;				
		}		
		//switch dat address				
		if(*cnt_num_dat_tile %2==0){
			cnt_cbuf_dat_address = cbuf_dat0_address;
		}
		else{
			cnt_cbuf_dat_address = cbuf_dat1_address;
		}
		//prepare extra feature loading, prepare start ddr address 		
		switch(tile_dat_type){
			case 0:
			{
				extend_t = 0;
                extend_b = 0;
                extend_l = 0;
                extend_r = 0;
				tile_size_x = tile_size_x_1_no_extend; 
				tile_size_y = tile_size_y_1_no_extend; 						
				cnt_address_incr_dat = address_incr_dat_type_0_num_1;
				break;
			}
			case 1:
			{
				if(*cnt_num_dat_tile==0)
				{
                     extend_t = 0;
                     extend_b = 0;
                     extend_l = 0;
                     extend_r = extend_dat_type_1_num_1_r;
					 tile_size_x = tile_size_x_1_no_extend; 
				     tile_size_y = tile_size_y_1_no_extend; 
                     cnt_address_incr_dat = address_incr_dat_type_1_num_1;
				}
                else
				{
                     extend_t = 0;
                     extend_b = 0;
                     extend_l = extend_dat_type_1_num_2_l;
                     extend_r = 0;
					 tile_size_x = tile_size_x_2_no_extend; 
				     tile_size_y = tile_size_y_2_no_extend; 							 
                     cnt_address_incr_dat = address_incr_dat_type_1_num_2;
				}
				break;
				
			}
			case 2:
			{
				if(*cnt_num_dat_tile==0)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_2_num_1_b;
                    extend_l = 0;
                    extend_r = 0;
					tile_size_x = tile_size_x_1_no_extend; 
				    tile_size_y = tile_size_y_1_no_extend; 							
                    cnt_address_incr_dat = address_incr_dat_type_2_num_1;
				}
                else{
                    extend_t = extend_dat_type_2_num_2_t;
                    extend_b = 0;
                    extend_l = 0;
                    extend_r = 0;
					tile_size_x = tile_size_x_2_no_extend; 
				    tile_size_y = tile_size_y_2_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_2_num_2;
				}
				break;
			}
			case 3:
			{
				switch(*cnt_num_dat_tile)
				{
                    case 0: 
					{
						    extend_t = 0;
                            extend_b = extend_dat_type_3_num_1_b;
                            extend_l = 0;
                            extend_r = extend_dat_type_3_num_1_r;
					        tile_size_x = tile_size_x_1_no_extend; 
				            tile_size_y = tile_size_y_1_no_extend; 										
                            cnt_address_incr_dat = address_incr_dat_type_3_num_1;
							break;
					}
                    case 1: 
					{       
					        extend_t = 0;
                            extend_b = extend_dat_type_3_num_2_b;
                            extend_l = extend_dat_type_3_num_2_l;
                            extend_r = 0;
					        tile_size_x = tile_size_x_2_no_extend; 
				            tile_size_y = tile_size_y_2_no_extend; 										
                            cnt_address_incr_dat = address_incr_dat_type_3_num_2;
							break;
					}
                    case 2: 
					{       
					        extend_t = extend_dat_type_3_num_3_t;
                            extend_b = 0;
                            extend_l = 0;
                            extend_r = extend_dat_type_3_num_3_r;
					        tile_size_x = tile_size_x_3_no_extend; 
				            tile_size_y = tile_size_y_3_no_extend; 										
                            cnt_address_incr_dat = address_incr_dat_type_3_num_3;
							break;
					}
                    case 3: 
					{       
					        extend_t = extend_dat_type_3_num_4_t;
                            extend_b = 0;
                            extend_l = extend_dat_type_3_num_4_l;
                            extend_r = 0;
					        tile_size_x = tile_size_x_4_no_extend; 
				            tile_size_y = tile_size_y_4_no_extend; 										
                            cnt_address_incr_dat = address_incr_dat_type_3_num_4;
							break;
					}									
				}
                break;						
			}
			case 4:
			{
				if(*cnt_num_dat_tile==0)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_4_num_1_b;
                    extend_l = 0;
                    extend_r = extend_dat_type_4_num_1_r;
					tile_size_x = tile_size_x_1_no_extend; 
				    tile_size_y = tile_size_y_1_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_4_num_1;
				}
                else if(*cnt_num_dat_tile <tile_num_x_c+1 && *cnt_num_dat_tile >0)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_4_num_2_b;
                    extend_l = extend_dat_type_4_num_2_l;
                    extend_r = extend_dat_type_4_num_2_r;
					tile_size_x = tile_size_x_2_no_extend; 
				    tile_size_y = tile_size_y_2_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_4_num_2;
				}		
                else if(*cnt_num_dat_tile == tile_num_x_c+1)
				{
                        extend_t = 0;
                        extend_b = extend_dat_type_4_num_3_b;
                        extend_l = extend_dat_type_4_num_3_l;
                        extend_r = 0;
					    tile_size_x = tile_size_x_3_no_extend; 
				        tile_size_y = tile_size_y_3_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_4_num_3;
				}				
                else if(*cnt_num_dat_tile == tile_num_x_c+2)
				{
                        extend_t = extend_dat_type_4_num_4_t;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = extend_dat_type_4_num_4_r;
					    tile_size_x = tile_size_x_4_no_extend; 
				        tile_size_y = tile_size_y_4_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_4_num_4;
				}
                else if(*cnt_num_dat_tile < tile_num_x_c+1+tile_num_x_c+2 && *cnt_num_dat_tile >tile_num_x_c+2)
				{
                        extend_t = extend_dat_type_4_num_5_t;
                        extend_b = 0;
                        extend_l = extend_dat_type_4_num_5_l;
                        extend_r = extend_dat_type_4_num_5_r;
					    tile_size_x = tile_size_x_5_no_extend; 
				        tile_size_y = tile_size_y_5_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_4_num_5;
				}
                else if(*cnt_num_dat_tile == tile_num_x_c+1+tile_num_x_c+2)
				{
                        extend_t = extend_dat_type_4_num_6_t;
                        extend_b = 0;
                        extend_l = extend_dat_type_4_num_6_l;
                        extend_r = 0;
					    tile_size_x = tile_size_x_6_no_extend; 
				        tile_size_y = tile_size_y_6_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_4_num_6;
				}				
                else
				{   
				        extend_t = 0;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = 0;
					    tile_size_x = tile_size_x_1_no_extend; 
				        tile_size_y = tile_size_y_1_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_4_num_1;
				}
                break;						
		    }
			case 5:
			{
				if(*cnt_num_dat_tile == 0)
				{
                        extend_t = 0;
                        extend_b = extend_dat_type_5_num_1_b;
                        extend_l = 0;
                        extend_r = extend_dat_type_5_num_1_r;
					    tile_size_x = tile_size_x_1_no_extend; 
				        tile_size_y = tile_size_y_1_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_1;
				}
                else if(*cnt_num_dat_tile == 1)
				{
                        extend_t = 0;
                        extend_b = extend_dat_type_5_num_2_b;
                        extend_l = extend_dat_type_5_num_2_l;
                        extend_r = 0;
					    tile_size_x = tile_size_x_2_no_extend; 
				        tile_size_y = tile_size_y_2_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_2;
				}		
                else if( (*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==0 )
				{
                        extend_t = extend_dat_type_5_num_3_t;
                        extend_b = extend_dat_type_5_num_3_b;
                        extend_l = 0;
                        extend_r = extend_dat_type_5_num_3_r;
					    tile_size_x = tile_size_x_3_no_extend; 
				        tile_size_y = tile_size_y_3_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_3;
				}				
                else if((*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==1)
				{
                        extend_t = extend_dat_type_5_num_4_t;
                        extend_b = extend_dat_type_5_num_4_b;
                        extend_l = extend_dat_type_5_num_4_l;
                        extend_r = 0;
					    tile_size_x = tile_size_x_4_no_extend; 
				        tile_size_y = tile_size_y_4_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_4;
				}
                else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1) )
				{
                        extend_t = extend_dat_type_5_num_5_t;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = extend_dat_type_5_num_5_r;
					    tile_size_x = tile_size_x_5_no_extend; 
				        tile_size_y = tile_size_y_5_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_5;
				}
                else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1)+1 )
				{
                        extend_t = extend_dat_type_5_num_6_t;
                        extend_b = 0;
                        extend_l = extend_dat_type_5_num_6_l;
                        extend_r = 0;
					    tile_size_x = tile_size_x_6_no_extend; 
				        tile_size_y = tile_size_y_6_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_6;
				}	
                else
				{       
			            extend_t = 0;
                        extend_b = 0;
                        extend_l = 0;
                        extend_r = 0;
					    tile_size_x = tile_size_x_1_no_extend; 
				        tile_size_y = tile_size_y_1_no_extend; 									
                        cnt_address_incr_dat = address_incr_dat_type_5_num_1;
				}
				break;
			}
			case 6:
			{
	            if(*cnt_num_dat_tile=0)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_6_num_1_b;
                    extend_l = 0;
                    extend_r = extend_dat_type_6_num_1_r;
					tile_size_x = tile_size_x_1_no_extend; 
				    tile_size_y = tile_size_y_1_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_1;
				}
                else if(*cnt_num_dat_tile < tile_num_x_c+1 && *cnt_num_dat_tile >0)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_6_num_2_b;
                    extend_l = extend_dat_type_6_num_2_l;
                    extend_r = extend_dat_type_6_num_2_r;
					tile_size_x = tile_size_x_2_no_extend; 
				    tile_size_y = tile_size_y_2_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_2;
				}
                else if(*cnt_num_dat_tile==tile_num_x_c+1)
				{
                    extend_t = 0;
                    extend_b = extend_dat_type_6_num_3_b;
                    extend_l = extend_dat_type_6_num_3_l;
                    extend_r = 0;
					tile_size_x = tile_size_x_3_no_extend; 
				    tile_size_y = tile_size_y_3_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_3;
				}
                else if(*cnt_num_dat_tile==tile_num_x_c+2)
				{
                    extend_t = extend_dat_type_6_num_4_t;
                    extend_b = extend_dat_type_6_num_4_b;
                    extend_l = 0;
                    extend_r = extend_dat_type_6_num_4_r;
					tile_size_x = tile_size_x_4_no_extend; 
				    tile_size_y = tile_size_y_4_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_4;
				}
                else if(*cnt_num_dat_tile>tile_num_x_c+2 && 
				        *cnt_num_dat_tile<(tile_num_x_c+2)*(tile_num_y_c+1) && 
                        *cnt_num_dat_tile%(tile_num_x_c+2)!=0 && 
                        (*cnt_num_dat_tile-1)%(tile_num_x_c+2)!=0)
				{
                    extend_t = extend_dat_type_6_num_5_t;
                    extend_b = extend_dat_type_6_num_5_b;
                    extend_l = extend_dat_type_6_num_5_l;
                    extend_r = extend_dat_type_6_num_5_r;
					tile_size_x = tile_size_x_5_no_extend; 
				    tile_size_y = tile_size_y_5_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_5;
				}
                else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1)-1 )
				{
                    extend_t = extend_dat_type_6_num_6_t;
                    extend_b = extend_dat_type_6_num_6_b;
                    extend_l = extend_dat_type_6_num_6_l;
                    extend_r = 0;
					tile_size_x = tile_size_x_6_no_extend; 
				    tile_size_y = tile_size_y_6_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_6;
				}		
                else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1) )
				{
                    extend_t = extend_dat_type_6_num_7_t;
                    extend_b = 0;
                    extend_l = 0;
                    extend_r = extend_dat_type_6_num_7_r;
					tile_size_x = tile_size_x_7_no_extend; 
				    tile_size_y = tile_size_y_7_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_7;
				}	
                else if(*cnt_num_dat_tile > (tile_num_x_c+2)*(tile_num_y_c+1) && 
                        *cnt_num_dat_tile < (tile_num_x_c+2)*(tile_num_y_c+2)-1)
				{
                    extend_t = extend_dat_type_6_num_8_t;
                    extend_b = 0;
                    extend_l = extend_dat_type_6_num_8_l;
                    extend_r = extend_dat_type_6_num_8_r;
					tile_size_x = tile_size_x_8_no_extend; 
				    tile_size_y = tile_size_y_8_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_8;
				}	
                else if(*cnt_num_dat_tile = (tile_num_x_c+2)*(tile_num_y_c+2)-1)
				{
                    extend_t = extend_dat_type_6_num_9_t;
                    extend_b = 0;
                    extend_l = extend_dat_type_6_num_9_l;
                    extend_r = 0;
					tile_size_x = tile_size_x_9_no_extend; 
				    tile_size_y = tile_size_y_9_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_9;
				}
                else
				{
                    extend_t = 0;
                    extend_b = 0;
                    extend_l = 0;
                    extend_r = 0;
					tile_size_x = tile_size_x_1_no_extend; 
				    tile_size_y = tile_size_y_1_no_extend; 								
                    cnt_address_incr_dat = address_incr_dat_type_6_num_1;
				}		
                break;
			}
			default:
			{
				extend_t = 0;
                extend_b = 0;
                extend_l = 0;
                extend_r = 0;
				tile_size_x = tile_size_x_1_no_extend; 
				tile_size_y = tile_size_y_1_no_extend; 							
				cnt_address_incr_dat = address_incr_dat_type_0_num_1;
				break;						
			}
		}
		//transfer data from ddr to cbuf
        cnt_ddr_dat_address = *cnt_ddr_dat_start_address -(extend_l+extend_t*all_feature_y)*ddr_size_input_channel ;
        len_y = extend_t + extend_b + tile_size_y ;
        len_x = extend_l + extend_r + tile_size_x ;

        for(i=0;i<len_y;i++)
		{
            for(j=0;j<len_x ;j++){
                m=0;
                for(k=0;k<ddr_size_input_channel;k++){
                           for(l=0;l<8;l++){
                               tmp[m][l]=ddr[cnt_ddr_dat_address][l];
                           }
                           cnt_ddr_dat_address++;
                           if(m==127){
                               for(p=0;p<128;p++){
                                   for(q=0;q<8;q++){
                                       cbuf[cnt_cbuf_dat_address][q+p*8]=tmp[p][q];
                                   }
                               }
                               m=0;
                               cnt_cbuf_dat_address++;
                           }                  
                           else{
                               m++;
                           }
                }
                for(k=0;k<num_adding_zero_input_channel_cdma;k++){
                           for(l=0;l<8;l++){
                               tmp[m][l]=0;
                               }
                              if(m==127){
                               for(p=0;p<128;p++){
                                   for(q=0;q<8;q++){
                                       cbuf[cnt_cbuf_dat_address][q+p*8]=tmp[p][q];
                                   }
                               }
                               cnt_cbuf_dat_address++;
                               m=0;
                           }                  
                           else{
                               m++;
                           }
                }
                
            }
            cnt_ddr_dat_address = cnt_ddr_dat_address+ddr_size_input_channel *(all_feature_x-len_x);  
        }
		(*cnt_num_dat_tile)++;	
		*cnt_ddr_dat_start_address = cnt_address_incr_dat + *cnt_ddr_dat_start_address;				

		
		while(1){
            if(*cnt_num_wt_tile == num_wt_tile){
			   *cnt_num_wt_tile = 0;
                break;
            }
            if(*cnt_num_wt_tile == 0){
                *cnt_ddr_wt_address  = ddr_wt_address  ;
		    }				
		    /*-------------------------------*/
		    /*       wt pingpong 2 stage     */
		    /*-------------------------------*/
            //switch wt address			
		    if(*cnt_num_wt_tile % 2==0){
		    	cnt_cbuf_wt_address = cbuf_wt0_address;
		    }
		    else{
		    	cnt_cbuf_wt_address = cbuf_wt1_address;
		    }
		    //switch wt size
		    if(*cnt_num_wt_tile == num_wt_tile - 1){
		    	cnt_ddr_wt_size = ddr_wt_size_last;
		    }
		    else{
		    	cnt_ddr_wt_size = ddr_wt_size_norm;
		    }			
		    //transfer weight from ddr to cbuf
		    k=0;			
		    for(i=0;i<cnt_ddr_wt_size;i++){
                for(j=0;j<8;j++){
                    tmp[k][j]=ddr[*cnt_ddr_wt_address][j];
                }
                if(k==127){
                   k=0;
                   for(p=0;p<128;p++){
                       for(q=0;q<8;q++){
                          cbuf[cnt_cbuf_wt_address][q+p*8]=tmp[p][q];
                       }
                   } 
                   cnt_cbuf_wt_address++;  
                }
                else{
                    k++;
                }
                (*cnt_ddr_wt_address)++;
            }
			(*cnt_num_wt_tile)++;
			}	
		}			
	}	
}






