/**
 * CPU: 89C52
 * Freq: 12MHz
 */

#include "adc.h"
#include "seg.h"
#include "timer.h"
#include "uart.h"
#include <8051.h>
#include <stdio.h>

void main(void) {
  SP = 0x60; // 给出更多堆空间
  unsigned char adc;
  initTimer();
  initUart();
  initAdc();
  setSeg(1234);
  while (1) {
    if (f_2ms == 1) {
      f_2ms = 0;
      refreshSeg();
    }
    if (f_100ms == 1) {
      f_100ms = 0;
      readAdc();
    }
    if (f_1s) {
      f_1s = 0;
      printf_tiny("Time is %ums\n", tick_count);
    }
    if (f_adc == 1) {
      adc = adc_raw;
      f_adc = 0;
      setSeg(adc);
    }
  }
}
