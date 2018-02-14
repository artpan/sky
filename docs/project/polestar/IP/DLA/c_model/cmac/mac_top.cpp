#include "mac_top.h"
#include <string.h> 

struct MAC DLA_MAC;
struct ACCU DLA_ACCU;


void mac_128(int feature_128[32][64], int weight_128[32][64], long sum_128[64])
{
	//cal_precision
	// 0: int16 x int16 c=8  k=16 for int16 x int16
	// 1: int16 x int8  c=8  k=32 for int16 x int8
	// 2: int8  x int8  c=16 k=32 for int8  x int8
	// 3: int8  x int4  c=16 k=64 for int8  x int4
	// 4: int4  x int4  c=32 k=64 for int4  x int4
	int c_128_length;
	int k_128_length;

	switch (DLA_MAC.cal_precision)
	{
	case 0:  c_128_length = 8 ; k_128_length = 16; break;
	case 1:  c_128_length = 8 ; k_128_length = 32; break;
	case 2:  c_128_length = 16; k_128_length = 32; break;
	case 3:  c_128_length = 16; k_128_length = 64; break;
	case 4:  c_128_length = 32; k_128_length = 64; break;
	default: c_128_length = 0 ; k_128_length = 0 ; break;
	}

	for (int k = 0; k < k_128_length; k++)
	{
		sum_128[k] = 0;
	}

	for (int k = 0; k < k_128_length; k++)
	{
		for (int c = 0; c < c_128_length; c++)
		{
			sum_128[k] += feature_128[c][k] * weight_128[c][k];
		}
	}

}

void mac_1024(int feature_1024[256][512], int  weight_1024[256][512], long sum_1024_mac[512])
{
	//cal_precision
	// 0: int16 x int16 c=8  k=16 for int16 x int16
	// 1: int16 x int8  c=8  k=32 for int16 x int8
	// 2: int8  x int8  c=16 k=32 for int8  x int8
	// 3: int8  x int4  c=16 k=64 for int8  x int4
	// 4: int4  x int4  c=32 k=64 for int4  x int4

	//mac_partition
	// 0: cx8 kx1  for example: 0 1
	// 1: cx4 kx2               2 3
	// 2: cx2 kx4               4 5
	// 3: cx1 kx8               6 7

	int c_128_length = 0;
	int k_128_length = 0;

	switch (DLA_MAC.cal_precision)
	{
	case 0:  c_128_length = 8;  k_128_length = 16; break;
	case 1:  c_128_length = 8;  k_128_length = 32; break;
	case 2:  c_128_length = 16; k_128_length = 32; break;
	case 3:  c_128_length = 16; k_128_length = 64; break;
	case 4:  c_128_length = 32; k_128_length = 64; break;
	default: c_128_length = 0;  k_128_length = 0; break;
	}

	int feature_128[8][32][64]; //[mac_number][max c][max k]
	int weight_128[8][32][64];  //[mac_number][max c][max k]
	long sum_128_mac[8][64];    //[mac_number][max k]

	int c_location_0;
	int c_location_1;
	int c_location_2;
	int c_location_3;
	int c_location_4;
	int c_location_5;
	int c_location_6;
	int c_location_7;
	int k_location_0;
	int k_location_1;
	int k_location_2;
	int k_location_3;
	int k_location_4;
	int k_location_5;
	int k_location_6;
	int k_location_7;

	//////data for 8 mac
	switch (DLA_MAC.mac_partition)
	{
	case 0:
		c_location_0 = 0;
		c_location_1 = 1;
		c_location_2 = 2;
		c_location_3 = 3;
		c_location_4 = 4;
		c_location_5 = 5;
		c_location_6 = 6;
		c_location_7 = 7;
		k_location_0 = 0;
		k_location_1 = 0;
		k_location_2 = 0;
		k_location_3 = 0;
		k_location_4 = 0;
		k_location_5 = 0;
		k_location_6 = 0;
		k_location_7 = 0;
		break;
	case 1:
		c_location_0 = 0;
		c_location_1 = 0;
		c_location_2 = 1;
		c_location_3 = 1;
		c_location_4 = 2;
		c_location_5 = 2;
		c_location_6 = 3;
		c_location_7 = 3;
		k_location_0 = 0;
		k_location_1 = 1;
		k_location_2 = 0;
		k_location_3 = 1;
		k_location_4 = 0;
		k_location_5 = 1;
		k_location_6 = 0;
		k_location_7 = 1;
	case 2:
		c_location_0 = 0;
		c_location_1 = 0;
		c_location_2 = 0;
		c_location_3 = 0;
		c_location_4 = 1;
		c_location_5 = 1;
		c_location_6 = 1;
		c_location_7 = 1;
		k_location_0 = 0;
		k_location_1 = 1;
		k_location_2 = 2;
		k_location_3 = 3;
		k_location_4 = 0;
		k_location_5 = 1;
		k_location_6 = 2;
		k_location_7 = 3;
	case 3:
		c_location_0 = 0;
		c_location_1 = 0;
		c_location_2 = 0;
		c_location_3 = 0;
		c_location_4 = 0;
		c_location_5 = 0;
		c_location_6 = 0;
		c_location_7 = 0;
		k_location_0 = 0;
		k_location_1 = 1;
		k_location_2 = 2;
		k_location_3 = 3;
		k_location_4 = 4;
		k_location_5 = 5;
		k_location_6 = 6;
		k_location_7 = 7;
	default:
		break;
	}

	for (int c_baisc = 0; c_baisc < c_128_length; c_baisc++)
	{
		for (int k_basic = 0; k_basic < k_128_length; k_basic++)
		{
			feature_128[0][c_baisc][k_basic] = feature_1024[c_location_0 * c_128_length + c_baisc][k_location_0 * k_128_length + k_basic];
			feature_128[1][c_baisc][k_basic] = feature_1024[c_location_1 * c_128_length + c_baisc][k_location_1 * k_128_length + k_basic];
			feature_128[2][c_baisc][k_basic] = feature_1024[c_location_2 * c_128_length + c_baisc][k_location_2 * k_128_length + k_basic];
			feature_128[3][c_baisc][k_basic] = feature_1024[c_location_3 * c_128_length + c_baisc][k_location_3 * k_128_length + k_basic];
			feature_128[4][c_baisc][k_basic] = feature_1024[c_location_4 * c_128_length + c_baisc][k_location_4 * k_128_length + k_basic];
			feature_128[5][c_baisc][k_basic] = feature_1024[c_location_5 * c_128_length + c_baisc][k_location_5 * k_128_length + k_basic];
			feature_128[6][c_baisc][k_basic] = feature_1024[c_location_6 * c_128_length + c_baisc][k_location_6 * k_128_length + k_basic];
			feature_128[7][c_baisc][k_basic] = feature_1024[c_location_7 * c_128_length + c_baisc][k_location_7 * k_128_length + k_basic];

			weight_128[0][c_baisc][k_basic] = weight_1024[c_location_0 * c_128_length + c_baisc][k_location_0 * k_128_length + k_basic];
			weight_128[1][c_baisc][k_basic] = weight_1024[c_location_1 * c_128_length + c_baisc][k_location_1 * k_128_length + k_basic];
			weight_128[2][c_baisc][k_basic] = weight_1024[c_location_2 * c_128_length + c_baisc][k_location_2 * k_128_length + k_basic];
			weight_128[3][c_baisc][k_basic] = weight_1024[c_location_3 * c_128_length + c_baisc][k_location_3 * k_128_length + k_basic];
			weight_128[4][c_baisc][k_basic] = weight_1024[c_location_4 * c_128_length + c_baisc][k_location_4 * k_128_length + k_basic];
			weight_128[5][c_baisc][k_basic] = weight_1024[c_location_5 * c_128_length + c_baisc][k_location_5 * k_128_length + k_basic];
			weight_128[6][c_baisc][k_basic] = weight_1024[c_location_6 * c_128_length + c_baisc][k_location_6 * k_128_length + k_basic];
			weight_128[7][c_baisc][k_basic] = weight_1024[c_location_7 * c_128_length + c_baisc][k_location_7 * k_128_length + k_basic];
		}
	}
	
	mac_128(feature_128[0], weight_128[0], sum_128_mac[0]);
	mac_128(feature_128[1], weight_128[1], sum_128_mac[1]);
	mac_128(feature_128[2], weight_128[2], sum_128_mac[2]);
	mac_128(feature_128[3], weight_128[3], sum_128_mac[3]);
	mac_128(feature_128[4], weight_128[4], sum_128_mac[4]);
	mac_128(feature_128[5], weight_128[5], sum_128_mac[5]);
	mac_128(feature_128[6], weight_128[6], sum_128_mac[6]);
	mac_128(feature_128[7], weight_128[7], sum_128_mac[7]);

	switch (DLA_MAC.cal_precision)
	{
	case 0:  c_128_length = 8;  k_128_length = 16; break;
	case 1:  c_128_length = 8;  k_128_length = 32; break;
	case 2:  c_128_length = 16; k_128_length = 32; break;
	case 3:  c_128_length = 16; k_128_length = 64; break;
	case 4:  c_128_length = 32; k_128_length = 64; break;
	default: c_128_length = 0;  k_128_length = 0 ; break;
	}

	switch (DLA_MAC.mac_partition)
	{
	case 0:
		for (int k_basic = 0; k_basic < k_128_length; k_basic++)
		{
			sum_1024_mac[0 * k_128_length + k_basic] = sum_128_mac[0][k_basic] + sum_128_mac[1][k_basic] + sum_128_mac[2][k_basic] + sum_128_mac[3][k_basic] +
													   sum_128_mac[4][k_basic] + sum_128_mac[5][k_basic] + sum_128_mac[6][k_basic] + sum_128_mac[7][k_basic];
		}
		break;
	case 1:
		for (int k_basic = 0; k_basic < k_128_length; k_basic++)
		{
			sum_1024_mac[0 * k_128_length + k_basic] = sum_128_mac[0][k_basic] + sum_128_mac[2][k_basic] + sum_128_mac[4][k_basic] + sum_128_mac[6][k_basic];
			sum_1024_mac[1 * k_128_length + k_basic] = sum_128_mac[1][k_basic] + sum_128_mac[3][k_basic] + sum_128_mac[5][k_basic] + sum_128_mac[7][k_basic];
		}
		break;
	case 2:
		for (int k_basic = 0; k_basic < k_128_length; k_basic++)
		{
			sum_1024_mac[0 * k_128_length + k_basic] = sum_128_mac[0][k_basic] + sum_128_mac[4][k_basic];
			sum_1024_mac[1 * k_128_length + k_basic] = sum_128_mac[1][k_basic] + sum_128_mac[5][k_basic];
			sum_1024_mac[2 * k_128_length + k_basic] = sum_128_mac[2][k_basic] + sum_128_mac[6][k_basic];
			sum_1024_mac[3 * k_128_length + k_basic] = sum_128_mac[3][k_basic] + sum_128_mac[7][k_basic];
		}
		break;
	case 3:
		for (int k_basic = 0; k_basic < k_128_length; k_basic++)
		{
			sum_1024_mac[0 * k_128_length + k_basic] = sum_128_mac[0][k_basic];
			sum_1024_mac[1 * k_128_length + k_basic] = sum_128_mac[1][k_basic];
			sum_1024_mac[2 * k_128_length + k_basic] = sum_128_mac[2][k_basic];
			sum_1024_mac[3 * k_128_length + k_basic] = sum_128_mac[3][k_basic];
			sum_1024_mac[4 * k_128_length + k_basic] = sum_128_mac[4][k_basic];
			sum_1024_mac[5 * k_128_length + k_basic] = sum_128_mac[5][k_basic];
			sum_1024_mac[6 * k_128_length + k_basic] = sum_128_mac[6][k_basic];
			sum_1024_mac[7 * k_128_length + k_basic] = sum_128_mac[7][k_basic];
		}
		break;
	default:
		break;
	}

}

void accu(long sum_1024_mac[512], long sum_1024_accu[512][1024], long feature_added_out[512][1024],
		  int kernel_xy_accu, int sliding_num_aacu)
	//sum_1024_mac[512]: [k]
	//sum_1024_accu[512][1024]: [k][sliding_num]
	//sliding_num: >=k & <=2k
{
	int c_mac_length;
	int k_mac_length;

	int c_128_length;
	int k_128_length;


	switch (DLA_ACCU.mac_partition)
	{
	case 0:  c_mac_length = 8;  k_mac_length = 1; break;
	case 1:  c_mac_length = 4;  k_mac_length = 2; break;
	case 2:  c_mac_length = 2;  k_mac_length = 4; break;
	case 3:  c_mac_length = 1;  k_mac_length = 8; break;
	default: c_mac_length = 0;  k_mac_length = 0; break;
	}

	switch (DLA_ACCU.cal_precision)
	{
	case 0:  c_128_length = 8;  k_128_length = 16; break;
	case 1:  c_128_length = 8;  k_128_length = 32; break;
	case 2:  c_128_length = 16; k_128_length = 32; break;
	case 3:  c_128_length = 16; k_128_length = 64; break;
	case 4:  c_128_length = 32; k_128_length = 64; break;
	default: c_128_length = 0;  k_128_length = 0; break;
	}

	for (int k = 0; k < (k_mac_length*k_128_length); k++)
	{
		long test_in_0 = sum_1024_accu[k][sliding_num_aacu];
		long test_in_1 = sum_1024_mac[k];
		sum_1024_accu[k][sliding_num_aacu] += sum_1024_mac[k];
		long test_out = sum_1024_accu[k][sliding_num_aacu];

		if (DLA_ACCU.truncate != 0)
		{
			sum_1024_accu[k][DLA_ACCU.sliding_num] = sum_1024_accu[k][DLA_ACCU.sliding_num] + (2 << (DLA_ACCU.truncate - 1));
			sum_1024_accu[k][DLA_ACCU.sliding_num] = sum_1024_accu[k][DLA_ACCU.sliding_num] >> DLA_ACCU.truncate;
		}
		if (DLA_ACCU.satuation != 0)
		{
			if (sum_1024_accu[k][DLA_ACCU.sliding_num] >= DLA_ACCU.satuation)
			{
				sum_1024_accu[k][DLA_ACCU.sliding_num] = DLA_ACCU.satuation;
			}
		}
	}

	if (kernel_xy_accu == DLA_ACCU.kernel_xy_num)
	{
		memcpy(feature_added_out, sum_1024_accu, sizeof(sum_1024_accu));
	}
}

//////for mac interface
int  feature_1024[256][512]; //[max c][max k]
int  weight_1024[256][512];  //[max c][max k]
long sum_1024_mac[512];      //[max k]

//////for accu interface
long sum_1024_accu[512][1024];
long feature_added_out[512][1024];


int main(int argc, char **argv)
{

	//////parameter setting	
	DLA_MAC.mac_partition = 0;
	DLA_MAC.cal_precision = 0;
	
	DLA_ACCU.mac_partition = 0;
	DLA_ACCU.cal_precision = 0;
	DLA_ACCU.truncate      = 2;
	DLA_ACCU.satuation     = 8;
	DLA_ACCU.sliding_num   = 0;
	DLA_ACCU.kernel_xy_num = 0;

	//////for mac interface
	int  kernel_xy_accu;
	int  sliding_num_aacu;

	//////data iinterface for debug
	kernel_xy_accu = 0;
	sliding_num_aacu = 0;
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			feature_1024[i][j] = 2;
			weight_1024[i][j] = 2;
		}
	}

	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			sum_1024_accu[i][j] = 0;
		}
	}


	csc2mac_data_convertor();

	mac_1024(feature_1024, weight_1024, sum_1024_mac);
	accu(sum_1024_mac, sum_1024_accu, feature_added_out, kernel_xy_accu, sliding_num_aacu);
	reshape();

	return 0;
}

void csc2mac_data_convertor(int csc2mac_dat[1024], int csc2mac_wt[1024])
{

	int feature_bit;
	int weight_bit;
	switch (DLA_ACCU.cal_precision)
	{
	case 0:  feature_bit = 16; weight_bit = 16; break;
	case 1:  feature_bit = 16; weight_bit = 8;  break;
	case 2:  feature_bit = 8;  weight_bit = 8;  break;
	case 3:  feature_bit = 8;  weight_bit = 4;  break;
	case 4:  feature_bit = 4;  weight_bit = 4; break;
	default: feature_bit = 0;  weight_bit = 0; break;
	}

	int feature[256];
	int weight[256];
	for (int i = 0; i < 256; i++)
	{
		feature[i] = 0;
		weight[i] = 0;
	}

	for (int i = 0; i < (1024 / feature_bit); i++)
	{
		for (int j = 0; j < feaure_bit; j++)
		{
			feature[i] += csc2mac_dat[i * feature_bit + j] << j;
		}
	}

	for (int i = 0; i < (1024 / weight_bit); i++)
	{
		for (int j = 0; j < weight_bit; j++)
		{
			feature[i] += csc2mac_wt[i * weight_bit + j] << j;
		}
	}
















}

