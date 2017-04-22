#define _ADC_C_

#include "ADC.h"

//***************************热敏电阻 10输出量 100K NTC*******************************
const uint16  rtTable1[] =
 {
    0x03fb,	// -40.00		3225.0000
    0x03fb,	// -39.00		3026.0000
    0x03fb,	// -38.00		2840.0000
    0x03fb,	// -37.00		2665.0000
    0x03fa,	// -36.00		2501.0000
    0x03fa,	// -35.00		2348.0000
    0x03fa,	// -34.00		2204.0000
    0x03fa,	// -33.00		2070.0000
    0x03f9,	// -32.00		1945.0000
    0x03f9,	// -31.00		1828.0000
    0x03f9,	// -30.00		1718.0000
    0x03f8,	// -29.00		1614.0000
    0x03f8,	// -28.00		1518.0000
    0x03f7,	// -27.00		1428.0000
    0x03f7,	// -26.00		1344.0000
    0x03f6,	// -25.00		1267.0000
    0x03f6,	// -24.00		1194.0000
    0x03f6,	// -23.00		1127.0000
    0x03f5,	// -22.00		1063.0000
    0x03f4,	// -21.00		1004.0000
    0x03f4,	// -20.00		948.8000
    0x03f3,	// -19.00		896.3000
    0x03f3,	// -18.00		847.1000
    0x03f2,	// -17.00		801.0000
    0x03f1,	// -16.00		757.8000
    0x03f0,	// -15.00		717.2000
    0x03f0,	// -14.00		679.0000
    0x03ef,	// -13.00		643.2000
    0x03ee,	// -12.00		609.6000
    0x03ed,	// -11.00		577.9000
    0x03ec,	// -10.00		548.1000
    0x03eb,	// -9.00		519.7000
    0x03ea,	// -8.00		492.8000
    0x03e9,	// -7.00		467.5000
    0x03e8,	// -6.00		443.5000
    0x03e7,	// -5.00		420.9000
    0x03e6,	// -4.00		399.5000
    0x03e4,	// -3.00		379.3000
    0x03e3,	// -2.00		360.2000
    0x03e1,	// -1.00		342.2000
    0x03e0,	// 0.00		325.1000
    0x03de,	// 1.00		309.4000
    0x03dd,	// 2.00		294.5000
    0x03db,	// 3.00		280.4000
    0x03da,	// 4.00		267.0000
    0x03d8,	// 5.00		254.3000
    0x03d6,	// 6.00		242.2000
    0x03d4,	// 7.00		230.7000
    0x03d2,	// 8.00		219.9000
    0x03d0,	// 9.00		209.5000
    0x03ce,	// 10.00		199.7000
    0x03cb,	// 11.00		190.4000
    0x03c9,	// 12.00		181.6000
    0x03c7,	// 13.00		173.2000
    0x03c4,	// 14.00		165.2000
    0x03c1,	// 15.00		157.7000
    0x03bf,	// 16.00		150.5000
    0x03bc,	// 17.00		143.7000
    0x03b9,	// 18.00		137.2000
    0x03b6,	// 19.00		131.0000
    0x03b3,	// 20.00		125.2000
    0x03b0,	// 21.00		119.6000
    0x03ac,	// 22.00		114.3000
    0x03a9,	// 23.00		109.3000
    0x03a5,	// 24.00		104.5000
    0x03a2,	// 25.00		100.0000
    0x039e,	// 26.00		95.6800
    0x039a,	// 27.00		91.5700
    0x0396,	// 28.00		87.6600
    0x0392,	// 29.00		83.9300
    0x038d,	// 30.00		80.3900
    0x0389,	// 31.00		77.0100
    0x0384,	// 32.00		73.7900
    0x0380,	// 33.00		70.7300
    0x037b,	// 34.00		67.8100
    0x0376,	// 35.00		65.0300
    0x0371,	// 36.00		62.3800
    0x036c,	// 37.00		59.8400
    0x0367,	// 38.00		57.4300
    0x0361,	// 39.00		55.1300
    0x035c,	// 40.00		52.9300
    0x0356,	// 41.00		50.8300
    0x0351,	// 42.00		48.8300
    0x034b,	// 43.00		46.9200
    0x0345,	// 44.00		45.0900
    0x033f,	// 45.00		43.3400
    0x0339,	// 46.00		41.6700
    0x0332,	// 47.00		40.0800
    0x032c,	// 48.00		38.5500
    0x0325,	// 49.00		37.0900
    0x031f,	// 50.00		35.7000
    0x0318,	// 51.00		34.3600
    0x0311,	// 52.00		33.0800
    0x030a,	// 53.00		31.8600
    0x0303,	// 54.00		30.6800
    0x02fc,	// 55.00		29.5600
    0x02f5,	// 56.00		28.4800
    0x02ed,	// 57.00		27.4500
    0x02e6,	// 58.00		26.4600
    0x02de,	// 59.00		25.5100
    0x02d7,	// 60.00		24.6000
    0x02cf,	// 61.00		23.7300
    0x02c7,	// 62.00		22.8900
    0x02c0,	// 63.00		22.0900
    0x02b8,	// 64.00		21.3200
    0x02b0,	// 65.00		20.5800
    0x02a8,	// 66.00		19.8600
    0x02a0,	// 67.00		19.1800
    0x0298,	// 68.00		18.5200
    0x0290,	// 69.00		17.8900
    0x0288,	// 70.00		17.2900
    0x027f,	// 71.00		16.7000
    0x0277,	// 72.00		16.1400
    0x026f,	// 73.00		15.6000
    0x0267,	// 74.00		15.0800
    0x025e,	// 75.00		14.5800
    0x0256,	// 76.00		14.1000
    0x024e,	// 77.00		13.6400
    0x0245,	// 78.00		13.1900
    0x023d,	// 79.00		12.7600
    0x0235,	// 80.00		12.3500
};
const uint16  rtTable2[] =
{
    0x022c,	// 81.00		11.9500
    0x0224,	// 82.00		11.5600
    0x021c,	// 83.00		11.1900
    0x0213,	// 84.00		10.8300
    0x020b,	// 85.00		10.4900
    0x0203,	// 86.00		10.1500
    0x01fb,	// 87.00		9.8300
    0x01f2,	// 88.00		9.5180
    0x01ea,	// 89.00		9.2170
    0x01e2,	// 90.00		8.9270
    0x01da,	// 91.00		8.6480
    0x01d2,	// 92.00		8.3800
    0x01ca,	// 93.00		8.1210
    0x01c2,	// 94.00		7.8710
    0x01ba,	// 95.00		7.6300
    0x01b3,	// 96.00		7.3980
    0x01ab,	// 97.00		7.1750
    0x01a3,	// 98.00		6.9590
    0x019c,	// 99.00		6.7510
    0x0194,	// 100.00		6.5500
    0x018d,	// 101.00		6.3570
    0x0186,	// 102.00		6.1700
    0x017f,	// 103.00		5.9890
    0x0178,	// 104.00		5.8150
    0x0171,	// 105.00		5.6470
    0x016a,	// 106.00		5.4850
    0x0163,	// 107.00		5.3280
    0x015c,	// 108.00		5.1760
    0x0156,	// 109.00		5.0300
    0x014f,	// 110.00		4.8880
    0x0149,	// 111.00		4.7510
    0x0143,	// 112.00		4.6190
    0x013d,	// 113.00		4.4910
    0x0136,	// 114.00		4.3670
    0x0130,	// 115.00		4.2470
    0x012b,	// 116.00		4.1310
    0x0125,	// 117.00		4.0180
    0x011f,	// 118.00		3.9090
    0x0119,	// 119.00		3.8040
    0x0114,	// 120.00		3.7020
    0x010e,	// 121.00		3.6020
    0x0109,	// 122.00		3.5060
    0x0104,	// 123.00		3.4130
};
      //--------130/5 =[0]-[26]
const uint8  rtTable3[] =
{
  0xff,	// 124.00		3.3220
  0xf9,//---0x0f9,	// 125.00		3.2340
  0xf4,	// 126.00		3.1440
  0xef,	// 127.00		3.0570
  0xea,	// 128.00		2.9730
  0xe5,	// 129.00		2.8910
  0xe0,	// 130.00		2.8120
  0xdb,	// 131.00		2.7350
  0xd7,	// 132.00		2.6610
  0xd2,	// 133.00		2.5890
  0xcd,	// 134.00		2.5190
  0xc9,	// 135.00		2.4520
  0xc5,	// 136.00		2.3870
  0xc0,	// 137.00		2.3230
  0xbc,	// 138.00		2.2620
  0xb8,	// 139.00		2.2030
  0xb4,	// 140.00		2.1460
  0xb0,	// 141.00		2.0910
  0xad,	// 142.00		2.0370
  0xa9,	// 143.00		1.9850
  0xa5,	// 144.00		1.9350
  0xa2,	// 145.00		1.8860
  0x9e,	// 146.00		1.8390
  0x9b,	// 147.00		1.7930
  0x98,	// 148.00		1.7490
  0x95,	// 149.00		1.7060
  0x92,//---0x092,	// 150.00		1.6650
  0x8f,	// 151.00		1.6250
  0x8c,	// 152.00		1.5860
  0x89,	// 153.00		1.5480
  0x86,	// 154.00		1.5110
  0x83,	// 155.00		1.4760
  0x80,	// 156.00		1.4420
  0x7e,	// 157.00		1.4080
  0x7b,	// 158.00		1.3760
  0x79,	// 159.00		1.3440
  0x76,	// 160.00		1.3140
  0x74,	// 161.00		1.2840
  0x72,	// 162.00		1.2550
  0x6f,	// 163.00		1.2270
  0x6d,	// 164.00		1.2000
  0x6b,//---0x06b,	// 165.00		1.1730
  0x69,	// 166.00		1.1480
  0x67,	// 167.00		1.1230
  0x65,	// 168.00		1.0980
  0x63,	// 169.00		1.0740
  0x61,	// 170.00		1.0510
  0x5f,	// 171.00		1.0286
  0x5d,	// 172.00		1.0066
  0x5b,	// 173.00		0.9852
  0x59,	// 174.00		0.9643
  0x58,	// 175.00		0.9439
  0x56,	// 176.00		0.9225
  0x54,	// 177.00		0.9016
  0x52,	// 178.00		0.8813
  0x51,	// 179.00		0.8615
  0x4f,	// 180.00		0.8423
  0x4d,	// 181.00		0.8236
  0x4c,	// 182.00		0.8053
  0x4a,	// 183.00		0.7877
  0x49,	// 184.00		0.7705
  0x47,//---0x047,	// 185.00		0.7537
  0x46,	// 186.00		0.7375
  0x44,	// 187.00		0.7216
  0x43,	// 188.00		0.7063
  0x42,	// 189.00		0.6913
  0x40,//---0x040,	// 190.00		0.6768
  0x3f,	// 191.00		0.6627
  0x3e,	// 192.00		0.6489
  0x3d,	// 193.00		0.6356
  0x3b,	// 194.00		0.6226
  0x3a,	// 195.00		0.6100
  0x39,	// 196.00		0.5977
  0x38,	// 197.00		0.5858
  0x37,	// 198.00		0.5742
  0x36,	// 199.00		0.5629
  0x35,	// 200.00		0.5519
  0x34,	// 201.00		0.5412
  0x33,	// 202.00		0.5308
  0x32,	// 203.00		0.5207
  0x31,	// 204.00		0.5108
  0x30,	// 205.00		0.5012
  0x2f,	// 206.00		0.4918
  0x2f,	// 207.00		0.4827
  0x2e,	// 208.00		0.4738
  0x2d,	// 209.00		0.4651
  0x2c,	// 210.00		0.4566
  0x2b,	// 211.00		0.4484
  0x2b,	// 212.00		0.4403
  0x2a,	// 213.00		0.4324
  0x29,	// 214.00		0.4247
  0x28,	// 215.00		0.4172
  0x28,	// 216.00		0.4099
  0x27,	// 217.00		0.4027
  0x26,	// 218.00		0.3956
  0x26,	// 219.00		0.3887
  0x25,	// 220.00		0.3820
  0x25,	// 221.00		0.3754
  0x24,	// 222.00		0.3689
  0x23,	// 223.00		0.3626
  0x23,	// 224.00		0.3563
  0x22,	// 225.00		0.3502
  0x22,	// 226.00		0.3438
  0x21,	// 227.00		0.3374
  0x20,	// 228.00		0.3312
  0x20,	// 229.00		0.3252
  0x1f,	// 230.00		0.3192
  0x1f,	// 231.00		0.3134
  0x1e,	// 232.00		0.3077
  0x1d,	// 233.00		0.3021
  0x1d,	// 234.00		0.2966
  0x1c,	// 235.00		0.2913
  0x1c,	// 236.00		0.2860
  0x1b,	// 237.00		0.2809
  0x1b,	// 238.00		0.2759
  0x1a,	// 239.00		0.2710
  0x1a,	// 240.00		0.2662
  0x1a,	// 241.00		0.2615
  0x19,	// 242.00		0.2569
  0x19,	// 243.00		0.2524
  0x18,	// 244.00		0.2480
  0x18,	// 245.00		0.2437
  0x17,	// 246.00		0.2395
  0x17,	// 247.00		0.2354
  0x17,	// 248.00		0.2314
  0x16,	// 249.00		0.2275
  0x16,	// 250.00		0.2236
  0x16,	// 251.00		0.2199
  0x15,	// 252.00		0.2162
  0x15,	// 253.00		0.2126
  0x14,	// 254.00		0.2090
  0x14,	// 255.00		0.2056
  0x14,	// 256.00		0.2022
  0x13,	// 257.00		0.1989
  0x13,	// 258.00		0.1957
  0x13,	// 259.00		0.1925
  0x13,	// 260.00		0.1894
  0x12,	// 261.00		0.1864
  0x12,	// 262.00		0.1834
  0x12,	// 263.00		0.1805
  0x11,	// 264.00		0.1776
  0x11,	// 265.00		0.1748
  0x11,	// 266.00		0.1720
  0x11,	// 267.00		0.1694
  0x10,	// 268.00		0.1667
  0x10,	// 269.00		0.1641
  0x10,	// 270.00		0.1616
  0x10,	// 271.00		0.1591
};
const uint4  rtTable4[] =
{
  0xf,	        // 272.00		0.1566
  0xf,	        // 273.00		0.1542
  0xf,	        // 274.00		0.1519
  0xf,	// 275.00		0.1496
  0xe,	        // 276.00		0.1473
  0xe,	        // 277.00		0.1451
  0xe,	        // 278.00		0.1429
  0xe,	        // 279.00		0.1407
  0xd,	// 280.00		0.1386
  0xd,	        // 281.00		0.1365
  0xd,	        // 282.00		0.1345
  0xd,	        // 283.00		0.1324
  0xd,	        // 284.00		0.1304
  0xc,	// 285.00		0.1285
  0xc,	        // 286.00		0.1266
  0xc,	        // 287.00		0.1247
  0xc,	        // 288.00		0.1228
  0xc,	        // 289.00		0.1210
  0xc,	// 290.00		0.1192
  0xb,	        // 291.00		0.1174
  0xb,	        // 292.00		0.1156
  0xb,	        // 293.00		0.1139
  0xb,	        // 294.00		0.1122
  0xb,	// 295.00		0.1105
  0xb,	        // 296.00		0.1088
  0xa,	        // 297.00		0.1071
  0xa,	        // 298.00		0.1055
  0xa,	        // 299.00		0.1039
  0xa	// 300.00		0.1023
};
//电压比例
float vol_f=0;

uint8 temps_num =0;
uint8 temps[] ={0,0,0,0};

uint8 switch_now = 0;
int16 coil_temp =0;
int16 pot_temp =0;
int16 null_num =0;
int16 igbt_one_temp=0;
int16 igbt_two_temp=0;
uint16 in_ampere=0;
uint16 out_ampere =0;


uint16 vol[VIL_LENGTH]={0};
uint8 vol_i =0;
uint16 ping_vol =380;
uint16 pong_vol =380;

void init_adc()
{
	uint8 i =0;
	vol_f = (1.0*VOL_H1)/VOL_L1;
	for(;i<VIL_LENGTH;i++)
	{
		vol[i]=380;
	}
}
//1s更新
void updata_adc()
{
	ping_vol =380;
	pong_vol =380;
}

/* 无锅标准*/
bit get_no_p()
{
  if(get_in_ampere() <20)//0.5V
  {
    return 1;
  }
  return 0;
}

bit get_switch_cut()
{
	if(get_adc(0)>NULL_NUM)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*线盘温度过高*/
uint4 get_coil()
{
	int16 temp = get_coil_temp();
	if(temp>=TEMP_COIL)
	{
		return 1;//超温
	}
	else if(temp <= -35)
	{
		return 2;//开路
	}
	else
	{
		return 0;
	}
}
uint4 get_pot()
{
	int16 temp = get_pot_temp();
	if(temp>=TEMP_COIL)
	{
		return 1;//超温
	}
	else if(temp <= -35)
	{
		return 2;//开路
	}
	else
	{
		return 0;
	}
}
uint4 get_igbt_one()
{
	int16 temp = get_igbt_one_temp();
	if(temp>=TEMP_IGBT)
	{
		return 1;//超温
	}
	else if(temp <= -35)
	{
		return 2;//开路
	}
	else
	{
		return 0;
	}
}
uint4 get_igbt_two()
{
	int16 temp = get_igbt_two_temp();
	if(temp>=TEMP_IGBT)
	{
		return 1;//超温
	}
	else if(temp <= -35)
	{
		return 2;//开路
	}
	else
	{
		return 0;
	}
}

uint4 get_check_vol(uint4 state,uint4 operation)
{
	uint16 now_vol = get_vol();
	now_vol=operation?now_vol+VOL_FIX:now_vol;
	if(now_vol<VOL_LOW-VOL_GAP)
	{
		return 2;
	}
	else if((now_vol>=VOL_LOW-VOL_GAP)&&(now_vol<=VOL_LOW+VOL_GAP))
	{
		return state ==2?2:0;
	}
	else if((now_vol>=VOL_HIGHT-VOL_GAP)&&(now_vol<=VOL_HIGHT+VOL_GAP))
	{
		return state ==1?1:0;
	}
	else if(now_vol>VOL_HIGHT+VOL_GAP)
	{
		return 1;
	}
	return 0;
}

uint4 get_check_vol_on()
{
	uint16 now_pp_vol = abs(ping_vol-pong_vol);
	if(now_pp_vol>VOL_PING_PONG)
	{
		return 1;
	}
	return 0;
}
uint4 get_check_out_ampere()
{
		return get_adc(7)<2?FALSE:TRUE;
}
//读取挡位0
uint8 get_switch()
{
	
	temps[temps_num] = get_switch_by_anum(get_adc(0));
	temps_num = (++temps_num>3)?0:temps_num;
	if(temps[0]==temps[1]
		&&temps[0]==temps[2]
		&&temps[0]==temps[3]
		&&temps[0]!=9)
	{
		if(switch_now != temps[0])
		{
				buz_on(3);
		}
		if(temps[0] == 0)
		{
			SetFirstOpen();
		}
		switch_now=temps[0];
	}

	return switch_now;
}
//读取线盘温度1
int16 get_coil_temp()
{
	int16 temp = get_temp_by_anum(get_adc(1));
	if((coil_temp == 0) || (coil_temp-temp>TEMP_JUMP)||(temp-coil_temp>TEMP_JUMP))
	{
		coil_temp = temp;
		return temp;
	}
	if(coil_temp-temp>TEMP_GAP)
	{
		coil_temp--;
	}
	else if(temp-coil_temp>TEMP_GAP)
	{
		coil_temp++;
	}
	return coil_temp;
}
//读取锅底温度2
int16 get_pot_temp()
{
	int16 temp = get_temp_by_anum(get_adc(2));
	if((pot_temp == 0)||(pot_temp-temp>TEMP_JUMP)||(temp-pot_temp>TEMP_JUMP))
	{
		pot_temp = temp;
		return temp;
	}
	if(pot_temp-temp>TEMP_GAP)
	{
		pot_temp--;
	}
	else if(temp-pot_temp>TEMP_GAP)
	{
		pot_temp++;
	}
	return pot_temp;
}
//读取NULL3
int16 get_null_num()
{
	return 0;
}
//读取IGBT1温度4
int16 get_igbt_one_temp()
{
	int16 temp = get_temp_by_anum(get_adc(4));
	if(igbt_one_temp == 0||(igbt_one_temp-temp>TEMP_JUMP)||(temp-igbt_one_temp>TEMP_JUMP))
	{
		igbt_one_temp = temp;
		return temp;
	}
	if(igbt_one_temp-temp>TEMP_GAP)
	{
		igbt_one_temp--;
	}
	else if(temp-igbt_one_temp>TEMP_GAP)
	{
		igbt_one_temp++;
	}
	return igbt_one_temp;
}
//读取IGBT2温度5
int16 get_igbt_two_temp()
{
	int16 temp = get_temp_by_anum(get_adc(5));
	if((igbt_two_temp == 0)||(igbt_two_temp-temp>TEMP_JUMP)||(temp-igbt_two_temp>TEMP_JUMP))
	{
		igbt_two_temp = temp;
		return temp;
	}
	if(igbt_two_temp-temp>TEMP_GAP)
	{
		igbt_two_temp--;
	}
	else if(temp-igbt_two_temp>TEMP_GAP)
	{
		igbt_two_temp++;
	}
	return igbt_two_temp;
}
//读取输入电流6
uint16 get_in_ampere()
{
	return get_adc(6);
}
//读取输出电流7
uint16 get_out_ampere()
{
	return get_adc(7);
}
//读取电压8
uint16 get_vol()
{
	uint16 now_vol = 0;
	uint8 i =0;
	for(i=0;i<VIL_LENGTH;i++)
	{
		now_vol+=vol[i];
	}
	return now_vol/VIL_LENGTH;
}
uint16 get_adc(uint8 io)
{
	uint16 uwADCResult=0;
	switch(io)
	{
		case 0://挡位 
				ADC1_vStartSeq0ReqChNum(0, 0, 0,0);
				while(ADC1_uwBusy());
				uwADCResult=ADC1_uwGetResultData(RESULT_REG_0);
			break;
		case 1://线盘温度
				ADC1_vStartSeq0ReqChNum(0, 0, 0,5);
				while(ADC1_uwBusy());
				uwADCResult=ADC1_uwGetResultData(RESULT_REG_1);
			break;
		case 2://锅底温度
				ADC1_vStartSeq0ReqChNum(0, 0, 0,4);
				while(ADC1_uwBusy());
				uwADCResult=ADC1_uwGetResultData(RESULT_REG_2);
			break;
		case 3://NULL
				//ADC0_vStartSeq0ReqChNum(0, 0, 0,2);
				//while(ADC0_uwBusy());
				//uwADCResult=ADC0_uwGetResultData(RESULT_REG_3);
			break;
		case 4://IGBT1
				ADC0_vStartSeq0ReqChNum(0, 0, 0,0);
				while(ADC0_uwBusy());
				uwADCResult=ADC0_uwGetResultData(RESULT_REG_3);
			break;
		case 5://IGBT2
				ADC0_vStartSeq0ReqChNum(0, 0, 0,3);
				while(ADC0_uwBusy());
				uwADCResult=ADC0_uwGetResultData(RESULT_REG_4);
			break;
		case 6://输入电流
				ADC0_vStartSeq0ReqChNum(0, 0, 0,4);
				while(ADC0_uwBusy());
				uwADCResult=ADC0_uwGetResultData(RESULT_REG_5);
			break;
		case 7://输出电流
				ADC0_vStartSeq0ReqChNum(0, 0, 0,8);
				while(ADC0_uwBusy());
				uwADCResult=ADC0_uwGetResultData(RESULT_REG_6);
			break;
		case 8://电压
				ADC0_vStartSeq0ReqChNum(0, 0, 0,5);
				while(ADC0_uwBusy());
				uwADCResult=ADC0_uwGetResultData(RESULT_REG_7);
			break;
		case 9:
			break;
	}
	return uwADCResult;
}

//温度转换
static int16 get_temp_by_anum(uint16 anum)
{
  uint16 i = 0;
  //-40 -80
  if(anum > 556)
  {
    while(i <=120 && anum < rtTable1[i])
    {
      i++;
    }
    return i-40;
  }
  // 80 - 123
  else if(anum > 255)
  {
    while(i<=43 && anum < rtTable2[i])
    {
      i++;
    }
    return i+80;
  }
  // 124 -271
  else if(anum > 15)
  {
    while(i<=147 && anum < rtTable3[i] )
    {
      i++;
    }
    return i+124;
  }
  else
  {
    // 272 -300
    while(i<= 28 && anum < rtTable4[i])
    {
      i++;
    }
    return i+272;
  }
	//while(i < 340 && anum < rtTable1[i])
  //{
  //    i++;
  //}
  //return i-40;
}

static uint8 get_switch_by_anum(uint16 anum)
{
  if(anum >(SWITCH_0-SWITCH_AREA) && anum <(SWITCH_0+SWITCH_AREA))
  {
    return 0;
  }
  else if(anum > (SWITCH_1-SWITCH_AREA) && anum <(SWITCH_1+SWITCH_AREA))
  {
    return 1;
  }
    else if(anum > (SWITCH_2-SWITCH_AREA) && anum <(SWITCH_2+SWITCH_AREA))
  {
    return 2;
  }
    else if(anum > (SWITCH_3-SWITCH_AREA) && anum <(SWITCH_3+SWITCH_AREA))
  {
    return 3;
  }
    else if(anum > (SWITCH_4-SWITCH_AREA) && anum <(SWITCH_4+SWITCH_AREA))
  {
    return 4;
  }
    else if(anum > (SWITCH_5-SWITCH_AREA) && anum <(SWITCH_5+SWITCH_AREA))
  {
    return 5;
  }
    else if(anum > (SWITCH_6-SWITCH_AREA) && anum <(SWITCH_6+SWITCH_AREA))
  {
    return 6;
  }
    else if(anum > (SWITCH_7-SWITCH_AREA) && anum <(SWITCH_7+SWITCH_AREA))
  {
    return 7;
  }
    else if(anum > (SWITCH_8-SWITCH_AREA) && anum <(SWITCH_8+SWITCH_AREA))
  {
    return 8;
  }
  return 9;

}
void ADCUpdate()
{
	if(vol_i>=VIL_LENGTH)
	{
		vol_i=0;
	}
	vol[vol_i] = get_adc(8);
	if(vol[vol_i]<ping_vol)
	{
		ping_vol=vol[vol_i];
	}
	else if(vol[vol_i]>pong_vol)
	{
		pong_vol=vol[vol_i];
	}
	vol_i++;
}