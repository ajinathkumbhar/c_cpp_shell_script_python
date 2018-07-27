#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
inline void getModel(void);
inline void getModel(void) {
    cout << "DELL LATTITUDE E6440" << endl;
}

int main(int argc, char * argv[] ){
    getModel();
    cout << "First call done " << endl;
    getModel();
    cout << "Sencod call done" << endl;
    return EXIT_SUCCESS;
}
