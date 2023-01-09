#include <avr/io.h>
#include <util/delay.h>

//initializing function
void  usart_init (void){
  
  /*Enabling receiver and transmitter */
  UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
 
  
  //8-bit data path
  UCSR0C |= (3<<UCSZ00);
  
  //x = 103 = 0x67
  
  UBRR0 = 0x67;
 
}

//for sending data
void usart_send (unsigned char data){
  
 
  /*if the buffer is empty*/
  while ( !( UCSR0A & (1<<UDRE0)) ) ;
  
   /* Putting data into buffer */
  UDR0 = data; 
  
}

void EEPROMread(unsigned int address){
	//wait for completion of previous write
	while(EECR & (1<<EEPE));
	
	//set up address
	EEAR = address;
	
	//start eeprom read
	EECR |= (1<<EERE);
	
	//return data
	return EEDR;
}

int main(){
  
	usart_init();
	//int i=0;
  
  //applying cipher
	for(int i=1;i<1025;i++){
      
        //recieve a character
        unsigned char c = EEPROMread(i);
      
        usart_send(c); 
      
	}

	return 0;
}
