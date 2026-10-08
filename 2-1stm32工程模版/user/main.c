#include "stm32f10x.h"
#include "Delay.h"
int main(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*GPIO_Write //同时对十六个端口进行写入操作
	GPIO_WriteBit//根据第三个参数的值来设置指定的端口
	GPIO_ResetBits//把指定端口设置为低电平
	GPIO_SetBits//把指定端口设置为高电平
*/
	
	
while(1){
    GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0040);//0000 0000 0100 0000
	Delay_ms(100);
	 GPIO_Write(GPIOA,~0x0080);//0000 0000 1000 0000
	Delay_ms(100);
	
	
	
} 
	
	
return 0;	
}
