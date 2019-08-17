

#include "global.h"


u16 keyscantime=0;

void clock_Init()
{
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);  
}

void Delay_us(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount--)
  {   
	
  }
 
}
void Delay_ms(uint16_t nCount)
{
   uint16_t i;
  while (nCount--)
  {   
        i=1000;   
        while(i--);  
  }
}


    /* 定时器4配置*/

void  Count_Timer4_Init(void)  
{ 
 
  CLK_PeripheralClockConfig(CLK_Peripheral_TIM4,ENABLE); //开启tim4时钟    
  TIM4_DeInit();  
  TIM4_TimeBaseInit(TIM4_Prescaler_1024,155);  //1024分频，向上计数，每10ms定时中断一次    
  TIM4_ITConfig(TIM4_IT_Update , ENABLE);  
  TIM4_Cmd(ENABLE);  
  
}  


void  Count_Timer2_Init(void)  
{ 
 
  CLK_PeripheralClockConfig(CLK_Peripheral_TIM2,ENABLE); //开启tim4时钟    
  TIM2_DeInit();  
  TIM2_TimeBaseInit(TIM2_Prescaler_64,TIM2_CounterMode_Up,250);  //64分频，向上计数，每9.984ms定时中断一次    
  TIM2_ITConfig(TIM2_IT_Update , ENABLE);  
  TIM2_Cmd(ENABLE);  
  
} 



void halt_stand_by(void)
{
  
  

}


void halt_weak_up(void)
{
  
  

}
