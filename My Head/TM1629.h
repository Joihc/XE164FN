/*--------------------HOW TO USE
init_TM1629();//初始化
set_TM1629_Up(uint8 num);//设置KW数
set_TM1629_LeftNum(uint4 num);//设置左下角数
set_TM1629_Leftstring(uint4 num);//设置实际功率
set_TM1629_Down(0/num, 0/1);//0表示时间状态，1标识实际数字 支持9999
whileUpdate_TM1629();//循环更新
interuptUpdate_TM1629();//滴答
*/
#ifndef _TM1629_H_
#define _TM1629_H_

#include "config.h"
#include "time.h"
#include "other.h"

#ifndef _TM1629_C_

#endif



#define STB_0 (IO_vResetPin(IO_P10_11))//(P10_OUT_P11 = 0)
#define STB_1 (IO_vSetPin(IO_P10_11))//(P10_OUT_P11 = 1)
#define CLK_0 (IO_vResetPin(IO_P10_10))//(P10_OUT_P10 = 0)
#define CLK_1 (IO_vSetPin(IO_P10_10))//(P10_OUT_P10 = 1)
#define DIO_0 (IO_vResetPin(IO_P10_13))//(P10_OUT_P13 = 0)
#define DIO_1 (IO_vSetPin(IO_P10_13))//(P10_OUT_P13 = 1)

#define dissetmode 0x03
#define writedatamode_z 0x40 //采用地址加一方式写
#define startaddress 0xc0 //起始地址
#define disconmode 0x8C //显示控制 亮度 0x80-0x8F（8 9 A B C D E F）
#define datacount 16 //采用地址自动加一方式传输数据的个

void whileUpdate_TM1629();
void interuptUpdate_TM1629();
void init_TM1629();

void set_TM1629_Leftstring(unsigned char n);
void set_TM1629_LeftNum(unsigned char n);

void set_TM1629_TimeMark();
void set_TM1629_TempMark();
void set_TM1629_Waterg();
void set_TM1629_Fell();
void set_TM1629_Temp();
void set_TM1629_Pot();
void set_TM1629_Hot();
void set_TM1629_Pro();
void set_TM1629_Colon();
void set_TM1629_Phone();
void set_TM1629_Vlotage();
void set_TM1629_UpNum();
void set_TM1629_Kw();

void set_TM1629_Up(uint8 up);
void set_TM1629_Down(int16 num,uint4 trim);
void set_TM1629_SignNum(uint4 pos,uint4 marks);

void indate(unsigned char p);
void display(short state);
//void display2(unsigned char adress,unsigned char disa);
#endif
