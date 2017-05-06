/*--------------------HOW TO USE
TM1629A
*/
#ifndef _KJ153852_H_
#define _KJ153852_H_

#include "config.h"
#include "time.h"
#include "other.h"

#ifndef _KJ153852_C_

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

#define DIS_TIME 5 //5S更新


void whileUpdate_KJ153852();
void interuptUpdate_KJ153852();
void init_KJ153852();
void KJ153852_500ms();
void set_KJ153852(uint16 num,uint8 fire,int16 vol,int16 lt,int16 pt,int16 it);

//void display2(unsigned char adress,unsigned char disa);
#endif
