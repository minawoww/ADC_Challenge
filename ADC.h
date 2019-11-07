
#ifndef ADC_H_
#define ADC_H_

#include "avr_reg.h"
#include "STD_Types.h"

typedef enum { ADC_OK , ADC_NOK , ADC_NoConvStarted , ADC_ConvBusy , ADC_ConvDone }EnumStdFunc_t;
typedef void (*PtrVfunctionV)(void);

EnumStdFunc_t ADC_Init(void);
EnumStdFunc_t ADC_StartCoversion(uint8 Channel);
EnumStdFunc_t ADC_ReadData(uint16 *Data);
EnumStdFunc_t ADC_ReadData_ISR(uint16 *PtrData);
EnumStdFunc_t ADC_Disable(void);
EnumStdFunc_t ADC_Enable(void);
EnumStdFunc_t ADC_ISR_SetCallback(PtrVfunctionV Ptr );

#define INTERNAL_VREF 3
#define VCC_VREF	  1
#define AREF          0

#define INTERRPUT   1
#define POLLING     0

#define FCPU_2     1
#define FCPU_4     2
#define FCPU_8     3
#define FCPU_16    4
#define FCPU_32    5
#define FCPU_64    6
#define FCPU_128   7

#define AUTO_TRIGGER_ENABLE 1
#define AUTO_TRIGGER_DISABLE 0

#define FREE_RUNNING_MODE		0
#define ExternalInt				2
#define TIMER1_OVF_AUTO_TRIGGER 6


#define CHANNEL_ZERO      0
#define CHANNEL_ONE       1
//#define CHANNEL2       2
//#define CHANNEL3       3
//#define CHANNEL4       4
//#define CHANNEL5       5
//#define CHANNEL6       6
//#define CHANNEL7       7


#endif