#include <stdio.h>

int fact(int n) {
    if (n == 0) { // base case
        return 1;
    }
    return n * fact(n - 1); // recursive case
}

int main() {

int f;
printf("Enter an integer to compute the factorial:\n");
scanf("%d", &f);

printf("!%d = %d\n", f, fact(f));

    return 0;
}