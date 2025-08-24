#include "stm32f4xx.h"

int adcData;
void systic(int ms){
    SysTick->LOAD = (16000*ms )-1;
    SysTick->VAL=0;
    SysTick->CTRL=5;
    while((SysTick->CTRL & (1<<16))==0);
    SysTick->CTRL=0;
}
int main(void){
    RCC->AHB1ENR |= (1<<0)
    RCC->AHB1ENR |= (1<<2)

    GPIOC->MODER &= ~((3 << 26) | (3 << 28)); 
    GPIOC->MODER |= (1 << 26) | (1 << 28);    
    GPIOB->MODER &= ~(3 << 18);  
    GPIOB->MODER |= (1 << 18);

    RCC->APB2ENR |=(1<<8);
    GPIOA->MODER |=(3<<0);
    ADC1->SMPR &= ~(0x7 <<0);
    ADC1->CCR &= ~(0x3 << 16);
    ADC1->CR1 =0;
    ADC1->CR2 =0;
    ADC1->CR2 |= (1<<1);
    ADC1->SQR3 &= ~(0x1F);
    ADC1->SQR1 &= ~(0xF << 20);
    ADC1->CR2 |= 1;

    while((ADC1->CR2 & 1)==0);
    ADC1->CR2 |= (1<<30);   

    while(1){
        while(!(ADC1->SR & (1<<1)));
        adcData=ADC1->DR;
        if()
    }
}