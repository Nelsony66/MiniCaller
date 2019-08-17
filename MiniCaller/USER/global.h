#ifndef __GLOBAL_H
#define __GLOBAL_H


#include "stm8l15x.h"
#include "stm8l15x_clk.h"
#include "stm8l15x_spi.h"
#include "stm8l15x_gpio.h"
#include "stm8l15x_tim4.h"
#include "stm8l15x_adc.h"
#include "stm8l15x_usart.h"
#include "stm8l15x_it.h"
#include "stm8l15x_exti.h"
#include "stm8l15x_rtc.h"
#include "stm8l15x_pwr.h"
#include "rf.h"
#include "led.h"
#include "uart.h"
#include "key.h"
#include "syniotRoundRF.h"



#define controllerLift  0X41;
#define controllerRight 0X42;

void clock_Init(void);
void  Count_Timer4_Init(void);
void Delay_ms(uint16_t nCount);
void  Count_Timer2_Init(void) ;

extern u8 rain_state;
extern unsigned char RF_sendbuf[5];
extern u8 address0;
extern u8 address1;
extern u8 address2;
extern u16 keyscantime;



#endif