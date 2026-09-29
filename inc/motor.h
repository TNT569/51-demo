#ifndef MOTOR_H
#define MOTOR_H
#define WARNING_LED P0_1
#define MOTOR_EN P0_3
#define MOTOR_DIRECTION P0_4
#define MOTOR_DIRECTION_FORWARD 1
#define MOTOR_DIRECTION_REVERSE 0
void initMotor(void);
void setMotorDirection(unsigned char direction);
void setMotorEnable(unsigned char status);
void refreshWarningLED(void);
void setWarningLED(unsigned char status);
#endif