#define _TIME_C_

#include "time.h"
/*
  
*/

uint8 whileTime = 0;

void delay(uint16 ms)
{
	unsigned int volatile i,j;
	for (i = 0; i < ms; i++)
	{
	    for(j = 0; j < 1000; j++) ;
	}
}

uint4 while_Time()
{
	if(whileTime)
	{
		return FALSE;
	}
	else
	{
		whileTime = WHILE_TIME;
		return TRUE;
	}
	
}
//0.1S更新一次
void while_Time_Minus()
{
	whileTime?--whileTime:0;
}