#include "GPIO_drive.h"

//GPIO initialization

void GPIO_init(unsigned short port,unsigned short pin,unsigned short direction,unsigned short option){
	//control register declaration
	volatile unsigned long * CR ;

	//offset setting

      unsigned short  offset =0x00;

	// Pin
      unsigned short tpin=pin;

   if(pin>7){ // High
	   tpin-=8;
	   offset=0x01; //data reference GPIO register map and reset values

   }

   if(port==1){
	   RCC_APB2ENR |=4;// Port A IOPA
	   CR=(volatile unsigned long *)(&GPIO_A+offset);

   }

   else if(port==2){
   	   RCC_APB2ENR |=8;// Port B IOPB
   	   CR=(volatile unsigned long *)(&GPIO_B+offset);

      }

   else if(port==3){
   	   RCC_APB2ENR |=0x10;// Port C IOPC
   	   CR=(volatile unsigned long *)(&GPIO_C+offset);

      }
   (*CR) &=~(0xF << (tpin)*4);//Reset Target pin

   (*CR) |=((direction<<(tpin)*4)) | (option<<(tpin*4+2)); //set target

}

// GPIO read
int GPIO_read(unsigned short port,unsigned short pin){
	//input data register Declaration
	volatile unsigned long * IDR ;

	//offset setting
	unsigned offset =0x2 ;

	//state declaration

	int state ;

	if(port==1){
		IDR=(volatile unsigned long *)(&GPIO_A+offset);

	}

	else if(port==2){

	   	   IDR=(volatile unsigned long *)(&GPIO_B+offset);

	      }

	else if(port==3){

		   	   IDR=(volatile unsigned long *)(&GPIO_C+offset);

		      }

state =((*IDR & (1<<pin))>>pin);
return state ;


}

// GPIO write
void GPIO_write(unsigned short port ,unsigned short pin , unsigned short state ){
	//Output data register Declaration
		volatile unsigned long * ODR ;

		//offset setting
		unsigned offset =0x3 ;


		if(port==1){
			ODR=(volatile unsigned long *)(&GPIO_A+offset);

		}

		else if(port==2){

		   	   ODR=(volatile unsigned long *)(&GPIO_B+offset);

		      }

		else if(port==3){

			   	   ODR=(volatile unsigned long *)(&GPIO_C+offset);

			      }


		state ?( *ODR|=(state<<pin)) : (*ODR &=~(1<<pin));


}

void GPIO_toggle(unsigned short port,unsigned short pin){
	if(GPIO_read(port,pin)){
		GPIO_write(port,pin,0);
	}
	else{
		GPIO_write(port,pin,1);
	}
}















































