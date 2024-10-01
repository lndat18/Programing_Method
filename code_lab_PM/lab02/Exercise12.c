#include<stdio.h>
#include<math.h>

int main(){
    int n;

    do
    {
        printf("Enter a positive integer (n): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (n < 0);
    

    int isPrime = 1;

    if(n < 2){
        isPrime = 0;
    }
    else{
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                isPrime = 0;
            }
        }
    }

    if(isPrime)
        printf("%d is prime number", n);
    else
        printf("%d is not prime number", n);
    
    return 0;
}