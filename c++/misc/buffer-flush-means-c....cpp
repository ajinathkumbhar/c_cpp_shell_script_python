#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<thread>

using namespace std;

int main(int argc, char const* argv[]) {
	for ( int i = 0; i < 5; i++) {
		cout << i << " " << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

}