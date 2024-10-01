#include<stdio.h>

int main(){
    double C;

    scanf("%lf", &C);

    double F = (C*1.8) + 32;

    printf("F = %.3lf", F);
    return 0;
}