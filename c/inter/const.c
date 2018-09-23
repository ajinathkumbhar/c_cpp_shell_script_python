#include <stdio.h>

int main(int argc, char const *argv[])
{
    const int line_number = 123;
    // const.c:6:5: error: assignment of read-only variable ‘line_number’
    // line_number = 234;
    // line_number++;

    int const page_number = 235;
    /*const.c:11:5: error: assignment of read-only variable ‘page_number’
    page_number = 33;
    page_number++;
    */

    /*
    We will go for some const complex case with pointer

    The const keyword is used to make a data to be constant. The data may be at address or it may be in side varible
    And variable may be a pointer (so, the pointer variable i.e. address will be constant)
    1. pointer, it contain address and we want to make it constant and the address inside pointer will not chagne 
    */

    int * const base_address = 0x08000000;
    base_address = 0x04000000;

    /*
    2. pointer, it contain hase address and which points some contents and we want to make that content to be constant or 
        would not change
    */
    const int * acc_number_new = 653231;
    int const * acc_number_old = 253231;

    * acc_number_new = 789895;
    * acc_number_old = 5454535;
    // const int and int const are samw

    char * old_password = "test";
    const char * const password = "********";
    password = & old_password;
    *password = "newpass";

    /*
                              ^
const.c:25:5: error: assignment of read-only variable ‘base_address’
     base_address = 0x04000000;
     ^
                                 ^
const.c:34:5: error: assignment of read-only location ‘*acc_number_new’
     * acc_number_new = 789895;
     ^
const.c:35:5: error: assignment of read-only location ‘*acc_number_old’
     * acc_number_old = 5454535;

     ^
const.c:40:5: error: assignment of read-only variable ‘password’
     password = & old_password;
     ^
const.c:41:5: error: assignment of read-only location ‘*password’
     *password = "newpass";


*/

    return 0;

}
