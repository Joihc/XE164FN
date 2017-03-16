//****************************************************************************
// @Module        Capture / Compare Unit 60 (CCU60)
// @Filename      CCU60.h
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for 
//                the CCU60 module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/14 14:27:25
//
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,1)

// USER CODE END



#ifndef _CCU60_H_
#define _CCU60_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CCU60 timer 12
#define CCU60_TIMER_12 12

//   This parameter identifies CCU60 timer 13
#define CCU60_TIMER_13 13

//   This parameter identifies CCU60 channel 0
#define CCU60_CHANNEL_0 0

//   This parameter identifies CCU60 channel 1
#define CCU60_CHANNEL_1 1

//   This parameter identifies CCU60 channel 2
#define CCU60_CHANNEL_2 2

//   This parameter identifies CCU60 channel 3
#define CCU60_CHANNEL_3 3


// USER CODE BEGIN (CCU60_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CCU60_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CCU60_vInit(void);


// USER CODE BEGIN (CCU60_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CCU60_vStartTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CCU60 timer. The timer 
//                continues counting from where it stopped. 
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be started
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vStartTmr(TimerNr) CCU60_vStartTmr_##TimerNr()
#define CCU60_vStartTmr_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0002
#define CCU60_vStartTmr_CCU60_TIMER_13() CCU60_TCTR4 |= 0x0200


//****************************************************************************
// @Macro         CCU60_vStopTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CCU60 timer. The content of 
//                the timer register remains unchanged. 
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be stopped
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vStopTmr(TimerNr) CCU60_vStopTmr_##TimerNr()
#define CCU60_vStopTmr_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0001
#define CCU60_vStopTmr_CCU60_TIMER_13() CCU60_TCTR4 |= 0x0100


//****************************************************************************
// @Macro         CCU60_vResetTmr(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the selected CCU60 timer counter register 
//                to zero. Timer is not stopped.
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be cleared
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vResetTmr(TimerNr) CCU60_vResetTmr_##TimerNr()
#define CCU60_vResetTmr_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0004
#define CCU60_vResetTmr_CCU60_TIMER_13() CCU60_TCTR4 |= 0x0400


//****************************************************************************
// @Macro         CCU60_vSetTmrPeriod(TimerNr, Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the period register of the selected CCU60 
//                timer.
//                
//                Note: Call the macro CCU60_vEnableShadowTransfer() to 
//                enable the shadow transfer.
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be used
// @Parameters    Value: 
//                16-bit Value with which the CCU60 timer reload register is 
//                to be loaded
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vSetTmrPeriod(TimerNr, Value) CCU60_vSetTmrPeriod_##TimerNr(Value)
#define CCU60_vSetTmrPeriod_CCU60_TIMER_12(Value) CCU60_T12PR = Value
#define CCU60_vSetTmrPeriod_CCU60_TIMER_13(Value) CCU60_T13PR = Value


//****************************************************************************
// @Macro         CCU60_vSetDeadTimePeriod(ubValue) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the counter of the deat time register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubValue: 
//                counter value (ubValue = 0x01 .. 0x3F)
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vSetDeadTimePeriod(ubValue) CCU60_T12DTC = (CCU60_T12DTC & ~(uword)0x003F) | ubValue


//****************************************************************************
// @Macro         CCU60_vEnableShadowTransfer(TimerNr) 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the transfer from the shadow registers 
//                to the actual CCU60 registers.
//                
//                The following definitions for TimerNr are available: 
//                CCU60_TIMER_12
//                CCU60_TIMER_13
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TimerNr: 
//                Name of the CCU60 timer to be used
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define CCU60_vEnableShadowTransfer(TimerNr) CCU60_vEnableShadowTransfer_##TimerNr()
#define CCU60_vEnableShadowTransfer_CCU60_TIMER_12() CCU60_TCTR4 |= 0x0040
#define CCU60_vEnableShadowTransfer_CCU60_TIMER_13() CCU60_TCTR4 |= 0x4000


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CCU60_NodeI0_INT    0x30
#define CCU60_NodeI1_INT    0x31


// USER CODE BEGIN (CCU60_Header,9)

// USER CODE END


#endif  // ifndef _CCU60_H_
