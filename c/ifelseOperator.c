#include<stdio.h>
int main(void) {

    int invalid_operator = 0;
    char operator;
    float number1,number2,result;

    printf("Enter two number and an operator is the format\n");
    printf(" number1 operator number2\n");
    scanf("%f %c %f",&number1, &operator, &number2);

    if(operator == '*')
        result = number1 * number2;
    else if (operator == '/')
        result = number1 / number2;
    else if (operator == '+')
        result = number1 + number2;
    else if (operator == '-')
        result = number1 - number2;
    else
        invalid_operator=1;

    if(invalid_operator != 1)
        printf("%f %c %f is %f\n",number1,operator, number2, result);
    else
        printf("Invalid Operator\n");

}

