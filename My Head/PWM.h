#ifndef _PWM_H_
#define _PWM_H_

#include "config.h"
#include "adc.h"
#include "main.h"

#ifndef _PWM_C_
#endif

#define PWM1 (35)
#define PWM2 (70)
#define PWM3 (110)
#define PWM4 (140)
#define PWM5 (170)
#define PWM6 (200)
#define PWM7 (230)
#define PWM8 (250)
// CCU60_T12PR=0x095F -16.66    0x0476 -35KHZ
#define PWM_MIN (0x0577) //28KHZ 1399
#define PWM_MAX  (0x0960) //16.66KHZ  2400
//(0x0476) //35KHZ  1142
//(0x0527)  //30KHZ
//(0x0577) //28KHZ 1399
//(0x0897)//18KHZ 2199
//(0x0960) //16.66KHZ  2400

void fixPWM(uint8 index);

bit PWMRun();
void openPWM();
void stopPWM();
void setPWMState();

void setTmrPeriod(bit add);
void PWMTest(uint8 test);
uint4 getPWMRate();
uint16 clamp(uint16 num);

#endif /* _PWM_H_ */
