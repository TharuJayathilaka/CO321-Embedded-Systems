#include <avr/io.h>

int main (void){
 
	DDRD = DDRD | (1<<6); //configure pin 5 of portB for output
	
	//PORTD = PORTD &~(1<<6);
	//DDRB=DDRB | (1<<1); //configure pin 5 of portB for output
    //PORTB = PORTB | (1<<1);
	TCNT0 = 0; //load timer counter register 
	OCR0A = 127;
	  
	TCCR0B |= (1<<CS01)|(1<<CS02);  
	
	// set the timer mode as fast pwm mode
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	TCCR0B |= (1<<WGM02); 
	TCCR0A |= (1<<COM0A1)|(1<<COM0A0); 
	
	while(1){
		
	}
	return 0;
}