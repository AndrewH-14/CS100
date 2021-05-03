#include <stdio.h>

int main() {
    int x = 3, y = 4, z = 5;
    printf("%d and %p\n", x, &x);
    printf("%d and %p\n", y, &y);
    printf("%d and %p\n", z, &z);
    int *a, *b, *c;
    a = &x;
    b = &y;
    c = &z;
    printf("x=%d, &x=%p, a=%p, *a=%d\n", x, &x, a, *a);
    printf("y=%d, &y=%p, b=%p, *b=%d\n", y, &y, b, *b);
    printf("z=%d, &z=%p, c=%p, *c=%d\n", z, &z, c, *c);

    return 0;
}