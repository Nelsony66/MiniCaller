#include "key.h"

//按键IO初始化//初始化引脚为输入
void key_io_init(void)
{
//输入
GPIO_Init(GPIOB,GPIO_Pin_3,GPIO_Mode_In_PU_No_IT);//初始化LED端口
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
    static uint8_t s_u8LastKey = KEY_NULL; //保存按键释放时候的键值
    uint8_t KeyTemp = KEY_NULL;
    KeyTemp = KeyScan(); //获取键值
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
        
        case KEY_STATE_WOBBLE: //消抖
        {
          s_u8KeyState = KEY_STATE_PRESS;
        }
        break;
        
        case KEY_STATE_PRESS:
        {
            if(KEY_NULL != (KeyTemp))
            {
                s_u8LastKey = KeyTemp; //保存键值,以便在释放按键状态返回键值
                KeyTemp |= KEY_DOWN; //按键按下
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
                  KeyTemp |= KEY_LONG; //长按键事件发生
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
    *pKeyValue = KeyTemp; //返回键值
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

