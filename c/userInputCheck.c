#include<stdio.h>
int main(void) {
    int number;
    int valid = 0;

    while( valid == 0) {
        printf("Enter a number between 1 and 100 ---> ");
        scanf("%d",&number);
        /* assume number is valid */
        valid = 1;
        if( number < 1) {
                printf("Number is below 1. Please re-enter\n");
                valid = 0;
        }
        if( number > 10 ) {
            printf("Number is above 10. Please re-enter \n");
            valid = 0;
        }
        printf("The number is %d\n", number);
    }
}

