#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/delay.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "adc.h"

volatile uint16_t adc_value;

void main (void) {
	 
	sei();
	init_adc();
	LED_init();
	uart_init();
	timer1_init();
	timer2_init();

	while (1){}
}


ISR(ADC_vect){

	// Read ADC and store it into a variable
	adc_value = ADC;
}

ISR(TIMER2_COMPA_vect){

	// Start new conversion and write previous value soted in adc_value to OCR0A
	ADCSRA |= (1 << ADSC);
	
	// Eveytime we start a new conversion, specify channel ADC0
	ADMUX = 0;

	// Convert range, otherwise LED fill flick and be inconsistent
	uint32_t adc_value_converted = convert_range(adc_value, 0, 1023, 0, 255);
	
	// If ADC 0 = turn off LED
	if(adc_value_converted == 0){
		PORTD &= ~(1 << PD6);
		//OCR0A = 0;
	} else {
		//PORTD |=(1 << PORTD6);
		OCR0A = adc_value_converted;
	}
}
