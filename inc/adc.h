#ifndef ADC_H
#define ADC_H
#define ADC_WR P3_6
#define ADC_RD P3_7
#define ADC_DATA P2
extern volatile unsigned char f_adc;
extern volatile unsigned char adc_raw;
void initAdc(void);
void readAdc(void);
void ext0_isr(void) __interrupt(0);
#endif