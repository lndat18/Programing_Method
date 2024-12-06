#include <stdio.h>
#include <math.h>

#define PI 3.14


float Ex1(float x_a, float y_a, float x_b, float y_b){
    return sqrt(pow((x_a - x_b),2) + pow((y_a - y_b),2));
}


void Ex2(){
    printf("enter perimeter: ");
    double perimeter, r;
    scanf("%lld", &perimeter);
    r = perimeter/(2*PI);
    double area = PI*r*r;
    printf("area of circle: %lld", area);
}


int main(){
    
}