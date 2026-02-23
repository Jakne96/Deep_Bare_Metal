#define PERIPH_BASE (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x00020000UL)
#define	AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET (0x0000UL)
#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define RCC_OFFSET (0x3800UL)
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)
#define AHB1ENR_OFFSET (0x30UL)
#define RCC_AHB1ENR (*(volatile unsigned int *) (RCC_BASE + AHB1ENR_OFFSET))
#define MODER_OFFSET (0x00UL)
#define GPIOA_MODER (*(volatile unsigned int *) (GPIOA_BASE + MODER_OFFSET))
#define ODR_OFFSET (0x14UL)
#define GPIOA_ODR (*(volatile unsigned int *) (GPIOA_BASE + ODR_OFFSET))
#define GPIOAEN (1UL << 0)
#define PIN5 (1UL << 5)
#define LED_PIN PIN5

int main (void){
	RCC_AHB1ENR |= GPIOAEN;
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);

	while(1){
		GPIOA_ODR ^= LED_PIN;
		for (int i = 0; i < 100000; i++){} //Delay loop for visible blinking
		GPIOA_ODR &= ~LED_PIN;
		for (int i = 0; i < 100000; i++){}
	}
}
