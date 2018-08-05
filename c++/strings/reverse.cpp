#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;
void reverse_local(string& );
	
int main(int argc, char const *argv[])
{
	string number = "123456789";
	reverse(number.begin(), number.end());
	cout << number << endl;
	reverse_local(number);
	cout << number << '\n';
	return 0;
}

void reverse_local(string& string) {
	int size = string.size();

	for (int i = 0; i < size/2; ++i)
	{
		/* code */
		swap(string[i],string[size - i - 1]);
	}

}