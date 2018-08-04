#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(int argc,char * argv[]) {

    char c;
    int count = 0;
    while (cin.get(c)) {
        count++;
        cout << c;
    }

return EXIT_SUCCESS;
}
