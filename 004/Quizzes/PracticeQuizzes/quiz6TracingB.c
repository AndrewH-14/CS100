#include <stdio.h>
void f1(int a) { a = a + 10; return; }
void f2(int *a) { *a = *a + 10; return; }
void f3(int *a, int *b) {
 int t1 = *a / *b;
 int t2 = *a % *b;
 *a = t1;
 *b = t2;
 return;
}
int main(void) {
 int x = 3, y=14, z=4;
 f1(x);
 printf("%d\n", x);
 f2(&x);
 printf("%d\n", x);
 f2(&x);
 printf("%d\n", x);
 f3(&y, &z);
 printf("%d and %d\n", y, z);
 f3(&y, &z);
 printf("%d and %d\n", y, z);
 return 0;
}