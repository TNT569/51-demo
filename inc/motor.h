#ifndef MOTOR_H
#define MOTOR_H
#define WARNING_LED P0_1
#define MOTOR_EN P3_0
#define MOTOR_DIRECTION P3_1
#define MOTOR_DIRECTION_FORWARD 1
#define MOTOR_DIRECTION_REVERSE 0
void initMotor(void);
void setMotorDirection(unsigned char direction);
void setMotorEnable(unsigned char status);
void refreshWarningLED(void);
void setWarningLED(unsigned char status);
#endif