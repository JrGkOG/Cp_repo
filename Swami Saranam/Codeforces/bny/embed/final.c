#include "stm32f4xx.h"
int adcValue;

void SysTick_delay_ms(int ms) {
    SysTick->LOAD = (16000 * ms) - 1; // 16 MHz system clock
    SysTick->VAL = 0;                 // Clear current value
    SysTick->CTRL = 5;                // Enable, use processor clock
    while ((SysTick->CTRL & (1 << 16)) == 0); // Wait COUNTFLAG
    SysTick->CTRL = 0;                // Stop timer
}

int main(void) {
    // Enable GPIO clocks
    RCC->AHB1ENR |= (1 << 2) | (1 << 1); // Enable GPIOC + GPIOB

    // Configure PC13, PC14, PB9 as outputs
    GPIOC->MODER &= ~((3 << 26) | (3 << 28)); 
    GPIOC->MODER |= (1 << 26) | (1 << 28);    
    GPIOB->MODER &= ~(3 << 18);  
    GPIOB->MODER |= (1 << 18);

    RCC->APB2ENR |= (1 << 8);     // Enable ADC1 clock

    GPIOA->MODER |= (3U << 0);    // PA0 as analog mode

    ADC1->SMPR2 &= ~(0x7 << 0);   // Sampling time for channel 0
    ADC->CCR &= ~(0x3 << 16);     // ADC prescaler PCLK2/2
    ADC1->CR1 = 0;                // Reset CR1
    ADC1->CR2 = 0;                // Reset CR2
    ADC1->CR2 |= (1U << 1);       // Continuous conversion mode
    ADC1->SQR3 &= ~(0x1F);        // Channel 0 selected
    ADC1->SQR1 &= ~(0xF << 20);   // Conversion sequence length = 1
    ADC1->CR2 |= 1;               // Enable ADC

    while ((ADC1->CR2 & 1) == 0); // Wait until ADC ready

    ADC1->CR2 |= (1 << 30);       // Start first conversion

    while (1) {
        while (!(ADC1->SR & (1 << 1)));      // Wait for conversion
        adcValue = ADC1->DR;                 // Store ADC value
        float percent = (adcValue / 4095.0f) * 100.0f;

        // Turn OFF all LEDs first
        GPIOC->ODR &= ~((1 << 13) | (1 << 14));
        GPIOB->ODR &= ~(1 << 9);

        if (percent < 30.0f) {
            GPIOC->ODR |= (1 << 13);      // Low speed
            SysTick_delay_ms(2000);       // Refresh every 2s
        }
        else if (percent < 70.0f) {
            GPIOC->ODR |= (1 << 14);      // Medium speed
            SysTick_delay_ms(1000);       // Refresh every 1s
        }
        else {
            GPIOB->ODR |= (1 << 9);       // High speed
            SysTick_delay_ms(500);        // Refresh every 0.5s
        }
    }
}
