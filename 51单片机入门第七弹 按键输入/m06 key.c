// Header: 51单片机入门第七弹
// File Name: 独立按键 按键点灯
// UP: hhhmxk
// Date: 2020/7/26

#include <reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;

void delay_ms(u16 x); // 延时函数声明

sbit key = P2^0;
sbit led = P3^0;

void main()
{
	while(1)
	{
		if(key == 0) // 查询P20引脚是否为0，若为零就说明被按下了
		{
			delay_ms(10); //按键消抖
			if(key == 0) // 再次查询，确实按键是否真的被按下
			{
				// 在这里写你想让单片机干的事
				led = 0; 
			}
		}	
	}
}

void delay_ms(u16 x) // 延时函数具体实现
{
	u16 i,j;
	for(i = x; i > 0; i --)
		for(j = 110; j > 0; j --);		
}




// 25行处
//				if(i == 0)
//				{
//					P0 = 0xfe; //第一个灯亮
//					i = 1;
//					while(!key); //松手检测
//					continue;
//				}
//				P0 = (P0<<1)|0x01;
//				if(P0 == 0xef) P0 = 0xfe;
//				while(!key); //松手检测