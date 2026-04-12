
#include <avr/io.h>         // standard AVR MC library
#include <util/delay.h>     // für delay function
#include <avr/sleep.h>      // für sleep mode
#include <avr/interrupt.h>  // für IRQs

#define F_CPU 1000000UL

#define TWOHUNDOMILLI 200
#define QUARTERSECOND 250
#define HALFSECOND 500
#define ONESECOND 1000
#define TWOSECONDS 2000
#define THREESECONDS 3000

#define one     0b001001
#define two     0b001010
#define three   0b001011
#define four    0b001100
#define five    0b001101
#define six     0b001110
#define button  0b001000

uint8_t TIME = 1000;
void outputRollNumber(int roll);    // function for outputting the light pattern for each roll
uint8_t seed;


// ------configs ---------------------------------------------------------------------------

DDRB = 0b000111;            // PB0, PB1, PB2 as output (all other dont care or floating input)
PORTB = 0b00001000;         // activate pull-up resistor for button on PB3
sei();                      // set enable interrupts (globaly)
GIMSK |= (1 << PCIE);       // set pin change interrupt enable
PCMSK |= (1 << PCINT3);      // set pin change interrupt for PB3 (button)
MCUCR |= (1 << SE);         // set sleep enable bit
PRR |= (1 << 0b0001111);     // power saving
ADCSRA |= (10000110);       // enable ADC, prescaler = 64 @ 1235kHz
ADMUX |= (1 << MUX1);       // set ADC input to pin 2/PB4

void flashingLights();


 ISR(PCINT3_vect)   // vector name depends on interrupt type
{
    delay_us(250);                                  // debounce delay
    for (uint8_t i = 0; i < 8; i++) {               // read LSB 8 times
        ADCSRA |= (1 << ADSC);                      // start conversion
        while (ADCSRA & (1 << ADSC));               // creating a mask over ADSC Bit to check if still converting
          seed = (seed << 1) | (ADC & 1);           // shift seed left, ADC marco that reads ADCL and ADCH correctly, uses (&1) mask to read just the LSB
    }

    ADCSRA &= ~(1 << ADEN);                       // disable ADC to save power
    flashingLights();
    outputRollNumber(seed);                       // output the result based on the seed
                      

}



int main(void) {


while (1)
{

sleep_mode();   // put the microcontroller to sleep until an interrupt occurs


}

}
// ---- end main ------------------------------


void flashingLights(){
    _delay_ms(TWOHUNDOMILLI);
    PORTB = four;
    _delay_ms(TWOHUNDOMILLI);
    PORTB = one;
    _delay_ms(TWOHUNDOMILLI);
    PORTB = four;
    _delay_ms(TWOHUNDOMILLI);
    PORTB = one;
    _delay_ms(TWOHUNDOMILLI);
    PORTB = two;
    _delay_ms(TWOHUNDOMILLI);
    PORTB = one;
    _delay_ms(QUARTERSECOND);
    PORTB = three;
    _delay_ms(QUARTERSECOND);
    PORTB = one;
    _delay_ms(QUARTERSECOND);
    PORTB = two;
    _delay_ms(HALFSECOND);
}

void outputRollNumber(uint8_t seed) {
    if      (seed < 43)  { flashingLights(); PORTB = one;   }
    else if (seed < 86)  { flashingLights(); PORTB = two;   }
    else if (seed < 128) { flashingLights(); PORTB = three; }
    else if (seed < 170) { flashingLights(); PORTB = four;  }
    else if (seed < 213) { flashingLights(); PORTB = five;  }
    else                 { flashingLights(); PORTB = six;   }
    _delay_ms(TIME);
}
