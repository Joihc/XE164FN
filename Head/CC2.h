//****************************************************************************
// @Module        Capture / Compare Unit 2 (CAPCOM2)
// @Filename      CC2.h
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for 
//                the CC2 module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/16 10:51:58
//
//****************************************************************************

// USER CODE BEGIN (CC2_Header,1)

// USER CODE END



#ifndef _CC2_H_
#define _CC2_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CC2_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CC2_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CAPCOM2 timer 7
#define CC2_TIMER_7 7

//   This parameter identifies CAPCOM2 timer 8
#define CC2_TIMER_8 8

//   This parameter identifies CAPCOM2 channel 20
#define CC2_CC_20 20


// USER CODE BEGIN (CC2_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CC2_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CC2_vInit(void);


// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CC2_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CAPCOM2 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be started
//
//----------------------------------------------------------------------------
// @Date          2017/3/16
//
//****************************************************************************

#define CC2_vStartTmr(TimerNr) CC2_vStartTmr_##TimerNr()
#define CC2_vStartTmr_CC2_TIMER_7() CC2_T78CON_T7R = 1
#define CC2_vStartTmr_CC2_TIMER_8() CC2_T78CON_T8R = 1


//****************************************************************************
// @Macro         CC2_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CAPCOM2 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          2017/3/16
//
//****************************************************************************

#define CC2_vStopTmr(TimerNr) CC2_vStopTmr_##TimerNr()
#define CC2_vStopTmr_CC2_TIMER_7() CC2_T78CON_T7R = 0
#define CC2_vStopTmr_CC2_TIMER_8() CC2_T78CON_T8R = 0



#define CC2_vStateTmr(TimerNr) CC2_vStateTmr_##TimerNr()
#define CC2_vStateTmr_CC2_TIMER_7() CC2_T78CON_T7R
#define CC2_vStateTmr_CC2_TIMER_8() CC2_T78CON_T8R

//****************************************************************************
// @Macro         CC2_vClearTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CAPCOM2 timer and sets the 
//                timer register to 0. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be cleared
//
//----------------------------------------------------------------------------
// @Date          2017/3/16
//
//****************************************************************************

#define CC2_vClearTmr(TimerNr) CC2_vClearTmr_##TimerNr()
#define CC2_vClearTmr_CC2_TIMER_7() CC2_T78CON_T7R = 0; CC2_T7 = 0x0000
#define CC2_vClearTmr_CC2_TIMER_8() CC2_T78CON_T8R = 0; CC2_T8 = 0x0000


//****************************************************************************
// @Macro         CC2_uwReadTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the content of the CAPCOM2 timer. The 
//                timer is not stopped. CPU access to the timer register has 
//                a higher priority than a timer increment or a reload. 
//                
//                The following definitions for TimerNr are available: 
//                CC2_TIMER_7
//                CC2_TIMER_8
//                (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 16-bit value of the timer register
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CAPCOM2 timer to be readed
//
//----------------------------------------------------------------------------
// @Date          2017/3/16
//
//****************************************************************************

#define CC2_uwReadTmr(TimerNr) CC2_uwReadTmr_##TimerNr()
#define CC2_uwReadTmr_CC2_TIMER_7() CC2_T7
#define CC2_uwReadTmr_CC2_TIMER_8() CC2_T8




#define CC2_vSetReload(TimerNr, Value) CC2_vSetReload_##TimerNr(Value)
#define CC2_vSetReload_CC2_TIMER_7(Value) CC2_T7REL = Value
#define CC2_vSetReload_CC2_TIMER_8(Value) CC2_T8REL = Value

//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CC2_T7INT    0x26
#define CC2_CC20INT    0x14


// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


#endif  // ifndef _CC2_H_
