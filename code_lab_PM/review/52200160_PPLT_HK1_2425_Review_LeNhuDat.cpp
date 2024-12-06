#include <stdio.h>
#include <math.h>

// Ex1 calculate the expression
double sum_a(int n){
    double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i/2.0;
    }
    return sum;
}

int sum_b(int n){
    int sum = 0;
    for(int i = 1; i <= n ; i++){
        sum += 2*i + 1;
    }
    return sum;
}

double sum_c(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (double)(i+1)/(i+2);
    }
    return sum;
}

long long factorial(int n){
    long long fac = 1;
    for(int i = 1; i <= n; i++){
        fac *= i;
    }
    return fac;
}

long long sum_d(int n){
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += factorial(i) + 1;
    }
    return sum;
}

long long product_e(int n){
    long long product = 1;
    for (int i = 1; i <= n; i++){
        product *= i;
    }
    return product;
}

long long product_f(int n){
    long long product = 1;
    for(int i = 1; i <= n; i++){
        product *= factorial(i);
    }
    return product;
}

double product_g(int n){
    double product = 1;
    for(int i = 1; i <= n; i++){
        product *= (2.0*i)/3;
    }
    return product;
}

double product_h(int n){
    double product = 1;
    for (int i = 1; i <= n; i++){
        product *= (double)(i-1)/(i+1);
    }
    return product;
}

// 2 check whether the number is palindrone or not
int isPalindrone(int n){
    int temp = n;
    int palin = 0;
    while (n != 0)
    {
        palin = 10*palin + n%10;
        n /= 10;
    }
    return palin == temp;
}

// 3 check whether the number is Prime or not
int isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

// 4 check whether the number is Armstrong or not
int isArmstrong(int n){
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

// 5 check whether the number is Perfect or not
int isPerfect(int n){
    int sum = 1;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n/i;
        }
    }

    return sum == n && n != 1;
}

// 6 print all Prime number between 1 -> n
void printPrime(int n){
    printf("All Prime number between 1 to n:");
    for(int i = 1; i <= n; i++){
        if (isPrime(i))
            printf("%d ", i);
    }
}

// 7 print all Armstrong number between 1 -> n
void printArmstrong(int n){
    printf("All Armstrong number between 1 to n:");
    for(int i = 1; i <= n; i++){
        if (isArmstrong(i))
            printf("%d ", i);
    }
}

// 8 print all Perfect number between 1 -> n
void printPerfect(int n){
    printf("All Perfect number between 1 to n:");
    for(int i = 1; i <= n; i++){
        if (isPerfect(i))
            printf("%d ", i);
    }
}

// 9 Convert Decimal to Binary
void Decimal2Binary(int n){
    if (n == 0)
        return;
    Decimal2Binary(n / 2);
    printf("%d", n % 2);
}

// 10 convert days into Years, Weeks, Days
void formatDate(int days){
    int years = days / 365;
    days = days % 365;
    int weeks = days / 7;
    days = days % 7;
    printf("years: %d, weeks: %d, days: %d", years, weeks, days);
}

// 11 find maximum number of an integer array
int findMax(int arr[10], int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// 12 find minimum number of an integer array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min)
           min = arr[i];
    }
    return min;
}

// 13 Sum all numbers of an integer array
int sumNumInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 14 Sum all non-positive numbers of an integer array
int sumNonPositiveInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            sum += arr[i];
    }
    return sum;
}

// 15 Sum all even numbers of an integer array
int sumEvenNumInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            sum += arr[i];
    }
    return sum;
}

// 16 Reverse an array without using any temporary array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArr(int arr[], int size) {
    int l = 0;
    int r = size - 1;
    while (l < r)
    {
        swap(&arr[l], &arr[r]);
        ++l;
        --r;
    }
}

// 17 delete an element from an array at specified position
void delElement(int arr[], int *n, int index){
    for(int i = index; i < *n - 1; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}

// 18 count total of number of duplicate elements in an array
int countDuplicate(int arr[], int size) {
    int *count = (int*)calloc(10000, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int res = 0;
    for (int i = 0; i < 10000; i++) {
        if (count[i] > 1)
            res++;
    }

    free(count);

    return res;
}

// 19 delete all duplicate elements from an array
void getIndexDuplicate(int arrSrc[], int arrDst[], int sizeSrc){
    int *count = (int*)calloc(10000, sizeof(int));

    for (int i = 0; i < sizeSrc; i++){
        count[arrSrc[i]]++;
    }
    
    for (int i = 0; i < sizeSrc; i++){
        if (count[arrSrc[i]] > 1){
            arrDst[i] = 1;
            count[arrSrc[i]] = 0;
        }
    }
    free(count);
}


void setZeroVal(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = 0;
    }
}


void delDupElement(int arr[], int *size){
    int arrDst[*size];
    setZeroVal(arrDst, *size);
    getIndexDuplicate(arr, arrDst, *size);
    
    for (int i = 0; i < *size; i++){
        if (arrDst[i] == 1){
            delElement(arr, size, i);
        }
    }
}

// 20 count frequency of each element in an array
void countFrequency(int arr[], int size){
    int *count = (int*)calloc(10000, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for(int i = 0; i < size; i++){
        if (count[arr[i]] != 0){
            printf("value: %d, frequency: %d\n", arr[i], count[arr[i]]);
            count[arr[i]] = 0;
        }
    }

    free(count);
}

// 21 merge two array to third array
void merge2Arr(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
    setZeroVal(arr3, n3);

    int i = 0, j = 0;

    for(i = 0; i < n1; i++){
        arr3[i] = arr1[i];
    }
    
    j = i;

    for(i = 0; i < n2; i++){
        arr3[j++] = arr2[i];
    }
}

// 22 put even and odd elements of array into two new seperate arrays
void separateEvenOdd(int arrSrc[], int arrEven[], int arrOdd[], int size, int *Esize, int *Osize){
    *Esize = 0;
    *Osize = 0;
    
    for (int i = 0; i < size; i++) {
        if (arrSrc[i] % 2 == 0) {
            arrEven[(*Esize)++] = arrSrc[i];
        } else {
            arrOdd[(*Osize)++] = arrSrc[i];
        }
    }
}

// 23 search an element in an array by providing key value
int searchElement(int arr[], int size, int key){
    int index = -1;
    for (int i = 0; i < size; i++){
        if (arr[i] == key)
            index = -1;
            break;
    }
    return index;
}

// 24 sort array element in ascending order
void selectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i+1; j < size; j++){
            if (arr[min] > arr[j])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// 25 add two matrices
void add2Matrix(int arr1[3][3], int arr2[3][3], int res[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// 26 subtract two matrices
void sub2Matrix(int arr1[3][3], int arr2[3][3], int res[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

// set zeros matrix
void zerosMatrix(int arr[3][3] ){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            arr[i][j] = 0;
        }
    }
}

// 27 multiply two matrix
void mul2Matrix(int arr1[3][3], int arr2[3][3], int res[3][3]){
    zerosMatrix(res);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

// 28 check whether two matrix are equal or not
int isEqual(int arr1[3][3], int arr2[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr1[i][j] != arr2[i][j])
                return 0;
        }
    }
    return 1;
}

// 29 find transpose of a matrix
void Tranpose(int arr[3][3], int res[3][3]){
    zerosMatrix(res);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            res[i][j] = arr[j][i];
        }
    }
}

// 30 find determinant of a matrix
int determinant(int matrix[3][3]) {
    int det = 1;
    int sign = 1;

    int temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination
    for (int i = 0; i < 3; i++) {
        // Search for maximum in this column
        int maxEl = abs(temp[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < 3; k++) {
            if (abs(temp[k][i]) > maxEl) {
                maxEl = abs(temp[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (row i)
        if (maxRow != i) {
            for (int k = 0; k < 3; k++) {
                int tmp = temp[maxRow][k];
                temp[maxRow][k] = temp[i][k];
                temp[i][k] = tmp;
            }
            sign = -sign; // Change the sign
        }

        // If the diagonal element is zero, the determinant is zero
        if (temp[i][i] == 0) {
            return 0;
        }

        // Eliminate all rows below this one
        for (int k = i + 1; k < 3; k++) {
            float factor = (float)temp[k][i] / temp[i][i];
            for (int j = i; j < 3; j++) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
    }

    // Calculate the determinant as the product of the diagonal elements
    for (int i = 0; i < 3; i++) {
        det *= temp[i][i];
    }

    // Adjust for the sign
    return sign * det;
}


int main(){
    // chỗ này em lười quá thầy ơi, tại em vướng mấy môn chuyên ngành ạ.
    // có gì thầy thông cảm và bỏ qua cho em với ạ. Em cảm ơn thầy
    return 0;
}