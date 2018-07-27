#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char * argv[]) {
    ifstream f_prog;
    char c;
    f_prog.open("progressBar.cpp");
    if (!f_prog) {
        cout << " failed to open file " << endl;
        return EXIT_FAILURE;
    }
    
    while(f_prog.get(c)) 
        cout << c;
    cout << endl;
    f_prog.close();

    return EXIT_SUCCESS;
}
