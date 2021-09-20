
//RCC APB2ENR adress
#define RCC_APB2ENR (*(volatile unsigned long*) 0x40021018)
//GPIO adress
#define GPIO_A (*(volatile unsigned long*) 0x40010800)
#define GPIO_B (*(volatile unsigned long*) 0x40010C00)
#define GPIO_C (*(volatile unsigned long*) 0x40011000)

//Ports
#define port_A 1
#define port_B 2
#define port_C 3

//Input/Output config

#define Input_mode 0
#define Output_10Mhz 1
#define Output_2Mhz 2
#define Output_50Mhz 3

#define Input_Analog 0
#define Input_floating 1
#define Input_PP 2 //pull-up pull-down

#define Output_GP_PP 0 //General purpose output push-pull
#define Output_GP_OD 1 //General purpose output open-drain
#define Output_AF_PP 2 //Alternate function output Push-pull
#define Output_AF_OD 3 //Alternate function output Open-drain

// Low & high

#define Low 0
#define high 1

//GPIO intialization

void GPIO_init(unsigned short port,unsigned short pin,unsigned short direction,unsigned short option);

//GPIO Read

int GPIO_read(unsigned short port,unsigned short pin);

//GPIO write

void GPIO_write(unsigned short port ,unsigned short pin , unsigned short state );

//toggling pin

void GPIO_toggle(unsigned short port,unsigned short pin);
