#include <stdio.h>

int main() {
    double grade;
    printf("Enter a grade:\n");
    scanf("%lf", &grade);

    if (grade < 0 || grade > 100) { //(!(grade >= 0) && (grade <= 100))
        printf("Grade out of range\n");

        return 0;
    }

    if (grade >= 70 && grade < 80) {
        printf("C\n");
    }
    else if (grade >= 80 && grade < 90)   {
        printf("B\n");
    }
    else if (grade >= 90)   {
        printf("A\n");
    }
    else   {
    printf("Failed\n"); 
    }
    return 0;
}