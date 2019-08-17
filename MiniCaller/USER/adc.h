#ifndef __ADC_H
#define __ADC_H
#include "stm8l15x.h"

#define LIGHT_PINS  GPIO_Pin_0
#define LIGHT_PORT GPIOB

void ADC_Initializes(void);
uint32_t ADC_Read(void);












#endif