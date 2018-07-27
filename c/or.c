#include<stdio.h>
int main(void) {
    int number;
    int valid=0;

    while(valid==0){
        printf("Enter a number between 1 and 100 ---> ");
        scanf("%d",&number);
        if((number < 1) || (number>10)) {
            printf("Number is outside range 1-10 please reenter\n");
            valid=0;
        }
        else 
            valid=1;
    }
    printf("The number is %d\n", number);

}
