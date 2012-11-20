//Will come in two parts: the launcher/patcher, and the actual parallel program
//May have to be distributed with Terminal

#include <stdlib.h>

int main(void){
	//non-silent may be useful for debugging, change code download URL
	system("curl --silent https://raw.github.com/ThatcherC/CarsonC/master/Carson.cpp> DCPMain.cpp");
}