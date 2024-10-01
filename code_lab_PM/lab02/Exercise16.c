#include<stdio.h>
#include<math.h>

int isArmstrongNum(int n){
    int newNumber = 0;
    int temp = n;
    int numDigit = log10(n) + 1;

    while(n > 10){
        newNumber += (int)pow(n%10, numDigit);
        n /= 10;
    }
    newNumber += (int)pow(n%10, numDigit);

    if(newNumber == temp){
        return 1;
    }else{
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
        if(isArmstrongNum(i))
            printf("%d ", i);
    }
    printf("\n");


    // while loop
    i = 1;
    while(i <= n){
        if(isArmstrongNum(i))
            printf("%d ", i);
        i++;
    }

    return 0; 
}