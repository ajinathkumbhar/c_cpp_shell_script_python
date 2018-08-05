#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

int main(int argc, char const* argv[]) {
	int loopcount = 10;
	cout << "time(NULL) : " << time(NULL) << '\n' ;
	srand(time(NULL));
	do {
		cout << rand() << setw(25) << rand() << endl;
	} while(loopcount--);
}
