#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "key.h"

uint8_t KeyNum = 0;
uint8_t Sec = 60;
uint16_t Add = 0;			

int main(void)
{
3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
	OLED_Init();
	Key_Init();

	OLED_ShowString(1, 4, "HERO");
	OLED_ShowNum(3, 5, Sec, 2);

	while (1)
	{
		
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 && KeyNum == 0)
		{
			Delay_ms(20);
			KeyNum = 1;
			OLED_Clear();		
			while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
			Delay_ms(20);
		}
		else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 && KeyNum == 1)
		{
			Delay_ms(20);
			KeyNum = 0;
			Sec = 60;
			Add = 0;
			OLED_ShowString(1, 4, "HERO");		
			OLED_ShowNum(3, 5, Sec, 2);
			while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
			Delay_ms(20);
		}

	
		if (KeyNum == 0)
		{
			Delay_ms(1);				
			Add++;
			if (Add >= 1000)
			{
				Add = 0;
				if (Sec > 0)				
				{
					Sec--;
				}
				OLED_ShowNum(3, 5, Sec, 2);	
			}
		}
	}

	return 0;
}
