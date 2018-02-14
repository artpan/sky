//-----------------------------------------  tile_feature_size_padding_init --------------------------------------------------------//

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
                           int *cnt_num_dat_tile          ,
                           int *feature_x                ,
                           int *feature_y                ,
						   int padding_x                 ,
						   int padding_y                 ,
 						   int *tile_padding_t           ,
						   int *tile_padding_b           ,
						   int *tile_padding_l           ,
						   int *tile_padding_r           ,						   
                           int *len_dat_stride_norm      ,
                           int *num_dat_stride_norm      ,
                           int *len_dat_stride_last      ,
                           int *num_dat_stride_last      							   
						   ){

switch (tile_dat_type){
		case 0 :  
		{
			      *feature_x           = tile_size_x_1;
		          *feature_y           = tile_size_y_1;
                  *len_dat_stride_norm = len_dat_stride_norm_1;
                  *num_dat_stride_norm = num_dat_stride_norm_1;
                  *len_dat_stride_last = len_dat_stride_last_1;
                  *num_dat_stride_last = num_dat_stride_last_1;
				  *tile_padding_t      = padding_t;
				  *tile_padding_b      = padding_b;				  
			      *tile_padding_r      = padding_r;			  
				  *tile_padding_l      = padding_l;
				  break;
		}
		case 1 :  
		{
			      if(*cnt_num_dat_tile==0){
			          *feature_x           = tile_size_x_1;  
				      *feature_y           = tile_size_y_1;
                      *len_dat_stride_norm = len_dat_stride_norm_1;
                      *num_dat_stride_norm = num_dat_stride_norm_1;
                      *len_dat_stride_last = len_dat_stride_last_1;
                      *num_dat_stride_last = num_dat_stride_last_1;					  
				      *tile_padding_t      = padding_t;
				      *tile_padding_b      = padding_b;
				      *tile_padding_r      = padding_x;				  
				      *tile_padding_l      = padding_l;	
				      break;
				  }
				  else{
			          *feature_x           = tile_size_x_2;  
				      *feature_y           = tile_size_y_2;
                      *len_dat_stride_norm = len_dat_stride_norm_2;
                      *num_dat_stride_norm = num_dat_stride_norm_2;
                      *len_dat_stride_last = len_dat_stride_last_2;
                      *num_dat_stride_last = num_dat_stride_last_2;					  
				      *tile_padding_t      = padding_t;
				      *tile_padding_b      = padding_b;				  
			          *tile_padding_r      = padding_r;
				      *tile_padding_l      = 0;						  
				      break;
				  }		
		}				  
		case 2 :  
		{
			      if(*cnt_num_dat_tile==0){
			          *feature_x           = tile_size_x_1;  
				      *feature_y           = tile_size_y_1;
                      *len_dat_stride_norm = len_dat_stride_norm_1;
                      *num_dat_stride_norm = num_dat_stride_norm_1;
                      *len_dat_stride_last = len_dat_stride_last_1;
                      *num_dat_stride_last = num_dat_stride_last_1;					  
					  *tile_padding_t      = padding_t;	
				      *tile_padding_b      = padding_y;						  
			          *tile_padding_r      = padding_r;			  
				      *tile_padding_l      = padding_l;	
				      break;
		          }
				  else{
			          *feature_x           = tile_size_x_2;  
				      *feature_y           = tile_size_y_2;
                      *len_dat_stride_norm = len_dat_stride_norm_2;
                      *num_dat_stride_norm = num_dat_stride_norm_2;
                      *len_dat_stride_last = len_dat_stride_last_2;
                      *num_dat_stride_last = num_dat_stride_last_2;	
					  *tile_padding_t      = 0;						  
				      *tile_padding_b      = padding_b;				  
			          *tile_padding_r      = padding_r;			  
				      *tile_padding_l      = padding_l;	
				      break;
				  }
		}
		case 3 :  
		{
			      switch(*cnt_num_dat_tile){
					  case 0 : 
					  {
						  *feature_x           = tile_size_x_1;
						  *feature_y           = tile_size_y_1;
                          *len_dat_stride_norm = len_dat_stride_norm_1;
                          *num_dat_stride_norm = num_dat_stride_norm_1;
                          *len_dat_stride_last = len_dat_stride_last_1;
                          *num_dat_stride_last = num_dat_stride_last_1;						  
				          *tile_padding_t      = padding_t;	
					      *tile_padding_b      = padding_y;		
					      *tile_padding_r      = padding_x;							  
				          *tile_padding_l      = padding_l;							  
				          break;
					  }	
					  case 1 : 
					  {
						  *feature_x           = tile_size_x_2;
						  *feature_y           = tile_size_y_2;
                          *len_dat_stride_norm = len_dat_stride_norm_2;
                          *num_dat_stride_norm = num_dat_stride_norm_2;
                          *len_dat_stride_last = len_dat_stride_last_2;
                          *num_dat_stride_last = num_dat_stride_last_2;						  
				          *tile_padding_t      = padding_t;	
					      *tile_padding_b      = padding_y;							  
			              *tile_padding_r      = padding_r;
						  *tile_padding_l      = 0;	
				          break;
					  }	
					  case 2 : 
					  {
						  *feature_x           = tile_size_x_3;
						  *feature_y           = tile_size_y_3;
                          *len_dat_stride_norm = len_dat_stride_norm_3;
                          *num_dat_stride_norm = num_dat_stride_norm_3;
                          *len_dat_stride_last = len_dat_stride_last_3;
                          *num_dat_stride_last = num_dat_stride_last_3;		
						  *tile_padding_t      = 0;							  
				          *tile_padding_b      = padding_b;	
						  *tile_padding_r      = padding_x;				  			  
				          *tile_padding_l      = padding_l;	
				          break;
					  }	
					  case 3 : 
					  {
						  *feature_x           = tile_size_x_4;
						  *feature_y           = tile_size_y_4;
                          *len_dat_stride_norm = len_dat_stride_norm_4;
                          *num_dat_stride_norm = num_dat_stride_norm_4;
                          *len_dat_stride_last = len_dat_stride_last_4;
                          *num_dat_stride_last = num_dat_stride_last_4;	
						  *tile_padding_t      = 0;							  
				          *tile_padding_b      = padding_b;				  
			              *tile_padding_r      = padding_r;	
						  *tile_padding_l      = 0;							  
				          break;
					  }
                      default:{
						  *feature_x           = tile_size_x_1;
						  *feature_y           = tile_size_y_1;
                          *len_dat_stride_norm = len_dat_stride_norm_1;
                          *num_dat_stride_norm = num_dat_stride_norm_1;
                          *len_dat_stride_last = len_dat_stride_last_1;
                          *num_dat_stride_last = num_dat_stride_last_1;						  
				          *tile_padding_t      = padding_t;
				          *tile_padding_b      = padding_b;				  
			              *tile_padding_r      = padding_r;			  
				          *tile_padding_l      = padding_l;
				          break;
					  }						  
				  }					  
		}
		case 4 :
		{
			      if(*cnt_num_dat_tile==0){
                      *feature_x           = tile_size_x_1;
                      *feature_y           = tile_size_y_1;
                      *len_dat_stride_norm = len_dat_stride_norm_1;
                      *num_dat_stride_norm = num_dat_stride_norm_1;
                      *len_dat_stride_last = len_dat_stride_last_1;
                      *num_dat_stride_last = num_dat_stride_last_1;					  
				      *tile_padding_t      = padding_t;
					  *tile_padding_b      = padding_y;						  
				      *tile_padding_l      = 0;						  
			          *tile_padding_r      = padding_r;
				      break;
				  }
                  else if(*cnt_num_dat_tile < tile_num_x_c+1 && *cnt_num_dat_tile >0){
					       *feature_x           = tile_size_x_2;
                           *feature_y           = tile_size_y_2;
	                       *len_dat_stride_norm = len_dat_stride_norm_2;
                           *num_dat_stride_norm = num_dat_stride_norm_2;
                           *len_dat_stride_last = len_dat_stride_last_2;
                           *num_dat_stride_last = num_dat_stride_last_2;					   
				           *tile_padding_t      = padding_t;
						   *tile_padding_b      = padding_y;	
						   *tile_padding_r      = padding_x;	
						   *tile_padding_l      = 0;							  
						   break;
				  }		
                       else if(*cnt_num_dat_tile==tile_num_x_c+1){
					            *feature_x           = tile_size_x_3;
                                *feature_y           = tile_size_y_3;
                                *len_dat_stride_norm = len_dat_stride_norm_3;
                                *num_dat_stride_norm = num_dat_stride_norm_3;
                                *len_dat_stride_last = len_dat_stride_last_3;
                                *num_dat_stride_last = num_dat_stride_last_3;								
				                *tile_padding_t      = padding_t;
						        *tile_padding_b      = padding_y;									
			                    *tile_padding_r      = padding_r;
						        *tile_padding_l      = 0;									
								break;
					   }						
                            else if(*cnt_num_dat_tile==tile_num_x_c+2){
								     *feature_x           = tile_size_x_4;
                                     *feature_y           = tile_size_y_4;
                                     *len_dat_stride_norm = len_dat_stride_norm_4;
                                     *num_dat_stride_norm = num_dat_stride_norm_4;
                                     *len_dat_stride_last = len_dat_stride_last_4;
                                     *num_dat_stride_last = num_dat_stride_last_4;
						             *tile_padding_t      = 0;										 
				                     *tile_padding_b      = padding_b;
						             *tile_padding_r      = padding_x;										 
				                     *tile_padding_l      = padding_l;
									 break;
							}
                                 else if(*cnt_num_dat_tile < tile_num_x_c+1+tile_num_x_c+2 && *cnt_num_dat_tile >tile_num_x_c+2){
                                          *feature_x           = tile_size_x_5;	
                                          *feature_y           = tile_size_y_5;
                                          *len_dat_stride_norm = len_dat_stride_norm_5;
                                          *num_dat_stride_norm = num_dat_stride_norm_5;
                                          *len_dat_stride_last = len_dat_stride_last_5;
                                          *num_dat_stride_last = num_dat_stride_last_5;
						                  *tile_padding_t      = 0;											  
	               			              *tile_padding_b      = padding_b;
						                  *tile_padding_r      = padding_x;
						                  *tile_padding_l      = 0;											  
										  break;
								 }
                                      else if(*cnt_num_dat_tile==tile_num_x_c+1+tile_num_x_c+2){
                                               *feature_x           = tile_size_x_6;	
                                               *feature_y           = tile_size_y_6;	
                                               *len_dat_stride_norm = len_dat_stride_norm_6;
                                               *num_dat_stride_norm = num_dat_stride_norm_6;
                                               *len_dat_stride_last = len_dat_stride_last_6;
                                               *num_dat_stride_last = num_dat_stride_last_6;
						                       *tile_padding_t      = 0;												   
				                               *tile_padding_b      = padding_b;
						                       *tile_padding_r      = padding_x;												   
				                               *tile_padding_l      = padding_l;
											   break;
									  }								
                                           else{
						                       *feature_x           = tile_size_x_1;
						                       *feature_y           = tile_size_y_1;	
                                               *len_dat_stride_norm = len_dat_stride_norm_1;
                                               *num_dat_stride_norm = num_dat_stride_norm_1;
                                               *len_dat_stride_last = len_dat_stride_last_1;
                                               *num_dat_stride_last = num_dat_stride_last_1;											   
				                               *tile_padding_t      = padding_t;
				                               *tile_padding_b      = padding_b;				  
			                                   *tile_padding_r      = padding_r;			  
				                               *tile_padding_l      = padding_l;
											   break;
										   }									  
		}
		case 5 :
		{
			      if(*cnt_num_dat_tile==0){
                      *feature_x = tile_size_x_1;
                      *feature_y = tile_size_y_1;
                      *len_dat_stride_norm = len_dat_stride_norm_1;
                      *num_dat_stride_norm = num_dat_stride_norm_1;
                      *len_dat_stride_last = len_dat_stride_last_1;
                      *num_dat_stride_last = num_dat_stride_last_1;					  
				      *tile_padding_t = padding_t;
					  *tile_padding_b      = padding_y;
					  *tile_padding_r      = padding_x;						  
			          *tile_padding_l =  padding_l;
					  break;
				  }
                  else if(*cnt_num_dat_tile==1){
					       *feature_x = tile_size_x_2;
                           *feature_y = tile_size_y_2;	
                           *len_dat_stride_norm = len_dat_stride_norm_2;
                           *num_dat_stride_norm = num_dat_stride_norm_2;
                           *len_dat_stride_last = len_dat_stride_last_2;
                           *num_dat_stride_last = num_dat_stride_last_2;						   
				           *tile_padding_t = padding_t;
						   *tile_padding_b = padding_y;							   
			               *tile_padding_r = padding_r;
						   *tile_padding_l      = padding_x;							   
						   break;
				  }		
                       else if( (*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==0 ){
					            *feature_x = tile_size_x_3;
                                *feature_y = tile_size_y_3;	
                                *len_dat_stride_norm = len_dat_stride_norm_3;
                                *num_dat_stride_norm = num_dat_stride_norm_3;
                                *len_dat_stride_last = len_dat_stride_last_3;
                                *num_dat_stride_last = num_dat_stride_last_3;
						        *tile_padding_t      = 0;
						        *tile_padding_b      = padding_y;
						        *tile_padding_r      = padding_x;								
				                *tile_padding_l = padding_l;
								break;
					   }						
                            else if((*cnt_num_dat_tile-2) > 0 && (*cnt_num_dat_tile-2) < 2*tile_num_y_c && *cnt_num_dat_tile%2==1){
								     *feature_x = tile_size_x_4;
                                     *feature_y = tile_size_y_4;
                                     *len_dat_stride_norm = len_dat_stride_norm_4;
                                     *num_dat_stride_norm = num_dat_stride_norm_4;
                                     *len_dat_stride_last = len_dat_stride_last_4;
                                     *num_dat_stride_last = num_dat_stride_last_4;
						             *tile_padding_t      = 0;
						             *tile_padding_b      = padding_y;									 
               			             *tile_padding_r = padding_r;
									 *tile_padding_l      = 0;
									 break;
							}
                                 else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1) ){
                                          *feature_x = tile_size_x_5;	
                                          *feature_y = tile_size_y_5;
                                          *len_dat_stride_norm = len_dat_stride_norm_5;
                                          *num_dat_stride_norm = num_dat_stride_norm_5;
                                          *len_dat_stride_last = len_dat_stride_last_5;
                                          *num_dat_stride_last = num_dat_stride_last_5;
						                  *tile_padding_t      = 0;										  
				                          *tile_padding_b = padding_b;
						                  *tile_padding_r = padding_x;										  
				                          *tile_padding_l = padding_l;
										  break;
								 }
                                      else if(*cnt_num_dat_tile == 2*(tile_num_y_c+1)+1 ){
                                               *feature_x = tile_size_x_6;	
                                               *feature_y = tile_size_y_6;
                                               *len_dat_stride_norm = len_dat_stride_norm_6;
                                               *num_dat_stride_norm = num_dat_stride_norm_6;
                                               *len_dat_stride_last = len_dat_stride_last_6;
                                               *num_dat_stride_last = num_dat_stride_last_6;
						                       *tile_padding_t      = 0;											   
				                               *tile_padding_b = padding_b;				  		  
				                               *tile_padding_r = padding_r;
						                       *tile_padding_l      = 0;											   
											   break;
									  }								
                                           else{
						                       *feature_x = tile_size_x_1;
						                       *feature_y = tile_size_y_1;
                                               *len_dat_stride_norm = len_dat_stride_norm_1;
                                               *num_dat_stride_norm = num_dat_stride_norm_1;
                                               *len_dat_stride_last = len_dat_stride_last_1;
                                               *num_dat_stride_last = num_dat_stride_last_1;											   
				                               *tile_padding_t = padding_t;
				                               *tile_padding_b = padding_b;				  
			                                   *tile_padding_r = padding_r;			  
				                               *tile_padding_l = padding_l;
											   break;
										   }
		}										   		
		case 6 :  
		{
			      if(*cnt_num_dat_tile=0){
                      *feature_x = tile_size_x_1;
                      *feature_y = tile_size_y_1;	
                      *len_dat_stride_norm = len_dat_stride_norm_1;
                      *num_dat_stride_norm = num_dat_stride_norm_1;
                      *len_dat_stride_last = len_dat_stride_last_1;
                      *num_dat_stride_last = num_dat_stride_last_1;					  
				      *tile_padding_t = padding_t;
					  *tile_padding_b      = 0;
					  *tile_padding_r      = padding_x;					  
			          *tile_padding_l = padding_l;
					  break;
				  }
                  else if(*cnt_num_dat_tile < tile_num_x_c+1 && *cnt_num_dat_tile >0){
					       *feature_x = tile_size_x_2;
                           *feature_y = tile_size_y_2;
                           *len_dat_stride_norm = len_dat_stride_norm_2;
                           *num_dat_stride_norm = num_dat_stride_norm_2;
                           *len_dat_stride_last = len_dat_stride_last_2;
                           *num_dat_stride_last = num_dat_stride_last_2;						   
				           *tile_padding_t = padding_t;
						   *tile_padding_b      = padding_y;
						   *tile_padding_r      = padding_x;
						   *tile_padding_l      = 0;
						   break;
				  }
                       else if(*cnt_num_dat_tile==tile_num_x_c+1){
					            *feature_x = tile_size_x_3;
                                *feature_y = tile_size_y_3;	
                                *len_dat_stride_norm = len_dat_stride_norm_3;
                                *num_dat_stride_norm = num_dat_stride_norm_3;
                                *len_dat_stride_last = len_dat_stride_last_3;
                                *num_dat_stride_last = num_dat_stride_last_3;								
				                *tile_padding_t = padding_t;
						        *tile_padding_b      = padding_y;								
			                    *tile_padding_r = padding_r;
						        *tile_padding_l      = 0;								
								break;
					   }
                            else if(*cnt_num_dat_tile==tile_num_x_c+2){
								     *feature_x = tile_size_x_4;
                                     *feature_y = tile_size_y_4;
                                     *len_dat_stride_norm = len_dat_stride_norm_4;
                                     *num_dat_stride_norm = num_dat_stride_norm_4;
                                     *len_dat_stride_last = len_dat_stride_last_4;
                                     *num_dat_stride_last = num_dat_stride_last_4;
						             *tile_padding_t      = 0;
						             *tile_padding_b      = padding_y;
						             *tile_padding_r      = padding_x;									 
			                         *tile_padding_l = padding_l;
									 break;
							}
                                 else if(*cnt_num_dat_tile>tile_num_x_c+2 && 
								         *cnt_num_dat_tile<(tile_num_x_c+2)*(tile_num_y_c+1) && 
										 *cnt_num_dat_tile%(tile_num_x_c+2)!=0 && 
										 (*cnt_num_dat_tile-1)%(tile_num_x_c+2)!=0){
							     	      *feature_x = tile_size_x_5;
                                          *feature_y = tile_size_y_5;
                                          *len_dat_stride_norm = len_dat_stride_norm_5;
                                          *num_dat_stride_norm = num_dat_stride_norm_5;
                                          *len_dat_stride_last = len_dat_stride_last_5;
                                          *num_dat_stride_last = num_dat_stride_last_5;
						                  *tile_padding_t      = 0;
						                  *tile_padding_b      = padding_y;
						                  *tile_padding_r      = padding_x;
						                  *tile_padding_l      = 0;								
										  break;
							     }
                                      else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1)-1 ){
							     	           *feature_x = tile_size_x_6;
                                               *feature_y = tile_size_y_6;
                                               *len_dat_stride_norm = len_dat_stride_norm_6;
                                               *num_dat_stride_norm = num_dat_stride_norm_6;
                                               *len_dat_stride_last = len_dat_stride_last_6;
                                               *num_dat_stride_last = num_dat_stride_last_6;
						                       *tile_padding_t      = 0;
						                       *tile_padding_b      = padding_y;											   
			                                   *tile_padding_r = padding_r;
						                       *tile_padding_l      = 0;											   
											   break;
									  }		
                                           else if(*cnt_num_dat_tile == (tile_num_x_c+2)*(tile_num_y_c+1) ){
							     	                *feature_x = tile_size_x_7;
                                                    *feature_y = tile_size_y_7;	
                                                    *len_dat_stride_norm = len_dat_stride_norm_7;
                                                    *num_dat_stride_norm = num_dat_stride_norm_7;
                                                    *len_dat_stride_last = len_dat_stride_last_7;
                                                    *num_dat_stride_last = num_dat_stride_last_7;
						                            *tile_padding_t      = 0;													
				                                    *tile_padding_b = padding_b;
						                            *tile_padding_r      = padding_x;													
			                                        *tile_padding_l = padding_l;
													break;
									       }	
                                                else if(*cnt_num_dat_tile > (tile_num_x_c+2)*(tile_num_y_c+1) && *cnt_num_dat_tile < (tile_num_x_c+2)*(tile_num_y_c+2)-1){
							     	                     *feature_x = tile_size_x_8;
                                                         *feature_y = tile_size_y_8;
                                                         *len_dat_stride_norm = len_dat_stride_norm_8;
                                                         *num_dat_stride_norm = num_dat_stride_norm_8;
                                                         *len_dat_stride_last = len_dat_stride_last_8;
                                                         *num_dat_stride_last = num_dat_stride_last_8;
						                                 *tile_padding_t      = 0;														 
				                                         *tile_padding_b = padding_b;
						                                 *tile_padding_r      = padding_x;
						                                 *tile_padding_l      = 0;														 
														 break;
									            }	
                                                     else if(*cnt_num_dat_tile = (tile_num_x_c+2)*(tile_num_y_c+2)-1){
							     	                          *feature_x = tile_size_x_9;
                                                              *feature_y = tile_size_y_9;
                                                              *len_dat_stride_norm = len_dat_stride_norm_9;
                                                              *num_dat_stride_norm = num_dat_stride_norm_9;
                                                              *len_dat_stride_last = len_dat_stride_last_9;
                                                              *num_dat_stride_last = num_dat_stride_last_9;
						                                      *tile_padding_t      = 0;															  
				                                              *tile_padding_b = padding_b;			  
			                                                  *tile_padding_r = padding_r;
						                                      *tile_padding_l      = 0;															  
															  break;
									                 }
                                                          else{
                                                              *feature_x = tile_size_x_1;	
                                                              *feature_y = tile_size_y_1;
                                                              *len_dat_stride_norm = len_dat_stride_norm_1;
                                                              *num_dat_stride_norm = num_dat_stride_norm_1;
                                                              *len_dat_stride_last = len_dat_stride_last_1;
                                                              *num_dat_stride_last = num_dat_stride_last_1;															  
				                                              *tile_padding_t = padding_t;
				                                              *tile_padding_b = padding_b;				  
			                                                  *tile_padding_r = padding_r;			  
				                                              *tile_padding_l = padding_l;
															  break;
										                  }													 
		}		
        default:  {
			      *feature_x = tile_size_x_1;
		          *feature_y = tile_size_y_1;
                  *len_dat_stride_norm = len_dat_stride_norm_1;
                  *num_dat_stride_norm = num_dat_stride_norm_1;
                  *len_dat_stride_last = len_dat_stride_last_1;
                  *num_dat_stride_last = num_dat_stride_last_1;				  
				  *tile_padding_t = padding_t;
				  *tile_padding_b = padding_b;				  
			      *tile_padding_r = padding_r;			  
				  *tile_padding_l = padding_l;
		}
	}	

		return 1;
}		