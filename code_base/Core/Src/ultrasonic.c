//****************************************************************************
//File Name : ultrasonic.c
//Creation Date : 04-dec-2023
//Author : "SHIVAKUMARA UL"
//****************************************************************************

#include "ultrasonic.h"

uint32_t g_first_capture = 0, g_second_capture = 0;
/***************************** Function definitions **************************/

/*!
 *@brief usDelay :This function provides minimum delay (in microseconds) based on variable incremented.
 *@param uSec    : integer value to get the delay.
 *@retval None
 */

void UsDelay(uint32_t uSec) {
	uint32_t get_count = HAL_GetTick();
	uint32_t required_time = get_count + uSec;

	while (required_time - HAL_GetTick() > 0) {

	};
}

/*!
 * @brief  measure the distance.
 * @param  GPIOx where x can be (A..K) to select the GPIO peripheral for STM32F429X device or
 * 					x can be (A..I) to select the GPIO peripheral for STM32F40XX and STM32F427X devices.
 * @param  GPIO_Pin specifies the port bit to read.
 *         This parameter can be GPIO_PIN_x where x can be (0..15).
 * @param  TIM_HandleTypeDef htim3 TIM Input Capture functions
 * @param	icFlag this flag is set after completion of call back
 * */
void MeasureDistance(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	float distance;
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
	UsDelay(3);

//*** START Ultrasonic measure routine ***//
//1. Output 10 usec TRIG
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	UsDelay(10);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);

//2. ECHO signal pulse width
	if (SystemFlags.Capture_Complete_Flag) {
		SystemFlags.Capture_Complete_Flag = 0;
		if (g_second_capture > g_first_capture) {
			distance = ((g_second_capture - g_first_capture) + 0.0f) * PERIOD
					* SPEED_OF_SOUND / 2;
		} else if (g_second_capture < g_first_capture) {
			distance = ((((CAPTURE_REGISTER_MAX_VALUE - g_first_capture)
					+ g_second_capture) + 0.0f) * PERIOD * SPEED_OF_SOUND / 2);
		} else {
			distance = 0.0f;
		}
		SystemParameter.Level = distance;
	}
}

/*!
 * @brief  Input Capture callback in non-blocking mode
 * @param  htim TIM IC handle
 * @retval None
 */

