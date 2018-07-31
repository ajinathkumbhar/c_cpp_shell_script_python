#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<tuple>

using namespace std;

int main(int argc, char * argv[]) {
	tuple<int,int,string> emp;
	emp = make_tuple(1072,29,"ajinath");

	int empID, age;
	string empName;
	tie(empID,age,empName) = emp;
	cout << "empID   : " << empID << endl;
	cout << "age     : " << age << endl;
	cout << "empName : " << empName << endl;


	
	return EXIT_SUCCESS;

}

