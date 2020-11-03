#include <avr/io.h>
#include "timer.h"
#include <util/atomic.h>

#define F_CPU 16000000UL

/*  Credit for millis() function
*   Author: Monoclecat, https://github.com/monoclecat/avr-millis-function
*/

volatile unsigned long timer1_millis; 

ISR(TIMER1_COMPA_vect)
{
  timer1_millis++;  
}

void init_millis()
{
  unsigned long ctc_match_overflow;
  
  ctc_match_overflow = ((F_CPU / 1000) / 8);
    
  TCCR1B |= (1 << WGM12) | (1 << CS11);
  
  OCR1AH = (ctc_match_overflow >> 8);
  OCR1AL = ctc_match_overflow;

  TIMSK1 |= (1 << OCIE1A);
}


unsigned long millis()
{
  unsigned long millis_return;

  ATOMIC_BLOCK(ATOMIC_FORCEON) {
    millis_return = timer1_millis;
  }
  return millis_return;
} 