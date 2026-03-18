/*
 * io.c
 *
 *  Created on: 2026年3月13日
 *      Author: 26461
 */
#include "io.h"

GPIO_Number_e led[4] = {LED_R_B, LED_L_B, LED_R_F, LED_L_F};

void io_init(void){
	//设置GPIO为通用输入输出模式
    GPIO_setMode(myGpio, LED_R_B, GPIO_0_Mode_GeneralPurpose);
    GPIO_setMode(myGpio, LED_L_B, GPIO_1_Mode_GeneralPurpose);
    GPIO_setMode(myGpio, LED_R_F, GPIO_2_Mode_GeneralPurpose);
    GPIO_setMode(myGpio, LED_L_F, GPIO_3_Mode_GeneralPurpose);
	//设置GPIO为推挽输出
    GPIO_setPullUp(myGpio, LED_R_B, GPIO_PullUp_Disable);
    GPIO_setPullUp(myGpio, LED_L_B, GPIO_PullUp_Disable);
    GPIO_setPullUp(myGpio, LED_R_F, GPIO_PullUp_Disable);
    GPIO_setPullUp(myGpio, LED_L_F, GPIO_PullUp_Disable);
	//设置GPIO为输出
    GPIO_setDirection(myGpio, LED_R_B, GPIO_Direction_Output);
    GPIO_setDirection(myGpio, LED_L_B, GPIO_Direction_Output);
    GPIO_setDirection(myGpio, LED_R_F, GPIO_Direction_Output);
    GPIO_setDirection(myGpio, LED_L_F, GPIO_Direction_Output);

	led_off(LED_R_B);
	led_off(LED_L_B);
	led_off(LED_R_F);
	led_off(LED_L_F);

}


