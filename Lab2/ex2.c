#include <avr/io.h>
#include <avr/interrupt.h>


int main(){
	DDRD &= ~(1<<2);  //PD2 (INT0) is input
  	DDRB |= (1<<0); //PB0 is output
  
  //the falling edge of INT0 generate interrupt signal
  	EICRA |= (1<<ISC01); //set for rising edge detection
  	EICRA |= (0<<ISC00); //set for falling edge detection
  
  	sei(); //enable global interrupt
  
  	EIMSK |= (1<<INT0); //enable external interrupt for INT0
  
  	while(1){ //continue code to get interrupts
    
  	}
 	return 0;
}
ISR(INT0_vect){
	PORTB =PORTB^(1<<0); //Toggles PB0
}