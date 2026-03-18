//#############################################################################
//
//! \file   f2802x_common/source/clk.c
//!
//! \brief  Contains the various functions related to the clock object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "F2802x_Component/include/clk.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

//关闭ADC时钟
void CLK_disableAdcClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_ADCENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableAdcClock() function
//关闭外部时钟输入
void CLK_disableClkIn(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_XCLKINOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableClkIn() function

//关闭比较器时钟
void CLK_disableCompClock(CLK_Handle clkHandle, const CLK_CompNumber_e compNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    // clear the bits
    clk->PCLKCR3 &= (~compNumber);

    return;
} // end of CLK_disableCompClock() function

//关闭CPU定时器时钟
void CLK_disableCpuTimerClock(CLK_Handle clkHandle, const CLK_CpuTimerNumber_e cpuTimerNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR3 &= (~cpuTimerNumber);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableCpuTimerClock() function

//关闭晶振时钟
void CLK_disableCrystalOsc(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_XTALOSCOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableCrystalOsc() function

//关闭ECAP1时钟
void CLK_disableEcap1Clock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR1 &= (~CLK_PCLKCR1_ECAP1ENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableEcap1Clock() function

//关闭ECAP1时钟
void CLK_disableGpioInputClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR3 &= (~CLK_PCLKCR3_GPIOINENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableGpioInputClock() function

//关闭高分辨率PWM时钟
void CLK_disableHrPwmClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_HRPWMENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableI2cClock() function

//关闭高分辨率PWM时钟
void CLK_disableI2cClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_I2CAENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableI2cClock() function

//关闭内部振荡器1时钟
void CLK_disableOsc1(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_INTOSC1OFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableOsc1() function

//关闭内部振荡器1的停机模式
void CLK_disableOsc1HaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_INTOSC1HALTI_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableOsc1HaltMode() function

//关闭内部振荡器2时钟
void CLK_disableOsc2(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_INTOSC2OFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableOsc2() function

//关闭内部振荡器2的停机模式
void CLK_disableOsc2HaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_INTOSC2HALTI_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableOsc2HaltMode() function

//关闭PWM时钟
void CLK_disablePwmClock(CLK_Handle clkHandle, const PWM_Number_e pwmNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR1 &= (~(1 << pwmNumber));

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disablePwmClock() function

//关闭SCI A时钟
void CLK_disableSciaClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
asm(" nop");

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_SCIAENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;
asm(" nop");
    return;
} // end of CLK_disableSciaClock() function

//关闭SPI A时钟
void CLK_disableSpiaClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_SPIAENCLK_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableSpiaClock() function

//关闭时间基准时钟同步
void CLK_disableTbClockSync(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->PCLKCR0 &= (~CLK_PCLKCR0_TBCLKSYNC_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableTbClockSync() function

//关闭看门狗停机模式
void CLK_disableWatchDogHaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL |= CLK_CLKCTL_WDHALTI_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_disableWatchDogHaltMode() function

//使能ADC时钟
void CLK_enableAdcClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_ADCENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableAdcClock() function

//使能比较器时钟
void CLK_enableCompClock(CLK_Handle clkHandle, const CLK_CompNumber_e compNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR3 |= compNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableCompClock() function

//使能CPU定时器时钟
void CLK_enableCpuTimerClock(CLK_Handle clkHandle, const CLK_CpuTimerNumber_e cpuTimerNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR3 |= cpuTimerNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableCpuTimerClock() function

//使能晶振时钟
void CLK_enableCrystalOsc(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_XTALOSCOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableCrystalOsc() function

//使能ECAP1时钟
void CLK_enableEcap1Clock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR1 |= CLK_PCLKCR1_ECAP1ENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableEcap1Clock() function

//使能外部时钟输入
void CLK_enableClkIn(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_XCLKINOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableClkIn() function


void CLK_enableGpioInputClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR3 |= CLK_PCLKCR3_GPIOINENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableGpioInputClock() function

//使能高分辨率PWM时钟
void CLK_enableHrPwmClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_HRPWMENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableI2cClock() function

//使能I2C时钟
void CLK_enableI2cClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_I2CAENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableI2cClock() function

//使能内部振荡器1
void CLK_enableOsc1(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL &= (~CLK_CLKCTL_INTOSC1OFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableOsc1() function

//使能内部振荡器1的停机模式
void CLK_enableOsc1HaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL &= (~CLK_CLKCTL_INTOSC1HALTI_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableOsc1HaltMode() function

//使能内部振荡器2
void CLK_enableOsc2(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL &= (~CLK_CLKCTL_INTOSC2OFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableOsc2() function

//使能内部振荡器2的停机模式
void CLK_enableOsc2HaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->CLKCTL &= (~CLK_CLKCTL_INTOSC2HALTI_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableOsc2HaltMode() function

//使能PWM时钟
void CLK_enablePwmClock(CLK_Handle clkHandle, const PWM_Number_e pwmNumber)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR1 |= 1 << pwmNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enablePwmClock() function

//使能SCI A时钟
void CLK_enableSciaClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
asm(" nop");

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_SCIAENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;
asm(" nop");
    return;
} // end of CLK_enableSciaClock() function

//使能SPI A时钟
void CLK_enableSpiaClock(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_SPIAENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableSpiaClock() function

//使能SPI A时钟
void CLK_enableTbClockSync(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->PCLKCR0 |= CLK_PCLKCR0_TBCLKSYNC_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableTbClockSync() function

//使能看门狗停机模式
void CLK_enableWatchDogHaltMode(CLK_Handle clkHandle)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_WDHALTI_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableWatchDogHaltMode() function

//初始化CLK对象
CLK_Handle CLK_init(void *pMemory, const size_t numBytes)
{
    CLK_Handle clkHandle;


    if(numBytes < sizeof(CLK_Obj))
    return((CLK_Handle)NULL);

    // assign the handle
    clkHandle = (CLK_Handle)pMemory;

    return(clkHandle);
} // end of CLK_init() function

//设置时钟输出预分频器
void CLK_setClkOutPreScaler(CLK_Handle clkHandle, 
                            const CLK_ClkOutPreScaler_e preScaler)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->XCLK &= (~CLK_XCLK_XCLKOUTDIV_BITS);

    // set the bits
    clk->XCLK |= preScaler;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setClkOutPreScaler() function

//设置低速时钟预分频器
void CLK_setLowSpdPreScaler(CLK_Handle clkHandle, 
                            const CLK_LowSpdPreScaler_e preScaler)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    clk->LOSPCP |= preScaler;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setLowSpdPreScaler() function

//设置振荡器源
void CLK_setOscSrc(CLK_Handle clkHandle, const CLK_OscSrc_e src)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_OSCCLKSRCSEL_BITS);
    // set the bits
    clk->CLKCTL |= src;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setOscSrc() function
                      
//设置振荡器2源
void CLK_setOsc2Src(CLK_Handle clkHandle, const CLK_Osc2Src_e src)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_OSCCLKSRC2SEL_BITS);

    // set the bits
    clk->CLKCTL |= src;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setOsc2Src() function
                      
//设置CPU定时器2预分频器
void CLK_setTimer2PreScaler(CLK_Handle clkHandle,
                           const CLK_Timer2PreScaler_e preScaler)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_TMR2CLKPRESCALE_BITS);

    // set the bits
    clk->CLKCTL |= preScaler;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setTimer2PreScaler() function
                      
//设置CPU定时器2源
void CLK_setTimer2Src(CLK_Handle clkHandle, const CLK_Timer2Src_e src)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_TMR2CLKSRCSEL_BITS);

    // set the bits
    clk->CLKCTL |= src;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setTimer2Src() function
                      
//设置看门狗时钟源
void CLK_setWatchDogSrc(CLK_Handle clkHandle, const CLK_WdClkSrc_e src)
{
    CLK_Obj *clk = (CLK_Obj *)clkHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    clk->CLKCTL &= (~CLK_CLKCTL_WDCLKSRCSEL_BITS);

    // set the bits
    clk->CLKCTL |= src;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_setWatchDogSrc() function
                      


// end of file
