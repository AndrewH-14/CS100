#include <stdio.h>

int main() {

    int n;
    printf("Enter a number to see if it is prime:");
    scanf("%d", &n);
    int isPrime = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = 0;
            printf("%d is divisible by %d\n", n, i);
            break;
        }
    }

    if (isPrime && n != 1) {
        printf("Is a prime!\n");
    }
    else {
        printf("Not a prime!\n");
    }
    return 0;
}