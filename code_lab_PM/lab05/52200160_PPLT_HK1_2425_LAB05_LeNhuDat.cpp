#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100


void inputString(char str[]){
    printf("Enter a string: ");
    fgets(str, 100, stdin);
}

int lenWithNoNewLine(char* str){
    if (str[0] == '\0')
        return 0;
    int len = 0;
    while (str[len] != '\0')
    {
        len += 1;
    }

    return len;
}

// 1
int strlen(char str[]){
    if (str[0] == '\0')
        return 0;
    int len = 0;
    while (str[len] != '\0')
    {
        len += 1;
    }

    return len - 1;
}

// 2
void printReverseOrder(char str[]){
    for (int i = strlen(str) - 1; i >= 0; i--){
        printf("%c", str[i]);
    }
}


// 3 print first name and last name
void firstName(char* str){
    char fname[SIZE];
    for (int i = 0; i < strlen(str); i++){
        if (isalnum(str[i])){
            fname[i] = str[i];
        }else{
            fname[i] = '\0';
        }
    }

    printf("%s\n", fname);
}


void reverse(char* str){
    int i = 0, j = strlen(str);
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;j--;
    }
}


void lastName(char* str){
    char lname[SIZE];
    int i = strlen(str) - 1, j = 0;
    while (i >= 0 && isalnum(str[i]))
    {
        lname[j] = str[i];
        i--;j++;
    }
    lname[j] = '\0';
    reverse(lname);

    printf("%s\n", lname);
}

//4 normalize string
void shiftLeft(char* str, int* n){
    for (int i = 0; i < *n-1; i++){
        str[i] = str[i+1];
    }
    *n -= 1;
}


void shiftAtIndex(char* str, int* n, int index){
    for (int i = index; i < *n - 1; i++){
        str[i] = str[i + 1];
    }
    *n -= 1;
}


void trimBefore(char* str, int* n){
    while (*n > 0 && str[0] == ' ') {
        shiftLeft(str, n);
    }
}

void trimInside(char* str, int* n){
    int i = 0;
    while (i < *n) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            shiftAtIndex(str, n, i);
        } else {
            i++;
        }
    }
}

void trimAfter(char* str, int* n){
    while (*n > 0 && str[*n - 1] == ' ') {
        *n -= 1;      
    }
    str[*n] = '\0';
}


void normalize(char* str, int* n){
    trimBefore(str, n);
    trimInside(str, n);
    trimAfter(str, n);

    int isFirst = 1;
    for (int i = 0; i < *n; i++){
        if (isFirst && isalpha(str[i])){
            str[i] = toupper(str[i]);
            isFirst = 0;
        }else{
            str[i] = tolower(str[i]);
            if (str[i] == ' ') {
                isFirst = 1;
            }
        }
    }
}


// 5
void concatenate(char* s1, const char* s2) {
    // Tìm đến cuối chuỗi s1
    while (*s1 != '\0') {
        s1++;
    }

    // Sao chép s2 vào cuối s1
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }

    // Thêm ký tự kết thúc '\0' vào cuối chuỗi
    *s1 = '\0';
}

// 6
int isAppears(char* str,int *n, char k){
    int isFound = -1;
    for (int i = 0; i < *n; i++){
        if (str[i] == k){
            isFound = 1;
            break;
        }
    }
    return isFound;
}

// 7 

void findCharacterPositions(const char* str, char ch) {
    int found = 0;
    printf("Positions of '%c' in the string: ", ch);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            printf("%d ", i); 
            found = 1;
        }
    }
    if (!found) {
        printf("Character '%c' not found in the string.", ch);
    }
    printf("\n");
}

// 8
int findWordPosition(const char *str, const char *word) {
    const char *pos = strstr(str, word);
    if (pos != NULL) {
        return pos - str; 
    }
    return -1; 
}

// 9
int findSubstringPosition(const char *s1, const char *s2) {
    const char *pos = strstr(s1, s2);
    if (pos != NULL) {
        return pos - s1; 
    }
    return -1;
}

// 10
void insertString(char *s1, const char *s2, int position) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (position < 0 || position > len1) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = len1; i >= position; i--) {
        s1[i + len2] = s1[i]; 
    }

    for (int i = 0; i < len2; i++) {
        s1[position + i] = s2[i]; 
    }

    s1[len1 + len2] = '\0'; 
}

// 11
void deleteCharacters(char *str, int position, int n) {
    int len = strlen(str);

    if (position < 0 || position >= len) {
        printf("Invalid position.\n");
        return;
    }

    if (position + n > len) {
        n = len - position;
    }

    for (int i = position; i < len - n; i++) {
        str[i] = str[i + n]; 
    }
    str[len - n] = '\0';
}

int main(){
    char str[SIZE];
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Input String and return string length\n");
        printf("2. Print Reverse Order\n");
        printf("3. Print first name, last name\n");
        printf("4. Print normalize string\n");
        printf("5. Concatenate Strings\n");
        printf("6. First position of character\n");
        printf("7. All appearing Positions\n");
        printf("8. First position of a string\n");
        printf("9. First position s2 appears in s1\n");
        printf("10. Insert s2 to s1\n");
        printf("11. Delete n character from position\n");
        printf("12. Exiting\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự newline còn lại trong bộ đệm

        switch (choice) {
            case 1:{
                inputString(str);
                printf("%d\n", strlen(str));
                break;
            }
            case 2:{
                inputString(str);
                printReverseOrder(str);
                break;
            }
            case 3:{
                inputString(str);
                firstName(str);
                lastName(str);
                break;
            }
            case 4:{
                char str[SIZE] = " PrOgRaMmInG MeThOd ";
                int n = lenWithNoNewLine(str);
                normalize(str, &n);
                break;
            }
            case 5:{
                char str2[SIZE];
                inputString(str);
                inputString(str2);
                concatenate(str, str2);
                printf("%s\n", str);
                break;
            }
            case 6: {   
                inputString(str);
                int n = strlen(str);
                char k = getchar();
                printf("%d\n", isAppears(str, &n, k));
                break;
            }
            case 7: {
                char ch;
                ch = getchar();
                printf("Enter character to find: ");
                findCharacterPositions(str, ch);
                break;
            }
            case 8: {
                inputString(str);
                char str2[SIZE];
                inputString(str2);
                printf("%d\n",findWordPosition(str, str2));
                break;
            }
            case 9: {
                inputString(str);
                char str2[SIZE];
                inputString(str2);
                printf("%d\n",findSubstringPosition(str, str2));
                break;
            }
            case 10:{
                inputString(str);
                char str2[SIZE];
                inputString(str2);
                int position;
                scanf("%d", &position);
                getchar();
                insertString(str, str2, position);
                printf("%s\n", str);
                break;
                
            }
            case 11:{
                inputString(str);
                int n, position;
                printf("Enter number and position");
                scanf("%d%d", &n, &position);
                getchar();
                deleteCharacters(str, position, n);
                printf("%s", str);
                break;
            }
            case 12:{
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}