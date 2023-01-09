#include <avr/io.h>
#include <util/delay.h>


int main (void){
  
DDRB = DDRB |  (1<<0) | (1<<1)| (1<<2)| (1<<3); /* configure PORTB bit 0,1,2,3 for output*/

// DDRB = DDRB & ( ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3) ); /* configure PORTB bit 0,1,2,3 for input*/
	while(1){
 		PORTB = PORTB | (1<<0) | (1<<1)| (1<<2)| (1<<3) ; /* set portB pin 0,1,2,3 high to turn leds on */
  		_delay_ms(1000);
		 PORTB = PORTB &~(1<<1)&~(1<<2)&~(1<<3)&~(1<<0); /* set portB pin 0,1,2,3 low to turn leds off */
 		_delay_ms(1000);
	}
  return 0;
}