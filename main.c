#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/atomic.h>
#include "serial.h"
#include "timer.h"

// Store button states
int buttonState = 0;     
int lastButtonState = 0;
unsigned lastpushed = 0;

char *relased = "Button released\r\n";
char *held = "button is being held\r\n"; 

void main (void) {

	uart_init();
	init_millis();
	sei();

	DDRD &= ~(1 << PD2);

	while (1) {
		buttonState = (PIND & (1<<PD2));
		if (buttonState != lastButtonState) {
			updateState();
		}
		lastButtonState = buttonState;
	}
}

void updateState() {
  if (buttonState == 0) {
      if ((millis() - lastpushed) >= 200) {
          uart_putstr(relased);
      }
  } else {
    if ((millis() - lastpushed) >= 300) {
          uart_putstr(held); 
      }
  }
}
