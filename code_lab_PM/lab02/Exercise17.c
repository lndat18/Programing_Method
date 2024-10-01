#include<stdio.h>
#include<math.h>


int isPerfectNum(int n){
    int sum = 1;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n/i;
        }
    }

    if(sum == n && n != 1)
        return 1;
    else{
        return 0;
    }
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
    for(i = 1; i <= n; i++){
        if(isPerfectNum(i))
            printf("%d ", i);
    }
    printf("\n");


    // while loop
    i = 1;
    while(i <= n){
        if(isPerfectNum(i))
            printf("%d ", i);
        i++;
    }

    return 0; 
}