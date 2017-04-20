//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.c
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2017/3/6 08:54:50
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"


// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/6
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          


  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8.00 MHz
  ///  - system clock is 80.00 MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  MAIN_vChangeFreq();          // load PLL control register

  //   -----------------------------------------------------------------------
  //   SCU Interrupt Disable configuration:
  //   -----------------------------------------------------------------------
  SCU_INTDIS     =  0xFFFF;      // SCU Interrupt Disable Register

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Capture / Compare Unit 2 (CAPCOM2)
  CC2_vInit();

  //   initializes the Capture / Compare Unit 60 (CCU60)
  CCU60_vInit();

  //   initializes the Analog / Digital Converter  (ADC0)
  ADC0_vInit();

  //   initializes the Analog / Digital Converter (ADC1)
  ADC1_vInit();

  //   initializes the Watchdog Timer (WDT)
  WDT_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  //   -----------------------------------------------------------------------
  //   SCU Interrupt Source Selection configuration:
  //   -----------------------------------------------------------------------
  SCU_ISSR       =  0x0000;      // SCU Interrupt Source Select Register

  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/6
//
//****************************************************************************

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uint16 uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/6
//
//****************************************************************************

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{
  uint16 uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x1800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCU_SLC = 0x8E00 | uwPASSWORD;      // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void MAIN_vChangeFreq(void) 
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 100MHz/80MHz/66MHz.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/6
//
//****************************************************************************

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void)
{
  Scs_ErrorType Error;

  Scs_EnableHighPrecOsc(1U);

  //For application and internal application resets, the complete PLL configuration could be avoided
  //The entry from application resets and internal application reset is covered in the following differentiation
  //in int/ext clock in lock/unlocked state.

  if  ((SCU_PLLSTAT & 0x0004) == 0x0004)       // fR derived from Internal clock
  {
    //Normal startup state during boot and the clock
    //has to be in the next step configured on the external crystal
    //use XTAL/VCO, count XTAL clock

    Scs_InitTimer();       // initialize CCU6 timer T13 for SCS driver

    // perform transition from base mode to normal mode, check for error
    Error = Scs_GoFromBaseModeToNormalMode();
    if(Error)
    {
      for(;;)      // this part of code should not be reached
      {
        NOP();
      }
    }

    if ((SCU_PLLSTAT & 0x1009) == 0x1009)      // fR derived from external crystal clock + VCO is locked
    {
      //usually after an application reset where clock need not be configured again.
      //check K2/P/N values and decide whether these values have to be adapted based on application needs.
      NOP();
      //usually the PLL losss of Lock TRAP schould be enabled here.
    }
    else       //fR derived from external crystal clock + VCO is not locked
    {
               //estimate the K1 value and the current frequency
               //reduce K2/P/N values in steps so that the frequency
               //jumps is limited to 20MHz or factor of 5 whichever is minimum
      NOP();
    }


  }

} //  End of function MAIN_vChangeFreq


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/6
//
//****************************************************************************

// USER CODE BEGIN (Main,1)
uint16 initTime=	0;
uint8 switchNow = 0;
const float switchSteps[] ={0,0.2,0.32,0.45,0.66,0.74,0.81,0.9,1};
uint16 statusViewNum = 0;		
//每位检测到状态表示左到右,
//1表示故障0表示正常  
//0无锅/1线盘超温/2线盘开路/3IGBT1超温/4IGBT1开路/5IGBT2超温/6IGBT2开路
//7电压低/8电压高/9缺相/10档位开关开路/11锅底开路/12锅底超温/13IGBT驱动故障/14输出互感器反/15线盘不通
uint8 statueViewCheckTime[17] ={0,0,0,0,  0,0,0,0,  0,0,0,0,   0,0,0,0,0}; 
uint8 statueViewCheckTimeOut[17] ={0,0,0,0,  0,0,0,0,  0,0,0,0,   0,0,0,0,0}; 
//16特殊字段，


uint8 temperatureCheckTime =40;//40s
uint8 nullPotCheckTime =0;
uint8 igbtErrorCheckTime =0;

bit firstOpen = TRUE;

uint4 igbtErrorLay =0;
uint4 nullPotLay=0;

uint8 checkNullPot=0;
uint8 checkIgbtError =0;


uint8 fanTime = FAN_ALL_TIME;

uint4 haveViewSet = FALSE;
uint4 checkTimeOn = FALSE;

uint8 whileTimeUpdate =0;
//volatile int16 mainTest =0;
// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)

  // USER CODE END

  MAIN_vInit();


  // USER CODE BEGIN (Main,3)
#ifdef Screen_74HC164
	init_74HC164();
#elif defined Screen_TM1629
	init_TM1629();
#endif
	init_buz();
	init_adc();
	
	while(TRAP && (initTime<6666))
	{
		initTime++;
	};//igbt or time is ready
	delay(6666);
  // USER CODE END

  while(1)
  {
		WDT_vServiceWDT();
		
		// USER CODE BEGIN (Main,4)
#ifdef DEBUG
		switchNow = get_switch();
		fixPWM(switchNow);
		ViewSet(switchNow);
#else
		switchNow = get_switch();
		
		haveViewSet = FALSE;
		checkTimeOn = FALSE;
		
		whileTimeUpdate++;
		if(whileTimeUpdate>100)
		{
			whileTimeUpdate =0;
			ADCUpdate();
		}
			DetectUnderPotCut();//锅底探头开路
		  DetectUnderPotHot();//锅底超温
			DetectCoilHot();//线盘超温
		  DetectCoilCut();//线盘探头开路
		  DetectIGBTHot_1();//IGBT超温
		  DetectIGBTCut_1();//IGBT探头开路
		  DetectIGBTHot_2();//IGBT超温
		  DetectIGBTCut_2();//IGBT探头开路
			DetectVLow();//低压检测
			DetectVHight();//高压检测	
		  //DetectVCut();//缺相检测
		  DetectSwitchCut();//档位开关开路
		//}
			if(PWMRun())//只在开通状态下检查
			{     			
				//DetectVPP();//电压波动
				//DetectVLow();//低压检测
				//DetectVHight();//高压检测	
				DetectTransformerCut();//线盘断了或者输出互感器坏了
				DetectIgbtError();//IGBT驱动故障
				DetectNullPot();//无锅检测 
			}
			//低压
		  if ((statusViewNum & ((uint16)1 << 7)) && !haveViewSet)
		  {
				ViewSet(108);
				haveViewSet = TRUE;
		  }
		  //高压
		  if ((statusViewNum & ((uint16)1 << 8)) && !haveViewSet)
		  {
				ViewSet(109);
				haveViewSet = TRUE;
		  }
		  //缺相
		  //if ((statusViewNum & ((uint16)1 << 9)) && !haveViewSet)
		  //{
			//	ViewSet(108);
			//	haveViewSet = TRUE;
		  //}
		  //档位开路
		  if ((statusViewNum & ((uint16)1 << 10)) && !haveViewSet)
		  {
				ViewSet(113);
				haveViewSet = TRUE;
		  }
		  //线盘开路
		  if ((statusViewNum & ((uint16)1 << 2)) && !haveViewSet && !temperatureCheckTime)
		  {
				ViewSet(103);
				haveViewSet = TRUE;
		  }
		  //IGBT1探头开路
		  if ((statusViewNum & ((uint16)1 << 4)) && !haveViewSet && !temperatureCheckTime)
		  {
				ViewSet(105);
				haveViewSet = TRUE;
		  }
		  //IGBT2探头开路
		  if ((statusViewNum & ((uint16)1 << 6)) && !haveViewSet && !temperatureCheckTime)
		  {
				ViewSet(105);
				haveViewSet = TRUE;
		  }
			//锅底探头开路
			if ((statusViewNum & ((uint16)1 << 11)) && !haveViewSet && !temperatureCheckTime)
			{
				ViewSet(107);
				haveViewSet = TRUE;
			}
		if (switchNow == 0 || firstOpen)
		{
			//为0档位时
			//firstOpen = FALSE;
			if (fanTime == 0)
			{
				fanTime = 1;//等待关闭风机
			}
			if (!haveViewSet)
			{
				ViewSet(0);
			}
			fixPWM(0);

			statueViewCheckTime[0] =	0;//无锅 正常
	    statueViewCheckTime[1] = 	0;//线盘超温置0 正常
			statueViewCheckTime[3] =	0;//IGBT1超温置0 正常
	    statueViewCheckTime[5] = 	0;//IGBT2超温置0 正常
			statueViewCheckTime[12] =	0;//锅底超温置0 正常
	    statueViewCheckTime[13] = 0;//IGBT驱动故障置0 正常
	    statueViewCheckTime[15] = 0;//线盘不通或者输出互感器损坏置0 正常
      //重置故障
      statusViewNum &= ~((uint16)1 << 0);//无锅 正常
      statusViewNum &= ~((uint16)1 << 1);//线盘超温置0 正常
      statusViewNum &= ~((uint16)1 << 3);//IGBT1超温置0 正常
      statusViewNum &= ~((uint16)1 << 5);//IGBT2超温置0 正常
      statusViewNum &= ~((uint16)1 << 12);//锅底超温置0 正常
      statusViewNum &= ~((uint16)1 << 13);//IGBT驱动故障置0 正常
      statusViewNum &= ~((uint16)1 << 15);//线盘不通或者输出互感器损坏置0 正常
		}
		else
		{
			//线盘超温
			if ((statusViewNum & ((uint16)1 << 1)) && !haveViewSet)
			{
				ViewSet(102);
				haveViewSet = TRUE;
			}
			//IGBT1超温
			if ((statusViewNum & ((uint16)1 << 3)) && !haveViewSet)
			{
				ViewSet(104);
				haveViewSet = TRUE;
			}
			//IGBT2超温
			if ((statusViewNum & ((uint16)1 << 5)) && !haveViewSet)
			{
				ViewSet(104);
				haveViewSet = TRUE;
			}
			//锅底超温
			if ((statusViewNum & ((uint16)1 << 12)) && !haveViewSet)
			{
				ViewSet(106);
				haveViewSet = TRUE;
			}
      //线盘不通或者输出互感器损坏
      if((statusViewNum & ((uint16)1 << 15)) && !haveViewSet)
      {                        
         ViewSet(110);
         haveViewSet = TRUE;
         statueViewCheckTime[0] =0;//无锅次数
      }
			//IGBT驱动故障
			if ((statusViewNum & ((uint16)1 << 13)) && !haveViewSet && !checkTimeOn)
			{
				if(igbtErrorLay<1)
				{
					ViewSet(switchNow);
				}
				else
				{
					ViewSet(112);
				}
				haveViewSet = TRUE;
				checkTimeOn = TRUE;
				if (igbtErrorCheckTime >=DELAY_TIME)
				{
				    igbtErrorCheckTime = 0;
						checkIgbtError = 0;
            if(igbtErrorLay<3)
            {
                igbtErrorLay++;
            }
				}
					if(checkIgbtError>10)
					{
            fixPWM(0);  
						IO_vResetPin(IO_P10_7);//REST 硬件复位
						statueViewCheckTimeOut[13]=0;						
					}
					else
					{
            fixPWM(switchNow);
						IO_vSetPin(IO_P10_7);//REST 硬件复位			
					}
					if(checkIgbtError<40)
					{
            checkIgbtError++;
					}
					statueViewCheckTime[0]  = 0;//无锅次数
					statueViewCheckTime[15] = 0;//线盘状态
			}
      //无锅
			if ((statusViewNum & ((uint16)1 << 0)) && !haveViewSet && !checkTimeOn)
			{
          if(nullPotLay <1)
          {
              ViewSet(switchNow);
          }
          else
          {
              ViewSet(101);
          }
				
					haveViewSet = TRUE;
					checkTimeOn = TRUE;
					if (nullPotCheckTime >=DELAY_TIME)
					{
				    nullPotCheckTime = 0;
						checkNullPot =0;
            if(nullPotLay<3)
            {
                nullPotLay++;
            }
					}
					if(checkNullPot>10)
					{
            fixPWM(0);                               
					}
					else
					{
            fixPWM(switchNow);
					}
					if(checkNullPot<40)
					{
            checkNullPot++;
					}
					statueViewCheckTime[15] = 0;//线盘状态
			}
			if (!haveViewSet)
			{
				if (firstOpen)
				{
					fixPWM(0);//关闭输出
					ViewSet(0);//显示0档位
					if (fanTime == 0)
					{
						fanTime = 1;//等待关闭风机
					}
          //0档检测的置0
          statueViewCheckTime[0] =0;//无锅次数
	        statueViewCheckTime[15] = 0;//线盘状态
				}
				else
				{
					fixPWM(switchNow);//开启输出
					ViewSet(switchNow);//显示档位
					fanTime = 0;//开启风机   
				}
			}
			else
			{
         if (firstOpen || !checkTimeOn)
					{
				    fixPWM(0);//关闭输出
            statueViewCheckTime[0] =0;//无锅次数
	          statueViewCheckTime[15] = 0;//线盘状态
          }
					if (fanTime == 0)
					{
						fanTime = 1;//等待关闭风机
					}
			}
		}
   // USER CODE END
#endif
  }

} //  End of function main

void SetFirstOpen()
{
	firstOpen = FALSE;
}
#ifdef Screen_74HC164
void ViewSet(uint8 ShowNum)
{
	setNum_74HC164(ShowNum);
	whileUpdate_74HC164();
}
#elif defined Screen_TM1629
void ViewSet(uint8 ShowNum)
{
	set_TM1629_LeftNum(switchNow);
	set_TM1629_Leftstring(getPWMRate());
	if (ShowNum<100 && ShowNum>0)//温度模式
	{
			set_TM1629_Down(get_pot_temp(), 1);
			//set_TM1629_Down(get_in_ampere(), 1);
			//set_TM1629_Down(get_vol(), 1);//get_vol()
			//set_TM1629_Down(mainTest, 1);
	}
	else
	{
		set_TM1629_Down(0, 0);
	}
	if(ShowNum>100)
	{
		set_TM1629_Up(ShowNum);
	}
	else
	{
		set_TM1629_Up((uint8)(NOWKW*switchSteps[ShowNum]));
	}
	whileUpdate_TM1629();
}
#endif

// USER CODE BEGIN (MAIN_General,10)
void DetectNullPot()
{
	uint16 temp_2 = (uint16)1 << 0;
  uint4 temp = get_no_p();
	if (!temp && !(statusViewNum & temp_2))
	{
		//检测到有锅且显示有锅
		statueViewCheckTime[0] = 0;
		return;
	}
	if (!temp && (statusViewNum & temp_2))
	{
		//检测到有锅且显示无锅
		delay(2);//延时2ms
		if (get_no_p())
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[0] = 0;
		return;
	}
	if (temp && (statusViewNum & temp_2))
	{
		//检测到无锅且无锅
    statueViewCheckTime[0]=0;
		return;
	}
	if (temp && !(statusViewNum & temp_2))
	{
		//检测到无锅且有锅
		delay(2);//延时2ms
		if (!get_no_p())
			return;
    statueViewCheckTime[0]++;
		if (statueViewCheckTime[0] >= 100)
		{
			statueViewCheckTime[0] = 0;
			statusViewNum |= temp_2;//置1 无锅状态
			nullPotCheckTime =0;
      nullPotLay =0;
      checkNullPot =0;
		}
	}
}
void DetectCoilHot()
{
	uint16 temp_2 = (uint16)1 << 1;
	uint4 temp = get_coil();//1 温高
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//由档位复位
		statueViewCheckTime[1] = 0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//由档位复位
		statueViewCheckTime[1] = 0;
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		statueViewCheckTime[1] = 0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//检查温度不正常且显示温度正常
		delay(2);//延时2ms
		if (get_coil() != 1)
			return;
		statueViewCheckTime[1]++;
		if (statueViewCheckTime[1] >= 3)
		{
			statueViewCheckTime[1] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}

}
void DetectCoilCut()
{
	uint16 temp_2 = (uint16)1 << 2;
	uint4 temp = get_coil();//2 探头开路
	if ((temp != 2) && !(statusViewNum & temp_2))
	{
		//检查正常且显示正常
		statueViewCheckTime[2] = 0;
		return;
	}
	if ((temp != 2) && (statusViewNum & temp_2))
	{
		//检查正常且显示不正常
		delay(2);//延时2ms
		if (get_coil() == 2)
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[2] = 0;
		return;
	}
	if ((temp == 2) && (statusViewNum & temp_2))
	{
		//检查不正常且显示不正常
		statueViewCheckTime[2] = 0;
		return;
	}
	if ((temp == 2) && !(statusViewNum & temp_2))
	{
		//检查不正常且显示正常
		delay(2);//延时2s
		if (get_coil() != 2)
			return;
		statueViewCheckTime[2]++;
		if (statueViewCheckTime[2] >= 3)
		{
			statueViewCheckTime[2] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectIGBTHot_1()
{
	uint16 temp_2 = (uint16)1 << 3;
	uint4 temp = get_igbt_one();//2高温
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//0档复位
		statueViewCheckTime[3]=0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//0档复位
		statueViewCheckTime[3]=0;
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[3]=0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_igbt_one() != 1)
			return;
		statueViewCheckTime[3]++;
		if (statueViewCheckTime[3] >= 3)
		{
			statueViewCheckTime[3] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectIGBTCut_1()
{
	uint16 temp_2 = (uint16)1 << 4;
	uint4 temp = get_igbt_one();//1开路
	if ((temp != 2) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[4] = 0;
		return;
	}
	if ((temp != 2) && (statusViewNum & temp_2))
	{
		//正常且不正常
		delay(2);
		if (get_igbt_one() == 2)
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[4] = 0;
		return;
	}
	if ((temp == 2) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[4] = 0;
		return;
	}
	if ((temp == 2) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_igbt_one() != 2)
			return;
		statueViewCheckTime[4]++;
		if (statueViewCheckTime[4] >= 3)
		{
			statueViewCheckTime[4] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectIGBTHot_2()
{
	uint16 temp_2 = (uint16)1 << 5;
	uint4 temp = get_igbt_two();//2高温
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[5] = 0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//正常且不正常
		statueViewCheckTime[5] = 0;
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[5] = 0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_igbt_two() != 1)
			return;
		statueViewCheckTime[5]++;
		if (statueViewCheckTime[5] >= 3)
		{
			statueViewCheckTime[5] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectIGBTCut_2()
{
	uint16 temp_2 = (uint16)1 << 6;
	uint4 temp = get_igbt_two();//1开路
	if ((temp != 2) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[6] =0;
		return;
	}
	if ((temp != 2) && (statusViewNum & temp_2))
	{
		//正常且不正常
		delay(2);
		if (get_igbt_two() == 2)
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[6] =0;
		return;
	}
	if ((temp == 2) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[6] =0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_igbt_two() != 2)
			return;
		statueViewCheckTime[6]++;
		if (statueViewCheckTime[6] >= 3)
		{
			statueViewCheckTime[6] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectVLow()
{
	uint16 temp_2 = (uint16)1 << 7;
	uint4 temp;//2 压低
	if((statusViewNum & temp_2))
	{
		temp=get_check_vol(2,1);
	}
	else
	{
		temp=get_check_vol(0,1);
	}
	if ((temp != 2) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[7] =0;
		statueViewCheckTimeOut[7]=0;
		return;
	}
	if ((temp != 2) && (statusViewNum & temp_2))
	{
		//正常且不正常
		statueViewCheckTime[7] =0;
		statueViewCheckTimeOut[7]++;
		if(statueViewCheckTimeOut[7]>=50)
		{	
			statueViewCheckTimeOut[7]=0;
			statusViewNum &= ~temp_2;//电压低
		}
		return;
	}
	if ((temp == 2) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[7] =0;
		statueViewCheckTimeOut[7]=0;
		return;
	}
	if ((temp == 2) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		statueViewCheckTime[7]++;
		if (statueViewCheckTime[7] >= 50)
		{
			statueViewCheckTime[7] =0;
			statusViewNum |= temp_2;//置1 不正常
		}
		statueViewCheckTimeOut[7]=0;
	}
}
void DetectVHight()
{
	uint16 temp_2 = (uint16)1 << 8;
  uint4 temp;//1 压高
	if((statusViewNum & temp_2))
	{
		temp=get_check_vol(1,1);
	}
	else
	{
		temp=get_check_vol(0,1);
	}
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[8] = 0;
		statueViewCheckTimeOut[8]=0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//正常且不正常
		statueViewCheckTime[8] = 0;
		statueViewCheckTimeOut[8]++;
		if(statueViewCheckTimeOut[8]>=50)
		{
			statueViewCheckTimeOut[8]=0;
			statusViewNum &= ~temp_2;//电压低
		}
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[8] = 0;
		statueViewCheckTimeOut[8]=0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		statueViewCheckTime[8]++;
		if (statueViewCheckTime[8] >= 50)
		{
			statueViewCheckTime[8] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
		statueViewCheckTimeOut[8]=0;
	}
}
void DetectVPP()
{
	uint16 temp_2 = (uint16)1 << 9;
  uint4 temp = get_check_vol_on();//1 压高
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//正常且正常
		//statueViewCheckTime[9] = 0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//正常且不正常
		//statueViewCheckTime[9] = 0;
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		//statueViewCheckTime[9] = 0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_check_vol_on() != 1)
			return;
		//statueViewCheckTime[9]++;
		//if (statueViewCheckTime[9] >= 10)
		//{
		//	statueViewCheckTime[9] = 0;
			statusViewNum |= temp_2;//置1 不正常
		//}
	}
}
void DetectSwitchCut()
{
	uint16 temp_2 = (uint16)1 << 10;
	uint4 temp = get_switch_cut();//1 开路
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[10] = 0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//正常且不正常
		delay(2);
		if (get_switch_cut() == 1)
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[10] = 0;
		return;
	}
	if ((temp == 1 )&& (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[10] = 0;
		return;
	}
	if ((temp == 1) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_switch_cut() != 1)
			return;
		statueViewCheckTime[10]++;
		if (statueViewCheckTime[10] >= 3)
		{
			statueViewCheckTime[10] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectUnderPotCut()
{
	uint16 temp_2 = (uint16)1 << 11;
	uint4 temp = get_pot();//2 锅底探头开路
	if ((temp != 2) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[11] = 0;
		return;
	}
	if ((temp != 2) && (statusViewNum & temp_2))
	{
		//正常且不正常
		delay(2);
		if (get_pot() == 2)
			return;
		statusViewNum &= ~temp_2;//置0 正常
		statueViewCheckTime[11] = 0;
		return;
	}
	if ((temp == 2) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[11] = 0;
		return;
	}
	if ((temp == 2) && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_pot() != 2)
			return;
		statueViewCheckTime[11]++;
		if (statueViewCheckTime[11] >= 3)
		{
			statueViewCheckTime[11] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectUnderPotHot()
{
	uint16 temp_2 = (uint16)1 << 12;
	uint4 temp = get_pot();//1超温
	if ((temp != 1) && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[12] =0;
		return;
	}
	if ((temp != 1) && (statusViewNum & temp_2))
	{
		//正常且不正常
		statueViewCheckTime[12] =0;
		return;
	}
	if ((temp == 1) && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[12] =0;
		return;
	}
	if ((temp == 1 )&& !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_pot() != 1)
			return;
		statueViewCheckTime[12]++;
		if (statueViewCheckTime[12] >= 3)
		{
			statueViewCheckTime[12] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}
}
void DetectIgbtError()
{
	uint16 temp_2 = (uint16)1 << 13;
	if (!TRAP && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[13] =0;
		statueViewCheckTimeOut[13] =0;
		return;
	}
	if (!TRAP && (statusViewNum & temp_2))
	{
		//正常且不正常 0档复位

		statueViewCheckTimeOut[13]++;
		if(statueViewCheckTimeOut[13]>=5)
		{
			statusViewNum &= ~temp_2;//置1 不正常
		}
		statueViewCheckTime[13] =0;
		return;
	}
	if (TRAP && (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[13] =0;
		statueViewCheckTimeOut[13] =0;
		return;
	}
	if (TRAP && !(statusViewNum & temp_2))
	{
		//不正常且正常
		statueViewCheckTime[13]++;
		if(statueViewCheckTime[13] >=3)
		{
			statueViewCheckTime[13] = 0;
      statusViewNum |= temp_2;//置1 不正常
			igbtErrorLay=0;
			checkIgbtError=0;
			igbtErrorCheckTime =0;
		}
		statueViewCheckTimeOut[13] =0;
	}

}
void DetectTransformerCut()
{
	uint16 temp_2 = (uint16)1 << 15;
	uint16 temp = get_check_out_ampere();//0表示线盘断了
	if (temp && !(statusViewNum & temp_2))
	{
		//正常且正常
		statueViewCheckTime[15] =0;
		return;
	}
	if (temp && (statusViewNum & temp_2))
	{
		//正常且不正常 0档置位
		delay(2);
		statueViewCheckTime[15] =0;
		return;
	}
	if (!temp&& (statusViewNum & temp_2))
	{
		//不正常且不正常
		statueViewCheckTime[15] =0;
		return;
	}
	if (!temp && !(statusViewNum & temp_2))
	{
		//不正常且正常
		delay(2);
		if (get_out_ampere())
			return;
		statueViewCheckTime[15]++;
		if (statueViewCheckTime[15] >=150)
		{
			statueViewCheckTime[15] = 0;
			statusViewNum |= temp_2;//置1 不正常
		}
	}

}

void settest(int16 test)
{
	//mainTest = test;
}
//1S
void mainUpdate()
{
		if(igbtErrorCheckTime < DELAY_TIME)
		{
			igbtErrorCheckTime++;
		}
    if(nullPotCheckTime <DELAY_TIME)
    {
       nullPotCheckTime++;
    }
		if (fanTime >= 1 && fanTime<FAN_ALL_TIME)
		{
				fanTime++;
		}
		if (fanTime <FAN_ALL_TIME - 5)
		{
				FAN_ON;
		}
		else
		{
				FAN_OFF;
		}
		
		
		if(PWMRun())
		{
			LED_1_ON;
		}
		else
		{
			LED_1_TOGGLE;
		}
		LED_2_ON;
		
		//INTERUPT 更新区域
#ifdef Screen_74HC164
			interuptUpdate_74HC164();
#elif defined Screen_TM1629
			interuptUpdate_TM1629();
#endif
      if(PWMRun() && temperatureCheckTime)//只在开通状态检查温度运转
      {
          temperatureCheckTime--;//开路延时倒计时
      }
		updata_adc();
}

// USER CODE END


