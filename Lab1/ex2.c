#include<util/delay.h>
#include <avr/io.h>

int main(void){
	DDRB=DDRB |( (1<<4)| (1<<1)| (1<<2)| (1<<3));  /* configure PORTB bit 4,1,2,3 for output*/
    while(1){
       	unsigned char i,j;
      //ABCD pattern
     	for(i=4;i>=1;i--){
         	PORTB = PORTB | (1<<i); //set high corresponding pin in portB
            _delay_ms(400);
       	    PORTB = PORTB &~ (1<<i);//set low corresponding pin in portB
            _delay_ms(400);
      	} 
      //CB pattern
      	for(j=2;j<4;j++){
          	PORTB = PORTB | (1<<j);//set high corresponding pin in portB
            _delay_ms(400);
        	PORTB = PORTB &~ (1<<j); //set low corresponding pin in portB
       	    _delay_ms(400);
      	}
  	}
  	return 0;
}