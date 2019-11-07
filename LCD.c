
#define F_CPU 8000000ul
#include "LCD.h"
#include <util/delay.h>
//static void Enable()
//{
	////CMD_PORT|=(1<<EN);
	//DIO_Write( LCD_EN , HIGH);
	//_delay_us(500);
	////CMD_PORT&=~(1<<EN);
	//DIO_Write(LCD_EN , LOW);
	////_delay_us(100);
//}

static void LCD_sendCommand(uint8 CMND)
{
	DIO_Write(RS , LOW);
	DIO_Write(RW , LOW);
	
	DIO_Write(LCD_D4 , (CMND >> 4) &1);
	DIO_Write(LCD_D5 , (CMND >> 5) &1);
	DIO_Write(LCD_D6 , (CMND >> 6) &1);
	DIO_Write(LCD_D7 , (CMND >> 7) &1);
	
	DIO_Write( LCD_EN , HIGH);
	_delay_us(500);
	//CMD_PORT&=~(1<<EN);
	DIO_Write(LCD_EN , LOW);
	
	DIO_Write(LCD_D4 , (CMND >> 0) &1);
	DIO_Write(LCD_D5 , (CMND >> 1) &1);
	DIO_Write(LCD_D6 , (CMND >> 2) &1);
	DIO_Write(LCD_D7 , (CMND >> 3) &1);
	
	DIO_Write( LCD_EN , HIGH);
	_delay_us(500);
	//CMD_PORT&=~(1<<EN);
	DIO_Write(LCD_EN , LOW);
	
}


 void LCD_DataWr(uint8 Data)
{
	DIO_Write(RS , HIGH);
	DIO_Write(RW , LOW);
	
	DIO_Write(LCD_D4 , (Data >> 4) &1 );
	DIO_Write(LCD_D5 , (Data >> 5) &1 );
	DIO_Write(LCD_D6 , (Data >> 6) &1 );
	DIO_Write(LCD_D7 , (Data >> 7) &1 );
	
	DIO_Write( LCD_EN , HIGH);
	_delay_us(500);
	//CMD_PORT&=~(1<<EN);
	DIO_Write(LCD_EN , LOW);
	
	DIO_Write(LCD_D4 , (Data >> 0) &1);
	DIO_Write(LCD_D5 , (Data >> 1) &1);
	DIO_Write(LCD_D6 , (Data >> 2) &1);
	DIO_Write(LCD_D7 , (Data >> 3) &1);
	
	DIO_Write( LCD_EN , HIGH);
	_delay_us(500);
	//CMD_PORT&=~(1<<EN);
	DIO_Write(LCD_EN , LOW);

}




void LCD_init(void)
	LCD_sendCommand(LCD_CursorHome);

	_delay_ms(1);
	LCD_sendCommand(LCD_Set4Bit2Lin);

	_delay_ms(1);
	LCD_sendCommand(LCD_DisOnCurOnBliOff);

	_delay_ms(1);
	LCD_sendCommand(LCD_IncOnShiOff);

	_delay_ms(1);
	LCD_sendCommand(LCD_ClearScreen);
{
	LCD_gotoRowColumn(COPY_u8Row,COPY_u8Column);
	if (0<=COPY_u16num)
	{
		if (COPY_u16num<=9) LCD_DataWr(COPY_u16num+0x30);
		else if(COPY_u16num<=99)
		{
			LCD_DataWr((COPY_u16num/10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
		else if(COPY_u16num<=999)
		{
			LCD_DataWr((COPY_u16num/100)+0x30);
			LCD_DataWr(((COPY_u16num/10)%10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
		else if (COPY_u16num<=9999)
		{
			LCD_DataWr((COPY_u16num/1000)+0x30);
			LCD_DataWr(((COPY_u16num/100)%10)+0x30);
			LCD_DataWr(((COPY_u16num/10)%10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
		else if (COPY_u16num<=99999)
		{
			LCD_DataWr((COPY_u16num/10000)+0x30);
			LCD_DataWr(((COPY_u16num/1000)%10)+0x30);
			LCD_DataWr(((COPY_u16num/100)%10)+0x30);
			LCD_DataWr(((COPY_u16num/10)%10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
	}

	if (0>COPY_u16num)
	{
		COPY_u16num = -1*COPY_u16num;
		
		if (COPY_u16num<=9)
		{
			LCD_DataWr(0x2d);
			LCD_DataWr(COPY_u16num+0x30);
		}
		else if(COPY_u16num<=99)
		{
			LCD_DataWr(0x2d);
			LCD_DataWr((COPY_u16num/10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
		else if(COPY_u16num<=999)
		{
			LCD_DataWr(0x2d);
			LCD_DataWr((COPY_u16num/100)+0x30);
			LCD_DataWr(((COPY_u16num/10)%10)+0x30);
			LCD_DataWr((COPY_u16num%10)+0x30);
		}
		
	}
	
}