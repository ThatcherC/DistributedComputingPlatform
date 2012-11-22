//Will come in two parts: the launcher/patcher, and the actual parallel program
//May have to be distributed with Terminal

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <mpi.h>
#include <math.h>

using namespace std;

int main(int argc, char **argv) {
	int numprocs, myid;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	std::cout << "Process " << getpid() << " is " << myid
			<< " of " << numprocs << " processes" << std::endl;
	
	//non-silent may be useful for debugging, change code download URL
	system("curl --silent http://107.21.212.198/u/25633961/version.txt> /Users/student/DCP/dversion.txt");
	fstream dv;
	fstream vers;
	string newV, oldV;
	dv.open("/Users/student/DCP/dversion.txt",ios::in|ios::binary);
	if(dv.is_open()){
		getline(dv, newV);
		dv.close();
		cout << "Got nv: " << newV << " " << getpid() << "\n";
	}
	vers.open("/Users/student/DCP/version.txt",ios::in|ios::binary);
	if(vers.is_open()){
		getline(vers, oldV);
		vers.close();
		cout << "Got ov:" << oldV << " " << getpid() << "\n";
	}
	
	if(oldV.compare(newV)!=0){
		cout << "Update time! ";
		//system("rm /Users/student/Desktop/C/DCP/version.txt");
		dv.open("/Users/student/DCP/version.txt");
		if(dv.is_open()){
			dv << newV;
			cout << "Changed version! " << getpid() <<"\n";
		}
		dv.close();
		system("curl --silent http://dl.dropbox.com/u/25633961/DCPMain> /Users/student/DCP/DCPMain;chmod +x /Users/student/DCP/DCPMain");
		//system("");
	}
	MPI_Finalize();
}