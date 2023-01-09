#include <avr/io.h>
#include <util/delay.h>

void usart_init(){
	UCSR0C &= ~(1<<UMSEL01 | 1<<UMSEL00);//asunchronous
	UCSR0C &= ~(1<<UPM01 | 1<<UPM00);//No parity
	UCSR0C &= ~(1<<USBS0);//1 stop bit

	UCSR0C |= (1<<UCSZ01);//8 bit
	UCSR0C |= (1<<UCSZ00);
	UCSR0B &= ~(1<<UCSZ02);

	UBRR0L = 9600%256;//Baud rate
	UBRR0H = 9600/256;
	
}


void usart_send(char c){
	UCSR0B |= (1<<TXEN0);//Transmitter enable
	UDR0=c;
	while(!(UCSR0A & (1<<UDRE0))){//wait
		//wait
	}
	
}


char usart_receive(){
	char c;
	UCSR0B |= (1<<RXEN0);//Reciever enable
	while(!(UCSR0A& (1<<RXC0))){//wait
		//wait
	}
	c=UDR0;
	return c;
}

int main(){
	


	return 0;
}