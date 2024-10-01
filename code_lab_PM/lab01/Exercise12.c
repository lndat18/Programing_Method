#include<stdio.h>

int main(){
    double angle1, angle2, angle3;
    scanf("%lf %lf %lf", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 == 180)
    {
        printf("valid");
    }else{
        printf("is not valid");
    }
    
    return 0;
}