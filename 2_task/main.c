#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>


int main(void) {
    // B ports
    // port B -> pins: 8,9,10,11,12,13
    // DDRx -> Data Direction, inputs and outputs    
    // Using pins 8,9 as inputs and 10,11 as outputs
    DDRB &= ~( 1 << PB0) & ~(1 << PB1); // Input
    DDRB |= 0b00001100;                 // Output
    // Read pins
    while(true) {
        int baseBtn = (PINB & (1 << PB0));
        int collectorBtn = (PINB & (1 << PB1));
        
        // PORTx write to port (B) Pxn defines the port and pin
        if (baseBtn) {
            PORTB |= (1 << PB2);
        } else {
            PORTB &= ~(1 << PB2);
        }

        if (collectorBtn) {
            PORTB |= (1 << PB3);
        } else {
            PORTB &= ~(1 << PB3);
        }
    }

    return 0;
}

