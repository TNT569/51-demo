#include "timer.h"
#include <8051.h>
#include <stdio.h>
volatile unsigned char f_2ms = 0, f_5ms = 0, f_10ms = 0, f_20ms = 0,
                       f_100ms = 0, f_1s = 0;
volatile unsigned int tick_count = 0;
void initTimer(void) {
  tick_count = 0;
  TMOD = 0b00100010; // timer0模式2 timer1模式2
  TH0 = 0x06;
  TL0 = 0x06; // 256-6 = 250. 1/4ms
  ET0 = 1;
  TR0 = 1;
  EA = 1;
}

void timer0Interrupt(void) __interrupt(1) {
  static unsigned char c1 = 0, c2 = 0, c5 = 0, c10 = 0, c20 = 0, c100 = 0;
  static unsigned int c1000 = 0;
  c1++;
  if (c1 == 4) {
    c1 = 0;
    tick_count++;
    if (++c2 >= 2) {
      c2 = 0;
      f_2ms = 1;
    }
    if (++c5 >= 5) {
      c5 = 0;
      f_5ms = 1;
    }
    if (++c10 >= 10) {
      c10 = 0;
      f_10ms = 1;
    }
    if (++c20 >= 20) {
      c20 = 0;
      f_20ms = 1;
    }
    if (++c100 >= 100) {
      c100 = 0;
      f_100ms = 1;
    }
    if (++c1000 >= 1000) {
      c1000 = 0;
      f_1s = 1;
    }
  }
}