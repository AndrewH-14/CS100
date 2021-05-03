#include <stdio.h>
#include <math.h>

int numSqr(int num);
void printNum(int numSqr);

int main() {
    int num;
    printf("Enter number to be squared: ");
    scanf("%d", &num);
    printNum(numSqr(num));

    return 0;
}

int numSqr(int num) {
    return pow(num, 2);
}

void printNum(int num) {
    printf("The number squared is %d.\n", num);
}