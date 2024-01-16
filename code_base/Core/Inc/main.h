/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include <ultrasonic.h>
#include <lcd.h>
#include <math.h>
#include "voltage_sensor.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern const uint8_t C__MinimumLevel;
extern const uint8_t C__MaximumLevel;
extern uint8_t tankHeight;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define voltage_sensor_Pin GPIO_PIN_1
#define voltage_sensor_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define current_sensor_Pin GPIO_PIN_4
#define current_sensor_GPIO_Port GPIOA
#define debug_Pin GPIO_PIN_5
#define debug_GPIO_Port GPIOA
#define trigger_Pin GPIO_PIN_7
#define trigger_GPIO_Port GPIOA
#define man_Pin GPIO_PIN_1
#define man_GPIO_Port GPIOB
#define Switch_Pin GPIO_PIN_2
#define Switch_GPIO_Port GPIOB
#define Blueled_Pin GPIO_PIN_10
#define Blueled_GPIO_Port GPIOB
#define highInc_relay_Pin GPIO_PIN_8
#define highInc_relay_GPIO_Port GPIOA
#define RedLed_Pin GPIO_PIN_10
#define RedLed_GPIO_Port GPIOA
#define GreenLed_Pin GPIO_PIN_11
#define GreenLed_GPIO_Port GPIOA
#define BlueLed_Pin GPIO_PIN_12
#define BlueLed_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define hightDec_buzzer_Pin GPIO_PIN_3
#define hightDec_buzzer_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOB
#define Enable_dis_Pin GPIO_PIN_5
#define Enable_dis_GPIO_Port GPIOB
#define RS_dis_Pin GPIO_PIN_6
#define RS_dis_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_8
#define D6_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_9
#define D5_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

typedef struct {
	_Bool Mode_Flag; // make enum
 // rename as capture complete flag
	_Bool DryRun_Flag;
	_Bool Over_Voltage_Flag;
	_Bool Motor_Status_Flag;
	uint8_t Capture_Complete_Flag;
} Flags;

extern Flags SystemFlags;

typedef struct {
	float Voltage;
	float ADC_Voltage_Value;
	float Current;
	float ADC_Current_Value;
	float Distance;
	uint8_t Level;
} Parameter;

extern Parameter SystemParameter;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
