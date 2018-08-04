#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

enum emt {
JOY,
SURPRISE,
TRUST,
SADNESS,
};

class emotion {
    private:
       emt current_emotion;
    public:
        emt getCurrentEmt(void) {
            cout << "Retrive current emotions" << endl;
            return current_emotion;
        }
        
        void setCurrentEmt(emt emotion) {
            cout << "store current emotions" << endl;
            current_emotion = emotion;
        }
};

int main(int argc, char * argv[]){

    emt tmpEmt;
    tmpEmt = TRUST;
    emotion one;
    one.setCurrentEmt(tmpEmt);
    cout << one.getCurrentEmt();
    return EXIT_SUCCESS;
}
