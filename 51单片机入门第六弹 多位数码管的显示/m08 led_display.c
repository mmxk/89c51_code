#include <reg52.h>
#define u8 unsigned char
#define u16 unsigned int
	
#include <stdlib.h>

// λѡ

// code ROM   RAM
// u8 tab[34] = {};
u8 code seg_tab[] = {  // 1111111111111111111111111111111111111111111111111111111111111
	0x40, 0x79, 0x24, 0x30, 0x19,
	0x12, 0x02, 0x78, 0x00, 0x10};  //�����ڴ�ռ�

void delay_ms(u16 num);

void main()
{
	u16 num = 0; //���� 0~60
	u16 shiwei, gewei, i;
	while(1) //ѭ����ʾ0~60
	{
		//34  ʮλ��3 ��λ��4
		shiwei = num/10; //ȡģ   34/10 = 3
		gewei = num%10; //ȡ��	34%10 = 4	
		for(i = 100; i>0; i--)  // ��ʱ������
		{
			delay_ms(2);
			P3 = 0x01; //��λλѡ
			P2 = seg_tab[shiwei];
				
			delay_ms(2);
			P3 = 0x02; //��λλѡ
			P2 = seg_tab[gewei];
		}		
		num ++;
		if(num == 60) num = 0;
		
	}
}

void delay_ms(u16 num) //u16 65535 16λ        u8 256 8λ
{
 	u16 x, y;  // 2222222222222222222222222222222222222222222222222222222222222222222222
	for(x = num; x > 0; x--)
		for(y = 110; y > 0; y--);
}