#include <stdio.h>

int main() {
int integer, intSum = 0;
scanf("%d", &integer);

while(integer != 0) {
    intSum = intSum + (integer % 10);
    integer = integer / 10;
}
printf("The digit sum is %d", intSum);


    return 0;
}