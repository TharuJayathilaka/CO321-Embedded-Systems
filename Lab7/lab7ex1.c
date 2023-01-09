#include <avr/io.h>
#include <util/delay.h>

void EEPROMwrite(unsigned int address,char data){
	//wait for completion of previous write
	while(EECR & (1<<EEPE));
	
	//set up address and data regs
	EEAR = address;
	EEDR = data;
	
	//write logical 1 to EEMPE
	EECR |= (1<<EEMPE);
	
	//start eeprom write
	EECR |= (1<<EEPE);
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