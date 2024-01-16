////*************************************************************************** Legal Notice *
//// Copyright (C) Skanray Technologies Pvt. Ltd. - All Rights Reserved.
////
//// Unauthorized copying of this file, via any medium is strictly prohibited.
////
//// If you are not the intended recipient of this file, please destroy all copies and notify
//// Skanray at office@skanray.com.
////
//// Proprietary and confidential.
////**************************************************************************** Source File *
////File Name : voltage_sensor.c
////Creation Date : 05-Dec-2023
////Modification Date : 09-Jan-2024
////Author : Abineshwar Kannan
////******************************************************************************************
//
///* Includes ------------------------------------------------------------------*/
//#include <string.h>
//#include <stdio.h>
//#include <math.h>
//#include "voltage_sensor.h"
///* Includes end ----------------------------------------------------------*/
//
///* Private variables ---------------------------------------------------------*/
//extern ADC_HandleTypeDef hadc1;
//extern UART_HandleTypeDef huart2;
///* Private variables end ---------------------------------------------------------*/
//
///* Variables initialize ---------------------------------------------------------*/
//uint64_t current_time;
//static uint64_t previous_sample_time = 0;
//static int taken_samples = 0;
//static float voltage_sample_sum = 0;
//static float voltage_sample_count = 0;
//
//const int c__sample_period = 3;	//Sampling time for 3ms
//const int c__required_samples=300; //Maximum samples to be sampled
//const float c__offset_value = 2020.0;	//Offset value when AC main is OFF
//const float c__scaling_factor = 1.5;	//Scaling factor for calibration
//const float c__threshold = 30.0;	//RMS threshold value for the offset
///* Variables initialize end ---------------------------------------------------------*/
//
///* Function handlers ------------------------------------------------------------------*/
//
///* ***** MAIN FUNCTION *****
// * Every 3ms the voltage sensor gets sampled through the ADC pin.
// * The analog value per sample is squared and accumulated for every 300 samples before being averaged.
// * The averaged value is then getting square-rooted.
// * And multiplied with scaling factor of calibration to map the actual voltage to the sensor output voltage.
// * The final vRMS value is obtained and value gets refreshed whenever the sample count reaches 300.
//*/
//void Voltage() {
//	current_time = HAL_GetTick(); //Auto-reloader timer function counts upto 1000ms
//
//	if (current_time - previous_sample_time >= c__sample_period) {
//		float adc_value = ReadAdcValue(); // Function to read ADC value
//		ProcessAdcValue(adc_value, &voltage_sample_sum, &voltage_sample_count); // Function to process the read ADC value
//		previous_sample_time = current_time;
//		taken_samples++;
//	}
//
//	if (taken_samples >= c__required_samples) {
//		float final_rms_voltage = CalculateRmsVoltage(voltage_sample_sum, voltage_sample_count); // Function to calculate RMS voltage
//		ResetVoltageMeasurement(&taken_samples, &voltage_sample_sum, &voltage_sample_count); //	Function to reset measurement parameters
//		DisplayVoltage(final_rms_voltage);	// Function to display voltage
//		VoltageLevel(final_rms_voltage);	// Function for flag set
//	}
//}
//
///*
// * This function continuously reads the voltage.
// * Returns the read voltage value.
//*/
//float ReadAdcValue(void) {
//	HAL_ADC_Start(&hadc1);
//	HAL_ADC_PollForConversion(&hadc1, 1000);	// Wait for the conversion to complete with a timeout of 1000 ms
//	return HAL_ADC_GetValue(&hadc1);
//}
//
///*
// * This function adjusts the ADC voltage by eliminating the offset value.
// * Adjusted voltage is squared and accumulated.
//*/
//void ProcessAdcValue(float adc_value, float *voltage_sample_sum, float *voltage_sample_count) {
//	float voltage_sample_read = adc_value - c__offset_value;	// Adjust the ADC value by the offset
//	(*voltage_sample_sum) += pow(voltage_sample_read, 2);	// Square the adjusted value and accumulate it
//	(*voltage_sample_count)++;	// Increment the count of voltage samples taken
//}
//
///*
// * In this function accumulated value is averaged and square rooted.
// * And multiplied with scaling factor of calibration.
// * Returns the RMS voltage
//*/
//float CalculateRmsVoltage(float voltage_sample_sum, float voltage_sample_count) {
//	float voltage_mean = voltage_sample_sum / voltage_sample_count;
//	float rms_voltage = sqrt(voltage_mean);
//	rms_voltage *= c__scaling_factor;	//Multiply RMS value with current scaling factor
//
//	if (rms_voltage <= c__threshold) {
//		rms_voltage = 0;
//	}
//	return rms_voltage;	// To eliminate the offset value when AC main is OFF
//}
//
///*
// * Resetting the accumulated values
//*/
//void ResetVoltageMeasurement(float *voltage_sample_sum, float *voltage_sample_count, int *taken_samples) {
//	*voltage_sample_sum = 0.0f;
//	*voltage_sample_count = 0.0f;
//	*taken_samples = 0;
//}	// Reset of values
//
///*
// * Display purpose
//*/
//void DisplayVoltage(float voltage) {
//	char str[50];
//	sprintf(str, "AC main voltage = %.0f V\r\n", voltage);
//	HAL_UART_Transmit(&huart2, (uint8_t*) str, strlen(str), 1000);
//}	// Verification purpose only...Remove it in production
//
///*
// * Voltage flag actuation function
//*/
//void VoltageLevel(float voltage){
//	if (voltage < 210 || voltage > 250){
//		// An over-voltage flag is to be set here.
//		HAL_GPIO_WritePin(, BLUE_Pin, RESET);
//		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
//	}
//	else{
//		// An over-voltage flag is to be reset here.
//		// Normal state for motor running
//		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET);
//		HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
//	}
//}
//
///* Function handlers end ------------------------------------------------------------------*/
