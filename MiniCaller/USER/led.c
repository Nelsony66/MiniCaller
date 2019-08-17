#include "global.h"

void LED_Init()
{       
  GPIO_Init(LED1_PORT,LED1_PINS,GPIO_Mode_Out_PP_Low_Slow);//³õÊ¼»¯LED¶Ë¿Ú
  GPIO_Init(LED2_PORT,LED2_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED3_PORT,LED3_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED4_PORT,LED4_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED5_PORT,LED5_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED6_PORT,LED6_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED7_PORT,LED7_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED8_PORT,LED8_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED9_PORT,LED9_PINS,GPIO_Mode_Out_PP_Low_Slow);
  GPIO_Init(LED10_PORT,LED10_PINS,GPIO_Mode_Out_PP_Low_Slow);
    LED1_H;
    LED2_H;
    LED3_H;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
}

void led_all_off(void)
{
    LED1_H;
    LED2_H;
    LED3_H;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;

}

void led_nunber(int num)
{
  
  switch(num)
  {
  case 0 :
    LED1_H;
    LED2_H;
    LED3_H;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
  case 1 :
    LED1_L;
    LED2_H;
    LED3_H;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 2:
    LED1_L;
    LED2_L;
    LED3_H;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 3:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_H;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 4:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_H;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 5:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_H;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 6:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_L;
    LED7_H;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 7:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_L;
    LED7_L;
    LED8_H;
    LED9_H;
    LED10_H;
    break;
   case 8:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_L;
    LED7_L;
    LED8_L;
    LED9_H;
    LED10_H;
    break;
  case 9:
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_L;
    LED7_L;
    LED8_L;
    LED9_L;
    LED10_H;
    break;
  case 10 :
    LED1_L;
    LED2_L;
    LED3_L;
    LED4_L;
    LED5_L;
    LED6_L;
    LED7_L;
    LED8_L;
    LED9_L;
    LED10_L;
    break;
  } 
    
}
 
void LED_Demo2(void)
{
  LED3_R;
  LED4_R;LED5_R;
  
}