#include <iostream>
#include <stdlib.h>

using namespace std;


class sound {
private:
	static float amplitude;
	int test ;
public:
	static float getAmplitude(void) {
		return amplitude;
	}
	void setAmplitude(float);
	void printfThis(){
		cout << "================ " <<  test  << ":" << this << '\n';
	}

};

float sound::amplitude = 0;

void sound::setAmplitude(float amp) {
	test = 11 + amp ;
	amplitude = amp;
}


//----------------------------
int main(int argc, char const *argv[])
{
	sound beep, ping;
	beep.setAmplitude(21.2);
	ping.setAmplitude(32.1);

	cout << sound::getAmplitude() << " " << sound::getAmplitude() << '\n';
	beep.printfThis();
	ping.printfThis();


}