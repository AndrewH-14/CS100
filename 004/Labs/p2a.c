#include <stdio.h>

int main() {

    int value1, value2;
    char a;
    scanf("%d %c %d", &value1, &a, &value2);
    
    if ((a != '/') && (a != '%') && (a != '+') && (a != '-')) {
        printf("Unkown operator\n");
    }   
    else if  (a == '+') {
            printf("%d\n", value1 + value2);
    }
    else if (a == '/') {
        if (value2 == 0) {
            printf("Cannot divide by zero\n");
        }
        else {
            printf("%d\n", value1 / value2);
        }
    }
    else if (a == '%') {
            printf("%d\n", value1 % value2);
    }
    else if (a == '-') {
        printf("%d\n", value1 - value2);
    }
    
    return 0;
}