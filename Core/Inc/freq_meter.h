#ifndef __FREQ_METER_H
#define __FREQ_METER_H

#include "main.h"
#include "tim.h"

#define TIM2_Clock  250000000  
#define TIM2_PSC    0
#define TIM2_ARR    0xFFFFFFFF

#define IC_BufSize  32          //DMA»º³åÇø´óÐ¡

extern float Freq_Capture_Freq;
extern float Freq_Capture_Duty;

void Freq_Meter_Init(void);
void Freq_Meter_DeInit(void);
void Freq_Calc(void);

#endif