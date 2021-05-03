#include <stdio.h>

// signatures
int max3(int, int, int);

int main() {
    int x, y, z;
    printf("Enter three integers:\n");
    scanf("%d%d%d", &x, &y, &z);

    int m = max3(x, y, z);
    printf("The max is %d\n", m);

    return 0;
}

// definitions
int max3(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }

    return c;
}
