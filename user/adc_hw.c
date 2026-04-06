/*
 * adc_hw.c
 *
 *  Created on: 2026年3月19日
 *      Author: 26461
 */

#include "adc_hw.h"

ADC_SocChanNumber_e adc_pin[7];
uint16_t adc_val[8];
uint16_t a5;

void adc_init(void) {
    uint16_t i = 0;
	adc_pin[0] = ADC_SocChanNumber_A7;
	adc_pin[1] = ADC_SocChanNumber_B1;
	adc_pin[2] = ADC_SocChanNumber_B2;
	adc_pin[3] = ADC_SocChanNumber_B3;
	adc_pin[4] = ADC_SocChanNumber_B4;
	adc_pin[5] = ADC_SocChanNumber_B6;
	adc_pin[6] = ADC_SocChanNumber_B7;
	ADC_powerUp(myAdc);								//上电 ADC 模块
	ADC_enableBandGap(myAdc);						//启用 ADC 内部基准电压
	ADC_enableRefBuffers(myAdc);					//启用 ADC 内部基准电压缓冲器
	ADC_enable(myAdc);								//使能 ADC 模块
	ADC_setVoltRefSrc(myAdc, ADC_VoltageRefSrc_Int);//设置 ADC 电压参考源为内部基准电压
	ADC_enableTempSensor(myAdc);					//启用内部温度传感器

	ADC_setSocChanNumber(myAdc, ADC_SocNumber_0, ADC_SocChanNumber_A5);//配置 ADC SOC0 的通道为 A5（内部温度传感器）
	//配置 ADC SOC1~SOC7 的通道为 adc_pin 数组中指定的引脚
	for (i = 0; i < 7; ++i) {
		ADC_setSocChanNumber(myAdc, (ADC_SocNumber_e)(i + 1), adc_pin[i]);
	}
	ADC_setSocSampleWindow(myAdc, ADC_SocNumber_0, ADC_SocSampleWindow_7_cycles);//配置 ADC SOC0 的采样窗口为 7 周期
	//配置 ADC SOC0~SOC7 的采样窗口为 7 周期
	for (i = 0; i < 7; ++i) {
		ADC_setSocSampleWindow(myAdc, (ADC_SocNumber_e)(i + 1), ADC_SocSampleWindow_7_cycles);
	}
	ADC_setSocTrigSrc(myAdc, ADC_SocNumber_0, ADC_SocTrigSrc_CpuTimer_0); //设置触发源为CPU定时器0
	//设置 ADC SOC1~SOC7 的触发源为 CPU 定时器 0
	for (i = 0; i < 7; ++i) {
		ADC_setSocTrigSrc(myAdc, (ADC_SocNumber_e)(i + 1), ADC_SocTrigSrc_CpuTimer_0);
	}

}




/* 在 hw_init 中调用，初始化 GPIO 并启动 ADC 配置 */
void hw_init(void) {
	GPIO_setMode(myGpio, HW_EN, GPIO_34_Mode_GeneralPurpose);//设置 GPIO 模式为通用输入输出
	GPIO_setPullUp(myGpio, HW_EN, GPIO_PullUp_Disable);//禁用上拉电阻
	GPIO_setDirection(myGpio, HW_EN, GPIO_Direction_Output);//设置 GPIO 方向为输出
    //使能红外传感器
    GPIO_setHigh(myGpio, HW_EN);

}
