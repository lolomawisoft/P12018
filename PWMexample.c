// source https://www.avrfreaks.net/forum/atmega8-16mhz-fast-pwm-50hz
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{

  DDRB  |= (1 << DDB1); // set output to PB1

  TCCR1A = ((1 << COM1A1) | (1 << WGM11)); // clear OC1A on match + WGM mode 14 
  TCCR1B = ((1 << WGM12) | (1 << WGM13) | (1 << CS11)); // WGM mode 14 (Fast PWM)
							// and 8x prescaler
  ICR1  = 40000;  //set ICR1 to produce 50Hz frequency
		  //(8000000 / 8 / 20000 = 50hz) <-- if you have divide on sure
		// ill use my 16000000MHz so (16000000 / 8 / 40000 = 50 hz)
  OCR1A = 2000;   // 40000 * 0.05 most left

  while (1)
    {
      while (OCR1A++ < 4000) // cca 2 sec loop
      	{
      	  _delay_ms(1);
      	}
      while (OCR1A-- > 1000) // cca 2 sec loop
      	{
      	  _delay_ms(1);
      	}
    }
  return 0;
}
