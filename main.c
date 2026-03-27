/**
 * main.c
 */
#include "Tianker.h"

void main(void)
{
    //系统初始化
    config();

    //用户初始化
    adc_init();
    io_init();
    key_init();
    motor_init();
    hw_init();

    time_pie_us(myTimer0, 1000);
    //中断
    pie_init();
    for(;;){
        //code begin
        switch (gn_id) {
            case 1:
                half_led();
                break;
            case 2:
                all_led_on();
                break;
            case 3:
				all_led_off();
                break;
			default:
				break;
        }

		//if (KEY_1.key_even == TWO_DOWN) {
  //          for (i = 0; i < 4; ++i) {
  //              led_on(led[i]);
  //              if (i) led_off(led[i - 1]);


//        switch(led_flag)
//		{
//		case 0:
//            for (i = 0; i < 4; ++i) {
//                led_on(led[i]);
//                if (i) led_off(led[i - 1]);
//				else led_off(led[3]);
//                delay_ms(500);
//            }
//            break;
//
//		case 1:
//            for (i = 0; i < 4; ++i) {
//                led_on(led[i]);
//            }
//            break;
//
//		case 2:
//            for (i = 0; i < 4; ++i) {
//                led_off(led[i]);
//            }
//            break;
//
//		case 3:
//            break;
//
//		default:
//            break;
//
//		}


        if(motor_flag){
            //motor1(1000);
            //motor2(1000);
        }else{
            //motor1(0);
            //motor2(0);
        }
//        led_toggle(LED_R_F);
//        delay_ms(50);
//        if(key_down) led_on(LED_R_F);
//        else led_off(LED_R_F);
        //code end
    }
}
