#include<stdio.h>

int main(){
    int n;

    do
    {
        printf("Enter a positive integer (n): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (n <= 0);
    

    int factorial = 1;
    int i;

    if(n == 0)
        printf("1");
    else{
        // for loop
        for(i = 2; i <= n; i++){
            factorial *= i;
        }
        printf("%d\n", factorial);


        // while loop
        i = 2;
        factorial = 1;
        while (i <= n)
        {
            factorial *= i;
            i++;
        }
        printf("%d\n", factorial);

    }

    return 0;
}