#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.14

// 1
void Ex1(float x_a, float y_a, float x_b, float y_b){
    printf("--------------Ex1--------------------\n");
    double res = sqrt(pow((x_a - x_b),2) + pow((y_a - y_b),2));
    printf("distance between two points: %lf\n", res);
}

// 2
void Ex2(){
    printf("--------------Ex2--------------------\n");
    double perimeter, r;

    printf("enter perimeter: ");
    scanf("%lf", &perimeter);

    r = perimeter/(2*PI);
    double area = PI*r*r;
    printf("area of circle: %lf\n", area);
}

// 3
int isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

void Ex3(){
    printf("--------------Ex3--------------------\n");
    int day, month, year;

    printf("enter day: ");
    scanf("%d", &day);

    printf("enter month: ");
    scanf("%d", &month);

    printf("enter year: ");
    scanf("%d", &year);

    if (year <= 0){
        printf("invalid year\n");
        return;
    }
    if (month <= 0 && month > 12){
        printf("invalid year\n");
        return;
    }
    if (month == 2){
        if (isLeapYear(year)){
            if (day <= 0 && day > 29){
                printf("invalid day\n");
                return;
            }
        }else{
            if (day <= 0 && day > 28){
                printf("invalid day\n");
                return;
            }
        }
    }else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day <= 0 && day > 30){
                printf("invalid day\n");
                return;
        }
    }else{
        if (day <= 0 && day > 31){
                printf("invalid day\n");
                return;
        }
    }
    
    printf("valid information ^^\n");
}


//4
int isPalindrone(char str[], int size){
    int l = 0, r = size - 1;
    while (l <= r)
    {
        if (str[l] != str[r])   return 0;
        l++;
        r--;
    }
    return 1;
}

void Ex4(){
    printf("--------------Ex4--------------------\n");

    while (getchar() != '\n');

    char str[100];
    printf("enter your string: ");
    fgets(str, sizeof(str), stdin);
    int size = strlen(str);

    if (str[size - 1] == '\n'){
        str[size - 1] = '\0';
        size--;
    }

    int res = isPalindrone(str, size);
    printf("%d\n", res);
}


// 5
void Decimal2Binary(int n){
    if (n == 0)
        return;
    Decimal2Binary(n/2);
    printf("%d", n%2);
}

void Ex5(){
    printf("--------------Ex5--------------------\n");
    printf("enter n: ");
    int n;
    scanf("%d", &n);
    printf("Decimal to Binary: ");
    Decimal2Binary(n);
    printf("\n");
}

// 6
typedef struct
{
    int Student_id;
    char Name[30];
    float PPLT_score;
    float DSTT_score;
    float Math_score;
    float GPA;
    char academic_grading[20];
} SinhVien;

void findSV(SinhVien students[], int student_id){
    int isFound = 0;
    for(int i = 0; i < 9; i++){
        if(students[i].Student_id == student_id){
            printf("Student ID: %d\n", students[i].Student_id);
            printf("Name: %s\n", students[i].Name);
            printf("PPLT Score: %.1f\n", students[i].PPLT_score);
            printf("DSTT Score: %.1f\n", students[i].DSTT_score);
            printf("Math Score: %.1f\n", students[i].Math_score);
            printf("GPA: %.1f\n", students[i].GPA);
            printf("Academic Grading: %s\n\n", students[i].academic_grading);
            isFound = 1;
            break;
        }
    }
    if (isFound == 0)
        printf("not found student with student id %d\n", student_id);
}

void findLowestGpa(SinhVien students[]){
    SinhVien s;
    int min_gpa = students[0].GPA;
    for(int i = 1; i < 9; i++){
        if(students[i].GPA < min_gpa){
            min_gpa = students[i].GPA;
            s = students[i];
        }
    }

    printf("Student ID: %d\n", s.Student_id);
    printf("Name: %s\n", s.Name);
    printf("PPLT Score: %.1f\n", s.PPLT_score);
    printf("DSTT Score: %.1f\n", s.DSTT_score);
    printf("Math Score: %.1f\n", s.Math_score);
    printf("GPA: %.1f\n", s.GPA);
    printf("Academic Grading: %s\n\n", s.academic_grading);
}

void countGoodStudents(SinhVien students[]){
    int count = 0;
    for(int i = 0; i < 9; i++){
        if(strcmp(students[i].academic_grading, "Good") == 0 ||
            strcmp(students[i].academic_grading, "Excellent") == 0){
                count++;
        }
    }

    printf("Number of students with 'Good' or higher classification: %d\n", count);
}

void Ex6(){
    int student_id;
    printf("--------------Ex6--------------------\n");
    SinhVien students[9] = {
        {52200001, "Nguyen Thi Lan", 9.5, 9.0, 9.8, 9.4, "Excellent"},
        {52200002, "Tran Minh Tu", 7.8, 7.2, 8.5, 7.8, "Good"},
        {52200003, "Le Quang Hieu", 9.2, 8.8, 9.7, 9.2, "Excellent"},
        {52200004, "Nguyen Thi Lan", 6.8, 7.0, 7.5, 7.0, "Average"},
        {52200005, "Tran Minh Tu", 7.2, 6.9, 8.0, 7.4, "Good"},
        {52200006, "Le Quang Hieu", 9.1, 8.5, 9.6, 9.0, "Excellent"},
        {52200007, "Pham Minh Tu", 5.8, 6.2, 6.7, 6.0, "Weak"},
        {52200008, "Nguyen Hoang Nam", 8.1, 7.5, 9.2, 8.3, "Good"},
        {52200009, "Bui Thuy Linh", 6.0, 6.5, 6.7, 6.2, "Weak"}
    };

    printf("enter student id: ");
    scanf("%d", &student_id);
    printf("part a\n");
    findSV(students, student_id);

    printf("find student with lowest gpa\n");
    findLowestGpa(students);

    countGoodStudents(students);
}


// 7
long long factorial(int n){
    if(n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

void Ex7(){
    printf("--------------Ex7--------------------\n");
    printf("enter number n: ");
    int n;
    scanf("%d", &n);
    printf("%d! = %lld\n", n, factorial(n));
}

// 8
long long f(int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    return 2*f(n-1) + 3*f(n-2);
}

void Ex8(){
    printf("--------------Ex8--------------------\n");
    printf("enter number n: ");
    int n;
    scanf("%d", &n);
    printf("f(%d) = %lld\n", n, f(n));
}

//9
long long f_9(int n){
    if (n == 0)
        return 3;
    if (n == 1)
        return 5;
    return f_9(n-1) + 2*f_9(n-2);
}

void Ex9(){
    printf("--------------Ex9--------------------\n");
    printf("enter number n: ");
    int n;
    scanf("%d", &n);
    printf("f(%d) = %lld\n", n, f_9(n));
}

// 10
long long f_10(int n){
    if (n == 0)
        return 4;
    if (n == 1)
        return 7;
    return 4*f_10(n-1) - f_10(n-2);
}

void Ex10(){
    printf("--------------Ex10--------------------\n");
    printf("enter number n: ");
    int n;
    scanf("%d", &n);
    printf("f(%d) = %lld\n", n, f_10(n));
}


// 11
int isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return n > 1;
}

int sumPrime(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(isPrime(arr[i])){
            sum += arr[i];
        }
    }
    return sum;
}

void Ex11(){
    printf("--------------Ex11--------------------\n");
    int arr[] = {1,2,3,4,5,6,7,8,9,10}, size = 10;
    printf("Sum of all prime number in arr: %d\n", sumPrime(arr, size));
}

// 12
void selectionSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int min_index = i;
        for(int j = i+1; j < size; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Ex12(){
    printf("--------------Ex12--------------------\n");

    int arr1[10] = {12,7,19,25,3,8,15,42,30,11};
    int arr2[10] = {5,9,14,22,6,18,27,33,10,4};
    int size1 = 10, size2 = 10;

    printf("arr1 after being sorted by Selection Sort: ");
    selectionSort(arr1, size1);
    printArray(arr1, size1);

    printf("arr2 after being sorted by Bubble Sort: ");
    bubbleSort(arr2, size2);
    printArray(arr2, size2);
}


// 13
void Ex13(){
    printf("--------------Ex13--------------------\n");
    printf("enter second: ");

    int n, hour, minute;
    scanf("%d", &n);
    
    hour = n / 3600;
    n %= 3600;

    minute = n / 60;
    n %= 60;

    printf("hour: %d, minute: %d, second: %d\n", hour, minute, n);
}

// 14
int countDuplicate(int a[], int n, int k){
    int count = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == k)
            count++;
    }
    return count;
}

void Ex14(){
    printf("--------------Ex14--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11,12,19,3,1}, n = 14, k;
    printf("enter a key to count duplicates: ");
    scanf("%d", &k);

    int res = countDuplicate(a,n,k);
    if (res > 1){
        printf("%d has %d duplicate occurrences\n", k, res);
    }else{
        printf("there are no duplicate occurrence of %d\n", k);
    }
}


// 15
int search(int a[], int n, int k){
    selectionSort(a, n);
    int l = 0, r = n-1, m;
    int position = -1;
    while (l <= r)
    {
        m = (l+r)/2;
        if (a[m] == k){
            position = m;
            break;
        }else if (a[m] < k) l = m + 1;
        else    r = m - 1;
    }
    return position;    
}

void Ex15(){
    printf("--------------Ex15--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11}, n = 10, k;
    printf("enter a key to search: ");
    scanf("%d", &k);

    int res = search(a,n,k);
    if (res == -1){
        printf("%d does not contain in array\n", k);
    }else{
        printf("array after sorting: ");
        printArray(a, n);
        printf("The position of %d is %d\n", k, res);
    }

}

// 16
void Ex16(){
    printf("--------------Ex16--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11};
    int sumEven = 0;
    for(int i = 0; i < 10; i++){
        if(a[i] % 2 == 0){
            sumEven += a[i];
        }
    }
    printArray(a,10);
    printf("Sum of all even numbers in the array is %d\n", sumEven);
}

// 17
void Ex17(){
    printf("--------------Ex17--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11};
    int sumOdd = 0;
    for(int i = 0; i < 10; i++){
        if(a[i] % 2 != 0){
            sumOdd += a[i];
        }
    }
    printArray(a,10);
    printf("Sum of all odd numbers in the array is %d\n", sumOdd);
}

// 18
void Ex18(){
    printf("--------------Ex18--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11};
    int max = a[0];
    for(int i = 1; i < 10; i++){
        if(a[i] > max)
            max = a[i];
    }
    printArray(a,10);
    printf("The maximum number of the array is: %d\n", max);
}

//19
void Ex19(){
    printf("--------------Ex19--------------------\n");
    int a[] = {12,7,19,25,3,8,15,42,30,11};
    int min = a[0];
    for(int i = 1; i < 10; i++){
        if(a[i] < min)
            min = a[i];
    }
    printArray(a,10);
    printf("The minimum number of the array is: %d\n", min);
}

// 20
// Function to calculate the sum of (2i + 1) from i = 1 to n
int sum1(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (2 * i + 1);
    }
    return sum;
}

// Function to calculate the sum of (i! + 1) from i = 1 to n
int sum2(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (factorial(i) + 1);
    }
    return sum;
}

// Function to calculate the sum of (2i + 1) / i from i = 1 to n
float sum3(int n) {
    float sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (2.0 * i + 1) / i;
    }
    return sum;
}

void Ex20(){
    printf("--------------Ex20--------------------\n");
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Sum for a: %d\n", sum1(n));
    printf("Sum for b: %d\n", sum2(n));
    printf("Sum for c: %.2f\n", sum3(n));

}

int main(){
    Ex1(1,1,2,2);
    Ex2();
    Ex3();
    Ex4();
    Ex5();
    Ex6();
    Ex7();
    Ex8();
    Ex9();
    Ex11();
    Ex12();
    Ex13();
    Ex14();
    Ex15();
    Ex16();
    Ex17();
    Ex18();
    Ex19();
    Ex20();
}