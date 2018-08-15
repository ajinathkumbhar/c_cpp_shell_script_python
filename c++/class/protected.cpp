#include <stdio.h>
#include <iostream>

using namespace std;

class machine {
private:
	int type;
protected:
	int arch;
public:
 	int getType(void);
 	int getArch(void);
 	void setType(int);
 	void setArch(int);
 };


class EmbMachine : public machine {
public:
	EmbMachine() {
		//type = 10002;
		arch = 43;
	}
};

void machine::setType(int type){
	this->type = type;
}

void machine::setArch(int arch) {
	this->arch = arch;
}

int machine::getType(void) {
	return this->type;
}

int machine::getArch(void){
	return this->arch;
}

int main(int argc, char const *argv[])
{
	
	machine server;
	server.setType(1001);
	server.setTypArch(64);
	cout << server.getType() << '\n';
	cout << server.getArch() << '\n';

	EmbMachine embM;
	embM.type = 1001;
	embM.arch = 32;


	return 0;
}