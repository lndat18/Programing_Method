#include <stdio.h>

int main() {
    float physics, chemistry, biology, mathematics, computer;
    float total, percentage;
    char grade;

    // Nhập điểm của năm môn học
    printf("Nhập điểm môn Vật lý: ");
    scanf("%f", &physics);
    printf("Nhập điểm môn Hóa học: ");
    scanf("%f", &chemistry);
    printf("Nhập điểm môn Sinh học: ");
    scanf("%f", &biology);
    printf("Nhập điểm môn Toán học: ");
    scanf("%f", &mathematics);
    printf("Nhập điểm môn Tin học: ");
    scanf("%f", &computer);

    // Tính tổng điểm và tỷ lệ phần trăm
    total = physics + chemistry + biology + mathematics + computer;
    percentage = (total / 500) * 100;

    // Xác định xếp hạng dựa trên tỷ lệ phần trăm
    if (percentage > 90) {
        grade = 'A';
    } else if (percentage > 80) {
        grade = 'B';
    } else if (percentage > 70) {
        grade = 'C';
    } else if (percentage > 60) {
        grade = 'D';
    } else if (percentage > 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    // In ra tỷ lệ phần trăm và xếp hạng
    printf("Percentage: %.2f\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}
