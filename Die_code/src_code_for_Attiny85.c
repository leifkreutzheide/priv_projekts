
#include <avr/io.h>        // standard AVR MC library
#include <util/delay.h>    // für delay function
#include <avr/sleep.h>     // für sleep mode
#include <avr/interrupt.h> // für IRQs
#define F_CPU 1000000UL
#define TIME 1000

#define one     0b000001
#define two     0b000010
#define three   0b000011
#define four    0b000100
#define five    0b000101
#define six     0b000110

int TIME = 1000;

DDRB = 0b000111;              // 1 => output
PORTB = 0b000000;             // alle low 



void main() {


while (1)
{

  int roll = rand() % 6;
  int num = -1;
  

  if (PIND & (1 << PIND4)) { 
    PORTB = 0b00010000; } else {
      num = roll; 
    switch (num) {
      case 0:
          PORTB = 0b00101000;
          _delay_ms(TIME);
          break;
      case 1:
          PORTB = 0b01001000;
          _delay_ms(TIME);
          break;
      case 2:
          PORTB = 0b01101000;
          _delay_ms(TIME);
          break;
      case 3:
          PORTB = 0b10001000;
          _delay_ms(TIME);
          break;
      case 4:
          PORTB = 0b10101000;
          _delay_ms(TIME);
          break;
      case 5:
          PORTB = 0b11001000;
          _delay_ms(TIME);
          break;
          }

    PORTB = 0b00010000;

    }

}

}