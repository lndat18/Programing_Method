#include<stdio.h>

int sum(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0)
            sum += i;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    int res = sum(n);
    printf("%d", res);
    return 0;
}