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
 printf("%d\n", fOne(20, 6) );
 printf("%d\n", fOne(fOne(9,2), fOne(8,3)));
 int x;
 printf("%d\n", fTwo(5, 10, &x) );
 printf("%d\n", fTwo(10, 5, &x) );
 printf("%d\n", x);
 return 0;
}