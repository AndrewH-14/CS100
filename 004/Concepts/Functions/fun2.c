#include <stdio.h>

// void functions don't return anything
void printStuff() {
    printf("Hello, my name is Maclane\n");
    //return; // optional return statement
}

void someOp(int, int);

int main(void) {
    int a, b;
    a = 1;
    b = 2;

    printf("a=%d, b=%d\n", a, b);
    someOp(a, b);
    printf("a=%d, b=%d\n", a, b); // unchanged after function

    return 0;
}

void someOp(int a, int b) {
    a += 2;
    b += 2;
    printf("x=%d, y=%d\n", a, b);
}