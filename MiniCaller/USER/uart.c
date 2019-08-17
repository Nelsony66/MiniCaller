
#include "global.h"


void UART_Init(void)
{
  CLK_PeripheralClockConfig (CLK_Peripheral_USART1,ENABLE);//开启时钟
  USART_Init(USART1,115200,USART_WordLength_8b,USART_StopBits_1,USART_Parity_No,USART_Mode_Tx|USART_Mode_Rx);
  //设置USART参数9600，8N1，接收/发送  
  USART_ITConfig (USART1,USART_IT_RXNE,ENABLE);//使能接收中断
  USART_Cmd (USART1,ENABLE);//使能USART
  
}

void UART1_SendByte(uint8_t data)
{
  USART_SendData8(USART1, data);  // 等待传输结束   
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
 
}

/************************************************
函数名称 ： UART1_SendNByte
功    能 ： 串口1发送N个字符
参    数 ： pData ---- 字符串
            Length --- 长度

*************************************************/
void UART1_SendNByte(uint8_t *pData, uint16_t Length)
{
  while(Length--)
  {
    UART1_SendByte(*pData);
    pData++;
  }
}

/*这个程序作用是，找到s开头的字符串中的结束位置，
运行之后s指针指向之前的s字符串中结束符的下一个位置。但是while每次循环都要把s+1*/
void UART1_Printf(uint8_t *String)
{
  while((*String) != '\0')
  {
    UART1_SendByte(*String);
    String++;
  }
}

