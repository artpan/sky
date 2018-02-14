#include "mac_top.h"
#include <string.h> 
#include <malloc.h> 
#include <stdio.h>
#include <stdlib.h>

struct RESHAPE DLA_RESHAPE;

void reshape()
{
	DLA_RESHAPE.reshape_mode = 3;
	//0:splitting
	//1:slicing
	//2:merging
	//3:reshape-transpose

	FILE *fp;

	if (DLA_RESHAPE.reshape_mode == 0)
	{
		//////for splitting mode
		DLA_RESHAPE.splitting_channel_size_ori = 16;
		DLA_RESHAPE.splitting_feature_size_x_ori = 6;
		DLA_RESHAPE.splitting_feature_size_y_ori = 5;

		DLA_RESHAPE.splitting_number = 5;
		DLA_RESHAPE.splitting_channel_size_0 = 2;
		DLA_RESHAPE.splitting_channel_size_1 = 2;
		DLA_RESHAPE.splitting_channel_size_2 = 3;
		DLA_RESHAPE.splitting_channel_size_3 = 3;
		DLA_RESHAPE.splitting_channel_size_4 = 6;
		DLA_RESHAPE.splitting_channel_size_5 = 0;
		DLA_RESHAPE.splitting_channel_size_6 = 0;
		DLA_RESHAPE.splitting_channel_size_7 = 0;

		int *splitting_feature_ori;
		splitting_feature_ori = (int*)malloc((DLA_RESHAPE.splitting_channel_size_ori * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));

		int *splitting_feature_0;
		int *splitting_feature_1;
		int *splitting_feature_2;
		int *splitting_feature_3;
		int *splitting_feature_4;
		int *splitting_feature_5;
		int *splitting_feature_6;
		int *splitting_feature_7;

		splitting_feature_0 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_0 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_1 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_1 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_2 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_2 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_3 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_3 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_4 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_4 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_5 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_5 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_6 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_6 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));
		splitting_feature_7 = (int*)malloc((DLA_RESHAPE.splitting_channel_size_7 * DLA_RESHAPE.splitting_feature_size_x_ori * DLA_RESHAPE.splitting_feature_size_y_ori) * sizeof(int));

		//////for debug data in
		int c_ori = DLA_RESHAPE.splitting_channel_size_ori;
		int w_ori = DLA_RESHAPE.splitting_feature_size_x_ori;
		int h_ori = DLA_RESHAPE.splitting_feature_size_y_ori;
		int c_0 = DLA_RESHAPE.splitting_channel_size_0;
		int c_1 = DLA_RESHAPE.splitting_channel_size_1;
		int c_2 = DLA_RESHAPE.splitting_channel_size_2;
		int c_3 = DLA_RESHAPE.splitting_channel_size_3;
		int c_4 = DLA_RESHAPE.splitting_channel_size_4;
		int c_5 = DLA_RESHAPE.splitting_channel_size_5;
		int c_6 = DLA_RESHAPE.splitting_channel_size_6;
		int c_7 = DLA_RESHAPE.splitting_channel_size_7;

		fopen_s(&fp, "test_in_0.txt","r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori; c++)
				{
					fscanf_s(fp, "%d\n", (splitting_feature_ori + c + w * c_ori + h * w_ori * c_ori));
					//printf("%d\n", (c + w * c_ori + h * w_ori * c_ori));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_splitting_ori.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_ori; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_ori + c + w * c_ori + h * w_ori * c_ori));
				}
			}
		}
		fclose(fp);
		//////
		reshape_splitting(splitting_feature_ori, 
						  splitting_feature_0, splitting_feature_1, splitting_feature_2, splitting_feature_3, 
						  splitting_feature_4, splitting_feature_5, splitting_feature_6, splitting_feature_7);

		//////for debug data out

		fopen_s(&fp, "test_splitting_out_0.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_0; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_0 + c + w * c_0 + h * w_ori * c_0));
					printf("%d\n", *(splitting_feature_0 + c + w * c_0 + h * w_ori * c_0));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_1.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_1; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_1 + c + w * c_1 + h * w_ori * c_1));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_2.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_2; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_2 + c + w * c_2 + h * w_ori * c_2));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_3.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_3; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_3 + c + w * c_3 + h * w_ori * c_3));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_4.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_4; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_4 + c + w * c_4 + h * w_ori * c_4));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_5.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_5; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_5 + c + w * c_5 + h * w_ori * c_5));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_6.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_6; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_6 + c + w * c_6 + h * w_ori * c_6));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_splitting_out_7.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_7; c++)
				{
					fprintf(fp, "%d\n", *(splitting_feature_7 + c + w * c_7 + h * w_ori * c_7));
				}
			}
		}
		fclose(fp);
		//////
	}

	if (DLA_RESHAPE.reshape_mode == 1)
	{
		//////for slicing mode
		DLA_RESHAPE.slicing_feature_size_x_ori = 8;
		DLA_RESHAPE.slicing_feature_size_y_ori = 7;
		DLA_RESHAPE.slicing_channel_size_ori = 10;

		DLA_RESHAPE.slicing_feature_size_x_new = 2;
		DLA_RESHAPE.slicing_feature_size_y_new = 5;
		DLA_RESHAPE.slicing_channel_size_new = 3;

		DLA_RESHAPE.slicing_start_point = 92;
		DLA_RESHAPE.slicing_step_h = 0;
		DLA_RESHAPE.slicing_step_w = 0;

		int *slicing_feature_ori;
		slicing_feature_ori = (int*)malloc((DLA_RESHAPE.slicing_channel_size_ori * DLA_RESHAPE.slicing_feature_size_x_ori * DLA_RESHAPE.slicing_feature_size_y_ori) * sizeof(int));

		int *slicing_feature_new;
		slicing_feature_new = (int*)malloc((DLA_RESHAPE.slicing_channel_size_new * DLA_RESHAPE.slicing_feature_size_x_new * DLA_RESHAPE.slicing_feature_size_y_new) * sizeof(int));

		//////for debug data in
		int c_ori = DLA_RESHAPE.slicing_channel_size_ori;
		int w_ori = DLA_RESHAPE.slicing_feature_size_x_ori;
		int h_ori = DLA_RESHAPE.slicing_feature_size_y_ori;

		int c_new = DLA_RESHAPE.slicing_channel_size_new;
		int w_new = DLA_RESHAPE.slicing_feature_size_x_new;
		int h_new = DLA_RESHAPE.slicing_feature_size_y_new;

		fopen_s(&fp, "test_in_0.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori; c++)
				{
					fscanf_s(fp, "%d\n", (slicing_feature_ori + c + w * c_ori + h * w_ori * c_ori));
					//printf("%d\n", (c + w * c_ori + h * w_ori * c_ori));
				}
			}
		}
		//////
		reshape_slicing(slicing_feature_ori, slicing_feature_new);

		//////for debug data out
		fopen_s(&fp, "test_slicing_new.txt", "w");
		for (int h = 0; h < h_new; h++)
		{
			for (int w = 0; w < w_new; w++)
			{
				for (int c = 0; c < c_new; c++)
				{
					fprintf(fp, "%d\n", *(slicing_feature_new + c + w * c_new + h * w_new * c_new));
					//printf("%d\n", *(slicing_feature_new + c + w * c_new + h * w_new * c_new));
				}
			}
		}
		fclose(fp);
	}

	if (DLA_RESHAPE.reshape_mode == 2)
	{
		//////for merging mode
		DLA_RESHAPE.merging_feature_size_x_ori = 8;
		DLA_RESHAPE.merging_feature_size_y_ori = 7;
		DLA_RESHAPE.merging_channel_size_ori_0 = 2;
		DLA_RESHAPE.merging_channel_size_ori_1 = 3;
		DLA_RESHAPE.merging_channel_size_ori_2 = 1;
		DLA_RESHAPE.merging_channel_size_ori_3 = 6;
		DLA_RESHAPE.merging_channel_size_ori_4 = 6;
		DLA_RESHAPE.merging_channel_size_ori_5 = 2;
		DLA_RESHAPE.merging_channel_size_ori_6 = 0;
		DLA_RESHAPE.merging_channel_size_ori_7 = 0;

		DLA_RESHAPE.merging_channel_size = 20;
		DLA_RESHAPE.merging_number = 6;

		int *merging_feature_0;
		int *merging_feature_1;
		int *merging_feature_2;
		int *merging_feature_3;
		int *merging_feature_4;
		int *merging_feature_5;
		int *merging_feature_6;
		int *merging_feature_7;

		merging_feature_0 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_0 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_1 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_1 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_2 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_2 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_3 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_3 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_4 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_4 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_5 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_5 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_6 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_6 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));
		merging_feature_7 = (int*)malloc((DLA_RESHAPE.merging_channel_size_ori_7 * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));

		int *merging_feature;
		merging_feature = (int*)malloc((DLA_RESHAPE.merging_channel_size * DLA_RESHAPE.merging_feature_size_x_ori * DLA_RESHAPE.merging_feature_size_y_ori) * sizeof(int));

		//////for debug data in
		int w_ori = DLA_RESHAPE.merging_feature_size_x_ori;
		int h_ori = DLA_RESHAPE.merging_feature_size_y_ori;
		int c_ori_0 = DLA_RESHAPE.merging_channel_size_ori_0;
		int c_ori_1 = DLA_RESHAPE.merging_channel_size_ori_1;
		int c_ori_2 = DLA_RESHAPE.merging_channel_size_ori_2;
		int c_ori_3 = DLA_RESHAPE.merging_channel_size_ori_3;
		int c_ori_4 = DLA_RESHAPE.merging_channel_size_ori_4;
		int c_ori_5 = DLA_RESHAPE.merging_channel_size_ori_5;
		int c_ori_6 = DLA_RESHAPE.merging_channel_size_ori_6;
		int c_ori_7 = DLA_RESHAPE.merging_channel_size_ori_7;

		int c_out = DLA_RESHAPE.merging_channel_size;

		fopen_s(&fp, "test_in_0.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_0; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_0 + c + w * c_ori_0 + h * w_ori * c_ori_0));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_1.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_1; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_1 + c + w * c_ori_1 + h * w_ori * c_ori_1));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_2.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_2; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_2 + c + w * c_ori_2 + h * w_ori * c_ori_2));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_3.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_3; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_3 + c + w * c_ori_3 + h * w_ori * c_ori_3));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_4.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_3; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_4 + c + w * c_ori_4 + h * w_ori * c_ori_4));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_5.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_5; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_5 + c + w * c_ori_5 + h * w_ori * c_ori_5));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_6.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_6; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_6 + c + w * c_ori_6 + h * w_ori * c_ori_6));
				}
			}
		}
		fclose(fp);

		fopen_s(&fp, "test_in_7.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori_7; c++)
				{
					fscanf_s(fp, "%d\n", (merging_feature_7 + c + w * c_ori_7 + h * w_ori * c_ori_7));
				}
			}
		}
		fclose(fp);

		//////

		reshape_merging(merging_feature_0, merging_feature_1, merging_feature_2, merging_feature_3,
						merging_feature_4, merging_feature_5, merging_feature_6, merging_feature_7,
						merging_feature);


		//////for debug data out
		fopen_s(&fp, "test_merging_new.txt", "w");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int c = 0; c < c_out; c++)
				{
					fprintf(fp, "%d\n", *(merging_feature + c + w * c_out + h * w_ori * c_out));
					//printf("%d\n", *(slicing_feature_new + c + w * c_new + h * w_new * c_new));
				}
			}
		}
		fclose(fp);


	}

	if (DLA_RESHAPE.reshape_mode == 3)
	{
		//////for reshape-transpose mode
		DLA_RESHAPE.transpose_feature_size_x_ori = 5;
		DLA_RESHAPE.transpose_feature_size_y_ori = 3;
		DLA_RESHAPE.transpose_channel_size_ori = 2;

		DLA_RESHAPE.transpose_feature_size_x_new = 5;
		DLA_RESHAPE.transpose_feature_size_y_new = 2;
		DLA_RESHAPE.transpose_channel_size_new = 3;

		DLA_RESHAPE.transpose_mode = 5;

		int *transpose_feature_ori;
		int *transpose_feature_new;

		transpose_feature_ori = (int*)malloc((DLA_RESHAPE.transpose_channel_size_ori * DLA_RESHAPE.transpose_feature_size_x_ori * DLA_RESHAPE.transpose_feature_size_y_ori) * sizeof(int));
		transpose_feature_new = (int*)malloc((DLA_RESHAPE.transpose_channel_size_ori * DLA_RESHAPE.transpose_feature_size_x_ori * DLA_RESHAPE.transpose_feature_size_y_ori) * sizeof(int));
		
		//////for debug data in
		int h_ori = DLA_RESHAPE.transpose_feature_size_y_ori;
		int w_ori = DLA_RESHAPE.transpose_feature_size_x_ori;
		int c_ori = DLA_RESHAPE.transpose_channel_size_ori;

		int h_new = DLA_RESHAPE.transpose_feature_size_y_new;
		int w_new = DLA_RESHAPE.transpose_feature_size_x_new;
		int c_new = DLA_RESHAPE.transpose_channel_size_new;

		fopen_s(&fp, "test_in_0.txt", "r");
		for (int h = 0; h < h_ori; h++)
		{
			for (int w = 0; w <w_ori; w++)
			{
				for (int c = 0; c < c_ori; c++)
				{
					fscanf_s(fp, "%d\n", (transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori));
				}
			}
		}
		fclose(fp);
		//////
		reshape_transpose(transpose_feature_ori, transpose_feature_new);

		//////for debug data out
		fopen_s(&fp, "test_transpose_5_new.txt", "w");
		for (int h = 0; h < h_new; h++)
		{
			for (int w = 0; w < w_new; w++)
			{
				for (int c = 0; c < c_new; c++)
				{
					fprintf(fp, "%d\n", *(transpose_feature_new + c + w * c_new + h * w_new * c_new));
					//printf("%d\n", *(slicing_feature_new + c + w * c_new + h * w_new * c_new));
				}
			}
		}
		fclose(fp);


	}
	
}

void reshape_splitting(	int *splitting_feature_ori,
						int *splitting_feature_0, int *splitting_feature_1, int *splitting_feature_2, int *splitting_feature_3,
						int *splitting_feature_4, int *splitting_feature_5, int *splitting_feature_6, int *splitting_feature_7)
{
	int splitting_channel_add_0 = 0;
	int splitting_channel_add_1 = DLA_RESHAPE.splitting_channel_size_0;
	int splitting_channel_add_2 = splitting_channel_add_1 + DLA_RESHAPE.splitting_channel_size_1;
	int splitting_channel_add_3 = splitting_channel_add_2 + DLA_RESHAPE.splitting_channel_size_2;
	int splitting_channel_add_4 = splitting_channel_add_3 + DLA_RESHAPE.splitting_channel_size_3;
	int splitting_channel_add_5 = splitting_channel_add_4 + DLA_RESHAPE.splitting_channel_size_4;
	int splitting_channel_add_6 = splitting_channel_add_5 + DLA_RESHAPE.splitting_channel_size_5;
	int splitting_channel_add_7 = splitting_channel_add_6 + DLA_RESHAPE.splitting_channel_size_6;

	int c_ori = DLA_RESHAPE.splitting_channel_size_ori;
	int w_ori = DLA_RESHAPE.splitting_feature_size_x_ori;
	int h_ori = DLA_RESHAPE.splitting_feature_size_y_ori;
	int c_0 = DLA_RESHAPE.splitting_channel_size_0;
	int c_1 = DLA_RESHAPE.splitting_channel_size_1;
	int c_2 = DLA_RESHAPE.splitting_channel_size_2;
	int c_3 = DLA_RESHAPE.splitting_channel_size_3;
	int c_4 = DLA_RESHAPE.splitting_channel_size_4;
	int c_5 = DLA_RESHAPE.splitting_channel_size_5;
	int c_6 = DLA_RESHAPE.splitting_channel_size_6;
	int c_7 = DLA_RESHAPE.splitting_channel_size_7;

	for (int h = 0; h < h_ori; h++)
	{
		for (int w = 0; w < w_ori; w++)
		{
			if (c_0 != 0)
			{
				for (int c0 = 0; c0 < c_0; c0++)
				{
					*(splitting_feature_0 + c0 + w * c_0 + h * w_ori * c_0) = *(splitting_feature_ori + c0 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_0);
					//printf("%d\n", *(splitting_feature_ori + c0 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_0));
					//printf("%d\n", *(splitting_feature_0 + c0 + w * c_0 + h * w_ori * c_0));
					//printf("%d\n", (c0 + w * c_0 + h * w_ori * c_0));
					//printf("%d\n", (c0 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_0));
				}
			}
			if (c_1 != 0)
			{
				for (int c1 = 0; c1 < c_1; c1++)
				{
					*(splitting_feature_1 + c1 + w * c_1 + h * w_ori * c_1) = *(splitting_feature_ori + c1 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_1);
					//printf("%d\n", (c1 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_1));
				}
			}
			if (c_2 != 0)
			{
				for (int c2 = 0; c2 < c_2; c2++)
				{
					*(splitting_feature_2 + c2 + w * c_2 + h * w_ori * c_2) = *(splitting_feature_ori + c2 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_2);
					//printf("%d\n", (c2 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_2));
				}
			}
			if (c_3 != 0)
			{
				for (int c3 = 0; c3 < c_3; c3++)
				{
					*(splitting_feature_3 + c3 + w * c_3 + h * w_ori * c_3) = *(splitting_feature_ori + c3 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_3);
					//printf("%d\n", (c3 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_3));
				}
			}
			if (c_4 != 0)
			{
				for (int c4 = 0; c4 < c_4; c4++)
				{
					*(splitting_feature_4 + c4 + w * c_4 + h * w_ori * c_4) = *(splitting_feature_ori + c4 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_4);
					//printf("%d\n", (c4 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_4));
				}
			}
			if (c_5 != 0)
			{
				for (int c5 = 0; c5 < c_5; c5++)
				{
					*(splitting_feature_5 + c5 + w * c_5 + h * w_ori * c_5) = *(splitting_feature_ori + c5 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_5);
					//printf("%d\n", (c5 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_5));
				}
			}
			if (c_6 != 0)
			{
				for (int c6 = 0; c6 < c_6; c6++)
				{
					*(splitting_feature_6 + c6 + w * c_6 + h * w_ori * c_6) = *(splitting_feature_ori + c6 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_6);
					//printf("%d\n", (c6 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_6));
				}
			}
			if (c_7 != 0)
			{
				for (int c7 = 0; c7 < c_7; c7++)
				{
					*(splitting_feature_7 + c7 + w * c_7 + h * w_ori * c_7) = *(splitting_feature_ori + c7 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_7);
					//printf("%d\n", (c7 + w * c_ori + h * w_ori * c_ori + splitting_channel_add_7));
				}
			}
		}
	}
}

void reshape_slicing(int *slicing_feature_ori, int *slicing_feature_new)
{
	int c_ori = DLA_RESHAPE.slicing_channel_size_ori;
	int w_ori = DLA_RESHAPE.slicing_feature_size_x_ori;
	int h_ori = DLA_RESHAPE.slicing_feature_size_y_ori;

	int c_new = DLA_RESHAPE.slicing_channel_size_new;
	int w_new = DLA_RESHAPE.slicing_feature_size_x_new;
	int h_new = DLA_RESHAPE.slicing_feature_size_y_new;

	for (int h = 0; h < h_new; h++)
	{
		for (int w = 0; w < w_new; w++)
		{
			for (int c = 0; c < c_new; c++)
			{
				*(slicing_feature_new + c + w * c_new + h * w_new * c_new) = *(slicing_feature_ori + DLA_RESHAPE.slicing_start_point + c + w * c_ori + h * w_ori * c_ori);
				//printf("%d\n", (DLA_RESHAPE.slicing_start_point + c + w * c_ori + h * w_ori * c_ori));
				printf("%d\n", (c + w * c_new + h * w_new * c_new));
				//printf("%d\n", *(slicing_feature_ori + DLA_RESHAPE.slicing_start_point + c + w * c_ori + h * w_ori * c_ori));
				//printf("%d\n", *(slicing_feature_new + c + w * c_new + h * w_new * c_new));
			}
		}
	}

}

void reshape_merging(int *merging_feature_0, int *merging_feature_1, int *merging_feature_2, int *merging_feature_3,
					 int *merging_feature_4, int *merging_feature_5, int *merging_feature_6, int *merging_feature_7,
					 int *merging_feature)
{

	int merging_channel_add_0 = 0;
	int merging_channel_add_1 = DLA_RESHAPE.merging_channel_size_ori_0;
	int merging_channel_add_2 = merging_channel_add_1 + DLA_RESHAPE.merging_channel_size_ori_1;
	int merging_channel_add_3 = merging_channel_add_2 + DLA_RESHAPE.merging_channel_size_ori_2;
	int merging_channel_add_4 = merging_channel_add_3 + DLA_RESHAPE.merging_channel_size_ori_3;
	int merging_channel_add_5 = merging_channel_add_4 + DLA_RESHAPE.merging_channel_size_ori_4;
	int merging_channel_add_6 = merging_channel_add_5 + DLA_RESHAPE.merging_channel_size_ori_5;
	int merging_channel_add_7 = merging_channel_add_6 + DLA_RESHAPE.merging_channel_size_ori_6;

	int w_ori = DLA_RESHAPE.merging_feature_size_x_ori;
	int h_ori = DLA_RESHAPE.merging_feature_size_y_ori;
	int c_ori_0 = DLA_RESHAPE.merging_channel_size_ori_0;
	int c_ori_1 = DLA_RESHAPE.merging_channel_size_ori_1;
	int c_ori_2 = DLA_RESHAPE.merging_channel_size_ori_2;
	int c_ori_3 = DLA_RESHAPE.merging_channel_size_ori_3;
	int c_ori_4 = DLA_RESHAPE.merging_channel_size_ori_4;
	int c_ori_5 = DLA_RESHAPE.merging_channel_size_ori_5;
	int c_ori_6 = DLA_RESHAPE.merging_channel_size_ori_6;
	int c_ori_7 = DLA_RESHAPE.merging_channel_size_ori_7;

	int c_out = DLA_RESHAPE.merging_channel_size;

	for (int h = 0; h < h_ori; h++)
	{
		for (int w = 0; w < w_ori; w++)
		{
			if (c_ori_0 != 0)
			{
				for (int c0 = 0; c0 < c_ori_0; c0++)
				{
					*(merging_feature + c0 + w * c_out + h * w_ori * c_out + merging_channel_add_0) = *(merging_feature_0 + c0 + w * c_ori_0 + h * w_ori * c_ori_0);
				}
			}
			if (c_ori_1 != 0)
			{
				for (int c1 = 0; c1 < c_ori_1; c1++)
				{
					*(merging_feature + c1 + w * c_out + h * w_ori * c_out + merging_channel_add_1) = *(merging_feature_1 + c1 + w * c_ori_1 + h * w_ori * c_ori_1);
				}
			}
			if (c_ori_2 != 0)
			{
				for (int c2 = 0; c2 < c_ori_2; c2++)
				{
					*(merging_feature + c2 + w * c_out + h * w_ori * c_out + merging_channel_add_2) = *(merging_feature_2 + c2 + w * c_ori_2 + h * w_ori * c_ori_2);
				}
			}
			if (c_ori_3 != 0)
			{
				for (int c3 = 0; c3 < c_ori_3; c3++)
				{
					*(merging_feature + c3 + w * c_out + h * w_ori * c_out + merging_channel_add_3) = *(merging_feature_3 + c3 + w * c_ori_3 + h * w_ori * c_ori_3);
				}
			}
			if (c_ori_4 != 0)
			{
				for (int c4 = 0; c4 < c_ori_4; c4++)
				{
					*(merging_feature + c4 + w * c_out + h * w_ori * c_out + merging_channel_add_4) = *(merging_feature_4 + c4 + w * c_ori_4 + h * w_ori * c_ori_4);
				}
			}
			if (c_ori_5 != 0)
			{
				for (int c5 = 0; c5 < c_ori_5; c5++)
				{
					*(merging_feature + c5 + w * c_out + h * w_ori * c_out + merging_channel_add_5) = *(merging_feature_5 + c5 + w * c_ori_5 + h * w_ori * c_ori_5);
				}
			}
			if (c_ori_6 != 0)
			{
				for (int c6 = 0; c6 < c_ori_6; c6++)
				{
					*(merging_feature + c6 + w * c_out + h * w_ori * c_out + merging_channel_add_6) = *(merging_feature_6 + c6 + w * c_ori_6 + h * w_ori * c_ori_6);
				}
			}
			if (c_ori_7 != 0)
			{
				for (int c7 = 0; c7 < c_ori_7; c7++)
				{
					*(merging_feature + c7 + w * c_out + h * w_ori * c_out + merging_channel_add_7) = *(merging_feature_7 + c7 + w * c_ori_7 + h * w_ori * c_ori_7);
				}
			}
		}
	}
}

void reshape_transpose(int* transpose_feature_ori, int* transpose_feature_new)
{

	int h_ori = DLA_RESHAPE.transpose_feature_size_y_ori;
	int w_ori = DLA_RESHAPE.transpose_feature_size_x_ori;
	int c_ori = DLA_RESHAPE.transpose_channel_size_ori;

	int h_new = DLA_RESHAPE.transpose_feature_size_y_new;
	int w_new = DLA_RESHAPE.transpose_feature_size_x_new;
	int c_new = DLA_RESHAPE.transpose_channel_size_new;

	switch (DLA_RESHAPE.transpose_mode)
	{
	case 1:
		for (int w = 0; w < w_ori; w++)
		{
			for (int h = 0; h < h_ori; h++)
			{
				for (int c = 0; c < c_ori; c++)
				{
					*(transpose_feature_new + c + h * c_ori + w * h_ori * c_ori) = *(transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori);
				}
			}
		}
		break;
	case 2:
		for (int h = 0; h < h_ori; h++)
		{
			for (int c = 0; c < c_ori; c++)
			{
				for (int w = 0; w < w_ori; w++)
				{
					*(transpose_feature_new + w + c * w_ori + h * c_ori * w_ori) = *(transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori);
				}
			}
		}
		break;
	case 3:
		for (int c = 0; c < c_ori; c++)
		{
			for (int h = 0; h < h_ori; h++)
			{
				for (int w = 0; w < w_ori; w++)
				{
					*(transpose_feature_new + w + h * w_ori + c * h_ori * w_ori) = *(transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori);
				}
			}
		}
		break;
	case 4:
		for (int w = 0; w < w_ori; w++)
		{
			for (int c = 0; c < c_ori; c++)
			{
				for (int h = 0; h < h_ori; h++)
				{
					*(transpose_feature_new + h + c * h_ori + w * c_ori * h_ori) = *(transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori);
				}
			}
		}
		break;
	case 5:
		for (int c = 0; c < c_ori; c++)
		{
			for (int w = 0; w < w_ori; w++)
			{
				for (int h = 0; h < h_ori; h++)
				{
					*(transpose_feature_new + h + w * h_ori + c * w_ori * h_ori) = *(transpose_feature_ori + c + w * c_ori + h * w_ori * c_ori);
				}
			}
		}
		break;
	default:
		break;
	}
}
