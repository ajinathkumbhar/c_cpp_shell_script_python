#include <stdio.h>
#include <time.h>
#include <limits.h>


#include "all.h"

/*
scope visiblity lifetime
auto        - on stack in side scope and no need to add keyword auto i.e local var
extern      - access from other files i.e declare in file which was declared and defined in another file
static      - static preserved value till program and access only in fuction scope and ALSO it store last assigned value.
                global declare var will be initlized to 0;
registers   - It is same as auto but it store in cpu register rathre than memory. If register is not free then
            it store in memory. It is used when a var is frequently accessed.
*/
void auto_var() {
    auto int flatno = 112;
    int flatsize = 1223; // no need to add auto keyword.
    printf("flatno : %d flatsize : %d \n", flatno, flatsize );
}

void static_var() {
    {
        static float phase_angle = 125.6;
        printf("phase angle in statuc var %f\n ", phase_angle);
    }
    int x = 0;
    static int list_items = 10;
    while ( x < 5 ) {
        static int list_items=10;
        // Here the list_items declare lonly once and updated value accoding to  ++
        // The first iteration will get default 10 value
        // will not declare every time
        printf("list_items : %d \n",list_items);
        list_items++;
        x++;
    }
    {
        static int list_items = 1110;
        printf("Reprint list_items : %d \n",list_items);
    }


    // static var not able access in another scope
    //printf("phase angle in statuc var outside scope : %f\n ", phase_angle);

}

void register_var() {
    //#define STORAGE_CLASS int
    clock_t t;
    t = clock();
    register int i,j = 0;
    for (i = 0; i < INT_MAX ; i++) {
         j = i ;
         j++;
    }

    t = clock() - t ;
    double time_taken = ((double) t / CLOCKS_PER_SEC);
    printf("Loop tooks to execute : %f\n",time_taken);
    // Loop tooks to execute : 0.644230 ------ for register class
    // Loop tooks to execute : 5.714980 ------ for auto storage class
}

int main(int argc, char * argv[]) {
    printf(" system name from main : %s\n", system_name);
    auto_var();
    static_var();
    print_sys_name();
    register_var();
    return 0;
}

