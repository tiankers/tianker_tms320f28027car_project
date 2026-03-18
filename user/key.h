/*
 * key.h
 *
 *  Created on: 2026年3月14日
 *      Author: 26461
 */

#ifndef USER_KEY_H_
#define USER_KEY_H_

#include "Tianker.h"

#define key_1   GPIO_Number_12
#define key_2   ADC_SocChanNumber_A0        //预留按键2，连接到ADC输入引脚上，读取ADC值来判断按键状态

#define key_down    !(GPIO_getData(myGpio, key_1))     //读取按键状态(按键按下时为低电平)

typedef struct _KEY_X_
{
    uint16_t key_num;
    bool down;
} KEY_X;

extern KEY_X KEY_1;

void key_init(void);

#endif /* USER_KEY_H_ */
