/**
 * CPU: 89C52
 * Freq: 12MHz
 */

#include "adc.h"
#include "motor.h"
#include "seg.h"
#include "timer.h"
#include "uart.h"
#include <8051.h>
#include <stdio.h>

volatile unsigned char f_motor = 0;
volatile unsigned char adc;

void init(void);
void loop(void);

void main(void) {
  init();
  while (1) {
    loop();
  }
}

void init(void) {
  initTimer();
  /*   initUart(); */
  initAdc();
  initMotor();
  setSeg(1234);
}

void loop(void) {
  if (f_2ms == 1) {
    f_2ms = 0;
    refreshSeg();
  }

  if (f_100ms == 1) {
    f_100ms = 0;
    readAdc();
    if (f_motor == 1) {
      refreshWarningLED();
    }
  }

  /*   if (f_1s) {
      f_1s = 0;
      printf_tiny("Time is %ums\n", tick_count);
    } */

  if (f_adc == 1) {
    adc = adc_raw;
    f_adc = 0;
    if (adc >= 95) {
      f_motor = 1;
    } else {
      f_motor = 0;
    }
    setMotorEnable(f_motor);
    setWarningLED(f_motor);
    setSeg(adc);
  }
}
