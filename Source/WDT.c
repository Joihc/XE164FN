//****************************************************************************
// @Module        Watchdog Timer (WDT)
// @Filename      WDT.c
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the WDT module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/6 08:55:01
//
//****************************************************************************

// USER CODE BEGIN (WDT_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (WDT_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (WDT_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (WDT_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (WDT_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (WDT_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (WDT_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (WDT_General,8)

// USER CODE END



//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (WDT_General,9)

// USER CODE END


//****************************************************************************
// @Function      void WDT_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the WDT function 
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

void WDT_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  - DISWDT executable only until End Of Init
  ///  - the input frequency is Fin / 16384
  ///  - period in normal watchdog mode =  819.200 usec
  ///  - period in time-out mode =  819.200 usec

  CPUCON1       |=  0x0000;      // CPU Control Register 1
  SCU_WDTREL     =  0xFFFC;      // WDT Reload Register
  SCU_WDTCS     |=  0x0000;      // WDT Control and Status Register



  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function WDT_vInit




// USER CODE BEGIN (WDT_General,10)

// USER CODE END

