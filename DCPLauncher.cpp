//Will come in two parts: the launcher/patcher, and the actual parallel program
//May have to be distributed with Terminal

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
	//non-silent may be useful for debugging, change code download URL
	system("curl --silent http://dl.dropbox.com/u/25633961/version.txt> /Users/student/Desktop/C/DCP/dversion.txt");
	fstream dv;
	fstream vers;
	string newV, oldV;
	dv.open("/Users/student/Desktop/C/DCP/dversion.txt",ios::in|ios::binary);
	if(dv.is_open()){
		getline(dv, newV);
		dv.close();
		cout << "Got nv: " << newV << "\n";
	}
	vers.open("/Users/student/Desktop/C/DCP/version.txt",ios::in|ios::binary);
	//if(vers.is_open()){
		getline(vers, oldV);
		vers.close();
		cout << "Got ov:" << oldV << "\n";
	//}
	
	if(oldV.compare(newV)!=0){
		cout << "Update time! ";
		//system("rm /Users/student/Desktop/C/DCP/version.txt");
		dv.open("/Users/student/Desktop/C/DCP/version.txt");
		if(dv.is_open()){
			dv << newV;
			cout << "Changed version!\n";
		}
		dv.close();
		system("curl --silent http://dl.dropbox.com/u/25633961/DCPMain> /Users/student/Desktop/C/DCP/DCPMain;chmod +x /Users/student/Desktop/C/DCP/DCPMain");
		//system("");
	}
}