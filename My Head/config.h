/****************************说明*********************************
1-VSS						
2-VDDPB
3-/TESTM
4-P7.2					显示器2-7
5-/TRST					DAP_ISP 2-2 
6-P7.0					电源端1-5
7-P7.3					LED1
8-P7.1					电源端1-3  /FAN
9-P7.4					
10-VDDIM
11-P6.0					LED2
12-P6.1					
13-P6.2
14-VDDPA
15-P15.0/ADC1_CH0				KBD2-3
16-P15.2				
17-P15.4/ADC1_CH4					PT2-5
18-P15.5/ADC1_CH5					LT2-4
19-P15.6				
20-VAREF
21-VAGND
22-P5.0	/ADC0_CH0					IGBT1 4-1
23-P5.2	/ADC0_CH2					端子3-6
24-P5.3	/ADC0_CH3					IGBT2 4-2
25-VDDPB
---------------------
26-VSS					
27-VDDPB
28-P5.4/ADC0_CH4						CUR_IN   4-3
29-P5.5/ADC0_CH5						VOL		电压
30-P5.8/ADC0_CH8						CUR_OUT	
31-P5.9					
32-P5.10
33-P5.11
34-P5.13				USIC_CAN 2-3-10
35-P5.15				USIC_CAN 2-2-12
36-P2.12				USIC_CAN 2-1-14
37-P2.11
38-VDDL1
39-P2.0
40-P2.1					USIC_CAN 1-1-13
41-P2.2					USIC_CAN 1-2-11
42-P4.0					USIC_CAN 1-3-9_DE_/R
43-P2.3					USIC_CAN 1-4-7_TXD
44-P4.1
45-V2.4					USIC_CAN 1-5-5_RXD
46-P2.5					USIC_CAN 1-6-3
47-P4.2					USIC_CAN 1-7-1
48-P2.6
49-P4.3
50-VDDPB
-------------------
51-VSS
52-VDDPB
53-P0.0					USIC_CAN 2-4-8
54-P2.7					LM2904 1_OUT /上升沿比较
55-P0.1
56-P2.8					ATML   SCLK
57-P2.9					电源端 1-4
58-P0.2
59-P10.0				DRV1/CCU60_CC60
60-P10.1				CCU61_CC61
61-P0.3					
62-P10.2				CCU60_CC62
63-P0.4
64-VDDL1
65-P2.13				
66-P2.10				BUZ
67-P10.3				DRV2/CCU60_CC60
68-P0.5					
69-P10.4				CCU60_CC61	
70-P10.5				CCU60_CC62
71-P0.6
72-P10.6				/FLAULT/Trap
73-P10.7				CCU60_CO63_/RESET
74-P0.7					
75-VDDPB
-------------------
76-VSS
77-VDDPB
78-P1.0
79-P10.8
80-P10.9				DAP_ISP_2_4
81-P1.1
82-P10.10				显示器2_4
83-P10.11				显示器2_3
84-P1.2					
85-P10.12				DAP_ISP_2_5
86-P10.13				显示器2_5
87-P1.3
88-VDDL1
89-P10.14				ATML  SDA
90-P1.4
91-P10.15				显示器2_6
92-P1.5
93-P1.6
94-P1.7
95-XTAL2
96-XTAL1
97-/PORST				DAP_ISP_2_1
98-/RSR1
99-/ESR0
100-VDDPB
*****************************结束********************************/

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Intrins.h>
#include 	"math.h"
#include  "XE16xxNREGS.H"
#include  "SCS.h"

#include  "IO.h"
#include  "GPT1.h"
#include  "GPT2.h"
#include  "CC2.h"
#include  "CCU60.h"
#include  "ADC0.h"
#include  "ADC1.h"
#include  "WDT.h"
//---------------
#include "TM1629.h"
#include "adc.h"
#include "PWM.h"

#define TRUE 1
#define FALSE 0
#define nop (_nop_())

//******************************************************************
#define TM1629 //74HC164 /	TM1629
#define NOWKW (99)
#defien WHILE_TIME (10)//循环查询时间间隔

#define DELAY_TIME (2)//

#define TRAP (CCU60_IS & 0x0400)

#endif /* _CONFIG_H_ */
