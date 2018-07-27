#include<stdio.h>
#include<iostream>
#include<cctype>
#include<stdlib.h>
using namespace std;

int main(int argc, char * argv[]) {
    char firstLetter;
    while(cin.get(firstLetter)) {
        if (isalnum('%'))
            cout << "its letter or digit" << endl;
        else if (isalpha(firstLetter))
            cout << "its alpha"<< endl;
        else if (isblank(firstLetter)) 
            cout << "its blank" << endl;
        else if (isdigit(firstLetter))
            cout << "its digit " << endl;
        else if (islower(firstLetter))
            cout << "its lower " <<endl;
        else if (isupper(firstLetter))
            cout << "its upper " << endl;
        else if (isspace(firstLetter))
            cout << "its space " << endl;
        else
            cout << " not filter found " << endl;
        
        cout << " lower : " << (char) tolower(firstLetter) << " "
            << " upper : " << (char) toupper(firstLetter) << endl;

    }
    return EXIT_SUCCESS;
}


