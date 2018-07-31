#include<stdio.h>
#include<stdlib.h>
#include<iostream>

/* Pair is not a part of container lib */

using namespace std;
int main(int argc, char * argv[]) {
	pair<int,int> dbl;
	pair<int,string> seat_number;
	
	dbl = make_pair(234,233);
	seat_number = make_pair(78859,"Ajinath");
	
	cout << dbl.first << ":" << dbl.second << endl;
	cout << seat_number.first << ":" << seat_number.second << endl;
cout << __cplusplus << endl;
return EXIT_SUCCESS;
}
