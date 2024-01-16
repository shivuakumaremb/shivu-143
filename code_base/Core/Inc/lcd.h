/*
 * lcd.h
 *
 *  Created on: 15/11/2023
 *      Author: Manasa R
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "main.h"

// #define LCD20xN 		// For 20xN LCDs
#define LCD16xN			// For 16xN LCDs

// For row start addresses
extern const uint8_t ROW_16[];
extern const uint8_t ROW_20[];
extern uint8_t percentage;

/************************************** Command register **************************************/
#define CLEAR_DISPLAY 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE_SET 0x04
#define OPT_S	0x01					// Shift entire display to right
#define OPT_INC 0x02					// Cursor increment

#define DISPLAY_ON_OFF_CONTROL 0x08
#define OPT_D	0x04					// Turn on display
#define OPT_C	0x02					// Turn on cursor
#define OPT_B 	0x01					// Turn on cursor blink
#define blink 0x0F
#define LEFT_SHIFT 0x1C

#define CURSOR_DISPLAY_SHIFT 0x10		// Move and shift cursor
#define OPT_SC 0x08
#define OPT_RL 0x04

#define FUNCTION_SET 0x20
#define OPT_DL 0x10						// Set interface data length
#define OPT_N 0x08						// Set number of display lines
#define OPT_F 0x04						// Set alternate font
#define SETCGRAM_ADDR 0x040
#define SET_DDRAM_ADDR 0x80				// Set DDRAM address


/************************************** Helper macros **************************************/
#define DELAY(X) HAL_Delay(X)


/************************************** LCD defines **************************************/
#define LCD_NIB 4
#define LCD_BYTE 8
#define LCD_DATA_REG 1
#define LCD_COMMAND_REG 0


/************************************** LCD typedefs **************************************/
#define Lcd_PortType GPIO_TypeDef*
#define Lcd_PinType uint16_t

typedef enum {
	LCD_4_BIT_MODE,
	LCD_8_BIT_MODE
} Lcd_ModeTypeDef;


typedef struct {
	Lcd_PortType * lcd_data_port[4];
	Lcd_PinType * lcd_data_pin[4];

	Lcd_PortType lcd_rs_port;
	Lcd_PinType lcd_rs_pin;

	Lcd_PortType lcd_en_port;
	Lcd_PinType lcd_en_pin;

	Lcd_ModeTypeDef lcd_mode;

} Lcd_HandleTypeDef;



/************************************** Public functions **************************************/
void LcdInit(Lcd_HandleTypeDef * lcd);
void LcdInt(Lcd_HandleTypeDef * lcd, int number);
void LcdString(Lcd_HandleTypeDef * lcd, char * string);
//void Lcd_blink(Lcd_HandleTypeDef * lcd);
void LcdCursor(Lcd_HandleTypeDef * lcd, uint8_t row, uint8_t col);
Lcd_HandleTypeDef LcdCreate(
Lcd_PortType lcd_port[4], Lcd_PinType lcd_pin[4],
Lcd_PortType lcd_rs_port, Lcd_PinType lcd_rs_pin,
Lcd_PortType lcd_en_port, Lcd_PinType lcd_en_pin, Lcd_ModeTypeDef lcd_mode);
void LcdDefineChar(Lcd_HandleTypeDef * lcd, uint8_t code, uint8_t bitmap[]);
void LcdClear(Lcd_HandleTypeDef * lcd);
Lcd_HandleTypeDef LcdInitialize();
void LcdCursor(Lcd_HandleTypeDef *lcd, uint8_t row, uint8_t col);
//void Lcd_shift(Lcd_HandleTypeDef * lcd);
void DisplayLevel(Lcd_HandleTypeDef *lcd,uint8_t levelInpercent);

#endif /* LCD_H_ */
