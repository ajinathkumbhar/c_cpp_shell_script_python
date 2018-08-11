#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef  SIZE
#define SIZE 10
#endif
using namespace std;

void printArray(int (&)[SIZE]);
int main(int argc, char const *argv[])
{
	int linenumber[SIZE] = {1,4,33,22,45,64,12,434,55,77};
	printArray(linenumber);	

	int *pInt;
	int& ref = *pInt;
	cout << ref;
	return 0;
}

void printArray(int (&data) [SIZE]){
	for (int i = 0; i < SIZE; ++i)
	{
		cout << data[i] << '\n';
	}
	cout << "size : " << sizeof(data) << '\n';
}