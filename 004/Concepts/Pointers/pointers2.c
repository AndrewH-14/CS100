#include <stdio.h>

int main() {
	int x[3] = { 101, 234, 999 };
	int *p1, *p2;
	p1 = x;
	p2 = x + 2;
	printf("%d and %d and %d\n", x[0], x[1], x[2]);
	printf("%p and %p\n", x, &x[0]);
	printf("%d - %p | %d - %p\n", x[0], &x[0], *p1, p1);
	printf("%d - %p | %d - %p\n", x[1], &x[1], *(x+1), x+1);
	printf("%d - %p | %d - %p\n", x[2], &x[2], *p2, p2);

    return 0;
}