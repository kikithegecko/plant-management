#define F_CPU 16000000L

#define LOW_BYTE(x)  (x & 0xff)
#define HIGH_BYTE(x) ((x >> 8) & 0xff)
#define REJOIN(LO, HI) ((HI << 8) | LO)

//#include<stdlib.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/pgmspace.h>
#include "twislave.h"

#define SLAVE_ADDR 0x50

uint16_t var1, var2;
uint16_t buffer;

/* This function sets the address */
void init(){

	cli(); // clear interrupts
	init_twi_slave(SLAVE_ADDR);
	sei(); // set enable interrupts

}

/* main is here! */
int main(){
	
	init();

	while(1){

		// receiving two bytes of data (supposed to be 42 and 23)
		var1 = rxbuffer[0];
		var2 = rxbuffer[1];

		//send Feedback
		if((var1 == 42) && (var2 == 23)){
			txbuffer[0] = 1;
		}
		else{
			txbuffer[0] = 0;
		}

	}

}
