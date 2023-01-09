#include <avr/io.h>

int main(){
  // in ex2 we have to design a bulb that automatically lights when it is dark=
  
	DDRD |=(1<<7); /* first we configure PORTD pin7 for output*/
  
    // then we have congigured ADC1 pin of the microcontroller for the input
    DDRC = DDRC &~(1<<1) ; 
	
    //Configuration of adcsra register has done after that
	// In that register we have turned on adc module of avr and set the speed prescalar to 128
	
                     //Turn on the ADC module of the AVR
    ADCSRA = ADCSRA |(1<<ADEN); 
  
             
    ADCSRA |=(1 << ADPS0);
    ADCSRA |=(1 << ADPS1);
    ADCSRA |=(1 << ADPS2);

                             
    // then we have Selected ADC1 as input channel
    ADMUX |= (1<< MUX0) ;
  
    // Select voltage reference as AREF
    ADMUX |= (0<<REFS0);
    ADMUX |= (0<<REFS1);
  
    //then we have configured the result will be left-justified
    ADMUX |= (1<<ADLAR);
  
    unsigned char low, high =0;
    while(1){
        // in a while loop we have 
		// Activate the start conversion bit by giving adsc bit to 1
		ADCSRA |=(1<<ADSC);
   
		/* and then Wait for the conversion to be completed */
		                       
		while(!(ADCSRA&(1<<ADIF)));
      
		//after that clear the ADIF by writing 1 to it.
		ADCSRA |=(1<<ADIF);
      
		//get the output the reading in ADCH to the high variable and shift 7 bits to right
		// most signnificat 8 bits of the result at ADCH
		high = ADCH;
		high = high>>7;
      
	   // if the high variable is grater than or equal to one led should be on, otherwise off
		if(high>=1){
			PORTD |=(1<<7)
		}else{
			PORTD = PORTD &~(1<<7);
		}
    } 
} // now chanika will show thw the simulation

//stepsize = 5v/(2^10) =0.0048828125
//Vin=3.3v -> Vout = 3.3/0.0048828125 = 675.84 ->675
//Vin=5v   -> Vout = 5/0.0048828125   = 1024
//Vin=GND  -> Vout = 0