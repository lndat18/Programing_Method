#include<stdio.h>

int main(){
    // height provided by user
    int height, width = 2;
    
    scanf("%d", &height);

    int perimeter = (height + width) * 2;
    int area = height * width;

    printf("p = %d, S = %d", perimeter, area);

    return 0;
}