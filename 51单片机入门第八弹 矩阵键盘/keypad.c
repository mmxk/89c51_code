// Header: 51��Ƭ�����ŵڰ˵�
// File Name: �������
// UP: hhhmxk
// Date: 2020/12/7

#include <reg52.h>
typedef unsigned int u16;
typedef unsigned char u8;

// �������ֵ
u8 code seg_tab[] = {
	0x40, 0x79, 0x24, 0x30, 0x19,
	0x12, 0x02, 0x78, 0x00, 0x10};

#define SEG P0 // ����ܶ�ѡ�˿�
#define KEYPAD P1 // ������̿��ƶ˿�
	
void delay_ms(u16);
void led_display(u8); 
u8 keypad_scan(void); // return
	
void main()
{
	u8 num;
	while(1)
	{
		switch ( keypad_scan() ) // keypad_scan() ��һ�������ֵ u8
		{
			case 0xee:num = 0;break;				
			case 0xed:num = 1;break;				
			case 0xeb:num = 2;break;				
			case 0x7e:num = 3;break;
			case 0xee:num = 0;break;				
			case 0xed:num = 1;break;				
			case 0xeb:num = 2;break;				
			case 0x7e:num = 3;break;
			case 0xee:num = 0;break;				
			case 0xed:num = 1;break;				
			case 0xeb:num = 2;break;				
			case 0x7e:num = 3;break;
			case 0xee:num = 0;break;				
			case 0xed:num = 1;break;				
			case 0xeb:num = 2;break;				
			case 0x7e:num = 3;break;			
			default:break; // 
		}
		
		led_display(num);
	}
}

u8 keypad_scan(void) // ����ɨ�躯��������ֵΪ��ֵ��encode
{
	u8 temp;
	KEYPAD = 0xf0;
	if(KEYPAD != 0xf0)
	{
		delay_ms(10); // ����
		if(KEYPAD != 0xf0)
		{
			temp = KEYPAD;
			KEYPAD = 0x0f;
			delay_ms(5);
			temp = temp | KEYPAD;
			return temp;				
		}
	}
}

void led_display(u8 number) // ���������ʾ��װ�ɺ���
{
	SEG = seg_tab[number];
}

void delay_ms(u16 num)
{
	u16 x, y;
	for(x = num; x > 0; x --)
		for(y = 110; y > 0; y--);		
}

//void display(u8 num)
//{
//	u8 shiwei, gewei; // ���ֵ�ʮλ ��λ
//	shiwei = num/10; //ȡģ   34/10 = 3
//	gewei = num%10; //ȡ��	34%10 = 4
//	
//	w1 = 1; //��λλѡ
//	dx = seg_tab[shiwei] | 0x80; //ȥ�������С��  ����ͬ��
//	delay_ms(2);
//	w1 = 0;

//	w2 = 1; //��λλѡ
//	dx = seg_tab[gewei] | 0x80;
//	delay_ms(2);
//	w2 = 0;
//}