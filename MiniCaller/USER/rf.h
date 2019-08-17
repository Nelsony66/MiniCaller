#ifndef __RF_H
#define __RF_H
#include "stm8l15x.h"



#define		SEND_RF_TIMES	6
#define RF315_H  GPIO_SetBits(GPIOB,GPIO_Pin_2)  // 315 data pin
#define RF315_L  GPIO_ResetBits(GPIOB,GPIO_Pin_2)

#define RF433_H  GPIO_SetBits(GPIOB,GPIO_Pin_1)  // 433 data pin
#define RF433_L  GPIO_ResetBits(GPIOB,GPIO_Pin_1)






void RF_Init(void);
unsigned char send_rfdata_433(unsigned char *inp);
unsigned char send_rfdata_315(unsigned char *inp);







#endif