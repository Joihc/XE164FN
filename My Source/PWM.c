#define _PWM_C_

#include "PWM.h"

uint16 pwm =PWM_MIN;//	// CCU60_T12PR=0x095F -16.66    0x0476 -35KHZ

void initPWM()
{
  pwm=PWM_MIN;
}

void fixPWM(uint8 index)
{
    uint16 outCurrent = get_out_ampere();//输出互感器
    uint16 inCurrent = get_in_ampere();//输入互感器

}

void openPWM()
{
		CCU60_ISR |= 0x0400;//trap  复位强制中断		
		////CCU60_MODCTR |=	0x0003;	//调制输出
		CCU60_vStartTmr(CCU60_TIMER_12);
}
void stopPWM()
{
		CCU60_ISS |= 0x0400;//trap  强制中断
		//CCU60_vStopTmr(CCU60_TIMER_12);
		//CCU60_MODCTR	&= 0xFFFC;	//不调制
		pwm=PWM_MIN;
}
void PWMTest(uint8 test)
{
	if(test  == 0)
	{
		stopPWM();
	}
	else if(test == 1)
	{	
		setTmrPeriod(TRUE);
		openPWM();
	}
	else
	{
		setTmrPeriod(FALSE);
		openPWM();
	}				
}

void setTmrPeriod(uint4 add)
{
		pwm = add?clamp(++pwm):clamp(--pwm);
		CCU60_vSetTmrPeriod(CCU60_TIMER_12,pwm);
		CCU60_CC60SR=pwm/2;
		CCU60_vEnableShadowTransfer(CCU60_TIMER_12);
}
uint4 getPWMRate()
{
  uint16 range  = get_out_ampere();
  if(range>PWM8)
  {
    return 8;
  }
  else if(range>PWM7)
  {
    return 7;
  }
  else if(range>PWM6)
  {
    return 6;
  }
  else if(range>PWM5)
  {
    return 5;
  }
  else if(range>PWM4)
  {
    return 4;
  }
  else if(range>PWM3)
  {
    return 3;
  }
  else if(range>PWM2)
  {
    return 2;
  }
  else if(range>PWM1-5)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
uint16 clamp(uint16 num)
{
  if(num<PWM_MIN)
  {
    return PWM_MIN;
  }
  else if(num >PWM_MAX)
  {
    return PWM_MAX;
  }
  return num;
}
