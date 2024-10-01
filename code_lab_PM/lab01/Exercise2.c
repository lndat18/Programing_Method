#include<stdio.h>

int main(){
    int num1, num2;
    scanf("%d%d",&num1,&num2);

    int addition = num1 + num2;
    printf("addition of two numbers is: %d\n", addition);

    int subtraction = num1 - num2;
    printf("subtraction of two numbers is: %d\n", subtraction);

    int multiplication = num1 * num2;
    printf("multiplication of two numbers is: %d\n", multiplication);

    int division = num1 / num2;
    printf("division of two numbers is: %d", division);

    double remainder = num1 % num2;
    printf("remainder of two numbers is: %d\n", remainder);
    return 0;
}