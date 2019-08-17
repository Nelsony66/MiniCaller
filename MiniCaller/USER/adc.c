
#include "global.h"


void ADC_Initializes(void)
{
  GPIO_Init(LIGHT_PORT, LIGHT_PINS, GPIO_Mode_In_FL_No_IT);
  ADC_Init (ADC1,ADC_ConversionMode_Single,ADC_Resolution_12Bit,ADC_Prescaler_1);//ADC1，单次采样，12位，1分频
  ADC_Cmd(ADC1,ENABLE);                              //使能ADC
  ADC_ChannelCmd (ADC1,ADC_Channel_18,ENABLE);//ADC1 18通道使能
}

uint32_t ADC_Read(void)
{
  uint8_t  i;
  uint16_t adc_value = 0;
  uint32_t adc_voltage = 0;

  for(i=0; i<4; i++)
  {
    ADC_SoftwareStartConv (ADC1);//开启软件转换               
    while(RESET == ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
    ADC_ClearFlag(ADC1,ADC_FLAG_EOC);               //等待转换完成，并清除标志

    adc_value += ADC_GetConversionValue(ADC1);      //读取转换结果
  }

  adc_voltage = adc_value >> 2;                  //求平均
  adc_voltage = (adc_voltage*3300) >> 10;        //1000倍电压值

  return adc_voltage;
}