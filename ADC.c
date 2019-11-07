

#include "ADC.h"
#include "ADC_CNFG.h"
#include "Interrupts.h"

PtrVfunctionV  g_ADC_CallBack_Ptr = NULL;

void __vector_16 (void)
{
	if(g_ADC_CallBack_Ptr != NULL)
	{
		g_ADC_CallBack_Ptr();
	}
	
}

EnumStdFunc_t ADC_Init(void)
{
	EnumStdFunc_t StateVal = ADC_OK;
	ADMUX &= 0x00;			
	ADMUX |= (REFRENCE_VOLTAGE << 6);
	
	ADCSRA &= 0x00;
	
	ADCSRA |= (AUTO_TRIGGER << 5);
	ADCSRA |= (INTERRUPT_OR_POLLING << 3);
	ADCSRA |= ADC_PRESCALER;
	
	SFIOR &= 0x00;
	SFIOR  |= (AUTO_TRIGGER_SOURCE << 5);
	
	ADC_Enable();
	
	return StateVal;
}

EnumStdFunc_t ADC_Enable(void)
{
	EnumStdFunc_t stateVal = ADC_OK;
	ADCSRA |= (1<<7);
	return stateVal;
}

EnumStdFunc_t ADC_Disable(void)
{
	EnumStdFunc_t stateVal = ADC_OK;
	ADCSRA &= ~(1<<7);
	return stateVal;
}


EnumStdFunc_t ADC_StartCoversion(uint8 Channel)
{
	EnumStdFunc_t StateVal = ADC_OK;
	if ( (ADCSRA & (1<<6) ) )
	{
		StateVal = ADC_ConvBusy;
	}
	else
	{
		ADMUX |= (Channel);
		ADCSRA |= (1<<6);
	}
	
	return StateVal;
}

EnumStdFunc_t ADC_ReadData(uint16 *PtrData)
{
	EnumStdFunc_t StateVal = ADC_OK;
	
	if(  ((ADCSRA & (1<<6)) == 0 ) &&  ((ADCSRA & (1<<4)) == 0 ) )
	{
		StateVal = ADC_NoConvStarted;
	}
	else if(  ((ADCSRA & (1<<6)) > 0 ) &&  ((ADCSRA & (1<<4)) == 0 ) )
	{
		StateVal = ADC_ConvBusy;		
	}
	else
	{
		*PtrData = 0;
		*PtrData = ADCL;
		*PtrData |= ((uint16)ADCH<<8);
		
		ADCSRA |= (1<<4);
		StateVal = ADC_ConvDone;
	}
	
	return StateVal;
}


EnumStdFunc_t ADC_ReadData_ISR(uint16 *PtrData)
{
	EnumStdFunc_t StateVal = ADC_OK;
	*PtrData = 0;
	*PtrData = ADCL;
	*PtrData |= ((uint16)ADCH<<8);
	return StateVal;
}


EnumStdFunc_t ADC_ISR_SetCallback(PtrVfunctionV COPY__ADC_CallBack_Ptr)
{
	EnumStdFunc_t StateVal = ADC_OK;
	
	g_ADC_CallBack_Ptr = COPY__ADC_CallBack_Ptr;	
	
	return StateVal;
}
