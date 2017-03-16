#define _TIME_C_

#include "time.h"
/*
  
*/
void delay(uint16 ms)
{
	unsigned int volatile i,j;
	for (i = 0; i < ms; i++)
	{
	    for(j = 0; j < 1000; j++) ;
	}
}
