#include <stdio.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
    // Try to use unsinged int 
    unsigned int weight_kg = 1123;

    // try to use c99 type def data type
    uint8_t one_byte = 'A';
    uint16_t two_byte_roll_number = 3214;
    uint32_t four_byte_card_number = 4476754;
    uint64_t eight_byte_key  = 83423235254567274;
    printf("%lu \n",eight_byte_key);
    unsigned int test = -234234;
    printf(" unsinged int test = %u \n", test); // this will not print as excepted
    return 0;
}
