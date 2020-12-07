#include <reg52.h>
#define u8 unsigned char
#define u16 unsigned int
	
#include <stdlib.h>

// 位选

// code ROM   RAM
// u8 tab[34] = {};
u8 code seg_tab[] = {  // 1111111111111111111111111111111111111111111111111111111111111
	0x40, 0x79, 0x24, 0x30, 0x19,
	0x12, 0x02, 0x78, 0x00, 0x10};  //分配内存空间

void delay_ms(u16 num);

void main()
{
	u16 num = 0; //计数 0~60
	u16 shiwei, gewei, i;
	while(1) //循环显示0~60
	{
		//34  十位：3 个位：4
		shiwei = num/10; //取模   34/10 = 3
		gewei = num%10; //取余	34%10 = 4	
		for(i = 100; i>0; i--)  // 定时计数器
		{
			delay_ms(2);
			P3 = 0x01; //高位位选
			P2 = seg_tab[shiwei];
				
			delay_ms(2);
			P3 = 0x02; //低位位选
			P2 = seg_tab[gewei];
		}		
		num ++;
		if(num == 60) num = 0;
		
	}
}

void delay_ms(u16 num) //u16 65535 16位        u8 256 8位
{
 	u16 x, y;  // 2222222222222222222222222222222222222222222222222222222222222222222222
	for(x = num; x > 0; x--)
		for(y = 110; y > 0; y--);
}