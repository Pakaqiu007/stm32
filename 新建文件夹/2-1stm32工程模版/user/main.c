#include "stm32f10x.h"                  // Device header

int main(void){
	RCC->APB2ENR=0X00000010;
	GPIOC->CRH=0x00300000;
	GPIOC->ODR=0x00002000;//
	
	while(1){
	
	}
	
	
	
	
	
	
	return 0;
}
