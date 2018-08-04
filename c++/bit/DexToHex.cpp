// Read ints and print their hex representations
// Note sizeof(int) returns number of bytes in an int.

#include <iostream>
using namespace std;

int main() {
        int n;
            while (cin >> n) {
                        cout << "decimal: " << n << endl;
                              
                                //--- Print hex with leading zeros
                                cout << "hex    : ";
                                        for (int i=2*sizeof(int) - 1; i>=0; i--) {
                                                        cout << "0123456789ABCDEF"[((n >> i*4) & 0xF)];
                                                                }
                                                cout << endl << endl;
                                                    }
return 0;
}
