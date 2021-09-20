#include "GPIO_drive.h"

//delay declaration
void delay(int rep);

int main(void){

GPIO_init(port_A,0,Input_mode,Input_PP);

GPIO_init(port_C,13,Output_50Mhz,Output_GP_PP);

 while(1){
	 if(GPIO_read(port_A,0)==1){
		 delay(10);

		 GPIO_toggle(port_C,13);

	 delay(1);

	 }
	 else{
		GPIO_write(port_C,13,0);
	 }
 }


}

void delay(int rep){
	for(;rep>0;rep--){
		for(int i=0;i<100000;i++)
		{

		}
	}
}
