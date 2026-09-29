#include "seg.h"
#include <8051.h>
volatile unsigned int seg_number = 0;
volatile unsigned char seg_digit = 0;
const unsigned int dig_table[4] = {1, 10, 100, 1000};
const unsigned char number[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99,
                                0x92, 0x82, 0xF8, 0x80, 0x90};
const unsigned char pos_map[4] = {0, 1, 2, 3};
void delay(unsigned char t) {
  volatile unsigned int i = t;
  while (i--)
    ;
}

void refreshSeg(void) {
  SEG_CS = 1;
  unsigned char num = (seg_number / dig_table[seg_digit]) % 10;
  SEG_NUM = number[num];
  SEG_A1 = pos_map[seg_digit] >> 1; // 高位
  SEG_A0 = pos_map[seg_digit] & 1;  // 低位
  seg_digit++;
  if (seg_digit > 3)
    seg_digit = 0;
}

void setSeg(unsigned int new_seg_num) { seg_number = new_seg_num; }