#include<stdio.h>

int main(){
    char ch;
    int isAlphanumeric = 0;

    scanf("%c", &ch);

    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        isAlphanumeric = 1;
    }

    if (isAlphanumeric) {
        printf("'%c' is alphanumeric.\n", ch);
    } else {
        printf("'%c' is not alphanumeric.\n", ch);
    }
    
    return 0;
}