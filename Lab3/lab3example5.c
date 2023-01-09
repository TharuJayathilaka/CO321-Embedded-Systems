
#include <avr/io.h>
#include<avr/interrupt.h>

int main(void){
	
	DDRB=DDRB |0b00100000;  /* configure PORTB bit 5 for output*/

	overflow_timer1();
	
    while(1){
    
  	}
}

void overflow_timer1(){
	TCNT0 = 6;   // for 4 miliseconds at 16 MHz	

	TCCR0A = 0x00;
	TCCR0B = 0x04;  // Timer mode with 256 prescler
	
	TIMSK0 = 0x01;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}

unsigned char i=0;

ISR (TIMER0_OVF_vect){    // Timer0 ISR
		
	TCNT0 = 6;   // for 4 miliseconds at 16 MHz
	i++;
	
	if(i==25){
		PORTB ^= (1 << 5);	
		i=0;
	}
}
