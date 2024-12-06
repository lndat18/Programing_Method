#include <stdio.h>


int sequentialSearch(int arr[],int size, int key){
    int position = -1;
    for (int i = 0; i < size; i++){
        if (arr[i] == key)
            position = i;
    }
    return position;
}


int binarySearch(int arr[], int size, int key){
    int low = 0, high = size-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (arr[mid] == key)    return mid;
        else if (key > arr[mid])    high = mid - 1;
        else    low = mid + 1;
    }

    return -1;
}


void selectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        int min_index = i;
        for (int j = i+1; j < size; j++){
            if (arr[min_index] < arr[j]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


void bubbleSort(int arr[], int size){
    for (int i = size - 2; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            if (arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int choice, key, result;
    int arr[] = {23, 45, 12, 56, 34, 78, 90, 3, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Sequential Search\n");
        printf("2. Binary Search\n");
        printf("3. Selection Sort\n");
        printf("4. Bubble Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = sequentialSearch(arr, size, key);
                if (result != -1)
                    printf("Key found at position %d\n", result);
                else
                    printf("Key not found\n");
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                selectionSort(arr, size);
                printf("Current Array: ");
                displayArray(arr, size);
                result = binarySearch(arr, size, key);
                if (result != -1)
                    printf("Key found at position %d\n", result);
                else
                    printf("Key not found\n");
                break;

            case 3:
                selectionSort(arr, size);
                printf("Array sorted using Selection Sort.\n");
                printf("Current Array: ");
                displayArray(arr, size);
                break;

            case 4:
                bubbleSort(arr, size);
                printf("Array sorted using Bubble Sort.\n");
                printf("Current Array: ");
                displayArray(arr, size);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}