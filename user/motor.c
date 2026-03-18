/*
 * motor.c
 *
 *  Created on: 2026年3月15日
 *      Author: 26461
 */
#include "motor.h"

void motor1(int32_t duty) {
	if (duty >= 0) {
		PWM_setCmpA(myPwm3, (uint16_t)duty);
		PWM_setCmpB(myPwm3, 0);
	}
	else {
		PWM_setCmpA(myPwm3, 0);
		PWM_setCmpB(myPwm3, (uint16_t)(-duty));
	}
}
void motor2(int32_t duty) {
	if (duty >= 0) {
		PWM_setCmpA(myPwm4, (uint16_t)duty);
		PWM_setCmpB(myPwm4, 0);
	}
	else {
		PWM_setCmpA(myPwm4, 0);
		PWM_setCmpB(myPwm4, (uint16_t)(-duty));
	}
}

void motor_init(void){
	GPIO_setMode(myGpio, RMIN1, GPIO_4_Mode_EPWM3A);
	GPIO_setMode(myGpio, RMIN2, GPIO_5_Mode_EPWM3B);
	GPIO_setMode(myGpio, LMIN1, GPIO_6_Mode_EPWM4A);
	GPIO_setMode(myGpio, LMIN2, GPIO_7_Mode_EPWM4B);

	GPIO_setPullUp(myGpio, RMIN1, GPIO_PullUp_Disable);
	GPIO_setPullUp(myGpio, RMIN2, GPIO_PullUp_Disable);
	GPIO_setPullUp(myGpio, LMIN1, GPIO_PullUp_Disable);
	GPIO_setPullUp(myGpio, LMIN2, GPIO_PullUp_Disable);

	GPIO_setDirection(myGpio, RMIN1, GPIO_Direction_Output);
	GPIO_setDirection(myGpio, RMIN2, GPIO_Direction_Output);
	GPIO_setDirection(myGpio, LMIN1, GPIO_Direction_Output);
	GPIO_setDirection(myGpio, LMIN2, GPIO_Direction_Output);

	CLK_disableTbClockSync(myClk);//禁止时钟同步，防止止在配置PWM时发生意外的时钟切换
	//设置分频
	PWM_setHighSpeedClkDiv(myPwm3, PWM_HspClkDiv_by_1);
	PWM_setHighSpeedClkDiv(myPwm4, PWM_HspClkDiv_by_1);
	PWM_setClkDiv(myPwm3, PWM_ClkDiv_by_1);
	PWM_setClkDiv(myPwm4, PWM_ClkDiv_by_1);
	PWM_setCounterMode(myPwm3, PWM_CounterMode_Up);
	PWM_setCounterMode(myPwm4, PWM_CounterMode_Up);
	PWM_setPeriod(myPwm3, 60000); //设置PWM周期为60000个时钟周期，即1ms
	PWM_setPeriod(myPwm4, 60000); //设置PWM周期为60000个时钟周期，即1ms
	PWM_setPeriodLoad(myPwm3, PWM_PeriodLoad_Shadow);
	PWM_setPeriodLoad(myPwm4, PWM_PeriodLoad_Shadow);//启用时钟同步
	PWM_setCmpA(myPwm3, 0); //初始占空比为0%
	PWM_setCmpB(myPwm3, 0); //初始占空比为0%
	PWM_setCmpA(myPwm4, 0); //初始占空比为0%
	PWM_setCmpB(myPwm4, 0); //初始占空比为0%
	PWM_setShadowMode_CmpA(myPwm3, PWM_ShadowMode_Shadow);//启用比较寄存器A的影子寄存器
	PWM_setShadowMode_CmpB(myPwm3, PWM_ShadowMode_Shadow);//启用比较寄存器B的影子寄存器
	PWM_setShadowMode_CmpA(myPwm4, PWM_ShadowMode_Shadow);//启用比较寄存器A的影子寄存器
	PWM_setShadowMode_CmpB(myPwm4, PWM_ShadowMode_Shadow);//启用比较寄存器B的影子寄存器

	PWM_setLoadMode_CmpA(myPwm3, PWM_LoadMode_Zero);//设置比较寄存器A在计数器清零时加载
	PWM_setLoadMode_CmpB(myPwm3, PWM_LoadMode_Zero);//设置比较寄存器B在计数器清零时加载
	PWM_setLoadMode_CmpA(myPwm4, PWM_LoadMode_Zero);//设置比较寄存器A在计数器清零时加载
	PWM_setLoadMode_CmpB(myPwm4, PWM_LoadMode_Zero);//设置比较寄存器B在计数器清零时加载

	PWM_setActionQual_CntDown_CmpA_PwmA(myPwm3, PWM_ActionQual_Clear); //当计数器向下计数并且比较寄存器A匹配时，清除PWM信号
	PWM_setActionQual_CntDown_CmpB_PwmB(myPwm3, PWM_ActionQual_Clear); //当计数器向下计数并且比较寄存器B匹配时，清除PWM信号
	PWM_setActionQual_CntDown_CmpA_PwmA(myPwm4, PWM_ActionQual_Clear); //当计数器向下计数并且比较寄存器A匹配时，清除PWM信号
	PWM_setActionQual_CntDown_CmpB_PwmB(myPwm4, PWM_ActionQual_Clear); //当计数器向下计数并且比较寄存器B匹配时，清除PWM信号

	PWM_setActionQual_Period_PwmA(myPwm3, PWM_ActionQual_Clear); //当计数器达到周期值时，清除PWM信号
	PWM_setActionQual_Period_PwmB(myPwm3, PWM_ActionQual_Clear); //当计数器达到周期值时，清除PWM信号
	PWM_setActionQual_Period_PwmA(myPwm4, PWM_ActionQual_Clear); //当计数器达到周期值时，清除PWM信号
	PWM_setActionQual_Period_PwmB(myPwm4, PWM_ActionQual_Clear); //当计数器达到周期值时，清除PWM信号

	CLK_enableTbClockSync(myClk);

	PIE_registerPieIntHandler(myPie, PIE_GroupNumber_3, PIE_SubGroupNumber_1, &pwm3);
	PIE_registerPieIntHandler(myPie, PIE_GroupNumber_3, PIE_SubGroupNumber_2, &pwm4);

	PWM_enableInt(myPwm3);
	PWM_enableInt(myPwm4);
	PIE_enableInt(myPie, PIE_GroupNumber_3, PIE_InterruptSource_EPWM3);
	PIE_enableInt(myPie, PIE_GroupNumber_3, PIE_InterruptSource_EPWM4);

	CPU_enableInt(myCpu, CPU_IntNumber_3); 
}


