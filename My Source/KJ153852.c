#ifndef _KJ153852_C_
#define _KJ153852_C_


#include "KJ153852.h"

static volatile uint8 startTimeSecond=0;
static volatile uint16 startTimeMin =0;
static volatile uint8 stateTime =0;
static volatile uint8 waterStateTime;

static enum LED_STATE factoryState = ON;
static enum LED_STATE fanState = ON;
static enum LED_STATE frontState = ON;
static enum LED_STATE behandState = ON;
static enum LED_STATE errorState = ON;
static enum LED_STATE buzzState = ON;


static uint4 frontIndex =0;//0标识熄灭，1标识亮
static int16 frontNum =0;//当前需要显示的

static uint4 behandIndex = 0;//0 灭 1-℃ 2-分钟 3-KW

static int16 dT =0;//需要显示的温度
//分钟
static uint16 kW =0;//当前功率

static uint8 fireNum =0;//火焰个数
static uint8 errorNum =0;

//BUZZ
static uint4 lastState = 0;


static volatile double kwNum =0.0;

static uint4 listIndex;

static void setNumber(uint8 index , uint8 num);
static void setFactory();
static void setFan();
static void setFireNum(uint8 num);
static void setErrorNum(uint8 num);
static void setFrontNum();
static void setBehandNum();
static void indate(uint8 p);
static void display(uint4 state);
/*
	Function List : 1 indate()  写入
			2 display() 采用地址自动加1显示
			3 display2() 采用固定地址方式显示
*/

const uint8 NumberCode[]={
  0x3F, //0 0011 1111
  0x06,	//1 0000 0110
  0x5B, //2 0101 1011
  0x4F, //3 0100 1111
  0x66, //4 0110 0110
  0x6D, //5 0110 1101
  0x7d, //6 0111 1101
  0x07, //7 0010 0111
  0x7f, //8 0111 1111
  0x6f, //9 0110 1111
  0x40, //10 0100 0000 -号
  0x00,//不显示

  0x77, //A 0111 0111
  0x7C, //b 0111 1100
  0x39, //C 0011 1001
  0x5E, //d 0101 1110
};



//C0H开始
volatile uint8 buffCode_KJ153852[]={
    0x00, //0
    0x00, //1 00 11 1110
    0x00, //2
    0x00, //3
    0x00, //4
    0x00, //5
    0x00, //6
    0x00, //7
    0x00, //8
    0x00, //9
    0x00, //10
    0x00, //11
    0x00, //12
    0x00, //13
    0x00, //14
    0x00, //15
};


void whileUpdate_KJ153852()
{
	//更新显示
	uint8 i = 1;
  display(1);
	stateTime = startTimeSecond;
	setFactory();	
	setFireNum(fireNum);
	setErrorNum(errorNum);
	setFrontNum();
	setBehandNum();
	setFan();
}
void interuptUpdate_KJ153852()
{
  startTimeSecond++;
  if(startTimeSecond >=60)
  {
    startTimeSecond =0;
		if(startTimeMin<999)
		{
		    startTimeMin++;
		}
		else
		{
			startTimeMin=0;
		}
  }
	if(kwNum <9999)
	{
		kwNum += (1.0f*kW)/360;
	}
	else
	{
		kwNum = 0.0;
	}
}
void init_KJ153852()
{
  display(0);
}
void KJ153852_500ms()
{
	waterStateTime++;
	if(waterStateTime>59)
	{
		waterStateTime = 0;
	}
}
void setNumber(uint8 index , uint8 num)
{
	switch(index)
	{
		case 1:
			buffCode_KJ153852[14] &= 0x80;
			buffCode_KJ153852[14] |= NumberCode[num];
			break;
		case 2:
			buffCode_KJ153852[12] &= 0x80;
			buffCode_KJ153852[12] |= NumberCode[num];
			break;
		case 3:
			buffCode_KJ153852[10] &= 0x80;
			buffCode_KJ153852[10] |= NumberCode[num];
			break;
		case 4:
			buffCode_KJ153852[8] &= 0x80;
			buffCode_KJ153852[8] |= NumberCode[num];
			break;
		case 5:
			buffCode_KJ153852[6] &= 0x80;
			buffCode_KJ153852[6] |= NumberCode[num];
			break;
		case 6:
			buffCode_KJ153852[4] &= 0x80;
			buffCode_KJ153852[4] |= NumberCode[num];
			break;
		case 7:
			buffCode_KJ153852[2] &= 0x80;
			buffCode_KJ153852[2] |= NumberCode[num];
			break;
	}
}

void setFactory()
{
	buffCode_KJ153852[15] &= ~(1<< 2);
	buffCode_KJ153852[13] &= ~(1<< 2);
	buffCode_KJ153852[11] &= ~(1<< 2);
	buffCode_KJ153852[9] &= ~(1<< 2);
	buffCode_KJ153852[7] &= ~(1<< 2);
	buffCode_KJ153852[5] &= ~(1<< 2);
	buffCode_KJ153852[3] &= ~(1<< 2);
	if(factoryState == ON ||(factoryState == FLUSH && stateTime%2))
	{
			buffCode_KJ153852[15] |= (1<< 2);
			buffCode_KJ153852[13] |= (1<< 2);
			buffCode_KJ153852[11] |= (1<< 2);
			buffCode_KJ153852[9] |= (1<< 2);
			buffCode_KJ153852[7] |= (1<< 2);
			buffCode_KJ153852[5] |= (1<< 2);
			buffCode_KJ153852[3] |= (1<< 2);
	}
}
void setFan()
{
	if(fanState == ON)
	{
		if(waterStateTime%2)
		{
			buffCode_KJ153852[0] &= (~0x0A);
			buffCode_KJ153852[0] |= 0x0A;
			buffCode_KJ153852[0] &= (~0x14);
		}
		else
		{
			buffCode_KJ153852[0] &= (~0x0A);
			buffCode_KJ153852[0] &= (~0x14);
			buffCode_KJ153852[0] |= 0x14;
		}

	}
	else
	{
		if(stateTime%2)
		{
			buffCode_KJ153852[0] &= (~0x0A);
			buffCode_KJ153852[0] |= 0x0A;
			buffCode_KJ153852[0] &= (~0x14);
			buffCode_KJ153852[0] |= 0x14;
		}
		else
		{
			buffCode_KJ153852[0] &= (~0x0A);
			buffCode_KJ153852[0] &= (~0x14);
		}

	}
	buffCode_KJ153852[0] &= 0xFE;
	buffCode_KJ153852[0] |= 0x01;
}



//最多13条火1 2 3 5 7 9 11 13
void setFireNum(uint8 num)
{
	buffCode_KJ153852[15] &= (~0x01);
	buffCode_KJ153852[15] &= (~0x02);
	buffCode_KJ153852[13] &= (~0x01);
	buffCode_KJ153852[13] &= (~0x02);
	buffCode_KJ153852[11] &= (~0x01);
	buffCode_KJ153852[11] &= (~0x02);
	buffCode_KJ153852[9] &= (~0x01);
	buffCode_KJ153852[9] &= (~0x02);
	buffCode_KJ153852[7] &= (~0x01);
	buffCode_KJ153852[7] &= (~0x02);
	buffCode_KJ153852[5] &= (~0x01);
	buffCode_KJ153852[5] &= (~0x02);
	buffCode_KJ153852[3] &= (~0x01);
	if(num>=1)
	{
			buffCode_KJ153852[15] |= 0x01;
	}
	if(num>=2)
	{
			buffCode_KJ153852[15] |= 0x02;
	}
	if(num>=3)
	{
			buffCode_KJ153852[13] |= 0x01;
	}
	if(num>=4)
	{
			buffCode_KJ153852[13] |= 0x02;
			buffCode_KJ153852[11] |= 0x01;
	}
	if(num>=5)
	{
			buffCode_KJ153852[11] |= 0x02;
			buffCode_KJ153852[9] |= 0x01;
	}
	if(num>=6)
	{
			buffCode_KJ153852[9] |= 0x02;	
			buffCode_KJ153852[7] |= 0x01;	
	}
	if(num>=7)
	{
			buffCode_KJ153852[7] |= 0x02;
			buffCode_KJ153852[5] |= 0x01;
	}
	if(num>=8)
	{
			buffCode_KJ153852[5] |= 0x02;
			buffCode_KJ153852[3] |= 0x01;
	}
	
	
}

//11条故障 0全灭
void setErrorNum(uint8 num)
{
	//锅具
	//锅底温
	//线盘温
	//IGBT温
	//电压异常
	//相位异常
	//电路异常
	//IGBT开路
	//锅底开路
	//线盘开路
	//传感器故障
	if((buzzState == ON)&& (stateTime%2) && (lastState==0))
	{
		lastState = 1;
		buz_on(4);
	}
	else
	{
		lastState = 0;
	}
	 if(errorState == OFF || (errorState == FLUSH && !(stateTime%2)))
	 {
			num =0;
	 }
		buffCode_KJ153852[15] &= (~0x08);
		buffCode_KJ153852[13] &= (~0x08);
		buffCode_KJ153852[11] &= (~0x08);
		buffCode_KJ153852[9] &= (~0x08);
		buffCode_KJ153852[7] &= (~0x08);
		buffCode_KJ153852[5] &= (~0x08);
		buffCode_KJ153852[3] &= (~0x08);
		buffCode_KJ153852[1] &= (~0x08);
		buffCode_KJ153852[1] &= (~0x04);
		buffCode_KJ153852[1] &= (~0x01);
		buffCode_KJ153852[0] &= (~0xA0);
	switch(num)
	{
		case 1:
			buffCode_KJ153852[15] |= 0x08;
			break;
		case 2:
			buffCode_KJ153852[13] |= 0x08;
			break;
		case 3:
			buffCode_KJ153852[11] |= 0x08;
			break;
		case 4:
			buffCode_KJ153852[9] |= 0x08;
			break;
		case 5:
			buffCode_KJ153852[7] |= 0x08;
			break;
		case 6:
			buffCode_KJ153852[5] |= 0x08;
			break;
		case 7:
			buffCode_KJ153852[3] |= 0x08;
			break;
		case 8:
			buffCode_KJ153852[1] |= 0x08;
			break;
		case 9:
			buffCode_KJ153852[1] |= 0x04;
			break;
		case 10:
			buffCode_KJ153852[1] |= 0x01;
			break;
		case 11:
			buffCode_KJ153852[0] |= 0xA0;
			break;
	}
}
//支持-999到9999  一位小数  默认增大了10倍
void setFrontNum()
{
	int16 num = frontNum;
	uint4 i = 4;
	int16 num_use;
	buffCode_KJ153852[8] &= ~(1<<7);
	if(frontState == OFF ||(frontState == FLUSH && stateTime%2 ))
	{
		while(i>=1)
		{
			setNumber(i--,11);
		}	
		return;
	}
	if(frontIndex)
	{
			buffCode_KJ153852[8] |= (1<<7);
	}
	if(num>9999)
	{
		num = 9999;
	}
	else if(num<-999)
	{
		num = -999;
	}
	buffCode_KJ153852[10] &= ~0x80;//.
	buffCode_KJ153852[10] |= 0x80;//.
	if(num == 0)
	{
		setNumber(i--,0);
		setNumber(i--,0);
		while(i>=1)
		{
			setNumber(i--,11);
		}	
	}
	else
	{
		i = 4;
		if(num>0)
		{
			num_use = num%10;
			while(num>0)
			{
				setNumber(i--,abs(num_use));
				num/=10;
				num_use = num%10;
			}
			if(i==3)
			{
				setNumber(i--,0);
			}
		}
		else
		{
			num_use = num%10;
			while(num!=0)
			{
				setNumber(i--,abs(num_use));
				num/=10;
				num_use = num%10;
			}
			if(i==3)
			{
				setNumber(i--,0);
			}
			setNumber(i--,10);
		}
		while(i>=1)
		{
				setNumber(i--,11);
		}
	}
}
//支持-99到999 
void setBehandNum()
{
	uint4 i = 7;
	int16 num_use;
	int16 num =0;
	
	buffCode_KJ153852[14] &= ~(1<<7);
	buffCode_KJ153852[12] &= ~(1<<7);
	buffCode_KJ153852[2]  &= ~(1<<7);
	
	if(behandState == OFF ||(behandState == FLUSH && stateTime%2 ))
	{
		while(i>=5)
		{
			setNumber(i--,11);
		}	
		return;
	}
	switch(behandIndex)
	{
		case 1:
			buffCode_KJ153852[14] |= (1<<7);
			num = dT;
			break;
		case 2:
			buffCode_KJ153852[12] |= (1<<7);
			num = startTimeMin;
			break;
		case 3:
			buffCode_KJ153852[2] |= (1<<7);
			num = kW;
			break;
	}
	if(num>999)
	{
		num = 999;
	}
	else if(num<-99)
	{
		num = -99;
	}
	buffCode_KJ153852[4] &= ~0x80;//.
	buffCode_KJ153852[6] &= ~0x80;//.
	if(num == 0)
	{
		if(behandIndex == 3)
		{
			while(i>=5)
			{
				setNumber(i--,10);
			}	
		}
		else
		{
			setNumber(i--,0);
			while(i>=5)
			{
				setNumber(i--,11);
			}	
		}
	}
	else
	{
		if(num>0)
		{
			num_use = num%10;
			while(num!=0)
			{
				setNumber(i--,abs(num_use));
				num/=10;
				num_use = num%10;
			}
		}
		else
		{
			num_use = num%10;
			while(num!=0)
			{
				setNumber(i--,abs(num_use));
				num/=10;
				num_use = num%10;
			}
			setNumber(i--,10);
		}
		while(i>=5)
		{
				setNumber(i--,11);
		}
	}
}
/* error = 101 无锅
        102 线盘超温
        103 线盘开路
        104 IGBT超温
        105 IGBT开路
        106 锅底超温
        107 锅底开路
        108 电压低或缺相
        109 电压高
        110 
        111 线盘或者互感器损坏
        112 驱动故障
        113 档位开路

        200+KW 无锅
        KW     正常
*/
void set_KJ153852(uint16 num,uint8 fire,int16 vol,int16 lt,int16 pt,int16 it)
{
	fireNum = fire;
	switch (num) {
    case 10001:
			kW = 0;
			errorNum = 1;
			factoryState = ON;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = OFF;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10002:
			kW = 0;
			errorNum = 3;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =1;
			dT=lt;
			frontNum = (int16)kwNum;
    break;
    case 10003:
			kW = 0;
			errorNum = 10;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10004:
		  kW = 0;
			errorNum = 4;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=it;
			frontNum = (int16)kwNum;
    break;
    case 10005:
			kW = 0;
			errorNum = 8;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10006:
			kW = 0;
			errorNum = 2;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =1;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10007:
			kW = 0;
			errorNum = 9;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10008:
			kW = 0;
			errorNum = 5;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 0;
			behandIndex =2;
			dT=pt;
			frontNum = vol;
    break;
    case 10009:
			kW = 0;
			errorNum = 5;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 0;
			behandIndex =2;
			dT=pt;
			frontNum = vol;
    break;
    case 10010:
			kW = 0;
			errorNum = 11;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			behandIndex =2;
			dT=pt;
			frontNum = kwNum;
    break;
    case 10011:
			kW = 0;
			errorNum = 6;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
		case 10012:
			kW = 0;
			errorNum = 6;
			factoryState = FLUSH;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    case 10013:
			kW = 0;
			errorNum = 11;
			factoryState = ON;
			fanState = OFF;
			frontState = ON;
			behandState = ON;
			errorState = FLUSH;
			buzzState = ON;
			frontIndex = 1;
			behandIndex =2;
			dT=pt;
			frontNum = (int16)kwNum;
    break;
    default:
			kW = num;
			errorNum = 0;
			factoryState = ON;
			fanState = kW?ON:FLUSH;
			frontState = ON;
			behandState = ON;
			errorState = OFF;
			buzzState = OFF;
			frontIndex = 1;
			behandIndex = 3;
			dT=pt;
			frontNum = (int16)pt;//kwNum;
    break;
  }
}

void indate(uint8 p)
{
	unsigned int i;
	STB_0;	//STB=0;//保证“STB”为低电平，程序不依赖于之前端口的状态
	//保证程序在实际运行中不会出现“端口迷失”
	nop;
	nop;
	for(i=0;i<8;i++)
	{
		CLK_0;//CLK=0;//先将“CLK”清零
		nop;
		nop;
		if(p &(1<<0))
		{
			DIO_1;//DIO=1;//需要传送的数据的低位为“1”，则把“DIO”清零
    }
		else
		{
			DIO_0;//DIO=0;//需要传送的数据的低位为“0”，则把“DIO”置高
		}
		nop;
		nop;
		CLK_1;//CLK=1;//送时钟的上升沿
		nop;
		nop;
		p=p>>1;//准备送下一个BIT
	}//送完一个字节后退出循环
}
//采用地址自动加1方式
void display(uint4 state)
{
	DIO_1;//DIO=1;
	nop;
	nop;
	CLK_1;//CLK=1;
	nop;
	nop;
	STB_1;//STB=1; //通讯开始前通讯端口全部初始化为“1”
	nop;
	nop;
	indate(writedatamode_z);  //传数据设置命令，设置采用地址自动加1方式写显示数据，
	nop;
	nop;
  STB_1;//STB=1; //数据设置命令传完后需要将“STB”置“1”
	nop;
	nop;
	indate(startaddress); //传起始地址
	//地址命令传完后，“STB”保持为“0”继续传需要显示的数据
  for(listIndex=0;listIndex<datacount;listIndex++)
  {
  		indate(state?buffCode_KJ153852[listIndex]:0xFF);  //在连续传显示的数据过程中，“STB”一直保持为”0“
  }
	nop;
	nop;
	STB_1;//STB=1; //传完所有的显示数据后（最多16BYTE）后，将“STB置“1”
	nop;
	nop;
	indate(disconmode); //传显示控制命令
	nop;
	nop;
	STB_1;//STB=1;    //显示控制命令传完后将“STB”置“1”
}
//----------------------------------------------采用固定地址方式传输地址和数据开始-----------
//采用固定地址方式
/*void  display2(unsigned char adress,unsigned char disa)
{
	DIO_1;//DIO=1;
	CLK_1;//CLK=1;
	STB_1;//STB=1;  //通讯开始前通讯端口全部初始化为“1”
	indate(writedatamode_g); //数据设置命令
	STB_1;//STB=1;
	indate(adress); //传显示数据对应的地址
	indate(disa); //保持“STB”=“0”，传1BYTE显示数据
	STB_1;//STB=1; //传完显示数据后将“STB”置“1”
}
*/
#endif
