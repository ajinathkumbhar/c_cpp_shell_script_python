#include <stdio.h>
#include <iostream>

using namespace std;

class DeviceInfo
{
private:
	char model;
	int ones;
	int zeros;
public:
	DeviceInfo(char mdl) {
		ones = 0;
		zeros = 0;
		this->model = mdl;
		getOnesAndZeros();
	}
	
	void printModel() {
		cout << model << " - Ones : " << ones << " zeros : "<< zeros << '\n';
	}

	void getOnesAndZeros(void);
};

void DeviceInfo::getOnesAndZeros() {
	char localModel = this->model;
	for (int k = 0; k < 32 ; k++) {
		localModel & 1 ? ones++ : zeros++;
		localModel = localModel >> 1;
	}

}

int main(int argc, char const *argv[], char *env[])
{
	DeviceInfo deskInfo((char)12);
	deskInfo.printModel();
	return 0;
}