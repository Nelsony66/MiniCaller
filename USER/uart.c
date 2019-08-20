
#include "global.h"


void UART_Init(void)
{
  CLK_PeripheralClockConfig (CLK_Peripheral_USART1,ENABLE);//����ʱ��
  USART_Init(USART1,115200,USART_WordLength_8b,USART_StopBits_1,USART_Parity_No,USART_Mode_Tx|USART_Mode_Rx);
  //����USART����9600��8N1������/����  
  USART_ITConfig (USART1,USART_IT_RXNE,ENABLE);//ʹ�ܽ����ж�
  USART_Cmd (USART1,ENABLE);//ʹ��USART
  
}

void UART1_SendByte(uint8_t data)
{
  USART_SendData8(USART1, data);  // �ȴ��������   
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
 
}

/************************************************
�������� �� UART1_SendNByte
��    �� �� ����1����N���ַ�
��    �� �� pData ---- �ַ���
            Length --- ����

*************************************************/
void UART1_SendNByte(uint8_t *pData, uint16_t Length)
{
  while(Length--)
  {
    UART1_SendByte(*pData);
    pData++;
  }
}

/*������������ǣ��ҵ�s��ͷ���ַ����еĽ���λ�ã�
����֮��sָ��ָ��֮ǰ��s�ַ����н���������һ��λ�á�����whileÿ��ѭ����Ҫ��s+1*/
void UART1_Printf(uint8_t *String)
{
  while((*String) != '\0')
  {
    UART1_SendByte(*String);
    String++;
  }
}

