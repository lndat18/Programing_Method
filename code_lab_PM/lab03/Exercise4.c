#include<stdio.h>

int sum(int n){
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += i;
    }
    return res;
}


int main(){
    int n;
    scanf("%d",&n);

    int a = sum(n);
    printf("%d", a);

    return 0;
}