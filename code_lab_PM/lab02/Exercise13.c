#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d", &n);

    int newNumber = 0;
    int temp = n;
    int numDigit = log10(n) + 1;

    while(n > 10){
        newNumber += (int)pow(n%10, numDigit);
        n /= 10;
    }
    newNumber += (int)pow(n%10, numDigit);

    if(newNumber == temp){
        printf("%d is ArmStrong number",temp);
    }else{
        printf("%d is not ArmStrong number",temp);
    }

    return 0;
}