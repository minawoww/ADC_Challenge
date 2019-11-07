/*
 * ADC.c
 *
 * Created: 11/7/2019 1:54:34 PM
 * Author : minam
 */ 

#define F_CPU 8000000ul
#include "STD_Types.h"
#include "avr_reg.h"
#include "ADC.h"
#include "LCD.h"
#include "timer.h"
#include <util/delay.h>

volatile uint8 g_Temp = 0 ;
volatile uint8 g_Temp_Displayed = 0 ;

volatile uint16 g_ADC_Data = 0 ;

volatile uint8 readState = 0;

void Calculate_Temp(){

	//ADC Vref = 2.56v Res = 10 bit ==> step = 0.0025v = 2.5mv
	//Temp sensor gives 10mv per degree

	//while(ADC_ReadData(&g_ADC_Data) != ADC_ConvDone);
	
	 ADC_ReadData_ISR(&g_ADC_Data);
	g_Temp = (g_ADC_Data / 4) ;
	//ADC_StartCoversion(CHANNEL_ZERO);
	
}


int main(void)
{
	SREG |= (1<<7);
	ADC_ISR_SetCallback(Calculate_Temp);
    ADC_Init();
	TIMER_Init(TIMER_1);
	DDRB = 0xff;
	
	uint8 FanSpeed = 0;

	DIO_Init();
	LCD_init();

	LCD_displayStringRowColumn("Temp :",0,0);
	LCD_displayStringRowColumn("Duty Cycle:",1,0);
	
	ADC_StartCoversion(CHANNEL_ZERO);
    while (1) 
    {
		if(g_Temp != g_Temp_Displayed)
		{
			
			LCD_displayStringRowColumn("   " , 0, 7);
			LCD_NUM_DISP(0 , 7, g_Temp); //first row and col 7 after "temp :"
			g_Temp_Displayed = g_Temp ;
			if (g_Temp <= 27)
			{
				FanSpeed = 50;
			}
			else
			{
				FanSpeed = 50 +  ((g_Temp - 27) / 2)*10;
				if (FanSpeed > 100)
				{
					FanSpeed = 100;
				}
			}
			LCD_displayStringRowColumn("   " , 1, 13);
			LCD_NUM_DISP(1,13,FanSpeed);
		}
		   	//_delay_ms(200);
		   	//Calculate_Temp();
		
		
    }
}

