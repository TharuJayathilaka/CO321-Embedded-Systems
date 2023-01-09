#include <avr/io.h>

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

//recieving data
unsigned char usart_receive (void){ 
  
  /* Waiting for data */
  while ( !(UCSR0A & (1<<RXC0)) );
  
  /* returning received data*/
  return UDR0;
}


int main(){
  
	usart_init();
  
  //applying cipher
	while(1){
      
        //recieve a character
        unsigned char c = usart_receive();
      
      //checking alphabatical
        if(c>='A' && c<='Z'){
				c =(char)((c-'A'+3)%26+'A');
		}
		else if(c>='a' && c<='z'){
				c=(char)((c-'a'+3)%26+'a');
		}
        
        usart_send(c); 
        
	}

	return 0;
}



    //frequency of oscillator =16Mhz
  	//Desired baud Rate =9600
    //X = (16000000/9600)-1=103 