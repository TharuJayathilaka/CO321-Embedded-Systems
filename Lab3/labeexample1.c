#include <avr/io.h>

void delay_timer0(){
	TCNT0 = 131; //load timer counter register 
                 //initial counter value should be 131
  
	TCCR0A= 0x00;  //set the timer under normal mode
	TCCR0B= 0x04;  // with 1:256 prescalar
	
	while((TIFR0&0x01)==0); //wait till the timer overflow bit is set
	
	TCCR0A= 0x00; //clear the timer settings (this stops the timer)
	TCCR0B= 0x00; 
	
	TIFR0=0x01;  //clear the timer overflow bit for the next round
	
}

int main (void){
 
	DDRB=DDRB | (1<<5); //configure pin 5 of portB for output
	
	while(1){
 		
		PORTB = PORTB | (1<<5); // toggle pin 5
      	delay_timer0();
        PORTB = PORTB &~(1<<5);
        delay_timer0();
		
	}
}
