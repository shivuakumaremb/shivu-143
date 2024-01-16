

#ifndef INC_CURRENT_SENSOR_H_
#define INC_CURRENT_SENSOR_H_



#include "stm32f4xx_hal.h"
extern uint8_t max_current,min_current;
extern _Bool dryrun_flag,over_current_flag;




void Read_Average_Current(ADC_HandleTypeDef *hadc);




#endif /* INC_CURRENT_SENSOR_H_ */
