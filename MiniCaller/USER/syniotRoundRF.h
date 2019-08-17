/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYNIOT_ROUND_RF_H
#define __SYNIOT_ROUND_RF_H

#define SEND_RF_TIMES   6
#define RF_L    GPIO_ResetBits(GPIOB,GPIO_Pin_1)
#define RF_H    GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define SYNIOT_SlEEP        800  //����ʱ�� n*0.1s =10s
#define SYNIOT_EC11_ERR     100
#define SYNIOT_EC11_ERR     100
//#define EC7=GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_7);



typedef struct syniot_roundRF_tt
{
  //unsigned int diff;
  int pulseNumber; //�������
  unsigned int openGrade;    //���ȵȼ�
  unsigned int timecount;   //����ʱ��
  unsigned char active;    //�������
  unsigned int  send_time_count ;   //���䵹��ʱ
  unsigned int  sendFlag ;
  unsigned int  sendRF;     //RF����          
  unsigned char postion;   
  unsigned char RFValue;
  unsigned char addr[4];
  unsigned char init;
  
}syniot_roundRF_t;

extern unsigned char Syniot_RF_BUFF[5];

void tim2Parse(void);
void ec_pin_init(void);
void time_start_count(int num );
#endif