#include<stdio.h>
#include<stdlib.h>

int main(){
    int n1, n2, max = 0;

    scanf("%d %d", &n1,&n2);

    if (n1 > n2)
    {
        max = n1;
    }else{
        max = n2;
    }

    printf("%d", max);

    return 0;
}