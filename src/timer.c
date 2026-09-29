#include <8052.h>
#include <stdio.h>
#include "timer.h"
volatile unsigned char f_5ms, f_10ms, f_20ms, f_100ms, f_1s;
volatile unsigned int tick_count = 0;
void initTimer(void)
{
    tick_count = 0;
    TMOD = 0x21;
    TH0 = 0xFC;
    TL0 = 0x18; // 64536 = 65536-1000 = 0xFC18(计时1000us=1ms)
    ET0 = 1;
    TR0 = 1;
    EA = 1;
}

void timer0Interrupt(void) __interrupt(1)
{
    static unsigned char c5 = 0, c10 = 0, c20 = 0, c100 = 0;
    static unsigned int c1000 = 0;
    TH0 = 0xFC;
    TL0 ^= 0x18;
    tick_count += 1;
    if (++c5 >= 5)
    {
        c5 = 0;
        f_5ms = 1;
    }
    if (++c10 >= 10)
    {
        c10 = 0;
        f_10ms = 1;
    }
    if (++c20 >= 20)
    {
        c20 = 0;
        f_20ms = 1;
    }
    if (++c100 >= 100)
    {
        c100 = 0;
        f_100ms = 1;
    }
    if (++c1000 >= 1000)
    {
        c1000 = 0;
        f_1s = 1;
    }
}