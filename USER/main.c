

#include "global.h"

syniot_roundRF_t syniotRF;

unsigned char RF_sendbufOpen[5]={0xFF,0xFF,0xFF,0x41,0x11}; 
unsigned char RF_sendbufStop[5]={0xFF,0xFF,0xFF,0x41,0x33}; 
unsigned char RF_sendbuf[5]={0x01,0x12,0x33,0x41,0x55}; 

//syniot_roundRF_t syniotRF;

void keydeal()
{  
   static u8 keyvalue=0;    
   keyloop(&keyvalue);
   if(keyvalue==(KEY_VALUE_1|KEY_DOWN))//长按
  {
    syniotRF.active = 1;
    led_nunber(syniotRF.pulseNumber);
    syniotRF.timecount=1000;
   

}
}
 
void RTC_Config(void)
{
        //CLK_LSEConfig(CLK_LSE_ON);
        CLK_LSICmd(ENABLE);//使能LSI
        CLK_PeripheralClockConfig(CLK_Peripheral_RTC, ENABLE);//RTC时钟门控使能
        CLK_RTCClockConfig(CLK_RTCCLKSource_LSI, CLK_RTCCLKDiv_1);//RTC时钟源LSI，1分频=38K
        while (CLK_GetFlagStatus(CLK_FLAG_LSIRDY) == RESET);//等待LSI就绪
        
        //RTC_WakeUpCmd(DISABLE);  
        
        RTC_WakeUpClockConfig(RTC_WakeUpClock_RTCCLK_Div16);//38K/16=2.375k=0.421ms
        RTC_ITConfig(RTC_IT_WUT, ENABLE);//开启中断
        RTC_SetWakeUpCounter(2375);//2375*0,421=1S左右

        //ITC_SetSoftwarePriority(RTC_CSSLSE_IRQn, ITC_PriorityLevel_3);//优先级
        //RTC_WakeUpCmd(ENSABLE);  //使能
      //  enableInterrupts();
}



void System_Initializes(void)
{    
     
     clock_Init();
     Count_Timer4_Init();
     Count_Timer2_Init();
     //disableInterrupts();
     key_io_init();        
     RF_Init();  
     ec_pin_init();
     LED_Init(); 
     EXTI_SetPinSensitivity(EXTI_Pin_6,EXTI_Trigger_Rising);
     EXTI_DeInit ();
     enableInterrupts();//开启中断总开关
     
}



void main()
{

   
  
  System_Initializes();
  //PWR_FastWakeUpCmd(ENABLE);  //快速唤醒使能
   
   while (1)  
   {
      //halt();
     
      keydeal();
  
    }
}






#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 广州朔月电子科技有限公司 *****END OF FILE****/
