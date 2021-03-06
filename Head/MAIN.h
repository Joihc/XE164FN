//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.h
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for 
//                the MAIN module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/6 08:54:50
//
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,1)

// USER CODE END



#ifndef _MAIN_H_
#define _MAIN_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************
#define KEIL

#define SEG(func) (unsigned int)(((unsigned long)((void (far*)(void))func) >> 16))
#define SOF(func) (unsigned int)(((void (far *) (void))func))

// USER CODE BEGIN (MAIN_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,7)
#include "config.h"
// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************


void MAIN_vUnlockProtecReg(void);

void MAIN_vLockProtecReg(void);

void MAIN_vChangeFreq(void);


// USER CODE BEGIN (MAIN_Header,8)
void ViewSet(uint16 ShowNum);

void DetectNullPot();
void DetectCoilHot();
void DetectCoilCut();
void DetectIGBTHot_1();
void DetectIGBTCut_1();
void DetectIGBTHot_2();
void DetectIGBTCut_2();
void DetectVLow();
void DetectVHight();
void DetectVPP();
void DetectSwitchCut();
void DetectUnderPotCut();
void DetectUnderPotHot();
void DetectIgbtError();
void DetectTransformerCut();

void SetFirstOpen();
void settest(int16 test);
	
void mainUpdate();
void main_500ms();
// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,9)

// USER CODE END


//****************************************************************************
// @Project Includes
//****************************************************************************



// USER CODE BEGIN (MAIN_Header,10)

// USER CODE END


#endif  // ifndef _MAIN_H_
