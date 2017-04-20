#ifndef _ADC_H_
#define _ADC_H_

#include "config.h"
#include "time.h"

#ifndef _ADC_C_
/*
  10位ADC输出数字量：ADValue = (模拟量/基准电压)*1023
  12位ADC输出数字量：ADValue = (模拟量/基准电压)*4095
  17位ADC输出数字量：ADValue = (模拟量/基准电压)*131071
*/
#endif

#define NULL_NUM (1000)//开路数字  4.98V
/******开关配置********/
#define SWITCH_AREA	(5)
#define SWITCH_0 (96)
#define SWITCH_1 (172)
#define SWITCH_2 (237)
#define SWITCH_3 (294)
#define SWITCH_4 (384)
#define SWITCH_5 (455)
#define SWITCH_6 (512)
#define SWITCH_7 (578)
#define SWITCH_8 (630)
/*********************/
/******电压配置*******/
#define VOL_GAP (5)
#define VOL_H1 (422)//运行电压+7
#define VOL_FIX (7)//停止电压
#define VOL_L1 (453)

#define VOL_HIGHT (515) //470V
#define VOL_LOW	(343)		//310v

#define VIL_LENGTH (20)

#define VOL_PING_PONG (70)
//电压低于 电压高于  1S内电压波动超过70V 均为输入故障
/*********************/
/******温度配置*******/
#define TEMP_GAP (1)
#define TEMP_JUMP (3)
#define TEMP_COIL (120)
#define TEMP_POT (180)
#define TEMP_SLOW_IGBT (70)
#define TEMP_IGBT (78)
/*********************/



//初始化
void init_adc();
void updata_adc();
//有无锅
bit get_no_p();
bit get_switch_cut();
uint4 get_coil();
uint4 get_pot();
uint4 get_igbt_one();
uint4 get_igbt_two();
uint4 get_check_vol(uint4 state,uint4 operation);
uint4 get_check_vol_on();
uint4 get_check_out_ampere();
//读取挡位
uint8 get_switch();
//读取线盘温度
int16 get_coil_temp();
//读取锅底温度
int16 get_pot_temp();
//读取NULL
int16 get_null_num();
//读取IGBT1温度
int16 get_igbt_one_temp();
//读取IGBT2温度
int16 get_igbt_two_temp();
//读取输入电流
uint16 get_in_ampere();
//读取输出电流
uint16 get_out_ampere();
//读取电压
uint16 get_vol();
//
uint16 get_adc(uint8 io);
int16 get_temp_by_anum(uint16 anum);
uint8 get_switch_by_anum(uint16 anum);
void ADCUpdate();
#endif
