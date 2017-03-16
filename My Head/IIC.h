#ifndef _IIC_H_
#define _IIC_H_

#include "config.h"
#include "time.h"

#ifndef _IIC_C_
#endif

#define tt_5us (delay(5))//延时5us 保证读写

#define SDA_1 (IO_vSetPin(IO_P10_14))//(P10_OUT_P14 = 1)
#define SDA_0 (IO_vResetPin(IO_P10_14))//(P10_OUT_P14 = 0)
#define SDA_T (IO_ubReadPin(IO_P10_14))//(P10_OUT_P14)

#define SCL_1 (IO_vSetPin(IO_P2_8))//(P2_OUT_P8 = 1)
#define SCL_0 (IO_vResetPin(IO_P2_8))//(P2_OUT_P8 = 0)

short IIC_SDA();
void IIC_Start();
void IIC_Stop();
void IIC_Ack();
void IIC_NoAck();
short IIC_GetACK();
uint8 IIC_SendByte(uint8 Data);
uint8 IIC_RecByte();

#endif /* _IIC_H_ */
