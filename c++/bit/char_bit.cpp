#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

void printInBinary(int);

int main(int argc, char const *argv[])
{
	int num;
	cout << "Enter number : " ;
	try {
		cin >> num;	

	}catch (...) {
		cout << "wrong input";
	}

	printInBinary(num);
	return 0;
}


void printInBinary(int num) {
	int n = CHAR_BIT*sizeof(num);
	stack<bool> s;

	for (int i = 1; i<=n ; i++) {
		s.push(num%2);
		num = num/2;
	}
	for (int i = 1; i <= n; i++){
		cout << s.top();
		s.pop();

		if (i % CHAR_BIT == 0) 
			cout << " ";
	}
	cout << endl;
}