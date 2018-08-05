#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool DataAvailable = true;

void isr_interrupt(void) {
	DataAvailable = false;
}
int main(int argc, char const *argv[])
{
	
	while(DataAvailable) {
		cout << " data isDataAvailable" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	
	return 0;
}
