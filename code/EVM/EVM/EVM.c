#include <avr/io.h>
#include "button.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;
int main(void)
{
	LCD_vInit();
	button_vInit('B',3);
	button_vInit('B',4);
	button_vInit('B',5);
	button_vInit('B',6);
	button_vInit('B',7);
	
	LCD_vSend_string("A=0");
	LCD_movecursor(1,12);
	LCD_vSend_string("B=0");
	LCD_movecursor(2,1);
	LCD_vSend_string("C=0");
	LCD_movecursor(2,12);
	LCD_vSend_string("D=0");
    while(1)
    {
		if (button_u8read('B',3)==1)
		{
			counter1++;
			LCD_movecursor(1,3);
			LCD_vSend_char(counter1+48);
			
		}
		else if(button_u8read('B',4)==1)
		{
			counter2++;
			LCD_movecursor(1,14);
			LCD_vSend_char(counter2+48);
			
		}
		else if(button_u8read('B',5)==1)
		{
			counter3++;
			LCD_movecursor(2,3);
			LCD_vSend_char(counter3+48);
			
		}
		else if(button_u8read('B',6)==1)
		{
			counter4++;
			LCD_movecursor(2,14);
			LCD_vSend_char(counter4+48);
			
		}
		else if(button_u8read('B',7)==1)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_movecursor(1,1);
			LCD_vSend_string("A=0");
			LCD_movecursor(1,12);
			LCD_vSend_string("B=0");
			LCD_movecursor(2,1);
			LCD_vSend_string("C=0");
			LCD_movecursor(2,12);
			LCD_vSend_string("D=0");
			LCD_movecursor(1,1);
		}
		_delay_ms(200);
    }
}

