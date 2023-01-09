#include <avr/io.h>
#include <avr/interrupt.h>


int main(){
	DDRD &= ~(1<<2);  //PD2 (INT0) is input
  //PB0,PB1,PB2,PB3,PB4,PB5 set to output
  	DDRB = DDRB |(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
  
  //the falling edge of INT0 generate interrupt signal
  	EICRA |= (1<<ISC01); //set for rising edge detection
  	EICRA |= (0<<ISC00); //set for falling edge detection
  
  	sei(); //enable global interrupt
  
  	EIMSK |= (1<<INT0); //enable external interrupt for INT0
  
  	while(1){ //continue code to get interrupts
    
  	}
 	return 0;
}
unsigned char count=0;
ISR(INT0_vect){
 	count+=1;
	PORTB = count; //display count
  
}