#include "motor.h"
#include <8051.h>
volatile unsigned char led_en = 0;
void initMotor() {
  MOTOR_DIRECTION = 0;
  MOTOR_EN = 0;
  WARNING_LED = 1;
}
void setMotorDirection(unsigned char direction) { MOTOR_DIRECTION = direction; }
void setMotorEnable(unsigned char status) { MOTOR_EN = status; }
void refreshWarningLED(void) {
  if (led_en == 1)
    WARNING_LED = !WARNING_LED;
}
void setWarningLED(unsigned char status) {
  if (status) {
    led_en = 1;
  } else {
    led_en = 0;
    WARNING_LED = 1;
  }
}
