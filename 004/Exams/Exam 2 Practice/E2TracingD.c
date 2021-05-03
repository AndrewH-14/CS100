#include <stdio.h>
int fOne(int a, int b) {
 return (a / b) + (a % b);
}
int fTwo(int a, int b, int *c) {
 if (a > b)
 *c = a * b;
 else
 *c = a + b;
 return a - b;
}
int main(void) {
 printf("%d\n", fOne(16, 3) );
 printf("%d\n", fOne(fOne(9,3), fOne(4,3)));
 int x;
 printf("%d\n", fTwo(4, 8, &x) );
 printf("%d\n", fTwo(8, 4, &x) );
 printf("%d\n", x);
 return 0;
}
