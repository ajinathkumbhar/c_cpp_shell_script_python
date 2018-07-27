#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "data/STL_data.h"
//#include<STL_data.h>

using namespace std;

int main(int argc, char * argv[]) {
    //int pid_numbers[PID_LIMIT];
    int pid_count = 0;

    //pid_count = getPidNumberList(pid_numbers);
    pid_count = getPidLimit();
    cout << "Pid count in main : " << pid_count << endl;
    return EXIT_SUCCESS;
}
