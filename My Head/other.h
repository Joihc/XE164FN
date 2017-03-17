#ifndef _OTHER_H_
#define _OTHER_H_

#include "config.h"

#ifndef _OTHER_C_
#endif

#define BUZ_ON (IO_vSetPin(IO_P2_10))
#define BUZ_OFF (IO_vResetPin(IO_P2_10))

#define FAN_ON (IO_vSetPin(IO_P7_1))
#define FAN_OFF (IO_vResetPin(IO_P7_1))
#define FAN_ALL_TIME 60

#define LED_2_TOGGLE (IO_vTogglePin(IO_P7_3))
#defube LED_1_ON (IO_vResetPin(IO_P6_0))

void init_buz();
void buz_on(uint8 time);
//0.5s更新一次
void update_buz();
#endif
