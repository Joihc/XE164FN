#define _PWM_C_

#include "PWM.h"

uint16 pwm =PWM_MIN;//	// CCU60_T12PR=0x095F -16.66    0x0476 -35KHZ
uint4 run = 0;//1 run  0stop

void fixPWM(uint8 index)
{
    uint16 outCurrent = get_out_ampere();//输出互感器
    uint16 inCurrent = get_in_ampere();//输入互感器
		uint16 p=0;
    switch(index)
    {
      case 0:
						stopPWM();
      return;
          case 1:
            p = PWM1;
      break;
          case 2:
            p = PWM2;
      break;
          case 3:
            p = PWM3;
      break;
          case 4:
            p = PWM4;
      break;
          case 5:
            p = PWM5;
      break;
          case 6:
            p = PWM6;
      break;
          case 7:
            p = PWM7;
      break;
          case 8:
            p = PWM8;
      break;
    }
    //if((inCurrent < RETURN_PWM) && (pwm > PWM_RETURN))
    //{
    //  --pwm;
    //}
    //else
    //{
    //if(!(P3INT & 0x0C))
    //{
    //  pwm -= 1;
     // P3INT |= 0x08;//开启中断
    //}
    //else 
    //{
      if(inCurrent !=0 && (outCurrent*4/inCurrent>=3))
      {
        //--pwm;
				setTmrPeriod(FALSE);
      }
      else
      {
        if(outCurrent<(p-2))
        {
          //++pwm;
					setTmrPeriod(TRUE);
        }
        else if(outCurrent>(p+2))
        {
          //--pwm;
					setTmrPeriod(FALSE);
        }
      }
    openPWM();
}

bit PWMRun()
{
	return run;
}
void openPWM()
{
	  CCU60_ISR |= 0x0400;//trap  软件复位		
		CCU60_vStartTmr(CCU60_TIMER_12);
	//IO_vSetPin(IO_P10_7);//REST 硬件复位
		run = 1;
}
void stopPWM()
{
		CCU60_ISS |= 0x0400;//trap  软件复位
		pwm=PWM_MIN;
	//IO_vResetPin(IO_P10_7);//REST 硬件复位
		run = 0;
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
