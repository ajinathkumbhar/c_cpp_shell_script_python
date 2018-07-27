#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cctype>

using namespace std;
int main(int argc, char * argv[]) {

    int dec;
    dec=0;
    int decRemain=0;
    cout << " Enter decimal number : " ; 
    while(cin >> dec) {
        cout << dec << '!' << endl;
       // if (!isdigit(dec) || dec == 0){
         //   cerr << "Entered number is not a digit. Pl reenter : " << endl;
           // continue;
       // }
        cout << " You have entered decinal number  : " << dec << endl;
        cout << " Binary : " ;
        while(dec > 0) {
            cout << dec%2;
            dec = dec/2;
        }
        cout << endl;
        cout << " Enter decimal number : " ; 
    }
return EXIT_SUCCESS;
}
