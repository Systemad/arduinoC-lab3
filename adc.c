#include <avr/io.h>
#include <stdio.h>

void init_adc(){

	// Channel ADC0
	ADMUX = 0;

	// Use VCC as reference
	ADMUX |= (1 << REFS0);

	// left bit result
	ADMUX |= (1 << ADLAR);
	
	// Set prescale to 8
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0);

	// Enable ADC
	ADCSRA |= (1 << ADEN);

	// Enable intrrupt
	ADCSRA |= (1 << ADIE);

	//DIDR0 |= _BV(ADC0D);

	// Start conversion adc
	//ADCSRA |= (1 << ADSC);
}

const uint8_t convert_range(uint32_t reference_value, uint32_t reference_minimum, uint32_t reference_maximum, uint32_t out_minimum, uint32_t out_maximum)
{
    return (reference_value - reference_minimum) * (out_maximum - out_minimum) / (reference_maximum - reference_minimum) + out_minimum;
}