#include "key.h"

//����IO��ʼ��//��ʼ������Ϊ����
void key_io_init(void)
{
//����
GPIO_Init(GPIOB,GPIO_Pin_3,GPIO_Mode_In_PU_No_IT);//��ʼ��LED�˿�
}


static uint8_t KeyScan(void)
{
    if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)==0)
    return KEY_VALUE_1 ;
    return KEY_NULL ;
}


void GetKey(uint8_t *pKeyValue)
{
    static uint8_t s_u8KeyState = KEY_STATE_INIT;
    static uint8_t s_u8KeyTimeCount = 0;
    static uint8_t s_u8LastKey = KEY_NULL; //���水���ͷ�ʱ��ļ�ֵ
    uint8_t KeyTemp = KEY_NULL;
    KeyTemp = KeyScan(); //��ȡ��ֵ
    switch(s_u8KeyState)
    {
        case KEY_STATE_INIT:
        {
          if(KEY_NULL != (KeyTemp))
          {
            s_u8KeyState = KEY_STATE_WOBBLE;
          }
         }
        break;
        
        case KEY_STATE_WOBBLE: //����
        {
          s_u8KeyState = KEY_STATE_PRESS;
        }
        break;
        
        case KEY_STATE_PRESS:
        {
            if(KEY_NULL != (KeyTemp))
            {
                s_u8LastKey = KeyTemp; //�����ֵ,�Ա����ͷŰ���״̬���ؼ�ֵ
                KeyTemp |= KEY_DOWN; //��������
                s_u8KeyState = KEY_STATE_LONG;
            }
            else
            {
                s_u8KeyState = KEY_STATE_INIT;
            }
        }
        break;
        
        case KEY_STATE_LONG:
        {
            if(KEY_NULL != (KeyTemp))
            {
              if(++s_u8KeyTimeCount > KEY_LONG_PERIOD)
              {
                  s_u8KeyTimeCount = 0;
                  KeyTemp |= KEY_LONG; //�������¼�����
                  s_u8KeyState = KEY_STATE_CONTINUE;
              }
            }
            else
            {
                s_u8KeyState = KEY_STATE_RELEASE;
            }
        }
        break;
        
        case KEY_STATE_CONTINUE:
        {
            if(KEY_NULL != (KeyTemp))
            {
              if(++s_u8KeyTimeCount > KEY_CONTINUE_PERIOD)
              {
                s_u8KeyTimeCount = 0;
                KeyTemp |= KEY_CONTINUE;
              }
            }
            else
            {
                s_u8KeyState = KEY_STATE_RELEASE;
            }
        }
        break;
        
        case KEY_STATE_RELEASE:
        {
          s_u8LastKey |= KEY_UP;
          KeyTemp = s_u8LastKey;
          s_u8KeyState = KEY_STATE_INIT;
        }
        break;
        
        default:
        break;
      }     
    *pKeyValue = KeyTemp; //���ؼ�ֵ
}

void keyloop(uint8_t *pKeyreValue)
{
 uint8_t keystate=0;
  if(keyscantime>5)//10ms
  {
    keyscantime=0;
    GetKey(&keystate);
  }
   
    *pKeyreValue=keystate;
}

