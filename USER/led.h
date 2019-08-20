#ifndef __LED_H
#define __LED_H
#include "stm8l15x.h"



#define LED1_PINS  GPIO_Pin_1 // led red
#define LED1_PORT GPIOB

#define LED2_PINS  GPIO_Pin_2  // led blue
#define LED2_PORT GPIOB

#define LED3_PINS  GPIO_Pin_4  //led light
#define LED3_PORT GPIOB

#define LED4_PINS  GPIO_Pin_5  //led light
#define LED4_PORT GPIOB

#define LED5_PINS  GPIO_Pin_0  //led light
#define LED5_PORT GPIOC

#define LED6_PINS  GPIO_Pin_1  //led light
#define LED6_PORT GPIOC

#define LED7_PINS  GPIO_Pin_6  //led light
#define LED7_PORT GPIOC

#define LED8_PINS  GPIO_Pin_2  //led light
#define LED8_PORT GPIOA

#define LED9_PINS  GPIO_Pin_0  //led light
#define LED9_PORT GPIOB

#define LED10_PINS  GPIO_Pin_0  //led light
#define LED10_PORT GPIOD




#define LED1_H GPIO_SetBits(LED1_PORT,LED1_PINS)
#define LED1_L GPIO_ResetBits(LED1_PORT,LED1_PINS)
#define LED1_R GPIO_ToggleBits(LED1_PORT,LED1_PINS)

#define LED2_H GPIO_SetBits(LED2_PORT,LED2_PINS)
#define LED2_L GPIO_ResetBits(LED2_PORT,LED2_PINS)
#define LED2_R GPIO_ToggleBits(LED2_PORT,LED2_PINS)

#define LED3_H GPIO_SetBits(LED3_PORT,LED3_PINS)
#define LED3_L GPIO_ResetBits(LED3_PORT,LED3_PINS)
#define LED3_R GPIO_ToggleBits(LED3_PORT,LED3_PINS)

#define LED4_H GPIO_SetBits(LED4_PORT,LED4_PINS)
#define LED4_L GPIO_ResetBits(LED4_PORT,LED4_PINS)
#define LED4_R GPIO_ToggleBits(LED4_PORT,LED4_PINS)

#define LED5_H GPIO_SetBits(LED5_PORT,LED5_PINS)
#define LED5_L GPIO_ResetBits(LED5_PORT,LED5_PINS)
#define LED5_R GPIO_ToggleBits(LED5_PORT,LED5_PINS)

#define LED6_H GPIO_SetBits(LED6_PORT,LED6_PINS)
#define LED6_L GPIO_ResetBits(LED6_PORT,LED6_PINS)
#define LED6_R GPIO_ToggleBits(LED6_PORT,LED6_PINS)

#define LED7_H GPIO_SetBits(LED7_PORT,LED7_PINS)
#define LED7_L GPIO_ResetBits(LED7_PORT,LED7_PINS)
#define LED7_R GPIO_ToggleBits(LED7_PORT,LED7_PINS)

#define LED8_H GPIO_SetBits(LED8_PORT,LED8_PINS)
#define LED8_L GPIO_ResetBits(LED8_PORT,LED8_PINS)
#define LED8_R GPIO_ToggleBits(LED8_PORT,LED8_PINS)

#define LED9_H GPIO_SetBits(LED9_PORT,LED9_PINS)
#define LED9_L GPIO_ResetBits(LED9_PORT,LED9_PINS)
#define LED9_R GPIO_ToggleBits(LED9_PORT,LED9_PINS)

#define LED10_H GPIO_SetBits(LED10_PORT,LED10_PINS)
#define LED10_L GPIO_ResetBits(LED10_PORT,LED10_PINS)
#define LED10_R GPIO_ToggleBits(LED10_PORT,LED10_PINS)



#define LED1_H GPIO_SetBits(LED1_PORT,LED1_PINS)
#define LED1_L GPIO_ResetBits(LED1_PORT,LED1_PINS)
#define LED1_R GPIO_ToggleBits(LED1_PORT,LED1_PINS)

#define LED2_H GPIO_SetBits(LED2_PORT,LED2_PINS)
#define LED2_L GPIO_ResetBits(LED2_PORT,LED2_PINS)
#define LED2_R GPIO_ToggleBits(LED2_PORT,LED2_PINS)

#define LED3_H GPIO_SetBits(LED3_PORT,LED3_PINS)
#define LED3_L GPIO_ResetBits(LED3_PORT,LED3_PINS)
#define LED3_R GPIO_ToggleBits(LED3_PORT,LED3_PINS)




void LED_Init(void);
void LED_Demo1(void);
void LED_Demo2(void);
void led_all_off(void);
void led_nunber(int num);






#endif