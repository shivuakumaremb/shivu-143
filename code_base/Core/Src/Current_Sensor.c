#include "Current_Sensor.h"

/*Private Includes.....*/
/*Private Variables...*/
extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;
/*Private Function Prototypes..*/

/*Main Loop*/
//
//	int Read_Current_Sensor(int adc_Value)
//	{
//		HAL_ADC_Start(&hadc1);
//		HAL_ADC_PollForConversion(&hadc1, Timeout);
//		adc_value =HAL_ADC_GetValue(&hadc1);
//
//
//	}



_Bool dryrun_flag=0, over_current_flag=0;
uint8_t max_current = 10, min_current = 3;


void Read_Average_Current(ADC_HandleTypeDef *hadc) {
	uint8_t average = 0;
	HAL_ADC_Start(hadc);
	for (int i = 0; i < 10; i++) {
		HAL_ADC_PollForConversion(hadc, 500);
		int adc_value = HAL_ADC_GetValue(hadc);
		average += adc_value;
	}

	if(min_current>average)
	{
		dryrun_flag=1;
	}
	if( max_current<average)
	{
		over_current_flag=1;
	}
	else
	{
		dryrun_flag=0;
		over_current_flag=0;
	}
}


