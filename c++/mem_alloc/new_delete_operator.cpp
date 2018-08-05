#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int * pInt = new int(332222);
	//pInt = NULL;
	if(!pInt) {
		cout << "failed to allocate memory" << endl;
		return -1 ;
	}
	cout << " new alloc " << endl;
	
	// alloc mem for block of 5 
	pInt = new int[5];
	int * tmp = pInt + 2;
	srand(time(NULL));
	
	for ( int i = 0; i < 5; i++)
	{	
		pInt[i] = i + 2;
		cout << "add : " << pInt + i << " val : " << pInt[i];
		cout << endl;
	}
	delete[] pInt;
	cout << " tmp : " << tmp << " val : " << *tmp << endl;


	return 0;
}