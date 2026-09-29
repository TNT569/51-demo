/**
 * CPU: 89C52
 * Freq: 12MHz
 */

#include "seg.h"
#include "timer.h"
#include "uart.h"
#include <8051.h>
#include <stdio.h>

void main(void) {
  SP = 0x60; // 给出更多堆空间
  initTimer();
  initUart();
  setSeg(1234);
  while (1) {
    if (f_2ms = 1) {
      f_2ms = 0;
      refreshSeg();
    }
    if (f_1s) {
      f_1s = 0;
      printf_tiny("Time is %ums\n", tick_count);
      setSeg(tick_count + 234);
    }
  }
}
