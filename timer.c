#include <avr/io.h>
#include "timer.h"

void timer1_init() {

	// Non-invering mode, Fast PWN mode, 0xFF as TOP
	TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);

	// Set prescale to 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
	
	// timer0 compare match interrupt
	TIMSK0 |= (1 << OCIE0A);
}


void timer2_init(){

	// Set timer interrupt match
	OCR2A = (F_CPU / 1024 / 1000 - 1);

	// Set timer2 to CTC mode
	TCCR2A |= (1 << WGM21);

	// Set prescaler to 1024
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);

	// Overflow interrupt enable
	TIMSK2 |= (1 << TOIE2);

	// Enable CTC timer interrupt
	TIMSK2 |= (1 << OCIE2A);
}