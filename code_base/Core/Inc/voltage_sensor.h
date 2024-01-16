//**************************************************************************** Header File *
//File Name : voltage_sensor.h
//Creation Date : 05-Dec-2023
//Modification Date : 05-Jan-2024
//Author : Abineshwar Kannan
//******************************************************************************************

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __VOLTAGE_SENSOR_H
#define __VOLTAGE_SENSOR_H
/* Define to prevent recursive inclusion end -------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
/* Includes end ----------------------------------------------------------*/

/* Private function defines ----------------------------------------------------------*/
void Voltage();
float ReadAdcValue(void);
void ProcessAdcValue(float adc_value, float* voltageSampleSum, float* voltageSampleCount);
float CalculateRmsVoltage(float voltageSampleSum, float voltageSampleCount);
void ResetVoltageMeasurement(float* voltageSampleSum, float* voltageSampleCount, int* takenSamples);
void DisplayVoltage(float voltage);
void VoltageLevel(float voltage);
/* Private function defines end ----------------------------------------------------------*/

#endif /* __VOLTAGE_SENSOR_H */


