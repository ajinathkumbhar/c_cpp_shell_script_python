#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cctype>

using namespace std;

unsigned int mul(unsigned int, unsigned int); 

int main(int argc, char * argv[]) {
    int number;
    cout << "Enter number : " ;
    cin >> number;
    if (!(number > 0)) {
        clog << number << " enter greater than 0 " << endl;
        return EXIT_FAILURE;
    }

    // check odd using & operator 
    //hint: the last bit of odd number always
    // set to '1'
    if ( number & 1 ) 
        cout << number << " : odd number " << endl;
    else 
        cout << number << " : event number " << endl;

    // Double the number 
    // hint : use left shift ( 8 4 2 1 )
    int dbl = number << 1;
    cout << dbl << " : double " << endl;

    // Devide by 2 
    //hint : use right shift operator (8 4 2 1 )
    int devideBy2 = number >> 1;
    cout << devideBy2 << " : devide by 2 " << endl;

    // multiplicaiton 
    cout << "Multiplication : " << mul(number, number) << endl;

    return EXIT_SUCCESS;
}

unsigned int mul(unsigned int length, unsigned int width) {
    unsigned int result = 0 ;
    while ( width > 0 ) {
        if ( width & 1 )
            result = result + length;
        length = length << 1 ;
        width = width >> 1 ;
        cout << "result : " << result << " " ;
        cout << "length : " << length << " " ;
        cout << "weight : " << width << " "  << endl ;
    }

return result;
}
