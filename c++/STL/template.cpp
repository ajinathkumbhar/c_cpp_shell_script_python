#include<stdlib.h>
#include<iostream>

using namespace std;
template<class T>
T getMax(T height,T width){
    return height > width ? height : width;
}

int main(int argc, char * argv[]) {
    cout << getMax<int>(11,12) << endl;
    cout << getMax<float>(11.2,22.1) << endl;
    cout << getMax(11.2,22.1) << endl;
    return EXIT_SUCCESS;
}

