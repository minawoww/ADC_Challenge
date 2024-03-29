
#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define LCD_ClearScreen        0x01				// CLEAR THE SCREEN
#define LCD_CursorHome         0x02				// GET CURSOR AT THE TOP LEFT CORNER
#define LCD_IncOnShiOff        0x06		        // ENTRY MODE SET (THE CURSOR WILL MOVE INCREMENTALLY WITH NO SHIFT)
#define LCD_IncOnShiOn		   0x07             // ENTRY MODE SET (THE CURSOR WILL MOVE INCREMENTALLY WITH SHIFTING)
#define LCD_DecOnShiOff        0x04             // ENTRY MODE SET (THE CURSOR WILL MOVE DECREMENTALLY WITH NO SHIFT)
#define LCD_DisOnCurOnBliOff   0x0E				// GET THE DISPLAY ON, CURSOR ON AND THE BLINKING FOR THE CURSOR OFF (TURNING ON VISIABLE UNDERLINE CURSOR)
#define LCD_DisOnCurOnBliOn    0x0F				// GET THE DISPLAY ON, CURSOR ON AND THE BLINKING ON (TURNING ON VISIABLE BLINKING CURSOR)
#define LCD_DisOnCurOffBliOff  0x0C				// GET DISPLAY ON, CURSOR OFF, BLINKING OFF (MAKE THE CURSOR INVISABLE)
#define LCD_BlankDis           0x08             // GET DISPLAY OFF, CURSOR OFF, BLINKING OFF
#define LCD_CurL               0x10				// MOVE CURSOR ONE CHARACTER LEFT
#define LCD_CurR               0x14             // MOVE CURSOR ONE CHARACTER RIGHT
#define LCD_ScrR		  	   0x1E				// SCROLL ALL CHARACTER RIGH
#define LCD_ScrL			   0x18				// SCROLL ALL CHARACTER LEFT
#define LCD_Set8Bit2Lin        0x38             // FUN SET 8 BIT MODE, 2 LINES, 5x7
#define LCD_Set8Bit1Lin		   0x30				//FUN SET 8 BIT MODE, 1 LINE, 5x7
#define LCD_Set4Bit2Lin		   0x28				//FUN SET 4 BIT MODE, 2 LINES, 5x7
#define LCD_Set4Bit1lin        0x20				//FUN SET 4 BIT MODE, 1 LINE, 5x7


extern void LCD_init(void);extern void LCD_DataWr(uint8 Data);extern void LCD_displayString(uint8 *COPY_ptrString);extern void LCD_gotoRowColumn( uint8 COPY_u8Row , uint8 COPY_u8Column);
extern void LCD_displayStringRowColumn(uint8 *COPY_ptrString,uint8 COPY_Row,uint8 COPY_Column);extern void LCD_NUM_DISP(uint8 COPY_u8Row , uint8 COPY_u8Column, uint16 COPY_u16num);



#endif