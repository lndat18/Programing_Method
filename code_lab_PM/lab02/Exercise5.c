#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int lastDigit = n % 10;

    while(n > 10){
        n /= 10;
    }
    
    int firstDigit = n;
    printf("first digit %d, last digit %d", firstDigit, lastDigit);

    return 0;
}