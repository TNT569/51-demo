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
    // 注意：这里不能清 TI！
    // putchar() 用轮询 TI 的方式判断“发送完成”，串口中断会和它争抢 TI：
    // TI 置位后 CPU 先响应中断，中断里把 TI 清零，putchar() 的 while(!TI)
    // 就永远等不到 TI 再次置位，程序卡死在第一个字符之后。
    // 本项目发送采用查询方式，TI 统一由 putchar() 清除。
}

int putchar(int c)
{
    TI = 0; // 清掉可能残留的发送完成标志，避免误判
    SBUF = c;
    while (!TI)
        ;
    TI = 0;
    return c;
}