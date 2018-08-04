//#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char const * argv[]) {
	fstream logfile;
	logfile.open("/tmp/log.txt",fstream::out);

	cout << "get all rdbuf() " << endl;
	streambuf * out_buf = cout.rdbuf();
	streambuf * in_buf = cin.rdbuf();
	streambuf * log_buf = logfile.rdbuf();
	cout << "Now open file and check " << endl;
	cout.rdbuf(log_buf);
	cout << "redirecting out to file" << endl;
	cout << "2 line for redirect " << " continune 3rd line " << endl;
	cout.rdbuf(out_buf);
	cout << "Now out rdbuf() reseted back to outbuf" << endl;

}

