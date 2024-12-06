#include <stdio.h>
#include <math.h>


// 1 2 are same question
int sumEven(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0)
            sum += i;
    }
    return sum;
}

// 3
void printTable(int n){
    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n",n,i, n*i);
    }
}

// 4 
int sumAllNum(int n){
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += i;
    }
    return res;
}


// 5
void FirstLastDigit(int n){
    int lastDigit = n % 10;

    while(n > 10){
        n /= 10;
    }
    
    int firstDigit = n;
    printf("first digit %d, last digit %d", firstDigit, lastDigit);
}


// 6
int sumDigit(int n){
    int sum = 0;
    int temp = n;

    while (n > 10){
        sum += n % 10;
        n /= 10;
    }
    
    sum += n;
    return sum;
}


// 7
long long productDigit(int n){
    int product = 1;
    int temp = n;

    while (n > 10){
        product *= n % 10;
        n /= 10;
    }
    
    product *= n;
    return product;
}

// 8
int countNumber(int n){
    int count = 0;
    int temp = n;

    while (n > 10){
        count++;
        n /= 10;
    }
    
    count++;
    
    return count;
}


// 9
int swapFirstLastDigit(int n){
    int numDigit = (int)log10(n);

    if(numDigit == 1){
        return n;
    }else{

        int lastDigit = n % 10;
        int firstDigit = n / (int)pow(10, numDigit);
        int middle = n % (int)pow(10, numDigit) / 10;

        int swapNumber = lastDigit*(int)pow(10, numDigit) + middle*10 + firstDigit;
        return swapNumber;
    }
}


// 10
void reverseOrder(int n){
    int temp = n;
    int reverseNum = 0;

    while(temp > 10){
        reverseNum = reverseNum*10 + temp%10;
        temp /= 10;
    }
    reverseNum = reverseNum*10 + temp%10;
    printf("%d", reverseNum);
}

// 11
int isPalindrone(int n){
    int temp = n;
    int reverseNum = 0;

    while(temp > 10){
        reverseNum = reverseNum*10 + temp%10;
        temp /= 10;
    }
    reverseNum = reverseNum*10 + temp%10;

    return n == reverseNum;
}

// 12
int isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }

    return n > 1;
}

// 13
int isArmstrongNum(int n){
    int newNumber = 0;
    int temp = n;
    int numDigit = log10(n) + 1;

    while(n > 10){
        newNumber += (int)pow(n%10, numDigit);
        n /= 10;
    }
    newNumber += (int)pow(n%10, numDigit);

    return temp == newNumber;
}

// 14
int isPerfectNum(int n){
    int sum = 1;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n/i;
        }
    }

    return sum == n && n != 1;
}

// 15
void printPrime(int n){
    for(int i = 2; i <= n; i++){
        if (isPrime(i))
            printf("%d ", i);
    }
}

// 16
void printAmstrong(int n){
    for(int i = 1; i <= n; i++){
        if (isArmstrongNum(i))
            printf("%d ", i);
    }
}


// 17
void printPerfect(int n){
    for(int i = 1; i <= n; i++){
        if (isPerfectNum(i))
            printf("%d ", i);
    }
}

// 18
void decimalToBinary(int num) {
    if (num > 1) {
        decimalToBinary(num / 2);
    }
    printf("%d", num % 2);
}

// 19
long long factorial(int n){
    long long res = 1;
    for(int i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}


int getValidInput() {
    int n;
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n'); // clear input buffer
    }
    return n;
}

void displayMenu() {
    printf("\nChoose an option:\n");
    printf("1. Sum of even numbers up to N\n");
    printf("2. Print multiplication table of N\n");
    printf("3. Sum of all numbers up to N\n");
    printf("4. First and last digit of N\n");
    printf("5. Sum of digits of N\n");
    printf("6. Product of digits of N\n");
    printf("7. Count number of digits in N\n");
    printf("8. Swap first and last digit of N\n");
    printf("9. Reverse the digits of N\n");
    printf("10. Check if N is a palindrome\n");
    printf("11. Check if N is prime\n");
    printf("12. Check if N is an Armstrong number\n");
    printf("13. Check if N is a perfect number\n");
    printf("14. Print all prime numbers up to N\n");
    printf("15. Print all Armstrong numbers up to N\n");
    printf("16. Print all perfect numbers up to N\n");
    printf("17. Convert N to binary\n");
    printf("18. Factorial of N\n");
    printf("19. Exit\n");
}


int main(){

    int choice, n;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        choice = getValidInput();

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Sum of even numbers: %d\n", sumEven(n));
                break;
            case 2:
                printf("Enter a number: ");
                n = getValidInput();
                printTable(n);
                break;
            case 3:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Sum of all numbers: %d\n", sumAllNum(n));
                break;
            case 4:
                printf("Enter a number: ");
                n = getValidInput();
                FirstLastDigit(n);
                break;
            case 5:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Sum of digits: %d\n", sumDigit(n));
                break;
            case 6:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Product of digits: %lld\n", productDigit(n));
                break;
            case 7:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Number of digits: %d\n", countNumber(n));
                break;
            case 8:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Number after swapping first and last digits: %d\n", swapFirstLastDigit(n));
                break;
            case 9:
                printf("Enter a number: ");
                n = getValidInput();
                reverseOrder(n);
                break;
            case 10:
                printf("Enter a number: ");
                n = getValidInput();
                if (isPalindrone(n))
                    printf("%d is a palindrome.\n", n);
                else
                    printf("%d is not a palindrome.\n", n);
                break;
            case 11:
                printf("Enter a number: ");
                n = getValidInput();
                if (isPrime(n))
                    printf("%d is prime.\n", n);
                else
                    printf("%d is not prime.\n", n);
                break;
            case 12:
                printf("Enter a number: ");
                n = getValidInput();
                if (isArmstrongNum(n))
                    printf("%d is an Armstrong number.\n", n);
                else
                    printf("%d is not an Armstrong number.\n", n);
                break;
            case 13:
                printf("Enter a number: ");
                n = getValidInput();
                if (isPerfectNum(n))
                    printf("%d is a perfect number.\n", n);
                else
                    printf("%d is not a perfect number.\n", n);
                break;
            case 14:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Prime numbers up to %d: ", n);
                printPrime(n);
                break;
            case 15:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Armstrong numbers up to %d: ", n);
                printAmstrong(n);
                break;
            case 16:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Perfect numbers up to %d: ", n);
                printPerfect(n);
                break;
            case 17:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Binary representation of %d: ", n);
                decimalToBinary(n);
                printf("\n");
                break;
            case 18:
                printf("Enter a number: ");
                n = getValidInput();
                printf("Factorial of %d: %lld\n", n, factorial(n));
                break;
            case 19:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 19);

    return 0;
}