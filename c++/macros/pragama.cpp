#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;


void init(void);
void teardown(void);

void __attribute__((constructor))	init();
void __attribute__((destructor))	teardown();



void init() {
	// cout << "init done " << endl;
	printf("%s\n","init done");
}

void teardown() {
	cout << "teardown  complete " << endl;
}

int main(int argc,char const * argv[]) {
	int model = 4535;
	cout <<  "model: " << model << endl;
	return EXIT_SUCCESS;
}