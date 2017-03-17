//****************************************************************************
// @Module        General Purpose Timer Unit (GPT1)
// @Filename      GPT1.c
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the GPT1 module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/6 14:22:21
//
//****************************************************************************

// USER CODE BEGIN (GPT1_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (GPT1_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT1_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT1_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT1_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT1_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT1_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPT1_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT1 function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
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

void GPT1_vInit(void)
{

  volatile unsigned int uwTemp;

  // USER CODE BEGIN (Init,2)

  // USER CODE END
  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 1:
  ///  -----------------------------------------------------------------------
  GPT12E_KSCCFG  =  0x0003;      // Module Enable

  uwTemp         =  GPT12E_KSCCFG;  // dummy read to avoid pipeline effects

  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 1:
  ///  -----------------------------------------------------------------------
  ///  - prescaler for timer block 1 is 8


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Core Timer 3:
  ///  -----------------------------------------------------------------------
  ///  - timer 3 works in timer mode
  ///  - external up/down control is disabled
  ///  - prescaler factor is 8
  ///  - up/down control bit is reset
  ///  - alternate output function T3OUT () is disabled
  ///  - timer 3 output toggle latch (T3OTL) is set to 0

  GPT12E_T3CON   =  0x0000;      // load timer 3 control register
  GPT12E_T3      =  0x3CB0;      // load timer 3 register
  ///  - prescaler for timer block 1 is 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Auxiliary Timer 2:
  ///  -----------------------------------------------------------------------
  ///  - timer 2 works in counter mode
  ///  - external up/down control is disabled
  ///  - timer 2 is clocked by any transition of output toggle latch T3OTL
  ///  - up/down control bit is set

  GPT12E_T2CON   =  0x008F;      // load timer 2 control register
  GPT12E_T2      =  0x00C7;      // load timer 2 register
  ///  - prescaler for timer block 1 is 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Auxiliary Timer 4:
  ///  -----------------------------------------------------------------------
  ///  - timer 4 works in reload mode
  ///  - external up/down control is disabled
  ///  - timer 4 is clocked by any transition of output toggle latch T3OTL
  ///  - timer 4 run bit is reset

  GPT12E_T4CON   =  0x0027;      // load timer 4 control register
  GPT12E_T4      =  0x3CB0;      // load timer 4 register
  ///  - prescaler for timer block 1 is 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT1 Port Pins:
  ///  -----------------------------------------------------------------------



  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT1 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  timer 2 service request node configuration:
  ///  - timer 2 interrupt priority level (ILVL) = 7
  ///  - timer 2 interrupt group level (GLVL) = 1
  ///  - timer 2 group priority extension (GPX) = 0

  GPT12E_T2IC    =  0x005D;  
	
	///  timer 3 service request node configuration:
  ///  - timer 3 interrupt priority level (ILVL) = 1
  ///  - timer 3 interrupt group level (GLVL) = 0
  ///  - timer 3 group priority extension (GPX) = 1

  GPT12E_T3IC    =  0x0144;   

  // USER CODE BEGIN (GPT1_Function,3)

  // USER CODE END

  GPT12E_T2CON_T2R  =  1;        // set timer 2 run bit

  GPT12E_T3CON_T3R  =  1;        // set timer 3 run bit

} //  End of function GPT1_viTmr4


// USER CODE BEGIN (Tmr3,1)
uint8 tmr3 = 0;
// USER CODE END

void GPT1_viTmr3(void) interrupt T3INT
{
  // USER CODE BEGIN (Tmr3,2)
	//5ms
	if(tmr3++>20)
	{
		tmr3 = 0;
		update_buz();
		while_Time_Minus();
	}
  // USER CODE END


  // USER CODE BEGIN (Tmr3,5)

  // USER CODE END

} //  End of function GPT1_viTmr3

//****************************************************************************
// @Function      void GPT1_viTmr2(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT1 timer 2. 
//                It is called up in the case of over or underflow of the 
//                timer 2 register.
//                If the incremental interface mode is selected and the 
//                interrupt for this mode is not disabled it is called up if 
//                count edge or count direction was detected.
//                
//                Please note that you have to add application specific code 
//                to this function.
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

// USER CODE BEGIN (Tmr2,1)

// USER CODE END

void GPT1_viTmr2(void) interrupt T2INT
{
  // USER CODE BEGIN (Tmr2,2)
	GPT1_vLoadTmr(GPT1_TIMER_2, 0x00c7);
  // USER CODE END

	mainUpdate();
  // USER CODE BEGIN (Tmr2,5)

  // USER CODE END

} //  End of function GPT1_viTmr2




// USER CODE BEGIN (GPT1_General,10)

// USER CODE END

