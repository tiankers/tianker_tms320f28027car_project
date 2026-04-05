/*
 * adc_hw.h
 *
 *  Created on: 2026年3月19日
 *      Author: 26461
 */

#ifndef USER_ADC_HW_H_
#define USER_ADC_HW_H_

#include "Tianker.h"

#define HW_EN           (GPIO_Number_34)

//1近2中3远
#define HW_l_1          (4)
#define HW_l_2          (2)
#define HW_l_3          (0)
#define HW_z            (5)
#define HW_r_3          (1)
#define HW_r_2          (3)
#define HW_r_1          (6)

extern ADC_SocChanNumber_e adc_pin[7];
extern uint16_t adc_val[7];
extern uint16_t a5;

void adc_init(void);
void hw_init(void);


#endif /* USER_ADC_HW_H_ */
