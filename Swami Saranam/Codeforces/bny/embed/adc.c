#include "stm32f4xx.h"

int adcdata;

int main(void){
    RCC->AHB1ENR |= (1<<0);
    RCC->APB2ENR |= (1<<5);
}