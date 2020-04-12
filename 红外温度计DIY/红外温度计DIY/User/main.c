/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h" 
#include "bsp_adc.h"
#include "bsp_usart.h"



#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount); 
// ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����SRAM
uint16_t ADC_ConvertedValue=0;
// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal; 
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	//���ڳ�ʼ��
	USART_Config();
	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	/* ͨ�ö�ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	ADCx_Init();
	
	
	
//	Beep_VoiceRegulation(50);

	Beep_VoiceRegulation(5);
	
	
	while (1)
	{
	 ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; // ��ȡת����ADֵ
		
	 ADC_ConvertedValueLocal=(ADC_ConvertedValueLocal*(10+10))/10 ;
	 printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 
		
	
	 printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		
		LED1_ON;			  // ��
		SOFT_DELAY;
		LED1_OFF;		   // ��

		LED2_ON;			 // ��
		SOFT_DELAY;
		LED2_OFF;		   // ��

		LED3_ON;			 // ��
		SOFT_DELAY;
		LED3_OFF;		   // ��	 

		/*������ʾ ������������� ��ɫ*/
		LED_RED;
		SOFT_DELAY;
		
		LED_GREEN;
		SOFT_DELAY;
		
		LED_BLUE;
		SOFT_DELAY;
		
		LED_YELLOW;
		SOFT_DELAY;
		
		LED_PURPLE;
		SOFT_DELAY;
				
		LED_CYAN;
		SOFT_DELAY;
		
		LED_WHITE;
		SOFT_DELAY;
		
		LED_RGBOFF;
		SOFT_DELAY;		
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
