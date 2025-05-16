#include "freq_meter.h"

uint32_t Capture_Raise[IC_BufSize] = {0x00000000};  //CH1的DMA缓冲区，用于存放上升沿捕获数据
uint32_t Capture_Fall[IC_BufSize] = {0x00000000};   //CH2的DMA缓冲区，用于存放下降沿捕获数据
uint32_t   duty[IC_BufSize];  

uint32_t Avg_Raise = 0x00000000;
uint32_t Avg_Fall = 0x00000000;

float Freq_Capture_Freq = 0.0;  //所测信号频率
float Freq_Capture_Duty = 0.0;  //所测信号占空比

void Freq_Meter_Init(void)
{
    //开始TIM2CH1的DMA传输
    HAL_TIM_IC_Start_DMA(&htim2, TIM_CHANNEL_1, Capture_Raise, IC_BufSize);  //只算周期用不到
    //还原TIM2状态，然后开始TIM2CH2的DMA传输
    htim2.State = HAL_TIM_STATE_READY;
    HAL_TIM_IC_Start_DMA(&htim2, TIM_CHANNEL_2, Capture_Fall, IC_BufSize);  //变量名是fall，实际上是两个上升沿之间的计数时间。 
                                                                                                                    //将cubemx 工程 TIM2_CH2改成捕获下降沿，可以算周期和占空比
}

void Freq_Meter_DeInit(void)
{
    HAL_TIM_IC_Stop_DMA(&htim2, TIM_CHANNEL_1);
    HAL_TIM_IC_Stop_DMA(&htim2, TIM_CHANNEL_2);
}

void Freq_Calc(void)
{

    
    for(uint16_t i = 0; i < IC_BufSize; i++)
    {
        duty[i] =  Capture_Fall[i] *5;  //200Mhz外设频率 计数器+1 过5ns
        
    }




}