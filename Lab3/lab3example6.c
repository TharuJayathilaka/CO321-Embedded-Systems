#include <avr/io.h>
#include<avr/interrupt.h>

int main(void){
	
	DDRB=DDRB |0b00100010;  /* configure PORTB bit 5 for output*/
	
	overflow_timer0();
	overflow_timer1();
	
    while(1){
    
  	}
}

void overflow_timer0(){
	TCNT0 = 131;   // for 2 miliseconds at 16 MHz	

	TCCR0A = 0x00;
	TCCR0B = 0x04;  // Timer mode with 256 prescler
	
	TIMSK0 = 0x01;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}
void overflow_timer1(){
	TCNT1 = 34286;   // for 500 miliseconds at 16 MHz	

	TCCR1A = 0x00;
	TCCR1B = 0x04;  // Timer mode with 256 prescler
	
	TIMSK1 = 0x01;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}

unsigned char i=0,j=0;

ISR (TIMER0_OVF_vect){    // Timer0 ISR
		
	TCNT0 = 131;   // for 2 miliseconds at 16 MHz
	i++;
	
	if(i==25){
		PORTB ^= (1 << 1);	
		i=0;
	}
}
ISR (TIMER1_OVF_vect){    // Timer0 ISR
	
	PORTB ^= (1 << 5);	
	TCNT1 = 34286;   // for 500 miliseconds at 16 MHz
}