
#include "LED.h"



void led_init(void){
	

	
	SET_BIT(LED_PORT_DIR,LED_PIN);
	CLR_BIT(LED_PORT,LED_PIN);

}



void led_on(void){
	SET_BIT(LED_PORT,LED_PIN);
}

void led_off(void){
	CLR_BIT(LED_PORT,LED_PIN);
}
