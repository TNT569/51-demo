#include "adc.h"
#include <8051.h>
volatile unsigned char adc_raw;
volatile unsigned char f_adc;
void initAdc(void) {
  IT0 = 1; // 设置外部中断为边沿触发
  EX0 = 1; // 使能外部中断
}
void readAdc(void) {
  ADC_WR = 0;
  ADC_WR = 1;
  // 产生上升沿启动ADC转换
}

void ext0_isr(void) __interrupt(0) {
  ADC_RD = 0;
  adc_raw = ADC_DATA;
  f_adc = 1;
  ADC_RD = 1; // 关闭ADC输出
}
