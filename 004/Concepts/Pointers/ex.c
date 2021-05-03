#include <stdio.h>

void swapByValue(int x, int y) {
    int tempX = x;
    x = y;
    y = tempX;
}

void swapByRef(int *refX, int *refY) {
    int tempX = *refX;
    *refX = *refY;
    *refY = tempX;
}

int main() {

    int a = 1;
    int *pA = &a;
    int *q = pA;

    printf("a=%d, *pA=%d, *q=%d\n", a, *pA, *q);
    printf("&a=%p, pA=%p, q=%p\n", &a, pA, q);

    a = a + 2;
    printf("a=%d, *pA=%d, *q=%d\n", a, *pA, *q);
    printf("&a=%p, pA=%p, q=%p\n", &a, pA, q);

    *q = *q + 2;
    printf("a=%d, *pA=%d, *q=%d\n", a, *pA, *q);
    printf("&a=%p, pA=%p, q=%p\n", &a, pA, q);

    return 0;
}