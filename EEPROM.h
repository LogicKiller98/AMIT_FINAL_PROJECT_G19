/*
 * EEPROM.h
 *
 * Created: 3/22/2021 6:27:32 PM
 *  Author: Hatem
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "BIT_MATH.h"
#include"STD_TYPES.h"

void EEPROM_write(const unsigned short addr, u8 data);
u8 EEPROM_read(const unsigned short addr);

#endif