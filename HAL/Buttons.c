
#include "Buttons.h"


void Buttons_init(void){
	// Setting the pins as INPUT pins
	CLR_BIT(PORT_B_DIR,ON_OFF_PIN);
	CLR_BIT(PORT_B_DIR,UP_PIN);
	CLR_BIT(PORT_B_DIR,DOWN_PIN);
	
	// Enable internal Pull-Up Resistor
	
	SET_BIT(PORT_B,ON_OFF_PIN);
	SET_BIT(PORT_B,UP_PIN);
	SET_BIT(PORT_B,DOWN_PIN);
	
	
	// This Following Section is for the external interrupt
	// assigned to the ON/OFF Button.
	
	// Enable Global Interrupt bit
	 GIE_voidEnable();
	
	// Trigger with Rising Edge
	SET_BIT(MCUCSR,ISC2);
	
	// Enable INT2 (External Interrupt)
	SET_BIT(GICR,INT2);
}




u8 DOWN(void){
	// Check if pressed for the first time
	if(!(read_bit(PINB,DOWN_PIN))){
		// wait for 50 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);

		// check one more time
		if (!(read_bit(PINB,DOWN_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
u8 UP(void){
	// Check if pressed for the first time
	if(!(read_bit(PINB,UP_PIN))){
		// wait for 50 ms to make sure it's pressed (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);

		// check one more time
		if (!(read_bit(PINB,UP_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
