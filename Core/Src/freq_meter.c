#include "freq_meter.h"

uint32_t Capture_Raise[IC_BufSize] = {0x00000000};  //CH1��DMA�����������ڴ�������ز�������
uint32_t Capture_Fall[IC_BufSize] = {0x00000000};   //CH2��DMA�����������ڴ���½��ز�������
uint32_t   duty[IC_BufSize];  

uint32_t Avg_Raise = 0x00000000;
uint32_t Avg_Fall = 0x00000000;

float Freq_Capture_Freq = 0.0;  //�����ź�Ƶ��
float Freq_Capture_Duty = 0.0;  //�����ź�ռ�ձ�

void Freq_Meter_Init(void)
{
    //��ʼTIM2CH1��DMA����
    HAL_TIM_IC_Start_DMA(&htim2, TIM_CHANNEL_1, Capture_Raise, IC_BufSize);  //ֻ�������ò���
    //��ԭTIM2״̬��Ȼ��ʼTIM2CH2��DMA����
    htim2.State = HAL_TIM_STATE_READY;
    HAL_TIM_IC_Start_DMA(&htim2, TIM_CHANNEL_2, Capture_Fall, IC_BufSize);  //��������fall��ʵ����������������֮��ļ���ʱ�䡣 
                                                                                                                    //��cubemx ���� TIM2_CH2�ĳɲ����½��أ����������ں�ռ�ձ�
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
        duty[i] =  Capture_Fall[i] *5;  //200Mhz����Ƶ�� ������+1 ��5ns
        
    }




}