//
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <bits/stdc++.h>

/*
string book_name("The Linux system programming");

book_name.length();
book_name.clear();
book_name.front();
book_name.back();
book_name.find("Linux");
book_name.erase(4,9);
book_name.replace(4,5,"Windows");
book_name.at(4);
book_name.c_str()

*/
using namespace std;

int main(int argc, char const * argv[]) {
	string product_name("tphoneY");
	string product_device("rimoY");
	string product_brand("smartron");
	string product_model("T5711");
	string product_manufacturer("smartron");
	string dash("-");
	string model = product_model;

	// build string with start and end
	string product_legacy_board(product_device.begin() , \
								product_device.begin() + 4);

	cout << product_legacy_board << endl;
	// clean string 
	product_legacy_board.clear();
	cout << product_legacy_board ;
	// print by index
	cout << product_model.at(2) << endl;

	//access each char by index
	for ( unsigned int index = 0 ; index < product_model.length() ; index++) {
		cout << product_model.at(index) << endl;
	}

	// get first and last char 
	cout << product_name.front()  << product_name.back() << endl;

	// get c type string
	printf("%s\n",product_manufacturer.c_str() );

	// find substring 
	if (product_name.find("tphone") != string::npos) {
		cout << "product_name matched " << endl;
		product_name.append(" 11");
	}

 	cout << product_name << endl;

 	// erase substring
 	product_name.erase(0,product_name.length() - 3);
 	cout << product_name << endl;

 	// get substring by start and number of char 
 	string tron = product_brand.substr(4,4);
 	cout << tron  << endl;

 	// print the lenght 
 	cout << product_device.length() << endl;

 	// erase string with start and end
 	product_device.erase(product_device.length() - 1, product_device.length());
 	cout << product_device << endl ;

 	// replace string with new string 
 	product_manufacturer.replace(4,4,"nort");
 	cout << product_manufacturer << endl;

 	string book_name("The Linux system programming");
	book_name.replace(4,5,"Windows");
	cout << book_name << endl;

	//return 0;
	string companyName = "Kryon mobile \n pvt ltd. \n tembhurni \n 413211\n";
	string companyName_a = R"(Kryon mobile \n pvt ltd. \n tembhurni \n 413211\n)";
	cout << companyName << '\n';
	cout <<companyName_a << '\n';
	return EXIT_SUCCESS;
}


