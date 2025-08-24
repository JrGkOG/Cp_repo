#include "stm32f4xx.h"

int main(void){
	RCC->AHB1ENR |= (1<<2);
	
	GPIOC->MODER &= ~(3<<28);
	GPIOC->MODER |= (1<<28);

	SysTick->LOAD= 16000000-1;
	SysTick->VAL=0;
	SysTick->CTRl=5;
	while(1){
		if(SysTick->CTRL & (1<<16)){
			GPIOC->ODR ^= (1<<14);
		}
	}

}