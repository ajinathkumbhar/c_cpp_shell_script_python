#include <stdlib.h>
//#include <iostream>
#include <stdio.h>

#define local_sizeof(x) ((char *)(&x + 1) - (char*)(&x))
#define local_sizeof_A(x) (*(&x + 1) - x)

//using namespace std;

int main(int argc, char const *argv[])
{
	int parts[] = {2,33,44,11,23,45,123};
	printf("%ld\n",local_sizeof(parts)/local_sizeof(parts[0]));
	printf("%ld\n",local_sizeof_A(parts));
	return 0;
}