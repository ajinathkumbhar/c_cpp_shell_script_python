#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	const int modelno = 12234;
	cout << modelno << endl;

	// can't change const var value as var is readonly
	//modelno = 213;

	// int const is same as const int	
	int const size = 123;
	cout << size << endl;
	// can't change const var value as var is readonly
	//size = 1243;


	// pInt is not constant 
	const int * pInt = NULL;
	pInt = new int(12);
	cout << pInt << " " << *pInt << '\n';
	pInt = new int(23);
	cout << pInt << " " << *pInt << '\n';
	// pInt is not constant, the value at pInt is contant
	//*pInt = 234;


	// const pFloat is readlonly pointer points to float value
	float  * const pFloat = NULL;


	// pFloat = new float(34.4);
	// cout << pFloat << " " << *pFloat << '\n';
	// pFloat = new float(234.4);
	// cout << pFloat << " " << *pFloat << '\n';


	return 0;
}