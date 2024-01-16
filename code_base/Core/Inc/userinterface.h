#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "stm32f4xx_hal.h"
#include "lcd.h"

// Define GPIO pins for LEDs and Buzzer on the STM32F401 Nucleo board
#define LED_GREEN_PIN   GPIO_PIN_10   // Replace with the actual GPIO pin for the green LED
#define LED_RED_PIN  GPIO_PIN_11  // Replace with the actual GPIO pin for the orange LED
#define BUZZER_PIN      GPIO_PIN_3   // Replace with the actual GPIO pin for the buzzer

// Define modes
#define AUTO_MODE   0
#define MANUAL_MODE 1
//
//// Function to initialize user interface peripherals (LEDs, Buzzer, etc.)
//void UI_Init(void);
//
//// Function to switch between manual and auto modes
//void UI_SwitchMode(int mode);
//
//// Function to blink LEDs for indication
//void UI_BlinkLEDs(void);
//
//// Function to sound the buzzer
//void UI_SoundBuzzer(void);
void ReadModeSwitch();
void UIStatus(Lcd_HandleTypeDef LCD_instance, GPIO_TypeDef *GPIOx,
		uint16_t GPIO_Pin, uint8_t row, uint8_t column, char *message, _Bool pinState);
void UIMessage(Lcd_HandleTypeDef lcd, uint8_t row, uint8_t column,
		char *message, uint8_t value);

#endif  // USER_INTERFACE_H
