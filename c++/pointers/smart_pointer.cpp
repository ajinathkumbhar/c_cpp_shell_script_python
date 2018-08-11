#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


template<class T>
class smartPointer {
private:
	T * ptr;
public:
	explicit smartPointer(T * p) {
		ptr = p;
	}
	~smartPointer(){
		delete ptr;
	}
	T &operator * () {
		return *ptr;
	}
	T * operator -> () {
		return ptr;
	}
};

int main(int argc, char const *argv[])
{
	smartPointer<char> model(new char(34));
	cout << *model << '\n';
	return 0;
}