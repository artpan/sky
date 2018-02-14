#pragma once

struct MAC
{
	int mac_partition;
	int cal_precision;


};


struct ACCU
{
	int mac_partition;
	int cal_precision;
	int truncate;
	int satuation; 
	int sliding_num;
	int kernel_xy_num;
};

void mac_128(int feature_128[32][64], int weight_128[32][64], long sum_128[64]);
void mac_1024(int feature_1024[256][512], int  weight_1024[256][512], long sum_1024_mac[512]);
void accu(long sum_1024_mac[512], long sum_1024_accu[512][1024], long feature_added_out[512][1024], int kernel_xy_aacu, int sliding_num_aacu);


struct RESHAPE
{
	int reshape_mode;
	//00:splitting
	//01:slicing
	//10:merging
	//11:reshape-transpose

	//for splitting mode
	int splitting_feature_size_x_ori;
	int splitting_feature_size_y_ori;
	int splitting_channel_size_ori;

	int splitting_number; //max=8
	int splitting_channel_size_0;
	int splitting_channel_size_1;
	int splitting_channel_size_2;
	int splitting_channel_size_3;
	int splitting_channel_size_4;
	int splitting_channel_size_5;
	int splitting_channel_size_6;
	int splitting_channel_size_7;


	//for slicing mode
	int slicing_feature_size_x_ori;
	int slicing_feature_size_y_ori;
	int slicing_channel_size_ori;

	int slicing_feature_size_x_new;
	int slicing_feature_size_y_new;
	int slicing_channel_size_new;

	int slicing_start_point;
	int slicing_step_h;
	int slicing_step_w;

	//for merging mode
	int merging_feature_size_x_ori;
	int merging_feature_size_y_ori;
	int merging_channel_size_ori_0;
	int merging_channel_size_ori_1;
	int merging_channel_size_ori_2;
	int merging_channel_size_ori_3;
	int merging_channel_size_ori_4;
	int merging_channel_size_ori_5;
	int merging_channel_size_ori_6;
	int merging_channel_size_ori_7;

	int merging_channel_size;
	int merging_number; //max=8

	//for reshape-transpose mode
	int transpose_feature_size_x_ori;
	int transpose_feature_size_y_ori;
	int transpose_channel_size_ori;

	int transpose_feature_size_x_new;
	int transpose_feature_size_y_new;
	int transpose_channel_size_new;

	int transpose_mode;
};

void reshape();
void reshape_splitting(int *splitting_feature_ori,
					   int *splitting_feature_0, int *splitting_feature_1, int *splitting_feature_2, int *splitting_feature_3,
					   int *splitting_feature_4, int *splitting_feature_5, int *splitting_feature_6, int *splitting_feature_7);
void reshape_slicing(int *slicing_feature_ori, int *slicing_feature_new);
void reshape_merging(int *merging_feature_0, int *merging_feature_1, int *merging_feature_2, int *merging_feature_3,
					 int *merging_feature_4, int *merging_feature_5, int *merging_feature_6, int *merging_feature_7,
					 int *merging_feature);
void reshape_transpose(int* transpose_feature_ori, int* transpose_feature_new);




