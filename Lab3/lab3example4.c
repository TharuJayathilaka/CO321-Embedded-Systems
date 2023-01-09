#include<util/delay.h>
#include <avr/io.h>
#include<avr/interrupt.h>

#define BLINK_DELAY_MS 1000


int main(void){
	
	DDRB=DDRB |0b00010000;  /* configure PORTB bit 5 for output*/
	DDRD=DDRD |0b00011110;  /* configure PORTD bit 4,1,2,3, for output*/

	overflow_timer1();
	
    while(1){
       	unsigned char i,j;
		
      //ABCD pattern
     	for(i=4;i>=1;i--){
         	PORTD = PORTD | (1<<i); //set high corresponding pin in portB
            _delay_ms(BLINK_DELAY_MS);
       	    PORTD = PORTD &~ (1<<i);//set low corresponding pin in portB
            _delay_ms(BLINK_DELAY_MS);
      	} 
      //CB pattern
      	for(j=2;j<4;j++){
          	PORTD = PORTD | (1<<j);//set high corresponding pin in portB
            _delay_ms(BLINK_DELAY_MS);
        	PORTD = PORTD &~ (1<<j); //set low corresponding pin in portB
       	    _delay_ms(BLINK_DELAY_MS);
      	}
  	}
}

void overflow_timer1(){
	TCNT1 = 49911;   // for 1 sec at 16 MHz	

	TCCR1A = 0x00;
	TCCR1B = 0x05;  // Timer mode with 1024 prescler
	
	TIMSK1 = 0x01;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}


ISR (TIMER1_OVF_vect){    // Timer1 ISR
	PORTB ^= (1 << 5);	
	TCNT1 = 49911;   // for 1 sec at 16 MHz
}
