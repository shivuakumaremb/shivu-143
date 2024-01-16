#include "userinterface.h"

// GPIO configuration structure
GPIO_InitTypeDef GPIO_InitStruct = { 0 };

//void UI_Init(void) {
//    // Initialize GPIO pins for LEDs and Buzzer
//    __HAL_RCC_GPIOA_CLK_ENABLE();  // Enable GPIOA clock
//
//    // Configure LED pins as output
//    GPIO_InitStruct.Pin = LED_GREEN_PIN | LED_RED_PIN | BUZZER_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//}
//
void ReadModeSwitch() {
	SystemFlags.Mode_Flag = HAL_GPIO_ReadPin(man_GPIO_Port,man_Pin);

}

//
//void UI_BlinkLEDs(void) {
//	// Toggle both LEDs with a delay for indication
//	HAL_GPIO_TogglePin(GPIOA, LED_GREEN_PIN);
//
//	//use timer for "delay"
//	HAL_GPIO_TogglePin(GPIOA, LED_RED_PIN);
//}
//
//void UI_SoundBuzzer(void) {
//	// Toggle the buzzer with a delay for indication
//	HAL_GPIO_TogglePin(GPIOA, BUZZER_PIN);
//	//use timer for "delay"
//
//	HAL_GPIO_TogglePin(GPIOA, BUZZER_PIN);
//}

void UIStatus(Lcd_HandleTypeDef lcd, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
		uint8_t row, uint8_t column, char *message, _Bool pinState) {
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, pinState);
	LcdCursor(&lcd, row, column);
	LcdString(&lcd, message);
}

void UIMessage(Lcd_HandleTypeDef lcd, uint8_t row, uint8_t column,
		char *message, uint8_t value) {
	LcdCursor(&lcd, row, column);
	LcdString(&lcd, message);
	LcdInt(&lcd, value);
}

