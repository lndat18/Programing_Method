#include<stdio.h>
#include<stdlib.h>

int main(){
    int y;

    scanf("%d", &y);

    if ( y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) ) {
        printf("Yes");
    }else{
        printf("No");
    }
    
    return 0;
}