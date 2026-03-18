/*
 * Delay.c
 *
 *  Created on: 2026Äê3ÔÂ13ÈÕ
 *      Author: 26461
 */

#include "Delay.h"

static void delay_1_ms(void){
    volatile uint16_t i;
	for (i = 0; i < ONE_MS; i++) {

	}
}

void delay_ms(uint16_t ms){
    uint16_t j;
    for (j = 0; j < ms; j++) {
        delay_1_ms();
    }
}
