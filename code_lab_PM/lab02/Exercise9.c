#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d", &n);
    // count digits
    int numDigit = (int)log10(n);

    if(numDigit == 1){
        printf("%d", n);
    }
    else{

        int lastDigit = n % 10;
        int firstDigit = n / (int)pow(10, numDigit);
        int middle = n % (int)pow(10, numDigit) / 10;

        int swapNumber = lastDigit*(int)pow(10, numDigit) + middle*10 + firstDigit;
        printf("%d", swapNumber);
        
    }
    
    return 0;
}