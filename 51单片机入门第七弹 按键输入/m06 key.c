// Header: 51��Ƭ�����ŵ��ߵ�
// File Name: �������� �������
// UP: hhhmxk
// Date: 2020/7/26

#include <reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;

void delay_ms(u16 x); // ��ʱ��������

sbit key = P2^0;
sbit led = P3^0;

void main()
{
	while(1)
	{
		if(key == 0) // ��ѯP20�����Ƿ�Ϊ0����Ϊ���˵����������
		{
			delay_ms(10); //��������
			if(key == 0) // �ٴβ�ѯ��ȷʵ�����Ƿ���ı�����
			{
				// ������д�����õ�Ƭ���ɵ���
				led = 0; 
			}
		}	
	}
}

void delay_ms(u16 x) // ��ʱ��������ʵ��
{
	u16 i,j;
	for(i = x; i > 0; i --)
		for(j = 110; j > 0; j --);		
}




// 25�д�
//				if(i == 0)
//				{
//					P0 = 0xfe; //��һ������
//					i = 1;
//					while(!key); //���ּ��
//					continue;
//				}
//				P0 = (P0<<1)|0x01;
//				if(P0 == 0xef) P0 = 0xfe;
//				while(!key); //���ּ��