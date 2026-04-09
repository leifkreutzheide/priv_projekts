
#include <avr/io.h>         // standard AVR MC library
#include <util/delay.h>     // für delay function
#include <avr/sleep.h>      // für sleep mode
#include <avr/interrupt.h>  // für IRQs
#define F_CPU 1000000UL
#define TIME 1000


#define one     0b010001
#define two     0b010010
#define three   0b010011
#define four    0b010100
#define five    0b010101
#define six     0b010110
#define button  0b010000

int TIME = 1000;

DDRB = 0b000111;              // 1 => output
PORTB = 0b00010000;           // alle low apart from the button pin


void outputLights(int roll);    // function for outputting the light pattern for each roll


int main(void) {


while (1)
{

  
    

}

}


void outputLights(int roll) {
  switch (roll) {
      case 0:
          PORTB = one;
          _delay_ms(TIME);
          break;
      case 1:
          PORTB = two;
          _delay_ms(TIME);
          break;
      case 2:
          PORTB = three;
          _delay_ms(TIME);
          break;
      case 3:
          PORTB = four;
          _delay_ms(TIME);
          break;
      case 4:
          PORTB = five;
          _delay_ms(TIME);
          break;
      case 5:
          PORTB = six;
          _delay_ms(TIME);
          break;
    }
}
