#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void setup()

{
  srand(time(NULL));
  DDRD = 0b11100000;   // 1 = output
  PORTD = 0b00010000;    // high low ect
  int TIME = 1000;

}
void loop()
{
  int roll = rand() % 6;
  int num = -1;
  int TIME = 1000;

  if (PIND & (1 << PIND4)) { 
    PORTD = 0b00010000; } else {
      num = roll; 
    switch (num) {
      case 0:
          PORTD = 0b00101000;
          _delay_ms(TIME);
          break;
      case 1:
          PORTD = 0b01001000;
          _delay_ms(TIME);
          break;
      case 2:
          PORTD = 0b01101000;
          _delay_ms(TIME);
          break;
      case 3:
          PORTD = 0b10001000;
          _delay_ms(TIME);
          break;
      case 4:
          PORTD = 0b10101000;
          _delay_ms(TIME);
          break;
      case 5:
          PORTD = 0b11001000;
          _delay_ms(TIME);
          break;
          }

    PORTD = 0b00010000;

    }

}