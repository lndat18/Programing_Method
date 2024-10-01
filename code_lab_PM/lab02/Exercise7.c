#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 1;
    int temp = n;

    while (n > 10){
        sum *= n % 10;
        n /= 10;
    }
    
    sum *= n;
    printf("sum all digit of %d: %d",temp, sum);
    
    return 0;
}