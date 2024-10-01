#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int count = 0;
    int temp = n;

    while (n > 10){
        count++;
        n /= 10;
    }
    
    count++;
    printf("sum all digit of %d: %d",temp, count);
    
    return 0;
}