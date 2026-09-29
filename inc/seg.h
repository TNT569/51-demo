#ifndef SEG_H
#define SEG_H
#include <8051.h>
#define SEG_A0 P3_3
#define SEG_A1 P3_4
#define SEG_CS P0_7
#define SEG_NUM P1
void refreshSeg(void);
void setSeg(unsigned int new_seg_num);
#endif