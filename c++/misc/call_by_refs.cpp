#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

bool getMaxbill(int , int , int&);


int main(int argc,char const * argv[]) {
	int preBill = 42325;
	int curBill = 2342;
	int payableAmt = 0;
	if(!getMaxbill(preBill,curBill,payableAmt)) {
		cout << "failed to get payableAmt " ;
		return EXIT_FAILURE;
	}

	cout << "payableAmt : " << payableAmt << endl;


return EXIT_SUCCESS;
}

bool getMaxbill(int preBill,int curBill,int& payableAmt) {
	payableAmt = preBill > curBill ? preBill : curBill;
	return payableAmt ? true : false ;
}