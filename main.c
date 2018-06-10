#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define LED 5
#define BV(x) (1<<x)
 
void sys_init(void);

int main()
{
    sys_init();
    
  for(;;)
    {
      PORTB |= 1 << 5;
      _delay_ms(100); 
      PORTB &= 0x00;
      _delay_ms(500);
    }
}

void sys_init(void)
{
  DDRB |= 0xFF;
  sei();
}
