#define _OTHER_C_

#include "other.h"
/*
  
*/

unsigned short buz_time = 0;

void init_buz()
{
	buz_on(4);
}
void buz_on(unsigned short time)
{
    if(time>buz_time)
		{
			buz_time = time;
		}
}
void update_buz()
{
	--buz_time?BUZON:BUZOFF;
}
