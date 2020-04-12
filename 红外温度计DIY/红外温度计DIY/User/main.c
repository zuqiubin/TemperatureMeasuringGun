/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
// ADC1转换的电压值通过MDA方式传到SRAM
uint16_t ADC_ConvertedValue=0;
// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal; 
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	//串口初始化
	USART_Config();
	
	/* LED 端口初始化 */
	LED_GPIO_Config();
	/* 通用定时器初始化 */
	GENERAL_TIM_Init();
	
	ADCx_Init();
	
	
	
//	Beep_VoiceRegulation(50);

	Beep_VoiceRegulation(5);
	
	
	while (1)
	{
	 ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; // 读取转换的AD值
		
	 ADC_ConvertedValueLocal=(ADC_ConvertedValueLocal*(10+10))/10 ;
	 printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 
		
	
	 printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		
		LED1_ON;			  // 亮
		SOFT_DELAY;
		LED1_OFF;		   // 灭

		LED2_ON;			 // 亮
		SOFT_DELAY;
		LED2_OFF;		   // 灭

		LED3_ON;			 // 亮
		SOFT_DELAY;
		LED3_OFF;		   // 灭	 

		/*轮流显示 红绿蓝黄紫青白 颜色*/
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

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
