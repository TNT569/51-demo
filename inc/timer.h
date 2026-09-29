#ifndef TIMER_H
#define TIMER_H
extern volatile unsigned char f_2ms, f_5ms, f_10ms, f_20ms, f_100ms, f_1s;
extern volatile unsigned int tick_count;
void initTimer(void);
void timer0Interrupt(void) __interrupt(1);
#endif