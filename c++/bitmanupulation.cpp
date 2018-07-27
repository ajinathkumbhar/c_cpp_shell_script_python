#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;

class number {
    private:
        char n;
        char dbl;
        char havle;
        bool even;

    public:
        number(char);
        char getNumber(void);
        char getDbl(void);
        char getHavle(void);
        bool isEven(void);
};

number::number(char num) {
    n = num ; 
    dbl = num << 1;
    havle = num >> 1; 
    even = num & 1 ? false : true ;
}

char number::getNumber(void){
    return n;
}

char number::getDbl(void) {
    return dbl;
}

char number::getHavle(void) {
    return havle;
}

bool number::isEven(void) {
    return even;
}


// 5 : 0000 0000 - 0000 0000 - 0000 0000 - 0000 0101
void DecToBin(int byte) {
char bits[32] = {'0'} ;
    for(int idx=0;idx < 32 ;idx++) {
        byte % 2 ? bits[idx] = '1' : bits[idx] = '0';
        byte = byte/2;
    }
    int idx=31;
    cout << " " ;
    while(idx >= 0) {
        cout << bits[idx];
        if ((idx) % 4 == 0)
            cout << " " ;
        idx--;
    }
    cout << " ";

}

namespace clg {
    char num;
}

int main(int argc, char * argv[]) {
    // 1 - number
    // 2 - double
    // 3 - havle
    // 4 - even or odd
    cin >> clg::num;
    clg::num = 'a';
    printf("%c --- \n\n ",clg::num);
    number rollnum(clg::num);
    printf("%c\n",rollnum.getNumber());
    cout << "number : " << (int)rollnum.getNumber() << endl;
    cout << "double : " << (int)rollnum.getDbl() << endl;
    cout << "havle  : " << (int)rollnum.getHavle() << endl;
    const char * evenOrodd = (int)rollnum.isEven() ? "YES" : "NO";
    cout << "Even   : " << evenOrodd << endl;
    
    number desknumber(63);
    cout << " number : " << (int)desknumber.getDbl() << endl;
        
        
    return EXIT_SUCCESS;
    
    
    int num=0;
    char * byte;
    cin >> num;
    if (num > 128 || num ==0 ) {
        cout << "enter number less than 127 and greater than 0  " << endl;
        return EXIT_FAILURE;
    }
 
    //0000 0000 - 0000 0000 - 0000 0000 - 0000 0000  
    //  number      double      havle     even or odd
    int tmp = num;
    num = num << 24;
    cout << " 1# : " << num << " \t: " ;
    DecToBin(num) ;  
    cout << endl; 
    
    num = num | ((tmp << 1) << 16);
    cout << " 2# : " << tmp << " \t\t: " ;
    DecToBin(num) ;  
    cout << endl; 
    
    num = num | ((tmp >> 1) << 8);
    cout << " 3# : " << num << " \t: " ;
    DecToBin(num) ;  
    cout << endl; 
    
    num = tmp & 1 ? num | 0x1 : num|0x0;
    cout << " 4# : " << num << " \t: " ;
    DecToBin(num) ;  
    cout << endl; 
   


}
