#include <iostream>

using namespace std;

enum dType
{
	VIRTUVAL,
	REAL,
	CONSIDERED,
};

class device
{
private:
	char device_name[256];
	int device_number;
	dType device_type;
	float device_temp;
public:
	device();
	~device();
	void dump(void);
};

device::device() :
device_number(123),
device_type(REAL),
device_temp(1.2) {
	this->device_name[0] = 'a';
	cout << "default constuctor called \n" ;
}

device::~device() {
	cout << "de-constructor called\n" ;
}


void device::dump() {
	cout << "device_name : " << device_name << '\n';
	cout << "device_number : " << device_number << '\n';
	cout << "device_type : " << device_type << '\n';
	cout << "device_temp : " << device_temp << '\n';
}

int main(int argc, char const *argv[])
{
	device d;
	d.dump();
	return 0;
}
