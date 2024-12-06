#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int product = 1;
    int temp = n;

    while (n > 10){
        product *= n % 10;
        n /= 10;
    }
    
    product *= n;
    printf("product all digit of %d: %d",temp, product);
    
    return 0;
}