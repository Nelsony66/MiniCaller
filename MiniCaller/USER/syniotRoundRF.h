/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYNIOT_ROUND_RF_H
#define __SYNIOT_ROUND_RF_H

#define SEND_RF_TIMES   6
#define RF_L    GPIO_ResetBits(GPIOB,GPIO_Pin_1)
#define RF_H    GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define SYNIOT_SlEEP        800  //唤醒时间 n*0.1s =10s
#define SYNIOT_EC11_ERR     100
#define SYNIOT_EC11_ERR     100
//#define EC7=GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_7);



typedef struct syniot_roundRF_tt
{
  //unsigned int diff;
  int pulseNumber; //脉冲个数
  unsigned int openGrade;    //开度等级
  unsigned int timecount;   //休眠时间
  unsigned char active;    //激活操作
  unsigned int  send_time_count ;   //发射倒计时
  unsigned int  sendFlag ;
  unsigned int  sendRF;     //RF发射          
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