#include "stdio.h"
int adcData;
const int threshold = 1024;
int main(void)
{
    // --- NON-ADC (Clock for GPIO) ---
    RCC->AHB1ENR |= (1U << 0);   // Enable GPIOA clock
    RCC->AHB1ENR |= (1U << 2);   // Enable GPIOC clock (for LED)

    // --- ADC Related (Clock for ADC1) ---
    RCC->APB2ENR |= (1 << 8);    // Enable ADC1 clock

    // --- ADC Related (Input pin setup) ---
    GPIOA->MODER |= (3U << 0);   // Set PA0 to analog mode

    // --- NON-ADC (LED pin setup) ---
    GPIOC->MODER &= ~(3 << 28);  
    GPIOC->MODER |= (1 << 28);   // Set PC14 as output for LED

    /* ---------- ADC1 Configurations ---------- */

    // --- ADC Related ---
    ADC1->SMPR2 &= ~(0x7 << 0);  // Sampling time for channel 0
    ADC->CCR &= ~(0x3 << 16);    // ADC prescaler
    ADC1->CR1 = 0;               // Reset CR1
    ADC1->CR2 = 0;               // Reset CR2
    ADC1->CR2 |= (1U << 1);      // Continuous conversion mode
    ADC1->SQR3 &= ~(0x1F);       // Channel 0 selected
    ADC1->SQR1 &= ~(0xF << 20);  // Sequence length = 1
    ADC1->CR2 |= 1;              // Enable ADC

    // --- ADC Related ---
    while ((ADC1->CR2 & 1) == 0) { }  // Wait until ADC ready

    // --- ADC Related ---
    ADC1->CR2 |= (1 << 30);      // Start conversion

    // --- MAIN LOOP ---
    while (1)
    {
        // --- ADC Related ---
        while (!(ADC1->SR & (1 << 1))) { } // Wait for conversion complete
        adcData = ADC1->DR;                // Read ADC data

        // --- NON-ADC (LED control based on ADC value) ---
        if (adcData > threshold)
            GPIOC->ODR |= (1 << 14);       // Turn ON LED
        else
            GPIOC->ODR &= ~(1 << 14);      // Turn OFF LED
    }
}
    