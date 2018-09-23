#include <stdio.h>
#include <stdint.h>

uint8_t *  get_model(void);

int main(int argc, char * argv[]) {
    uint8_t * model_name = "While simple to implement, this representation has been prone to errors and performance problems The NUL termination has historically created security problems.[4] A NUL byte inserted into the middle of a string will truncate it unexpectedly. A common bug was to not allocate the additional space for the NUL, so it was written over adjacent memory. Another was to not write the NUL at all, which was often not detected during testing because a NUL was already there by chance from previous use of the same block of memory. Due to the expense of finding the length, many programs did not bother before copying a string to a fixed-size buffer, causing a buffer overflow if it was too long.The inability to store a NUL requires that string data and binary data be kept distinct and handled by different functions (with the latter requiring the length of the data to also be supplied). This can lead to code redundancy and errors when the wrong function is used.The speed problems with finding the length can usually be mitigated by combining it with another operation that is O(n) anyway, such as in strlcpy. However, this does not always result in an intuitive API.";
    uint8_t * m = get_model();
    uint32_t serial_number = 23423423;
    uint32_t serial_number_2 = 444423;
    uint32_t * const sr_num = &serial_number;
    //sr_num = &serial_number_2;
    
    model_name[4] = 'h';
    printf("model name : 0x%8x \n", model_name);
    printf("model num  : 0x%8x \n", m);
    printf("model : %s \n",m);
    m[0] = 'R';
    printf(" model : %s \n",m);
    return 0;
}


uint8_t * get_model() {
	static uint8_t model[4] = {'T','X','5','\0'};
	static uint8_t model_2[4] = {'T','Y','5','\0'};
    return model;
}
