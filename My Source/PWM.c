#define _PWM_C_

#include "PWM.h"

static volatile uint16 pwm =PWM_MIN;//	// CCU60_T12PR=0x095F -16.66    0x0476 -35KHZ
static bit pwm_run =0;//0关闭 1开启
static bit pwm_state = 0;

void fixPWM(uint8 index)
{
    uint16 outCurrent = get_out_ampere();//输出互感器
    uint16 inCurrent = get_in_ampere();//输入互感器
		uint16 p=0;
		int16 igbt_temp_one = get_igbt_one_temp();
		int16 igbt_temp_two = get_igbt_two_temp();
		igbt_temp_one = ((igbt_temp_one >= igbt_temp_two)?igbt_temp_one:igbt_temp_two);
		igbt_temp_one =	igbt_temp_one-TEMP_SLOW_IGBT;
		if((igbt_temp_one>0)&& (index !=0) && (index !=9))
		{
			if(index>igbt_temp_one)
			{
				index = index - igbt_temp_one;
			}
			else
			{
				index = 1;
			}
		}
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
					default:
						stopPWM();			
			return;
    }
		if(pwm_state==1)
		{
			setTmrPeriod(0);
			pwm_state=0;
		}
		else
		{
			if(inCurrent !=0 && (outCurrent*4/inCurrent>=15))
			{
					setTmrPeriod(0);
			}
			else
			{
				if(outCurrent<(p-2))
				{
						setTmrPeriod(1);
				}
				else if(outCurrent>(p+2))
				{
						setTmrPeriod(0);
				}
			}
		}
    openPWM();
}
void openPWM()
{
	  CCU60_ISR |= 0x0400;//trap  软件复位		
		CCU60_vStartTmr(CCU60_TIMER_12);
		pwm_run =1;
}
void stopPWM()
{
		CCU60_ISS |= 0x0400;//trap  软件复位
		pwm=PWM_MIN;
		pwm_run =0;
}
bit PWMRun()
{
	return pwm_run;
}
bit PWMChange()
{
	return pwm<=(PWM_MIN+5)?1:0;
}
void setPWMState()
{
	if(pwm_state == 0)
	{
		pwm_state = 1;
	}
}

void setTmrPeriod(bit add)
{
		(add==1)?pwm++:pwm--;
		pwm = clamp(pwm);
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
