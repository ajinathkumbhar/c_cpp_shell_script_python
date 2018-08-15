#include <iostream>

using namespace std;

class Thermal {
private:
	float cureentTemp;
	float threshHold;
	Thermal() {
		cureentTemp = 0;
		threshHold = 15.5;
	}

};

class gpuThermal : public Thermal {
private:
	int gpuThreshold;

public:
	gpuThermal() {
		gpuThreshold = this->threshHold - 1;
	}

	void dump(){
		cout << cureentTemp << " " << threshHold << " " << gpuThreshold << '\n';
	}
};

int main(int argc, char const *argv[])
{
	gpuThermal C1;
	C1.dump();
	return 0;
}