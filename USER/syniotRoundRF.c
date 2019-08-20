#include "stm8l15x.h"
#include "stm8l15x_gpio.h"
#include "stm8l15x_exti.h"
#include "stm8l15x_clk.h"
#include "stm8l15x_itc.h"
#include "syniotRoundRF.h"
#include "global.h"

extern syniot_roundRF_t syniotRF;


/*     0-2 ��ַ   3 ����  4 ����   */

unsigned char Syniot_RF_BUFF[5]={0xFF,0xFF,0xFF,0x41,0x33}; 



void ec_pin_init(void)
{
  GPIO_Init(GPIOB, GPIO_Pin_6, GPIO_Mode_In_PU_IT);     
  GPIO_Init(GPIOB, GPIO_Pin_7, GPIO_Mode_In_PU_No_IT);    

}

/* ����ʱ�� ��λ S*/ 
void time_start_count(int num )
{
  
  syniotRF.timecount= num*100 ;
}

  
/* �����0.5���Ĳ���Ϊ��Ч����*/  

