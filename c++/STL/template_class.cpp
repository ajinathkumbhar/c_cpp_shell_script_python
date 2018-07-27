#include<stdlib.h>
#include<iostream>

using namespace std;

template<class T>
class xnum {
    private:
        T num;
        T dbl;
    public:
        xnum(T);
        T getNum(void);
        T getDbl(void);
        bool isEven(void);
};

template<class T>
xnum<T>::xnum(T n){
    num = n;
}

template<class T>
T xnum<T>::getNum(){
    return num;
}

template<class T>
T xnum<T>::getDbl(){
    return num << (T)1;
}

template<class T>
bool xnum<T>::isEven(){
    return num & 0x1 ? false : true;
}

int main(int argc, char * argv[]) {
   xnum<int> width(5);
   xnum<char> height('A');
   cout << width.getDbl() << endl;
   cout << (int)height.getDbl() << endl;

return EXIT_SUCCESS;
}

