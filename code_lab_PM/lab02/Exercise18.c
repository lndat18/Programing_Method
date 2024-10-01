#include <stdio.h>

void decimalToBinary(int num) {
    if (num > 1) {
        decimalToBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int decimalNum;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    printf("Binary: ");
    if (decimalNum == 0) {
        printf("0\n");
    } else {
        decimalToBinary(decimalNum);
        printf("\n");
    }

    return 0;
}
