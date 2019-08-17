#ifndef __UART_H
#define __UART_H
#include "stm8l15x.h"



void UART_Init(void);
void UART1_SendByte(uint8_t Data);
void UART1_SendNByte(uint8_t *pData, uint16_t Length);
void UART1_Printf(uint8_t *String);


#endif