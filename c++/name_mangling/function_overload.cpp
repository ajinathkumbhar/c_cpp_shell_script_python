#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

extern "C" 
{
	int printf(const char * format,...);
}
int main(int argc, char const * argv[]) {	
	printf("----------- test -----------\n");

return EXIT_SUCCESS;
}
