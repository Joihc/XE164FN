//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.c
// @Project       164FN.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE164FN-40F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          2017/3/6 08:54:58
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
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

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P0 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  P2.7 is used as alternate input for the CAPCOM2 input(CC2_20)
  ///  P2.9 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P2.10 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P2.0 - P2.3 output driver characteristic: strong driver
  ///  P2.4 - P2.7 output driver characteristic: strong driver
  ///  P2.8 - P2.13 output driver characteristic: strong driver

  ///  P2.0 - P2.3 output edge characteristic: sharp edge mode
  ///  P2.4 - P2.7 output edge characteristic: sharp edge mode
  ///  P2.8 - P2.13 output edge characteristic: sharp edge mode

  P2_IOCR09      =  0x0080;      // load port control register 9
  P2_IOCR10      =  0x0080;      // load port control register 10

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P4 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.0 is used as alternate input for the  Analog Input Pin (AN50)
  ///  P5.2 is used as alternate input for the  Analog Input Pin (AN52)
  ///  P5.3 is used as alternate input for the  Analog Input Pin (AN53)
  ///  P5.4 is used as alternate input for the  Analog Input Pin (AN54)
  ///  P5.5 is used as alternate input for the  Analog Input Pin (AN55)
  ///  P5.8 is used as alternate input for the  Analog Input Pin (AN58)


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  P6.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P6.0 - P6.2 output driver characteristic: strong driver

  ///  P6.0 - P6.2 output edge characteristic: sharp edge mode

  P6_IOCR00      =  0x0080;      // load port control register 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P7:
  ///  -----------------------------------------------------------------------
  ///  P7.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P7.1 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P7.2 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P7.3 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P7.0 - P7.3 output driver characteristic: strong driver
  ///  P7.4 - P7.4 output driver characteristic: strong driver

  ///  P7.0 - P7.3 output edge characteristic: sharp edge mode
  ///  P7.4 - P7.4 output edge characteristic: sharp edge mode

  P7_IOCR00      =  0x0080;      // load port control register 0
  P7_IOCR01      =  0x0080;      // load port control register 1
  P7_IOCR02      =  0x0080;      // load port control register 2
  P7_IOCR03      =  0x0080;      // load port control register 3

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P10:
  ///  -----------------------------------------------------------------------
  ///  P10.0 is used as alternate output for the CCU60 output(CC60)
  ///  - push/pull output is selected
  ///  P10.3 is used as alternate output for the CCU60 output(COUT60)
  ///  - push/pull output is selected
  ///  P10.6 is used as alternate input for the  CCU60 input(CTRAPA)
  ///  P10.10 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.11 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.13 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.15 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P10.0 - P10.3 output driver characteristic: strong driver
  ///  P10.4 - P10.7 output driver characteristic: strong driver
  ///  P10.8 - P10.11 output driver characteristic: strong driver
  ///  P10.12 - P10.15 output driver characteristic: strong driver

  ///  P10.0 - P10.3 output edge characteristic: sharp edge mode
  ///  P10.4 - P10.7 output edge characteristic: sharp edge mode
  ///  P10.8 - P10.11 output edge characteristic: sharp edge mode
  ///  P10.12 - P10.15 output edge characteristic: sharp edge mode

  P10_IOCR10     =  0x0080;      // load port control register 10
  P10_IOCR11     =  0x0080;      // load port control register 11
  P10_IOCR13     =  0x0080;      // load port control register 13
  P10_IOCR15     =  0x0080;      // load port control register 15

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P15:
  ///  -----------------------------------------------------------------------
  ///  P15.0 is used as alternate input for the  Analog Input Pin (AN0)
  ///  P15.4 is used as alternate input for the  Analog Input Pin (AN4)
  ///  P15.5 is used as alternate input for the  Analog Input Pin (AN5)



  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

