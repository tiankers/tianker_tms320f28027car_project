/*
 * key.c
 *
 *  Created on: 2026年3月14日
 *      Author: 26461
 */
#include "key.h"

KEY_X KEY_1;

void key_init(void){
    GPIO_setMode(myGpio, key_1, GPIO_12_Mode_GeneralPurpose);
    GPIO_setPullUp(myGpio, key_1, GPIO_PullUp_Disable);
    GPIO_setDirection(myGpio, key_1, GPIO_Direction_Input);

	//GPIO_setQualification(myGpio, key_1, GPIO_Qual_ASync);//异步输入，立即响应

	GPIO_setQualification(myGpio, key_1, GPIO_Qual_Sample_6);//滤波，采样6次
	GPIO_setQualificationPeriod(myGpio, key_1, 255);//采样周期为255个时钟周期（0.1~0.3ms*6）

	key_pie = 1;//使能按键中断
}
