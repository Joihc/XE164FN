#define _OTHER_C_

#include "other.h"
/*
  
*/

uint8 buz_time = 0;
uint4 buz_state =0;

void init_buz()
{
	buz_on(10);
	while(buz_time!=0);
}
void buz_on(uint8 time)
{
    if(time>buz_time)
		{
			buz_time = time;
		}
}
void update_buz()
{
	if(buz_time >0)
	{
		BUZ_ON;
	}
}
void buz_sum()//50ms
{
	buz_time>0?buz_time--:0;
}
