#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int temp = n;
    int reverseNum = 0;

    while(temp > 10){
        reverseNum = reverseNum*10 + temp%10;
        temp /= 10;
    }
    reverseNum = reverseNum*10 + temp%10;

    if(n == reverseNum){
        printf("n is palindrone");
    }else{
        printf("n is not palindrone");
    }
    return 0;
}