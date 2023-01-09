#include <avr/io.h>
#include <avr/interrupt.h>
	
int main(){
  //PD2 (INT0) and PD3 (INT1) is input
	DDRD =DDRD & (~(1<<2)) & (~(1<<3));  
  //PB0,PB1,PB2,PB3,PB4,PB5 set to output
  	DDRB = DDRB |(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
  
  //the rising edge of INT0 generate interrupt signal
  	EICRA |= (1<<ISC01); //set for rising edge detection
  	EICRA |= (1<<ISC00); //set for rising edge detection
  
  //the rising edge of INT1 generate interrupt signal
    EICRA |= (1<<ISC10); //set for rising edge detection
  	EICRA |= (1<<ISC11); //set for rising edge detection
  
  	sei(); //enable global interrupt
  
  	EIMSK |= (1<<INT0); //enable external interrupt for INT0
  	EIMSK |= (1<<INT1); //enable external interrupt for INT1
  
  //get the code continuously
  	while(1){
    
  	}
 	return 0;
}

int sum=0; //get the  entered value

//push button A(0)
ISR(INT0_vect){
  	sum =sum<<1; //shift left by 1 but no value to add
	PORTB = sum; //display count	
}
//push button B(1)
ISR(INT1_vect){
  	sum =(sum<<1)+(1<<0); //shift left by 1 and add 1
	PORTB = sum; //display count 	
}