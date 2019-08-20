#ifndef __KEY_H
#define __KEY_H

#include "global.h"


//根据按键硬件连接定义按键键值
#define KEY_VALUE_1 0x0e
#define KEY_VALUE_2 0x0d
#define KEY_VALUE_3 0x0b
#define KEY_VALUE_4 0x07
#define KEY_VALUE_5 0x09
#define KEY_NULL 0x0f


#define KEY_PORT GPIOB;
#define KEY_PIN GPIO_Pin_3;


//定义长按键的 TICK 数,以及连发间隔的 TICK 数
#define KEY_LONG_PERIOD 30
#define KEY_CONTINUE_PERIOD 10
//定义按键返回值状态(按下,长按,连发,释放)
#define KEY_DOWN 0x80
#define KEY_LONG 0x40
#define KEY_CONTINUE 0x20
#define KEY_UP 0x10
//定义按键状态
#define KEY_STATE_INIT 0
#define KEY_STATE_WOBBLE 1
#define KEY_STATE_PRESS 2
#define KEY_STATE_LONG 3
#define KEY_STATE_CONTINUE 4
#define KEY_STATE_RELEASE 5

void key_io_init(void);
void keyloop(uint8_t *pKeyreValue);
void dealkeyvalue(void);
#endif