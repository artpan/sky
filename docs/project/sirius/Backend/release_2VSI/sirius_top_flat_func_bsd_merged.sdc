#----func sdc----#
source -e sirius_top_flat.sdc.modified_by_vsi

#----BSD TCK----#
create_clock -name bsd_tck [get_ports GBE_RXEN_PAD] -period 100 -waveform {45 55} -add
create_clock -name bsd_virtual_clk -period 100 -waveform {0 50}

#----set clock unertainty----#
set_clock_uncertainty -setup 0.3 [get_clocks bsd_tck]
set_clock_uncertainty -hold 0.05 [get_clocks bsd_tck]

#----set clock groups----#
set_clock_groups -name bsd_tck -asynchronous \
	-group {bsd_tck bsd_virtual_clk}

#----remove bsd_mode case_analysis----#
remove_case_analysis [get_pins sirius_sub_top_inst/sirius_test_func_inst/u_cfg_mode_gen/u_mux2_bsd/X]
remove_case_analysis [get_pins bsd_mode_case_point/X]
set_case_analysis 0 [get_pins bsd_mode_top_buf/X]

#----io constraints----#
set io_under_test "\
DDR_DQ0 \
DDR_DQ1 \
DDR_DQ2 \
DDR_DQ3 \
DDR_DQS0 \
DDR_DQS0N \
DDR_DQ4 \
DDR_DQ5 \
DDR_DQ6 \
DDR_DQ7 \
DDR_DM0 \
DDR_DQ8 \
DDR_DQ9 \
DDR_DQ10 \
DDR_DQ11 \
DDR_DQS1 \
DDR_DQS1N \
DDR_DQ12 \
DDR_DQ13 \
DDR_DQ14 \
DDR_DQ15 \
DDR_DM1 \
DDR_DQ16 \
DDR_DQ17 \
DDR_DQ18 \
DDR_DQ19 \
DDR_DQS2 \
DDR_DQS2N \
DDR_DQ20 \
DDR_DQ21 \
DDR_DQ22 \
DDR_DQ23 \
DDR_DM2 \
DDR_DQ24 \
DDR_DQ25 \
DDR_DQ26 \
DDR_DQ27 \
DDR_DQS3 \
DDR_DQS3N \
DDR_DQ28 \
DDR_DQ29 \
DDR_DQ30 \
DDR_DQ31 \
DDR_DM3 \
DDR_A0 \
DDR_A1 \
DDR_A2 \
DDR_A3 \
DDR_A4 \
DDR_A5 \
DDR_A6 \
DDR_A7 \
DDR_A8 \
DDR_A9 \
DDR_A10 \
DDR_A11 \
DDR_A12 \
DDR_A13 \
DDR_A14 \
DDR_A15 \
DDR_A16 \
DDR_A17 \
DDR_CK \
DDR_CKN \
DDR_ACTN \
DDR_BA0 \
DDR_BA1 \
DDR_BG0 \
DDR_BG1 \
DDR_PARITY \
DDR_CSN0 \
DDR_CSN1 \
DDR_ODT0 \
DDR_ODT1 \
DDR_CKE0 \
DDR_CKE1 \
DDR_ALERTN \
DDR_RAM_RSTN \
DDR_DTO0 \
DDR_DTO1 \
DDR_DQ32 \
DDR_DQ33 \
DDR_DQ34 \
DDR_DQ35 \
DDR_DQS4 \
DDR_DQS4N \
DDR_DQ36 \
DDR_DQ37 \
DDR_DQ38 \
DDR_DQ39 \
DDR_DM4 \
DDR_DQ40 \
DDR_DQ41 \
DDR_DQ42 \
DDR_DQ43 \
DDR_DQS5 \
DDR_DQS5N \
DDR_DQ44 \
DDR_DQ45 \
DDR_DQ46 \
DDR_DQ47 \
DDR_DM5 \
DDR_DQ48 \
DDR_DQ49 \
DDR_DQ50 \
DDR_DQ51 \
DDR_DQS6 \
DDR_DQS6N \
DDR_DQ52 \
DDR_DQ53 \
DDR_DQ54 \
DDR_DQ55 \
DDR_DM6 \
DDR_DQ56 \
DDR_DQ57 \
DDR_DQ58 \
DDR_DQ59 \
DDR_DQS7 \
DDR_DQS7N \
DDR_DQ60 \
DDR_DQ61 \
DDR_DQ62 \
DDR_DQ63 \
DDR_DM7 \
GP0_PAD \
GP1_PAD \
GP2_PAD \
GP3_PAD \
GP4_PAD \
GP5_PAD \
GP6_PAD \
GP7_PAD \
I2C_SDA0_PAD \
I2C_SCLK0_PAD \
I2C_SDA1_PAD \
I2C_SCLK1_PAD \
I2C_SDA2_PAD \
I2C_SCLK2_PAD \
UART_RX0_PAD \
UART_TX0_PAD \
UART_RX1_PAD \
UART_TX1_PAD \
UART_RX2_PAD \
UART_TX2_PAD \
UART_RX3_PAD \
UART_TX3_PAD \
EMMC_CLKOUT_PAD \
EMMC_CCMD_PAD \
EMMC_PWR_PAD \
EMMC_D0_PAD \
EMMC_D1_PAD \
EMMC_D2_PAD \
EMMC_D3_PAD \
EMMC_D4_PAD \
EMMC_D5_PAD \
EMMC_D6_PAD \
EMMC_D7_PAD \
GBE_TXC_PAD \
GBE_TXEN_PAD \
GBE_TXD0_PAD \
GBE_TXD1_PAD \
GBE_RXD1_PAD \
GBE_RXD2_PAD \
GBE_RXD3_PAD \
GBE_MDC_PAD \
GBE_MDIO_PAD \
GBE_INT_PAD \
GBE_CLK_PAD \
GBE_RST_PAD \
SD_CCLK_OUT_PAD \
SD_CCMD_PAD \
SD_CARD_DETECT_N_PAD \
SD_CARD_WPRT_PAD \
SD_CDATA_0_PAD \
SD_CDATA_1_PAD \
SD_CDATA_2_PAD \
SD_CDATA_3_PAD \
UART_SIN4_PAD \
UART_SOUT4_PAD \
PWM2_PAD \
PWM4_PAD \
PWM5_PAD \
PWM6_PAD \
PWM7_PAD \
PWM8_PAD \
PWM9_PAD \
I2C_SDA3_PAD \
I2C_SCLK3_PAD \
I2C_SDA4_PAD \
I2C_SCLK4_PAD \
SPI_M0_DI_PAD \
SPI_M0_DO_PAD \
SPI_M0_SCLK_PAD \
SPI_M0_CSN_PAD \
SPI_M1_DI_PAD \
SPI_M1_DO_PAD \
SPI_M1_SCLK_PAD \
SPI_M1_CSN_PAD \
SPI_M2_DI_PAD \
SPI_M2_DO_PAD \
SPI_M2_SCLK_PAD \
SPI_M2_CS0N_PAD \
SPI_MS3_DI_PAD \
SPI_MS3_DO_PAD \
SPI_MS3_SCLK_PAD \
SPI_MS3_CS0N_PAD \
SPI_MS3_CS1N_PAD \
SPI_MS3_CS2N_PAD \
SPI_MS3_CS3N_PAD \
SPI_MS3_CS4N_PAD \
I2S_WS0_PAD \
I2S_SDI0_PAD \
I2S_SDO0_PAD \
I2S_CLK0_PAD \
I2S_WS1_PAD \
I2S_SDI1_PAD \
I2S_SDO1_PAD \
I2S_CLK1_PAD \
I2S_WS2_PAD \
I2S_SDI2_PAD \
I2S_SDO2_PAD \
I2S_CLK2_PAD \
I2S_WS3_PAD \
I2S_SDI3_PAD \
I2S_SDO3_PAD \
I2S_CLK3_PAD \
PCLK1_PAD \
DE1_PAD \
VSYNC1_PAD \
HSYNC1_PAD \
QE1_0_PAD \
QE1_1_PAD \
QE1_2_PAD \
QE1_3_PAD \
QE1_4_PAD \
QE1_5_PAD \
QE1_6_PAD \
QE1_7_PAD \
PCLK0_PAD \
DE0_PAD \
VSYNC0_PAD \
HSYNC0_PAD \
QE0_0_PAD \
QE0_1_PAD \
QE0_2_PAD \
QE0_3_PAD \
QE0_4_PAD \
QE0_5_PAD \
QE0_6_PAD \
QE0_7_PAD \
USB_OC_PAD \
USB_PWR_PAD \
HDMI_SCL_PAD \
HDMI_SDA_PAD \
HDMI_CEC_PAD \
"

set jtag_io_input "\
GBE_RXC_PAD \
GBE_RXEN_PAD \
GBE_TXD2_PAD \
GBE_TXD3_PAD \
"

set jtag_io_output "GBE_RXD0_PAD"

set_input_delay 5 -max -clock bsd_virtual_clk [get_ports "$io_under_test $jtag_io_input"] -add
set_input_delay 0 -min -clock bsd_virtual_clk [get_ports "$io_under_test $jtag_io_input"] -add
set_output_delay [expr 5 + 3] -max -clock bsd_tck [get_ports "$io_under_test $jtag_io_output"] -add

#----disable mbist timing check----#
set blocks_hier "sirius_asic_top_baseband_inst \
luxury_isp_top_inst \
hevc_top_inst \
sirius_sub_1_inst \
sirius_sub_2_inst \
sirius_sub_3_inst \
sirius_sub_4_inst \
sirius_sub_ceva_inst \
sirius_sub_ceva_inst/cevaxm4_subsys_inst/u_cevaxm4_harden_subsys/u_cevaxm4_core_3/u_cevaxm4_top \
sirius_sub_ceva_inst/cevaxm4_subsys_inst/u_cevaxm4_harden_subsys/u_cevaxm4_core_2/u_cevaxm4_top \
sirius_sub_ceva_inst/cevaxm4_subsys_inst/u_cevaxm4_harden_subsys/u_cevaxm4_core_1/u_cevaxm4_top \
sirius_sub_ceva_inst/cevaxm4_subsys_inst/u_cevaxm4_harden_subsys/u_cevaxm4_core_0/u_cevaxm4_top \
sirius_sub_ca7_inst/a7_subsystem_inst/u_a7_harden_subsystem"

foreach block_hier $blocks_hier {
  puts "VSI_INFO: disable mbist logic in $block_hier:" 
  #disable top mbist:
  set_case_analysis 0 [get_pins "$block_hier/LV_TM"]
  
  # Reset the WTAP
  set_case_analysis 0 [get_pins "$block_hier/LV_WRSTN"]
  set_case_analysis 0 [get_pins "$block_hier/LV_WRCK"]
  set_false_path -from [get_pins "$block_hier/LV_SelectWIR"]
  set_false_path -from [get_pins "$block_hier/LV_EnableWR"]
  set_false_path -from [get_pins "$block_hier/LV_ShiftWR"]
  
  #disable mbist logic:
  if {[regexp "luxury_isp_top_inst" $block_hier] == 1} {
    set_case_analysis  0 $block_hier/u_isp_core/LVISION_WTAP_INST/LVISION_WTAP_IR_REG/INST_INT_reg_*_/Q
  } elseif {[regexp "hevc_top_inst" $block_hier] == 1} {
    set_case_analysis  0 $block_hier/uhevc_core/LVISION_WTAP_INST/LVISION_WTAP_IR_REG/INST_INT_reg_*_/Q
  } else {
    set_case_analysis  0 $block_hier/LVISION_WTAP_INST/LVISION_WTAP_IR_REG/INST_INT_reg_*_/Q
  }
  puts "VSI_INFO: disable mbist logic in $block_hier end." 
}
