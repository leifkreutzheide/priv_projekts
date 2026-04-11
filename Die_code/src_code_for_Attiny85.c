
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

int TIME = 1000;
void outputLights(int roll);    // function for outputting the light pattern for each roll

// ------configs ---------------------------------------------------------------------------

DDRB = 0b000111;            // PB0, PB1, PB2 as output (all other dont care or floating input)
PORTB = 0b00001000;         // activate pull-up resistor for button on PB3
sei();                      // set enable interrupts (globaly)
GIMSK |= (1 << PCIE);       // set pin change interrupt enable
PCMSK |= (1 << PCINT3);       // set pin change interrupt for PB3 (button)
MCUCR |= (1 << SE);         // set sleep enable bit
PRR |= (1 << 0b001111);     // power saving
ADCSRA |= (1 << ADEN);      // disable ADC


 ISR(PCINT3_vect)   // vector name depends on interrupt type
{
    // debounce the button press
    // read pin number 3/PB4
    // map readings to 0-5
    / call outputLights with the mapped value

}

void flashingLights();

 //-----main -----------------------------------------------------------------------------

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

void outputLights(int roll) {
  switch (roll) {
      case 0:
        flashingLights()
          PORTB = one;
          _delay_ms(TIME);
          break;
      case 1:
        flashingLights()
          PORTB = two;
          _delay_ms(TIME);
          break;
      case 2:
        flashingLights()
          PORTB = three;
          _delay_ms(TIME);
          break;
      case 3:
        flashingLights()
          PORTB = four;
          _delay_ms(TIME);
          break;
      case 4:
            flashingLights()
          PORTB = five;
          _delay_ms(TIME);
          break;
      case 5:
            flashingLights()

          PORTB = six;
          _delay_ms(TIME);
          break;
    }
}
