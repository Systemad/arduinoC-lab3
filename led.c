#include <avr/io.h>
#include "led.h"

void LED_init() {
	DDRB |= (1 << PB3);

	DDRD |= (1 << PD6);
}

uint8_t simple_ramp() {
	// ...
}