#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

static int isWriteSuccess = 0;
void setWriteSuccess(int);

int main(int argc, char const *argv[])
{
	setWriteSuccess(1);
	cout << "isWriteSuccess :"  << isWriteSuccess << '\n';
	setWriteSuccess(0);
	cout << "isWriteSuccess :"  << isWriteSuccess << '\n';
	return 0;
}

void setWriteSuccess(int val) {
 	isWriteSuccess = val;
 	return;
}