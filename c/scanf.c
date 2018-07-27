#include<stdio.h>
#define PI 3.14
void main(void) {
    float radius;
    printf("Enter radius of circle :");
    scanf("%f",&radius);
    printf("The area is :%.2f\n",2*PI*radius*radius);
}

