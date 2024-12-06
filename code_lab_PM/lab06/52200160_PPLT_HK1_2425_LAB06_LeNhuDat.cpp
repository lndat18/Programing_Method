#include <stdio.h>
#include <math.h>


int isPrime(int n, int i = 2){
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrime(n, i + 1);
}


long long factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}


long long two_exp(int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    return 2 * two_exp(n-1);
}


long long x_exp(int x, int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    return x * x_exp(x, n - 1);
}


int numDigit(int n){
    if (n < 10)
        return 1;
    return 1 + numDigit(n/10);
}


// 6
int sum_expression_a(int n){
    if (n == 1)
        return 3;
    return (2 * n + 1) + sum_expression_a(n - 1);
}


double sum_expression_b(int n){
    if (n == 1)
        return 1.0 / 2;
    return (n / 2.0) + sum_expression_b(n - 1);
}


long long sum_expression_c(int n){
    if (n == 1)
        return 1;
    return factorial(n) + sum_expression_c(n - 1);
}


double sum_expression_d(int n){
    if (n == 1)
        return 1;
    return sqrt(n) + sum_expression_d(n - 1);
}


long long product_expression_e(int n){
    if (n == 1)
        return 1;
    return factorial(n) * product_expression_e(n - 1);
}

// 7 find gcd
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

// 8 C(k,n)
int combination(int k, int n) {
    if (k == 0 || k == n) {
        return 1;
    }
    return combination(k - 1, n - 1) + combination(k, n - 1);
}

// 9 convert Decimal to Binary
void Decimal2Binary(int n){
    if (n == 0)
        return;
    Decimal2Binary(n / 10);
    printf("%d", n % 10);
}

// 10 find max element in an array
int max(int a, int b){
    return (a > b) ? a : b;
}


int findMax(int arr[10], int size){
    if (size == 1)
        return arr[size];
    return max(arr[size-1], findMax(arr, size-1));
}

// 11 count Even number in an array
int countEven(int arr[10], int size){
    if (size == 0)
        return 0;
    return ((arr[size - 1] % 2 == 0) ? 1: 0) + countEven(arr, size - 1);
}

// 12 product 2 numbers by recursion
int product(int a, int b){
    if (b == 1)
        return 1;
    return a + product(a, b - 1);
}

// 13 find max digit in a number
int findMaxDigit(int n){
    if (n < 10)
        return n;
    return max(n % 10, findMaxDigit(n / 10));
}

// 14 find element in an array by key
int findElement(int arr[], int size, int key){
    // this function returns an index of the key
    if (size == 0)
        return -1;
    if (arr[size - 1] == key)
        return size - 1;
    return findElement(arr, size - 1, key);
}

// 15 calculate sum by expression
double sum(int n){
    if(n == 1)
        return 1;
    return (double)(factorial(n))/(factorial(n-1)) + sum(n - 1);
}


int main(){
    int choice, n, x, size = 10, key = 10, index;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    do {
        printf("\nMenu:\n");
        printf("1. Check if a number is prime\n");
        printf("2. Calculate factorial\n");
        printf("3. Calculate 2^n\n");
        printf("4. Calculate x^n\n");
        printf("5. Count the number of digits in a number\n");
        printf("6. Sum expression a: Sum(2i + 1) for i=1 to n\n");
        printf("7. Sum expression b: Sum(i/2) for i=1 to n\n");
        printf("8. Sum expression c: Sum(i!) for i=1 to n\n");
        printf("9. Sum expression d: Sum(√i) for i=1 to n\n");
        printf("10. Product expression e: Product(i!) for i=1 to n\n");
        printf("11. Find GCD of two numbers\n");
        printf("12. Calculate Combination C(k, n)\n");
        printf("13. Convert Decimal to Binary\n");
        printf("14. Find max element in an array\n");
        printf("15. Count Even numbers in an array\n");
        printf("16. Product 2 numbers by recursion\n");
        printf("17. Find max digit in a number\n");
        printf("18. Find element in an array by key\n");
        printf("19. Sum by expression: Sum(i!/(i-1)!) for i = 1 to n\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("%d is %sprime.\n", n, isPrime(n) ? "" : "not ");
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d is %lld\n", n, factorial(n));
                break;
            case 3:
                printf("Enter a power n: ");
                scanf("%d", &n);
                printf("2^%d is %lld\n", n, two_exp(n));
                break;
            case 4:
                printf("Enter a base x and power n: ");
                scanf("%d %d", &x, &n);
                printf("%d^%d is %lld\n", x, n, x_exp(x, n));
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Number of digits in %d is %d\n", n, numDigit(n));
                break;
            case 6:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Sum expression a for n=%d is %d\n", n, sum_expression_a(n));
                break;
            case 7:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Sum expression b for n=%d is %.2f\n", n, sum_expression_b(n));
                break;
            case 8:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Sum expression c for n=%d is %lld\n", n, sum_expression_c(n));
                break;
            case 9:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Sum expression d for n=%d is %.2f\n", n, sum_expression_d(n));
                break;
            case 10:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Product expression e for n=%d is %lld\n", n, product_expression_e(n));
                break;
            case 11:
                printf("Enter two numbers: ");
                int a, b;
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
                break;
            case 12:
                printf("Enter k and n: ");
                scanf("%d %d", &x, &n); // n is for 'n', x is for 'k'
                printf("Combination C(%d, %d) is %d\n", x, n, combination(x, n));
                break;
            case 13:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Decimal %d in binary is: ", n);
                Decimal2Binary(n);
                printf("\n");
                break;
            case 14:
                printf("Max element in the array is %d\n", findMax(arr, size));
                break;
            case 15:
                printf("Number of even elements in the array is %d\n", countEven(arr, size));
                break;
            case 16:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Product of %d and %d is %d\n", a, b, product(a, b));
                break;
            case 17:
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Max digit in %d is %d\n", n, findMaxDigit(n));
                break;
            case 18:
                index = findElement(arr, size, key);
                if (index != -1) {
                    printf("Key %d found at index %d\n", key, index);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 19:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Sum by expression for n=%d is %.2lf\n", n, sum(n));
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}