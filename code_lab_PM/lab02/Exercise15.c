#include<stdio.h>
#include<math.h>

int isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return n > 1;
}

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
    
    int i;


    // for loop
    for(i = 2; i <= n; i++){
        if(isPrime(i))
            printf("%d ", i);
    }
    printf("\n");


    // while loop
    i = 2;
    while(i <= n){
        if(isPrime(i))
            printf("%d ", i);
        i++;
    }

    return 0; 
}