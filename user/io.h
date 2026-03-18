/*
 * io.h
 *
 *  Created on: 2026Äê3ÔÂ13ÈÕ
 *      Author: 26461
 */

#ifndef USER_IO_H_
#define USER_IO_H_

#include "Tianker.h"
#include "F2802x_Component/include/gpio.h"

#define LED_L_F     GPIO_Number_3
#define LED_L_B     GPIO_Number_1
#define LED_R_F     GPIO_Number_2
#define LED_R_B     GPIO_Number_0

#define led_on(led)			GPIO_setLow(myGpio, led)
#define led_off(led)		GPIO_setHigh(myGpio, led)
#define led_toggle(led)		GPIO_toggle(myGpio, led)

extern GPIO_Number_e led[4];

void io_init(void);

#endif /* USER_IO_H_ */
