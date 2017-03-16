#ifndef _74HC164_H_
#define _74HC164_H_

#include "config.h"
#include "time.h"
#include "other.h"

#ifndef _74HC164_C_

enum LED_STATE
{
  OFF,
  ON,
  FLUSH
};

#endif




#define DAT_1 (IO_vSetPin(IO_P10_11))//(P10_OUT_P11 = 1)
#define DAT_0 (IO_vResetPin(IO_P10_11))//(P10_OUT_P11 = 0)

#define CLK_1 (IO_vSetPin(IO_P10_10))//(P10_OUT_P10 = 1)
#define CLK_0 (IO_vResetPin(IO_P10_10))//(P10_OUT_P10 = 0)

//红灯显示
#define COM_1_1 (IO_vSetPin(IO_P10_13))//(P10_OUT_P13 = 1)
#define COM_1_0 (IO_vResetPin(IO_P10_13))//(P10_OUT_P13 = 0)
#define COM_COM_1 (IO_vTogglePin(IO_P10_10))//(P10_OUT_P10=~P10_OUT_P10)

//数字显示开关
#define COM_2_1 (IO_vSetPin(IO_P10_15))//(P10_OUT_P15 = 1)
#define COM_2_0 (IO_vResetPin(IO_P10_15))//(P10_OUT_P15 = 0)


void setNum_74HC164(uint8 num);
void init_74HC164();
void whileUpdate_74HC164();
void interuptUpdate_74HC164();

static void display();

#endif
