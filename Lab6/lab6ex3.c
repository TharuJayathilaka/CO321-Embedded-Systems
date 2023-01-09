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


void sendLine(char ar[]){
	int i=0;
	while(ar[i]){
		usart_send(ar[i]);
		i++;
	}
	usart_send('\0');
}

void recieveLine(char* ar){
	int i=0;
	while(1){
		char c=usart_receive();
		if(c!='\r'){
			ar[i]=c;
		}
		else{
			ar[i]='\0';
			break;
		} 
	}
}

int main(){
	usart_init();
	char* recLine=(char*)malloc(1000);
	
	while(1){
		recieveLine(recLine);
		int len=1;
		while(recLine[len])len++;
		int i;
		for(i=0;i<len;i++){
			if(recLine[i]>='A' && recLine[i]<='Z'){
				recLine[i]=(char)((recLine[i]-'A'+3)%26+'A');
			}
			else if(recLine[i]>='a' && recLine[i]<='z'){
				recLine[i]=(char)((recLine[i]-'a'+3)%26+'a');
			}

		}
		sendLine(recLine);
	}


	return 0;
}