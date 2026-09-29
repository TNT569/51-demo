#include <8052.h>
void initUart(void)
{
    SCON = 0x50;
    PCON |= 0x80;
    TH1 = 0xF3;
    TR1 = 1;
    ES = 1;
}

void uart_isr(void) __interrupt(4)
{
    if (RI)
    {
        RI = 0;
        // 处理接收到的数据
    }
    if (TI)
    {
        TI = 0;
        // 发送完成处理
    }
}

int putchar(int c)
{
    SBUF = c;
    while (!TI)
        ;
    TI = 0;
    return c;
}