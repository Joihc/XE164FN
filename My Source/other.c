#define _OTHER_C_

#include "other.h"
/*
  
*/

uint8 buz_time = 0;

void init_buz()
{
	buz_on(10);
	while(buz_time!=0);
}
void buz_on(uint8 time = 1)
{
    if(time>buz_time)
		{
			buz_time = time;
		}
}
void update_buz()//0.1s
{
	if(buz_time >0)
	{
		--buz_time?BUZ_ON:BUZ_OFF;
	}
}
