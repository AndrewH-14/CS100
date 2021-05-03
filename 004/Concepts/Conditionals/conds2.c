#include <stdio.h>

int main() {

    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);

    if (num % 2)
        printf("%d is odd\n", num);
    else
        printf("%d is even\n", num);

    printf("%d = %d and %d\n", num, num / 10, num % 10);

    return 0;
    
}