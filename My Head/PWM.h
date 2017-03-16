#ifndef _PWM_H_
#define _PWM_H_

#include "config.h"
#include "adc.h"

#ifndef _PWM_C_
#endif

/*   28KHZ   17 -30KHZ  0.9V-3V·
  0->0V
  1->0.9V->184.14
  2->1.2V->245.52
  3->1.5V->306.9
  4->1.8V->368.28
  5->2.1V->429.66
  6->2.4V->471.04
  7->2.7V->552.42
  8->3.0V->613.8
*/
#define PWM1 (35)
#define PWM2 (70)
#define PWM3 (110)
#define PWM4 (140)
#define PWM5 (170)
#define PWM6 (200)
#define PWM7 (230)
#define PWM8 (250)
// CCU60_T12PR=0x095F -16.66    0x0476 -35KHZ
#define PWM_MIN (0x0476) //35KHZ  1142
#define PWM_MAX (0x0960) //16.66KHZ  2400

void initPWM();
void fixPWM(uint8 index);

void openPWM();
void stopPWM();

void setTmrPeriod(uint4 add);
void PWMTest(uint8 test);
uint4 getPWMRate();
uint16 clamp(uint16 num);

#endif /* _PWM_H_ */
