#include<stdio.h>

int main(){

    int n, i, sum = 0;

    // do-while loop
    do
    {
        printf("Enter a positive integer (n): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (n <= 0);
    

    // for loop
    for (i = 1; i <= n; i++){
        if(i % 2 == 0)
            sum += i;
    }
    printf("%d\n", sum);

    // while loop
    sum = 0;
    i = 1;
    while(i <= n){
        if(i % 2 == 0)
            sum += i;
        i++;
    }
    printf("%d\n", sum);

    return 0;
}