#include <stm32f10x.h>
#include <Delay.h>
#include <PIO.h>

// Alternates blue and green LEDs quickly
int main(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = PAAll;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    // A0-A7引脚
    uint16_t pio_as[8] = {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7};
    while (1) {
        for (int i = 0; i < 8; i++) { /* code */
            GPIO_Write(GPIOA, ~pio_as[i]);
            Delay_ms(100);
        }
    }
    return 0;
}