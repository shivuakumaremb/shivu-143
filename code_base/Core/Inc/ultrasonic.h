/* ultrasonic.h*/

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "main.h"
#include "stm32f401xe.h"

extern uint32_t g_first_capture, g_second_capture;
/*****************************************************************/
#define SPEED_OF_SOUND 34300
#define CAPTURE_REGISTER_MAX_VALUE 0xffff // max value of input capture register

#define PERIOD 0.000001 // 10 microseconds

/************************************** Public functions **************************************/

void UsDelay(uint32_t uSec);
void MeasureDistance(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
