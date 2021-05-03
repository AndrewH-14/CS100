#include <stdio.h>

int main() {

    int n, k;
    scanf("%d", &n);

    for (int a = n; a > 0; a--) {
        for (int b = n; b > a; b--) {
            printf(" ");
        }
        for (k = 0; k < a; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}