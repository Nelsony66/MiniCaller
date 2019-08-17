
#include "global.h"


void ADC_Initializes(void)
{
  GPIO_Init(LIGHT_PORT, LIGHT_PINS, GPIO_Mode_In_FL_No_IT);
  ADC_Init (ADC1,ADC_ConversionMode_Single,ADC_Resolution_12Bit,ADC_Prescaler_1);//ADC1�����β�����12λ��1��Ƶ
  ADC_Cmd(ADC1,ENABLE);                              //ʹ��ADC
  ADC_ChannelCmd (ADC1,ADC_Channel_18,ENABLE);//ADC1 18ͨ��ʹ��
}

uint32_t ADC_Read(void)
{
  uint8_t  i;
  uint16_t adc_value = 0;
  uint32_t adc_voltage = 0;

  for(i=0; i<4; i++)
  {
    ADC_SoftwareStartConv (ADC1);//�������ת��               
    while(RESET == ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
    ADC_ClearFlag(ADC1,ADC_FLAG_EOC);               //�ȴ�ת����ɣ��������־

    adc_value += ADC_GetConversionValue(ADC1);      //��ȡת�����
  }

  adc_voltage = adc_value >> 2;                  //��ƽ��
  adc_voltage = (adc_voltage*3300) >> 10;        //1000����ѹֵ

  return adc_voltage;
}