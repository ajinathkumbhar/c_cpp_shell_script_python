#include<stdio.h>
int main(){
    char c;
    printf("Enter char:");
    scanf("%c",&c);

    switch(c) {
        case 'a' :
                printf( "This is a");
                break;
        case 'A' :
                printf("This is A");
                break;
        }

}
