#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


int main(){
  
	DDRD = 0xFF; /* configure PORTD for output*/
    DDRB |=(1<<0)|(1<<1);
  
    // then we have congigured ADC1 pin of the microcontroller for the input
    DDRC = DDRC &~(1<<1) ; 
    //Configuration of adcsrra register has done after that
	
    //Turn on the ADC module of the AVR
    ADCSRA = ADCSRA |(1<<ADEN); 
  
    // Select the conversion speed.prescalar is 128.
    //As  f(osc) is 16MHz and 
    //ADC requires an input clock frequency less than 200 kHz
    ADCSRA |=(1 << ADPS0);
    ADCSRA |=(1 << ADPS1);
    ADCSRA |=(1 << ADPS2);

    //ADCSRA = 0x87;	
    //Select input channel ADC1 
    ADMUX |= (1<< MUX0) ;
  
    // Select voltage reference as AVCC
    ADMUX |= (1<<REFS0);
    ADMUX |= (0<<REFS1);
  
    //the result will be left-justified
    ADMUX |= (1<<ADLAR);
  
    unsigned char low, high =0;
    while(1){
      
		// Activate the start conversion bit
		ADCSRA |=(1<<ADSC);
   
		/* Wait for the conversion to be completed 
		by polling the ADIF bit in the ADCSRA register*/
		while(!(ADCSRA&(1<<ADIF)));
      
		//clear the ADIF bit
		ADCSRA |=(1<<ADIF);
      
		//get the output to the variable reading in ADCL
		low = ADCL; //least signnificat 2 bits at ADCL
		//as this is left justified in the block, 
		//to read the value right shift must be done 
		low = low>>6; 
      
		//get the output to the variable reading in ADCL
		// most signnificat 8 bits of the result at ADCH
		high = ADCH;
      
		//turn on the LEDS
		PORTD = high; 
		PORTB = low;
  
     
    } 
     
    return 0;

}

//stepsize = 5v/(2^10) =0.0048828125
//Vin=3.3v -> Vout = 3.3/0.0048828125 = 675.84 ->675
//Vin=5v   -> Vout = 5/0.0048828125   = 1024
//Vin=GND  -> Vout = 0