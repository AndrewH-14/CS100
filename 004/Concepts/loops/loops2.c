#include <stdio.h>

int main() {
    
    int n;
    printf("Enter an integer:\n");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }

    printf("The summation from 0 to %d is %d\n", n, sum);


    for (int i = 0; i < 400; i += 4) {
        printf("%d\n", i);
    }

    return 0;
}