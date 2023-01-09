#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 200

int main(){
	DDRD &= ~(1<<7);  //PD7 (INT0) is input
  	//PB0,PB1,PB2,PB3,PB4,PB5 is output
  	DDRB =DDRB |((1<<0) |(1<<1) |(1<<2) |(1<<3) |(1<<4) |(1<<5)); 

  	unsigned char count=0;
 	while(1){ //make the loop infinite
		if(PIND &(1<<7)){//check whether push button pressed
  	 		count +=1; //count increment
     		PORTB = count; //display count
  	 		_delay_ms(BLINK_DELAY_MS);
 		} 
    }
  
  	return 0;
}