#include<stdio.h>

int main(){
    int day;
    
    scanf("%d", &day);

    int years = day / 365;
    day %= 365;
    int weeks = day / 7;
    int days = day % 7;

    printf("years: %d, weeks: %d, days: %d", years, weeks, days);

    return 0;
}