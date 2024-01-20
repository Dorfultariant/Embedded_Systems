#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>


int main(void) {
// https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf
    // A port is used for 24 and 26 pins and H port is used for 6 and 7.
    // DDRx -> Data Direction, inputs and outputs    
    // Using pins 24, 26 as inputs and 6,7 as outputs
    const int C_BTN_PIN = PA2;
    const int B_BTN_PIN = PA4;
    const int C = PH3;
    const int B = PH4;

    DDRA &= ~( 1 << C_BTN_PIN) & ~(1 << B_BTN_PIN); // Input
    DDRH |= (1 << C) | (1 << B);                 // Output

    // Read pins
    while(1) {
        int c_Btn_State = (PINA & (1 << C_BTN_PIN));
        int b_Btn_State = (PINA & (1 << B_BTN_PIN));
        
        // PORTx write to port (B) Pxn defines the port and pin
        if (b_Btn_State) {
            PORTH |= (1 << B);
        } else {
            PORTH &= ~(1 << B);
        }

        if (c_Btn_State) {
            PORTH |= (1 << C);
        } else {
            PORTH &= ~(1 << C);
        }
    }

    return 0;
}


