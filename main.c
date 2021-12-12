/*
 * main.c
 *
 *  Created on: 5 Dec 2021
 *      Author: sa
 */


/*
 * main.c
 *
 * Created: 3/20/2021 5:13:23 PM
 *  Author: sa
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "System_control.h"


/*----------------------------------------------------------------------------*-
ON/OFF_Button_INTERRUPT
-*----------------------------------------------------------------------------*/

ISR(INT2_vect){
	if(Current_mode==OFF){
		Current_mode = ON;
		desired_temp = EEPROM_read(0x0000);
	}
	else if (Current_mode==ON || Current_mode==SETTING){
		Current_mode = OFF;
	}
}

/*----------------------------------------------------------------------------*-
TRIGGERS EVERY 100MS
-*----------------------------------------------------------------------------*/

ISR(TIMER1_COMPA_vect){
	temp_measure_f = 1;
}

//timer trriger

ISR(TIMER0_COMP_vect){
	if ((Current_mode==SETTING) || (Current_mode==ON)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_f ^= 1;
		}
		if (setting_counter > 20){

			Current_mode = ON;
		}
	}
}




int main(void){

	sys_init();

	while(1){
		switch (Current_mode){
			case ON:{
				ON_mode();
				break;
			}
			case OFF:{
				OFF_mode();
				break;
			}
			case SETTING:{
				SET_mode();
				break;
			}
		}
	}
	return 0;
}
