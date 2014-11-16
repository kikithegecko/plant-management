#define F_CPU 16000000L
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>

// let's make our lives easier :)
#define PORT_(port) PORT ## port
#define DDR_(port)  DDR  ## port
#define PIN_(port)  PIN  ## port
#define PORT(port) PORT_(port)
#define DDR(port)  DDR_(port)
#define PIN(port)  PIN_(port)


#define LED PB0

/* init output channels */
void init(void) {
        // enable output for led:
        DDR(B) |= (1<<LED);
}

int main(void){
        init();

        while(1){
                _delay_ms(1000);
                PORT(B) |= (1<<LED);
                _delay_ms(1000);
                PORT(B) &= ~(1<<LED);
        }
} 
