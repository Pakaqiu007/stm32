#include "stm32f10x.h"
#include "Delay.h"
int main(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/*GPIO_Write //同时对十六个端口进行写入操作
	GPIO_WriteBit//根据第三个参数的值来设置指定的端口
	GPIO_ResetBits//把指定端口设置为低电平
	GPIO_SetBits//把指定端口设置为高电平
*/
	
	
while(1){
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);
    Delay_ms(100);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(100);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
    Delay_ms(500);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	Delay_ms(700);
	
	
} 
	
	
return 0;	
}
