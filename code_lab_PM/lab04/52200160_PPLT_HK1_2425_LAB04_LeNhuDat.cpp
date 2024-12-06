#include <stdio.h>
#include <stdlib.h>

// print
void printArr(int arr[], int size){

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// print matrix
void printMatrix(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// set 0-value to array
void setZeroVal(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = 0;
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

// 1
float Ex1_a(int n) {
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i / 2.0;
    }
    return sum;
}


long long Ex1_b(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 2*i + 1;
    }
    return sum;
}


long long factorial(int n) {
    long long fac = 1;
    for (int i = 1; i <= n;i++) {
        fac *= i;
    }
    return fac;
}

long long Ex1_c(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i) + 1;
    }
    return sum;
}

long long Ex1_d(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= factorial(i);
    }
    return res;
}


double Ex1_e(int n) {
    double res = 1;
    for (int i = 1; i <= n; i++) {
        res *= (2 * i) / 3.0;
    }
    return res;
}

// 2
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// 3
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min)
           min = arr[i];
    }
    return min;
}

// 4
int sumNumInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 5
int sumNonPositiveInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            sum += arr[i];
    }
    return sum;
}

// 6
int sumEvenNumInArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            sum += arr[i];
    }
    return sum;
}

// 7
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

// 8
void delElement(int arr[], int *n, int index){
    for(int i = index; i < *n - 1; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}

// 9
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

// 10
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

// 11
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

// 12
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

// 13
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

// 14
int searchElement(int arr[], int size, int key){
    int index = -1;
    for (int i = 0; i < size; i++){
        if (arr[i] == key)
            index = -1;
            break;
    }
    return index;
}

// 15
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

// 16
void add2Matrix(int arr1[3][3], int arr2[3][3], int res[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// 17
void sub2Matrix(int arr1[3][3], int arr2[3][3], int res[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

// 18
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

// 19
int isEqual(int arr1[3][3], int arr2[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr1[i][j] != arr2[i][j])
                return 0;
        }
    }
    return 1;
}

// 20
void Tranpose(int arr[3][3], int res[3][3]){
    zerosMatrix(res);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            res[i][j] = arr[j][i];
        }
    }
}

// 21
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

void inputMatrix(int arr[3][3]){
    printf("Enter 3x3 matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}


void inputArr(int arr[], int size){
    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}


int main() {
int choice;
    int matrix[3][3], res[3][3];
    int size;
    int arr[100]; // Example array to perform operations
    int arrEven[100], arrOdd[100], Esize, Osize;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Perform Ex1_a to Ex1_e (n = 10)\n");
        printf("2. Find Max in Array\n");
        printf("3. Find Min in Array\n");
        printf("4. Sum of Numbers in Array\n");
        printf("5. Sum of Non-Positive Numbers in Array\n");
        printf("6. Sum of Even Numbers in Array\n");
        printf("7. Reverse Array\n");
        printf("8. Delete Element from Array\n");
        printf("9. Count Duplicates in Array\n");
        printf("10. Delete Duplicates from Array\n");
        printf("11. Count Frequency of Elements in Array\n");
        printf("12. Merge Two Arrays\n");
        printf("13. Separate Even and Odd Numbers\n");
        printf("14. Search for Element in Array\n");
        printf("15. Sort Array using Selection Sort\n");
        printf("16. Add Two 3x3 Matrices\n");
        printf("17. Subtract Two 3x3 Matrices\n");
        printf("18. Multiply Two 3x3 Matrices\n");
        printf("19. check two 3x3 Matrix is equal or not\n");
        printf("20. Transpose a 3x3 Matrix\n");
        printf("21. Determinant Matrix (3x3)\n");
        printf("22. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Ex1_a: %.2f\n", Ex1_a(10));
                printf("Ex1_b: %lld\n", Ex1_b(10));
                printf("Ex1_c: %lld\n", Ex1_c(10));
                printf("Ex1_d: %lld\n", Ex1_d(10));
                printf("Ex1_e: %.2f\n", Ex1_e(10));
                break;
            }
            case 2: {
                inputArr(arr, size);
                printf("Max: %d\n", findMax(arr, size));
                break;
            }
            case 3: {
                inputArr(arr, size);
                printf("Min: %d\n", findMin(arr, size));
                break;
            }
            case 4: {
                inputArr(arr, size);
                printf("Sum: %d\n", sumNumInArr(arr, size));
                break;
            }
            case 5: {
                inputArr(arr, size);
                printf("Sum of Non-Positive Numbers: %d\n", sumNonPositiveInArr(arr, size));
                break;
            }
            case 6: {
                inputArr(arr, size);
                printf("Sum of Even Numbers: %d\n", sumEvenNumInArr(arr, size));
                break;
            }
            case 7: {
                inputArr(arr, size);
                reverseArr(arr, size);
                printf("Reversed Array: ");
                printArr(arr, size);
                break;
            }
            case 8: {
                inputArr(arr, size);
                int index;
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delElement(arr, &size, index);
                printf("Array after deletion: ");
                printArr(arr, size);
                break;
            }
            case 9: {
                inputArr(arr, size);
                printf("Count of Duplicates: %d\n", countDuplicate(arr, size));
                break;
            }
            case 10: {
                inputArr(arr, size);
                delDupElement(arr, &size);
                printf("Array after deletion of duplicates: ");
                printArr(arr, size);
                break;
            }
            case 11: {
                inputArr(arr, size);
                countFrequency(arr, size);
                break;
            }
            case 12: {
                int arr2[100], arr3[200];
                int n1, n2;
                
                inputArr(arr, n1);
                inputArr(arr2, n2);

                merge2Arr(arr, arr2, arr3, n1, n2, n1 + n2);
                printf("Merged Array: ");
                printArr(arr3, n1 + n2);
                break;
            }
            case 13: {
                inputArr(arr, size);
                separateEvenOdd(arr, arrEven, arrOdd, size, &Esize, &Osize);
                printf("Even Numbers: ");
                printArr(arrEven, Esize);
                printf("Odd Numbers: ");
                printArr(arrOdd, Osize);
                break;
            }
            case 14: {
                inputArr(arr, size);
                int key;
                printf("Enter element to search: ");
                scanf("%d", &key);
                int index = searchElement(arr, size, key);
                if (index != -1) {
                    printf("Element found at index: %d\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 15: {
                inputArr(arr, size);
                selectionSort(arr, size);
                printf("Sorted Array: ");
                printArr(arr, size);
                break;
            }
            case 16: {
                inputMatrix(matrix);
                int matrix2[3][3];
                inputMatrix(matrix2);
                add2Matrix(matrix, matrix2, res);
                printf("Resultant Matrix after Addition:\n");
                printMatrix(res);
                break;
            }
            case 17: {
                inputMatrix(matrix);
                int matrix2[3][3];
                inputMatrix(matrix2);
                sub2Matrix(matrix, matrix2, res);
                printf("Resultant Matrix after Subtraction:\n");
                printMatrix(res);
                break;
            }
            case 18: {
                inputMatrix(matrix);
                int matrix2[3][3];
                inputMatrix(matrix2);
                mul2Matrix(matrix, matrix2, res);
                printf("Resultant Matrix after Multiplication:\n");
                printMatrix(res);
                break;
            }
            case 19: {
                inputMatrix(matrix);
                int matrix2[3][3];
                inputMatrix(matrix2);
                if (isEqual(matrix, matrix2))
                    printf("2 matrices is equal");
                else 
                    printf("2 matrices is not equal.");
                break;
            }
            case 20: {
                inputMatrix(matrix);
                int transposed[3][3];
                Tranpose(matrix, transposed);
                printf("Transposed Matrix:\n");
                printMatrix(transposed);
                break;
            }
            case 21: {
                inputMatrix(matrix);
                int det = determinant(matrix);
                printf("Determinant: %d\n", det);
                break;
            }
            case 22:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}