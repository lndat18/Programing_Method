#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 1;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n/i;
        }
    }

    if(sum == n && n != 1)
        printf("%d is perfect number", n);
    else{
        printf("%d is not perfect number",n);
    }
    
    return 0;
}