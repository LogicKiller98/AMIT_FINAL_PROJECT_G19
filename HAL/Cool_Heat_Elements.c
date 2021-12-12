

#include "BIT_MATH.h"
#include "Cool_Heat_Elements.h"

void heat_init(void){
	SET_BIT(HEAT_PORT_DIR,HEAT_PIN);
}

void cool_init(void){
	SET_BIT(COOL_PORT_DIR,COOL_PIN);
}



void heat_start(void){
	SET_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_start(void){
	SET_BIT(COOL_PORT,COOL_PIN);
}



void heat_stop(void){
	CLR_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_stop(void){
	CLR_BIT(COOL_PORT,COOL_PIN);
}
