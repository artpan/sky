#DONT CARE
$DONT_CARE = 99;
#----------SUB2SUB----------#
$ABB2BB_SKEW = 1;

#----------INPUT----------#
#DVP IN
$DVP_IN_CLK_SKEW  = 2.1;
$DVP_IN_DATA_SKEW = 0.5;
#SD IN
$SD_IN_DATA_SKEW = 0.2;
#EMMC IN
$EMMC_IN_DATA_SKEW = 0.5;
#ETH IN
$ETH_IN_DATA_SKEW = 0.5 ;
#FLASH IN
$FLASH_IN_CLK_SKEW = 0.2; 
$FLASH_IN_DATA_SKEW = 0.2;
#I2S MST IN
$I2S_MST_CLK_SKEW = 1;
$I2S_MST_DATA_SKEW = 0.5;
#----------OUTPUT----------#
#EMMC OUT
$EMMC_OUT_CLK_SKEW  = 0.5;
$EMMC_OUT_DATA_SKEW = 0.2;
#SD OUT
$SD_OUT_CLK_SKEW  = 0.5;
$SD_OUT_DATA_SKEW = 0.5;
#TRACE 
$TRACE_OUT_CLK_SKEW = 1;
$TRACE_OUT_DATA_SKEW = 0.65;
#ETH
$ETH_OUT_CLK_SKEW  = 0.3;
$ETH_OUT_DATA_SKEW = 0.2;
#DVP
$DVP_OUT_CLK_SKEW = 1.2;
$DVP_OUT_DATA_SKEW = 0.8;
#FLASH
$FLASH_OUT_CLK_SKEW = 0.5; 
$FLASH_OUT_DATA_SKEW = 0.5;
#I2S GBE_PAD
$I2S_GBE_OUT_CLK_SKEW  =  1;
$I2S_GBE_OUT_DATA_SKEW = 1;
#I2S I2S_PAD
$I2S_I2S_OUT_CLK_SKEW  =  1;
$I2S_I2S_OUT_DATA_SKEW = 1;
#HDMI GBE_PAD
$HDMI_GBE_OUT_CLK_SKEW  =  1;
$HDMI_GBE_OUT_DATA_SKEW = 1;
#HDMI I2S_PAD
$HDMI_I2S_OUT_CLK_SKEW  =  1;
$HDMI_I2S_OUT_DATA_SKEW = 1;
#I2S SLV OUT    #not clk balance
$I2S_SLV_OUT_CLK_SKEW = 1;
$I2S_SLV_OUT_DATA_SKEW = 1;




%hash = (
'input_fall_from_CLK_DVP_0_PAD_through_PAD_fall_to_CLK_DVP_0_PAD.rpt.skew'                        => [$DVP_IN_CLK_SKEW,  $DVP_IN_DATA_SKEW ],
'input_fall_from_CLK_DVP_1_PAD_through_PAD_fall_to_CLK_DVP_1_PAD.rpt.skew'                        => [$DVP_IN_CLK_SKEW,  $DVP_IN_DATA_SKEW ],
'input_fall_from_vir_CLK_SD_CKIN_SAMPLE_fall_to_CLK_SD_CKIN_SAMPLE.rpt.skew'                      => [$DONT_CARE,        $SD_IN_DATA_SKEW  ],
'input_fall_from_vir_CLK_SD_CKIN_SAMPLE_rise_to_CLK_SD_CKIN_SAMPLE.rpt.skew'                      => [$DONT_CARE,        $SD_IN_DATA_SKEW  ],
'input_fall_from_vir_clk_emmc_pad_1_fall_to_CLK_EMMC_PAD_0.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_clk_emmc_pad_1_fall_to_CLK_EMMC_PAD_1.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_clk_emmc_pad_1_fall_to_CLK_EMMC_PAD_2.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_0.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_1.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_2.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_fall_from_vir_eth_fall_to_rgmii_rx_clk_i.rpt.skew'                                         => [$DONT_CARE,        $ETH_IN_DATA_SKEW ],
'input_from_GP_PAD_to_sirius_asic_top_baseband_inst_SPI.rpt.skew'                                 => [$DONT_CARE,        $DONT_CARE        ],
'input_from_all_inputs_no_GP_PAD_to_sirius_asic_top_baseband_inst_SPI.rpt.skew'                   => [$DONT_CARE,        $DONT_CARE        ],
'input_rise_from_CLK_DVP_0_PAD_through_PAD_rise_to_CLK_DVP_0_PAD.rpt.skew'                        => [$DVP_IN_CLK_SKEW,  $DVP_IN_DATA_SKEW ],
'input_rise_from_CLK_DVP_1_PAD_through_PAD_rise_to_CLK_DVP_1_PAD.rpt.skew'                        => [$DVP_IN_CLK_SKEW,  $DVP_IN_DATA_SKEW ],
'input_rise_from_vir_CLK_M7_FLASH_rise_to_CLK_M7_FLASH.rpt.skew'                                  => [$FLASH_IN_CLK_SKEW,$FLASH_IN_DATA_SKEW],
'input_rise_from_vir_CLK_SD_CKIN_SAMPLE_fall_to_CLK_SD_CKIN_SAMPLE.rpt.skew'                      => [$DONT_CARE,        $SD_IN_DATA_SKEW  ],
'input_rise_from_vir_CLK_SD_CKIN_SAMPLE_rise_to_CLK_SD_CKIN_SAMPLE.rpt.skew'                      => [$DONT_CARE,        $SD_IN_DATA_SKEW  ],
'input_rise_from_vir_clk_emmc_pad_1_fall_to_CLK_EMMC_PAD_1.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_rise_from_vir_clk_emmc_pad_1_fall_to_CLK_EMMC_PAD_2.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_rise_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_0.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_rise_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_1.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_rise_from_vir_clk_emmc_pad_1_rise_to_CLK_EMMC_PAD_2.rpt.skew'                              => [$DONT_CARE,        $EMMC_IN_DATA_SKEW],
'input_rise_from_vir_eth_rise_to_rgmii_rx_clk_i.rpt.skew'                                         => [$DONT_CARE,        $ETH_IN_DATA_SKEW ],
'input_through_GBE_PAD_fall_from_i2s_sclk_in_rise_to_inner_i2s_sclk_in.rpt.skew'                  => [$DONT_CARE,        $DONT_CARE        ],
'input_through_GBE_PAD_fall_from_vir_i2s_sclk_out_rise_to_clocks.rpt.skew'                        => [$DONT_CARE,        $DONT_CARE	   ],
'input_through_I2S_PAD_fall_from_i2s_sclk_in_rise_to_inner_i2s_sclk_in.rpt.skew'                  => [$DONT_CARE,        $DONT_CARE        ],
'input_through_I2S_PAD_fall_from_vir_i2s_sclk_out_rise_to_clocks.rpt.skew'                        => [$DONT_CARE,        $DONT_CARE        ],
'input_through_u_t28_abb_top_ADC_to_sirius_asic_top_baseband_inst.rpt.skew'                       => [$DONT_CARE,        $ABB2BB_SKEW      ],
'output_fall_from_CLK_EMMC_PAD_0_fall_to_CLK_EMMC_PAD_2_OUT.rpt.skew'                             => [$EMMC_OUT_CLK_SKEW,$EMMC_OUT_DATA_SKEW],
'output_fall_from_CLK_SD_200_fall_to_CLK_SD_CKIN_DRV_OUT.rpt.skew'                                => [$SD_OUT_CLK_SKEW,  $SD_OUT_DATA_SKEW ],
'output_fall_from_sd_cclk_out_fall_to_CLK_SD_CKIN_DRV_OUT.rpt.skew'                               => [$SD_OUT_CLK_SKEW,  $SD_OUT_DATA_SKEW ],
'output_from_sirius_asic_top_baseband_inst_SPI_to_all_outputs_no_gbe_pad.rpt.skew'                => [$DONT_CARE,        $DONT_CARE        ],
'output_from_sirius_asic_top_baseband_inst_SPI_to_gbe_pad.rpt.skew'                               => [$DONT_CARE,        $DONT_CARE        ],
'output_rise_from_CLK_CFG_250_fall_to_traceclkout.rpt.skew'                                       => [$TRACE_OUT_CLK_SKEW,$TRACE_OUT_DATA_SKEW],
'output_rise_from_CLK_CFG_250_rise_to_traceclkout.rpt.skew'                                       => [$TRACE_OUT_CLK_SKEW,$TRACE_OUT_DATA_SKEW],
'output_rise_from_CLK_CORE_GMAC_fall_to_tx_output_clock.rpt.skew'                                 => [$ETH_OUT_CLK_SKEW,  $ETH_OUT_DATA_SKEW],
'output_rise_from_CLK_CORE_GMAC_rise_to_tx_output_clock.rpt.skew'                                 => [$ETH_OUT_CLK_SKEW,  $ETH_OUT_DATA_SKEW],
'output_rise_from_CLK_DVP_PIX_fall_to_CLK_DVP_PIX_OUT0.rpt.skew'                                  => [$DVP_OUT_CLK_SKEW,  $DVP_OUT_DATA_SKEW],
'output_rise_from_CLK_DVP_PIX_rise_to_CLK_DVP_PIX_OUT0.rpt.skew'                                  => [$DVP_OUT_CLK_SKEW+3.3,  $DVP_OUT_DATA_SKEW],
'output_rise_from_CLK_EMMC_PAD_0_rise_to_CLK_EMMC_PAD_2_OUT.rpt.skew'                             => [$EMMC_OUT_CLK_SKEW,$EMMC_OUT_DATA_SKEW],
'output_rise_from_CLK_M7_FLASH_fall_to_qspi_sclk_pad.rpt.skew'                                    => [$FLASH_OUT_CLK_SKEW,$FLASH_OUT_DATA_SKEW],
'output_rise_from_CLK_M7_FLASH_rise_to_qspi_sclk_pad.rpt.skew'                                    => [$FLASH_OUT_CLK_SKEW,$FLASH_OUT_DATA_SKEW],
'output_rise_from_CLK_SD_200_rise_to_CLK_SD_CKIN_DRV_OUT.rpt.skew'                                => [$SD_OUT_CLK_SKEW,  $SD_OUT_DATA_SKEW  ],
'output_rise_from_CLK_SD_CKIN_DRV_rise_to_CLK_SD_CKIN_DRV_OUT.rpt.skew'                           => [$SD_OUT_CLK_SKEW,  $SD_OUT_DATA_SKEW  ],
'output_rise_from_CLK_SUB_1_2X_PIX_fall_to_CLK_DVP_PIX_OUT0.rpt.skew'                             => [$DVP_OUT_CLK_SKEW, $DVP_OUT_DATA_SKEW ],
'output_rise_from_CLK_SUB_1_2X_PIX_rise_to_CLK_DVP_PIX_OUT0.rpt.skew'                             => [$DVP_OUT_CLK_SKEW, $DVP_OUT_DATA_SKEW ],
'output_rise_from_sd_cclk_out_rise_to_CLK_SD_CKIN_DRV_OUT.rpt.skew'                               => [$SD_OUT_CLK_SKEW,  $SD_OUT_DATA_SKEW  ],
'output_through_GBE_PAD_fall_from_i2s_sclk_out_3_tmp1_fall_to_i2s_sclk_out_gbe_pad.rpt.skew'      => [$I2S_GBE_OUT_CLK_SKEW, $I2S_GBE_OUT_DATA_SKEW ],
'output_through_GBE_PAD_fall_from_i2s_sclk_out_fall_to_i2s_sclk_out_gbe_pad.rpt.skew'             => [$I2S_GBE_OUT_CLK_SKEW, $I2S_GBE_OUT_DATA_SKEW ],
'output_through_GBE_PAD_fall_from_inner_i2s_sclk_in_rise_to_i2s_sclk_in_gbe.rpt.skew'             => [$DONT_CARE,        $DONT_CARE         ],
'output_through_GBE_PAD_rise_from_CLK_AUDIO_div_buf_fall_to_hdmi_typec_i2s_sclk_gbe_pad.rpt.skew' => [$HDMI_GBE_OUT_CLK_SKEW,$HDMI_GBE_OUT_DATA_SKEW],
'output_through_I2S_PAD_fall_from_i2s_sclk_out_3_tmp1_fall_to_i2s_sclk_out_pad.rpt.skew'          => [$I2S_I2S_OUT_CLK_SKEW, $I2S_I2S_OUT_DATA_SKEW ],
'output_through_I2S_PAD_fall_from_i2s_sclk_out_fall_to_i2s_sclk_out_pad.rpt.skew'                 => [$I2S_I2S_OUT_CLK_SKEW, $I2S_I2S_OUT_DATA_SKEW ],
'output_through_I2S_PAD_fall_from_inner_i2s_sclk_in_rise_to_i2s_sclk_in.rpt.skew'                 => [$DONT_CARE,        $DONT_CARE         ],
'output_through_I2S_PAD_rise_from_CLK_AUDIO_div_buf_fall_to_hdmi_typec_i2s_sclk_pad.rpt.skew'     => [$HDMI_I2S_OUT_CLK_SKEW,$HDMI_I2S_OUT_DATA_SKEW]
);

opendir(DIR, "./") or die "Error open ./";
while($file = readdir(DIR)) {
  if($file=~/\.rpt$/) {
   @values = (); 
   @value_b2s = (); 
   open(FILE, "<$file") or die "Error open $file";
    while(<FILE>) {
      if($_=~/(\w+)\s+([\w|\/|\[|\]]+)\s+([\-]*[\.|\d]+)/) {
        push(@values, $3);
      }
    }
    @value_b2s=sort {$a<=>$b} @values;
    open(FILEW, ">$file\.skew");
    printf(FILEW pop(@value_b2s));
    printf(FILEW "\n");
    printf(FILEW shift(@value_b2s));
  }
}






foreach $key (keys %hash) {
  open(FILE, "<$key") or die "Error open $key";
  $tmp = <FILE>;
  $tmp1 = <FILE>;
  chomp($tmp);
  chomp($tmp1);
  $delta = $tmp - $tmp1;
##  print(abs($tmp1));
##  print(abs($tmp));
##  print("%f\n",$hash{$key}->[1]);
  if( abs($tmp1) > ($hash{$key}->[0]) || abs($tmp) > ($hash{$key}->[0]) || abs($delta) > ($hash{$key}->[1])  ) {
          open(FILEW, ">$key\.vio") or die "Error open $key";
          if (abs($tmp) > ($hash{$key}->[0]) ){
              printf(FILEW "absolute value violation : %f > %f\n", $tmp, $hash{$key}->[0]);
          }
          if (abs($tmp1) > ($hash{$key}->[0]) ){
              printf(FILEW "absolute value violation : %f > %f\n", $tmp1, $hash{$key}->[0]);
          }
          if (abs($delta) > ($hash{$key}->[1])){
              printf(FILEW "skew value violation: %f > %f\n", abs($delta), $hash{$key}->[1]);
          }
          close(FILEW);
  }
  close(FILE);
}



### EMMC EN ###
open(emmc_en_file,"<emmc_out_en.rpt.skew");
open(emmc_file,"output_rise_from_CLK_EMMC_PAD_0_rise_to_CLK_EMMC_PAD_2_OUT.rpt.skew");
$tmp_emmc_en  = <emmc_en_file>;
$tmp_emmc_en1 = <emmc_en_file>;
$tmp_emmc     = <emmc_file>;
$tmp_emmc1    = <emmc_file>;
if($tmp_emmc_en1 < $tmp_emmc1){
    print("aaaaa\n");
    open(emmc_en_vio_file,">emmc_out_en.rpt.skew\.vio");
    printf(emmc_en_vio_file "emmc_out_en delay %f is slower than data delay %f\n", $tmp_emmc_en1, $tmp_emmc1);
    close(emmc_en_vio_file);
}
close(emmc_en_file);
close(emmc_file);

### SD EN ###
open(sd_en_file,"<sd_out_en.rpt.skew");
open(sd_file1,"output_fall_from_CLK_SD_200_fall_to_CLK_SD_CKIN_DRV_OUT.rpt.skew");
open(sd_file2,"output_rise_from_CLK_SD_200_rise_to_CLK_SD_CKIN_DRV_OUT.rpt.skew");
$tmp_sd_en  = <sd_en_file>;
$tmp_sd_en1 = <sd_en_file>;
$tmp_sd1    = <sd_file1>;
$tmp_sd1_1  = <sd_file1>;
$tmp_sd2    = <sd_file2>;
$tmp_sd2_1  = <sd_file2>;
if($tmp_sd_en1 < $tmp_sd1_1 || $tmp_sd_en1 < $tmp_sd2_1) {
    open(sd_en_vio_file,">sd_out_en.rpt.skew\.vio");
    if($tmp_sd_en1 < $tmp_sd1_1){
        printf(sd_en_vio_file "sd_out_en delay %f is slower than data delay %f by clock fall edge\n", $tmp_sd_en1, $tmp_sd1_1);
    }
    if($tmp_sd_en1 < $tmp_sd2_1){ 
        printf(sd_en_vio_file "sd_out_en delay %f is slower than data delay %f by clock rise edge\n", $tmp_sd_en1, $tmp_sd2_1);
    }
    close(sd_en_vio_file);
}
close(sd_en_file);
close(sd_file1);
close(sd_file2);


### QSPI EN ###
open(qspi_en_file,"<qspi_out_en.rpt.skew");
open(qspi_file1,"output_rise_from_CLK_M7_FLASH_rise_to_qspi_sclk_pad.rpt");
open(qspi_file2,"output_rise_from_CLK_M7_FLASH_fall_to_qspi_sclk_pad.rpt");
$tmp_qspi_en  = <qspi_en_file>;
$tmp_qspi_en1 = <qspi_en_file>;
$tmp_qspi1    = <qspi_file1>;
$tmp_qspi1_1  = <qspi_file1>;
$tmp_qspi2    = <qspi_file2>;
$tmp_qspi2_1  = <qspi_file2>;
if($tmp_qspi_en1 < $tmp_qspi1_1 || $tmp_qspi_en1 < $tmp_qspi2_1) {
    open(qspi_en_vio_file,">qspi_out_en.rpt.skew\.vio");
    if($tmp_qspi_en1 < $tmp_qspi1_1){
        printf(qspi_en_vio_file "qspi_out_en delay %f is slower than data delay %f by clock fall edge\n", $tmp_qspi_en1, $tmp_qspi1_1);
    }
    if($tmp_qspi_en1 < $tmp_qspi2_1){ 
        printf(qspi_en_vio_file "qspi_out_en delay %f is slower than data delay %f by clock rise edge\n", $tmp_qspi_en1, $tmp_qspi2_1);
    }
    close(qspi_en_vio_file);
}
close(qspi_en_file);
close(qspi_file1);
close(qspi_file2);

1
