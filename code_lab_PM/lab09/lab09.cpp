#include <stdio.h>
#include <string.h>


void Ex1(){
    const char *inputFile = "input01.txt";
    const char *outputFile = "output01.txt";

    FILE* infile = fopen(inputFile, "r");
    if(infile == NULL){
        printf("Error: Could not open %s for reading.\n", inputFile);
        return;
    }

    int sum = 0, number;
    while (fscanf(infile, "%d", &number) == 1)
    {
        sum += number;
    }

    fclose(infile);
    
    FILE* outfile = fopen(outputFile, "w");

    fprintf(outfile, "%d", sum);

    fclose(outfile);
    printf("Sum of numbers written to %s successfully.\n", outputFile);
}


void Ex2(){
    const char *inputFile = "input02.txt";
    const char *outputFile = "output02.txt";

    FILE* infile = fopen(inputFile, "r");
    if (infile == NULL) {
        printf("Error: Could not open %s for reading.\n", inputFile);
        return;
    }

    char str[100];

    FILE *outFile = fopen(outputFile, "w");

    while (fgets(str, sizeof(str), infile) != NULL)
    {
        // delete new line
        str[strcspn(str, "\n")] = '\0';
        
        int length = strlen(str);
        fprintf(outFile, "\"%s\" length: %d\n", str, length);
    }

    fclose(infile);
    fclose(outFile);
    printf("Lengths of strings written to %s successfully.\n", outputFile);
}


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


int linearSearch(int arr[], int size, int target){
    int position = -1;
    for(int i = 0; i < size; i++){
        if (arr[i] == target){
            position = i;
        }
    }
    return position;
}


int binarySearch(int arr[], int size, int target){
    int l = 0, r = size-1, position = -1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (arr[m] == target){
            position = m;
            break;
        }else if (target > arr[m]) l = m+1;
        else    r = m-1;
    }
    return position;    
}


void Ex3(){
    char filename[100];
    int data[100], size = 0, target;
    char choice;

    printf("enter a filename (input03.txt): ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if(filename == NULL){
        printf("Error: Could not open file '%s'.\n", filename);
        return;
    }

    while (fscanf(file, "%d", &data[size]) == 1) {
        size++;
        if (size >= 100) {
            printf("Error: File contains more than 100 integers.\n");
            fclose(file);
            return;
        }
    }
    fclose(file);

    if (size == 0){
        printf("Error: No valid data in file.\n");
        return;
    }

    printf("\nAvailable search algorithms:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Choose one of these search algorithms: ");
    scanf(" %c", &choice);

    if (choice != '1' && choice != '2') {
        printf("Invalid choice. Exiting.\n");
        return;
    }

    printf("Enter a value to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Error: Invalid input. Exiting.\n");
        return;
    }

    int result;
    if (choice == '1') {
        result = linearSearch(data, size, target);
    } else {
        // Sort data for binary search
        selectionSort(data, size);
        printf("Note: Data has been sorted for binary search.\n");
        result = binarySearch(data, size, target);
    }

    if (result != -1) {
        printf("Value %d found at position %d.\n", target, result);
    } else {
        printf("Value not found.\n");
    }
}


int main(){
    Ex1();
    Ex2();
    Ex3();
    return 0;
}