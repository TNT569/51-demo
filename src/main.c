/**
 * CPU: 89C52
 * Freq: 12MHz
 */

#include <8052.h>
#include <stdio.h>
#include "uart.h"
#include "timer.h"

void main(void)
{
  initTimer();
  initUart();
  while (1)
  {
    if (f_1s == 1)
    {
      f_1s = 0;
      printf_tiny("time is %d ms\n", tick_count);
    }
  }
}
