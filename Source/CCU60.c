//****************************************************************************
// @Module        Capture / Compare Unit 60 (CCU60)
// @Filename      CCU60.c
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the CCU60 module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/14 14:27:25
//
//****************************************************************************

// USER CODE BEGIN (CCU60_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (CCU60_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU60_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CCU60_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU60_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CCU60_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CCU60_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CCU60_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CCU60 function 
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
// @Date          2017/3/14
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void CCU60_vInit(void)
{
  volatile unsigned int uwTemp;
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of KERNEL REGISTERS :
  ///  -----------------------------------------------------------------------
  ///  - CCU60 Module is enabled.
  ///  - The CCU60 module clock = 80.000 MHz. 
  ///  - T12 is enabled.
  ///  - T13 is enabled.
  ///  - MCM is enabled.

  CCU60_KSCFG    =  0x0003;      // Kernel State Configuration Register

  uwTemp         =  CCU60_KSCFG;  // dummy read to avoid pipeline effects

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Timer 12:
  ///  -----------------------------------------------------------------------
  ///  - Timer 12 Input clock factor (T12CLK) is 0
  ///  - prescaler factor is 0
  ///  - Timer 12 run bit is reset
  ///  - Single shot mode is disabled
  ///  - Timer 12 works in center aligned mode
  ///  - Interrupt on period match is enabled
  ///  - Interrupt on one match is disabled
  ///  - No External run selection is selected.
  ///  - Timer mode is selected.
  ///  - 

  CCU60_T12PR    =  0x0960;      // load CCU60 T12 period register

  ///  -----------------------------------------------------------------------
  ///  Configuration of T13HR Signal:
  ///  -----------------------------------------------------------------------
  ///  - Signal T13HRD is selected as Input
  CCU60_PISELH   =  0x0003;      // Load CCU60 Port Input Selection register


  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Timer 13:
  ///  -----------------------------------------------------------------------
  ///  - Timer 13 Input Clock factor (T13CLK) is 0
  ///  - prescaler factor is 0
  ///  - Timer 13 run bit is reset
  ///  - Trigger control is disabled
  ///  - No External run selection is selected.
  ///  - Timer mode is selected.
  ///  - 
  ///  - Single shot mode is disabled
  ///  - Interrupt on period match is disabled
  ///  - Interrupt on compare match is disabled

  CCU60_T13PR    =  0x0001;      // load CCU60 T13 period register

  CCU60_TCTR0    =  0x0080;      // load CCU60 timer control register 0
  CCU60_TCTR2    =  0x0020;      // load CCU60 timer control register 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of Multi Channel Mode:
  ///  -----------------------------------------------------------------------
  ///  - Multi channel mode is disabled


  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Channel 0:
  ///  -----------------------------------------------------------------------
  ///  - Compare mode 1 is selected
  ///  - T12 modulation for output CC60 is enabled
  ///  - T13 modulation for output CC60 is disabled
  ///  - The trap functionality of the pin CC60 is enabled
  ///  - The compare output CC60 drives passive level while CC60ST is '0'
  ///  - The passive level of the output CC60 is '0'
  ///  - T12 modulation for output COUT60 is enabled
  ///  - T13 modulation for output COUT60 is disabled
  ///  - The trap functionality of the pin COUT60 is enabled
  ///  - The compare output COUT60 drives passive level while CC60ST is '1'
  ///  - The passive level of the output COUT60 is '0'
  ///  - Dead time generation is enabled

  ///  - Generation interrupt on flag ICC60R is enabled
  ///  - Generation interrupt on flag ICC60F is enabled

  CCU60_CC60SR   =  0x04B0;      // Load CCU60 capture/compare shadow 
                                 // register for channel 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Channel 1:
  ///  -----------------------------------------------------------------------
  ///  - Channel 1 is disabled
  ///  - T12 modulation for output CC61 is disabled
  ///  - T13 modulation for output CC61 is disabled
  ///  - T13 modulation for output CC61 is disabled

  ///  - Generation interrupt on flag ICC61R is disabled
  ///  - Generation interrupt on flag ICC61F is disabled

  CCU60_CC61SR   =  0x0000;      // Load CCU60 capture/compare shadow 
                                 // register for channel 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Channel 2:
  ///  -----------------------------------------------------------------------
  ///  - Channel 2 is disabled
  ///  - T12 modulation for output CC62 is disabled
  ///  - T13 modulation for output CC62 is disabled
  ///  - T13 modulation for output CC62 is disabled

  ///  - Generation interrupt on flag ICC62R is disabled
  ///  - Generation interrupt on flag ICC62F is disabled

  CCU60_CC62SR   =  0x0000;      // Load CCU60 capture/compare shadow 
                                 // register for channel 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 Channel 3:
  ///  -----------------------------------------------------------------------
  ///  - T13 output is not inverted


  CCU60_CC63SR   =  0x0000;      // load CCU60 capture/compare shadow 
                                 // register for channel 3


  CCU60_T12DTC   =   0x01C0; 		//2.4us  0x01C0;   2.45us 0x01C4;  // load CCU60 dead time control register for 
                                 // timer T12

  CCU60_T12MSEL  =  0x0001;      // load CCU60 T12 campture/compare mode 
                                 // select register

  CCU60_CMPSTAT  =  0x0200;      // load CCU60 compare status register

  CCU60_MODCTR   =  0x0003;      // load CCU60 modulation control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 trap control:
  ///  -----------------------------------------------------------------------
  ///  - Trap can be generated by SW or by rising edge on #CTRAP
  ///  - The trap state is left when a zero-match of T12 (while counting up) 
  ///    is detected (synchronization to T12)
  ///  - The trap state can be left as soon as bit TRPF is reset by SW 
  ///    (according to TRPPEN, TRPM0 and TRPM1)
  ///  - Trap interrupt is enabled


  CCU60_TRPCTR   =  0x8304;      // Load CCU60 trap control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of CCU60 interrupt control:
  ///  -----------------------------------------------------------------------
  ///  - For channel 0 interrupts is node I1 selected
  ///  - For channel 1 interrupts is node I0 selected
  ///  - For channel 2 interrupts is node I0 selected
  ///  - For correct hall event interrupt is node I0 selected
  ///  - For error interrupts is node I0 selected
  ///  - For T12 interrupts is node I1 selected
  ///  - For T13 interrupts is node I0 selected


  CCU60_INP      =  0x0401;      // Load CCU60 capture/compare interrupt node 
                                 // pointer register

  CCU60_IEN      =  0x0483;      // Load CCU60 capture/compare interrupt 
                                 // enable register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CCU60 Channels Interrupts:
  ///  -----------------------------------------------------------------------
  ///  NodeI0 service request node configuration:
  ///  - NodeI0 interrupt priority level (ILVL) = 1
  ///  - NodeI0 interrupt group level (GLVL) = 0
  ///  - NodeI0 group priority extension (GPX) = 0

  CCU60_0IC      =  0x0044;     

  ///  NodeI1 service request node configuration:
  ///  - NodeI1 interrupt priority level (ILVL) = 2
  ///  - NodeI1 interrupt group level (GLVL) = 0
  ///  - NodeI1 group priority extension (GPX) = 0

  CCU60_1IC      =  0x0048;     


  ///  -----------------------------------------------------------------------
  ///  Configuration of T12, T13 ---- CCU60_TCTR4 Register:
  ///  -----------------------------------------------------------------------
  ///  - Enable shadow transfer of T12 and T13
  ///  - Timer 12 run bit is reset
  ///  - Timer 13 run bit is reset
  CCU60_TCTR4    =  0x4040;      // load CCU60 timer control register 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CCU60 Channel Port Pins:
  ///  -----------------------------------------------------------------------
  ///  - P10.0 is used for CCU60 output(CC60)
  ///  - P10.3 is used for CCU60 output(COUT60)
  ///  - P10.6 is used for  CCU60 input(CTRAPA)

  P10_IOCR00 = 0x00A0;    //set direction register
  P10_IOCR03 = 0x00A0;    //set direction register

  CCU60_PISELL   =  0xFF00;      // Load CCU60 Port Input Selection register


  // USER CODE BEGIN (NodeI3,3)

  // USER CODE END

} //  End of function CCU60_vInit


//****************************************************************************
// @Function      void CCU60_viNodeI0(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CCU60 node 
//                I0. If the content of the corresponding compare timer 
//                (configurable) equals the content of the capture/compare 
//                register or if a capture event occurs at the associated 
//                port pin, the interrupt request flag is set and an 
//                interrupt is triggered (only if enabled).
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
// @Date          2017/3/14
//
//****************************************************************************

// USER CODE BEGIN (NodeI0,1)

// USER CODE END

void CCU60_viNodeI0(void) interrupt CCU60_NodeI0_INT
{
  // USER CODE BEGIN (NodeI0,2)

  // USER CODE END

  if(CCU60_IS & 0x0400)  // if CCU60_IS_TRPF
  {
    // Trap detection

    // USER CODE BEGIN (NodeI0,17)

    // USER CODE END

    //CCU60_ISR |= 0x0400;  // clear flag CCU60_IS_TRPF
  }


} //  End of function CCU60_viNodeI0


//****************************************************************************
// @Function      void CCU60_viNodeI1(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CCU60 node 
//                I1. If the content of the corresponding compare timer 
//                (configurable) equals the content of the capture/compare 
//                register or if a capture event occurs at the associated 
//                port pin, the interrupt request flag is set and an 
//                interrupt is triggered (only if enabled).
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
// @Date          2017/3/14
//
//****************************************************************************

// USER CODE BEGIN (NodeI1,1)

// USER CODE END

void CCU60_viNodeI1(void) interrupt CCU60_NodeI1_INT
{
  // USER CODE BEGIN (NodeI1,2)

  // USER CODE END

  if(CCU60_IS & 0x0001)   // if CCU60_IS_ICC60R
  {
    // Capture, Compare match rising edge detection an channel 0
		
    // USER CODE BEGIN (NodeI1,10)
		//if(CC2_vStateTmr(CC2_TIMER_8))
		//{
			//若定时器没有关闭，说明没有检测到电流。互感器过比例大或者互感器损坏或者电阻过小
		//	setPWMState();
		//}
		//开启捕获comp 2计时
		//CC2_vClearTmr(CC2_TIMER_8);
		//CC2_vStartTmr(CC2_TIMER_8);

    // USER CODE END

    CCU60_ISR |= 0x0001;  // clear flag CCU60_IS_ICC60R
  }

  if(CCU60_IS & 0x0002)  // if CCU60_IS_ICC60F
  {
    // Capture, Compare match faling edge detection an channel 0

    // USER CODE BEGIN (NodeI1,11)

    // USER CODE END
    CCU60_ISR |= 0x0002;  // clear flag CCU60_IS_ICC60F
  }

  if(CCU60_IS & 0x0080)  // if CCU60_IS_T12PM
  {
    // Timer T12 period match detection

    // USER CODE BEGIN (NodeI1,19)

    // USER CODE END

    CCU60_ISR |= 0x0080;  // clear flag CCU60_IS_T12PM
  }


} //  End of function CCU60_viNodeI1




// USER CODE BEGIN (CCU60_General,10)

// USER CODE END

