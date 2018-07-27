#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define SET_BIT(dec,n) \
    dec = dec | (1 << n)
#define UNSET_BIT(dec,n) \
    dec = dec & ~(1 << n)

using namespace std;
int error = 0x0;

enum errorcodes {
    FILE_NOT_FOUND=0,
    FILE_EMPTY,
    FILE_PERMISSION,
    FILE_COURRPT,
    FILE_SIZE,
    FILE_TYPE,
    FILE_LARGE,
    FILE_RDONLY,
};

errorcodes t_error;

void setError(errorcodes err) {
    SET_BIT(error,err);
}

void printError(void) {
    cout << "error: " << error << endl;
}
int main(int argc, char * argv[]) {
    int number;
    errorcodes eRR;
    cout << "Enter number : " ;
    cin >> number;
    cout << "number           : "  << number << endl;
    SET_BIT(number,1);
    cout << "number bit set   : "  << number << endl;
    UNSET_BIT(number,1);
    cout << "number bit unset : "  << number << endl;
    printError();
    eRR=FILE_SIZE;
    setError(eRR);
    printError();
    eRR=FILE_COURRPT;
    setError(eRR);
    printError();
     
return EXIT_SUCCESS;
}

