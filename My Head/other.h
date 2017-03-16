#ifndef _OTHER_H_
#define _OTHER_H_

#include "config.h"

#ifndef _OTHER_C_
#endif

#define BUZON (IO_vSetPin(IO_P2_10))
#define BUZOFF (IO_vResetPin(IO_P2_10))

void init_buz();
void buz_on(unsigned short time);
//0.5s更新一次
void update_buz();
#endif
