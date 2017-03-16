//****************************************************************************
// @Module        Analog / Digital Converter (ADC1)
// @Filename      ADC1.h
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for 
//                the ADC1 module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/14 10:07:43
//
//****************************************************************************

// USER CODE BEGIN (ADC1_Header,1)

// USER CODE END


#ifndef _ADC1_H_

#define _ADC1_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (ADC1_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ADC1_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies ADC1 analog channel 0
#define ADC1_ANA_0 0

//   This parameter identifies ADC1 analog channel 1
#define ADC1_ANA_1 1

//   This parameter identifies ADC1 analog channel 2
#define ADC1_ANA_2 2

//   This parameter identifies ADC1 analog channel 3
#define ADC1_ANA_3 3

//   This parameter identifies ADC1 analog channel 4
#define ADC1_ANA_4 4

//   This parameter identifies ADC1 analog channel 5
#define ADC1_ANA_5 5

//   This parameter identifies ADC1 analog channel 6
#define ADC1_ANA_6 6

//   This parameter identifies ADC1 analog channel 7
#define ADC1_ANA_7 7

//   This parameter identifies ADC1 -Source 0
#define ADC1_SOURCE_0 0

//   This parameter identifies ADC1 -Source 1
#define ADC1_SOURCE_1 1

//   This parameter identifies ADC1 -Source 2
#define ADC1_SOURCE_2 2


// USER CODE BEGIN (ADC1_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************


// USER CODE BEGIN (ADC1_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC1_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC1_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void ADC1_vInit(void);
void ADC1_vStartSeq0ReqChNum(uint8 ubExtTrg, uint8 ubEnIntr, uint8 ubRFill, uint8 ubChannelNum);


// USER CODE BEGIN (ADC1_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         uint16 ADC1_uwBusy() 
//
//----------------------------------------------------------------------------
// @Description   This macro checks the conversion state of the current ADC 
//                channel by examination of the busy flag (BUSY).It returns 
//                '1' while a conversion is running.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns a 1 if A/D converter is active, else 0
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define ADC1_uwBusy()  (ADC1_GLOBSTR & 0x0001)

//****************************************************************************
// @Macro         uint16 ADC1_uwGetResultData(RegNum) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the left aligned, 10-bit result data of 
//                the last conversion from requested result register
//                Ex- RegNum = RESULT_REG_0,for Result register 0
//                    RegNum = RESULT_REG_2,for Result register 2
//                  - For 8 bit resolution user has to right shift the result
//                    by 2 bits as shown below
//                    uwResult = ADC0_uwGetResultData(RESULT_REG_0);
//                    uwResult >>= 2;
//                NOTE -
//                If this macro is called before ADC1_uwGetResultChNum macro 
//                for the same result register then channel information will 
//                be lost.So always call ADC1_uwGetResultChNum macro before 
//                this macro if channel information is required.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns result data from requested result register
//
//----------------------------------------------------------------------------
// @Parameters    RegNum: 
//                RegNum: defines the result register number
//
//----------------------------------------------------------------------------
// @Date          2017/3/14
//
//****************************************************************************

#define ADC1_uwGetResultData(RegNum)  (ADC1_uwGetResultData_##RegNum)
#define ADC1_uwGetResultData_RESULT_REG_0 ((ADC1_RCR0 & 0x1000) ? ((ADC1_RESR0 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_1 ((ADC1_RCR1 & 0x1000) ? ((ADC1_RESR1 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_2 ((ADC1_RCR2 & 0x1000) ? ((ADC1_RESR2 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_3 ((ADC1_RCR3 & 0x1000) ? ((ADC1_RESR3 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_4 ((ADC1_RCR4 & 0x1000) ? ((ADC1_RESR4 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_5 ((ADC1_RCR5 & 0x1000) ? ((ADC1_RESR5 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_6 ((ADC1_RCR6 & 0x1000) ? ((ADC1_RESR6 & 0x0fff) >> 2) : 0)
#define ADC1_uwGetResultData_RESULT_REG_7 ((ADC1_RCR7 & 0x1000) ? ((ADC1_RESR7 & 0x0fff) >> 2) : 0)

//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (ADC1_Header,9)

// USER CODE END


#endif  // ifndef _ADC1_H_
