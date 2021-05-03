#include <stdio.h>

int main() {

double hw1, hw2, hw3, q1, q2, q3, e1, e2, e3;
double hwavg, qavg, eavg;
double hwTotal, qTotal, eTotal;
double totalGrade;
printf("Enter homework grades: ");
scanf("%lf %lf %lf", &hw1, &hw2, &hw3);
printf("\n");
printf("Enter quiz grades: ");
scanf("%lf %lf %lf", &q1, &q2, &q3);
printf("\n");
printf("Enter exam grades: ");
scanf("%lf %lf %lf", &e1, &e2, &e3);
printf("\n");

//hwTotal = (hw1 + hw2 + hw3) * 0.1;
//qTotal = (q1 + q2 + q3) * 0.4;
hwavg = (hw1 + hw2 + hw3) / 3;
qavg = (q1 + q2 + q3) / 3;
eavg = (e1 + e2 + e3) / 3;

hwTotal = hwavg * 0.1;
qTotal = qavg * 0.4;
eTotal = eavg * 0.5;

totalGrade = hwTotal + qTotal + eTotal;
printf("Your grade: %.2lf ", totalGrade);

if (totalGrade >= 90) {
    printf("(A)");
}
else if (totalGrade >= 80) {
    printf("(B)");
}
else if (totalGrade >= 70) {
    printf("(C)");
}
else if (totalGrade >= 60) {
    printf("(D)");
}
else {
    printf("(F)");
}

    return 0;
}