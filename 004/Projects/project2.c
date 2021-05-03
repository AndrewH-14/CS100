#include <stdio.h>

int main() {

    double userValue1, userValue2;
    int intValue1, intValue2;
    char operator;
    scanf("%lf %c %lf", &userValue1, &operator, &userValue2);
    intValue1 = (int)userValue1;
    intValue2 = (int)userValue2;

    if ((operator != '/') && (operator != '%') && (operator != '+') && (operator != '-') && (operator != '*')) {
        printf("Unknown operator\n");
    }   
    if  (operator == '+') {
        if((userValue1 != intValue1) || (userValue2 != intValue2)) {
            printf("%lf\n", userValue1 + userValue2);
            if (((userValue1 + userValue2) < -1000) || ((userValue1 + userValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
        else {
            printf("%d\n", intValue1 + intValue2);
            if (((intValue1 + intValue2) < -1000) || ((intValue1 + intValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
    }
    if (operator == '/') {
        if (userValue2 == 0) {
            printf("Cannot divide by zero\n");
        }
        else {
            printf("%lf\n", userValue1 / userValue2);
            
            if (((userValue1 / userValue2) < -1000) || ((userValue1 / userValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
    }
    if (operator == '%') {
        if ((userValue1 != intValue1) || (userValue2 != intValue2)) {
            printf("Modulo requires integers\n");
        }
        if ((intValue2 == 0) || (intValue2 == 0)) {
            printf("Modulo by zero\n");
        }
    
        else if ((userValue1 == intValue1) && (userValue2 == intValue2)) {
            printf("%d\n", intValue1 % intValue2);
            if (((intValue1 % intValue2) < -1000) || ((intValue1 % intValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
    }
    if (operator == '-') {
        if ((userValue1 != intValue1) || (userValue2 != intValue2)) {
            printf("%lf\n", userValue1 - userValue2);
                if (((userValue1 - userValue2) < -1000) || ((userValue1 - userValue2) > 1000)) {
                    printf("Large Number\n");
                }
        }
        else {
            printf("%d\n", intValue1 - intValue2);
            if (((intValue1 - intValue2) < -1000) || ((intValue1 - intValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
    }
    if (operator == '*') {
        if((userValue1 != intValue1) || (userValue2 != intValue2)) {
        printf("%lf\n", userValue1 * userValue2);
            if (((userValue1 * userValue2) < -1000) || ((userValue1 * userValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
        else {
            printf("%d\n", intValue1 * intValue2);
            if (((intValue1 * intValue2) < -1000) || ((intValue1 * intValue2) > 1000)) {
                printf("Large Number\n");
            }
        }
    }
   
    return 0;
}