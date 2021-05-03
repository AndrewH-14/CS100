#include <stdio.h>
int f1(int a, int b) {return a-b; }
int f2(int a, int b) {return a%b; }
int g(int a, int b) {
 if (a%2==0) return f1(a, b);
 else return f2(a, b);
}
int h(int a, int b) {
 while (a!=b)
 if (a>b)
 a=g(a, b);
 else
 b=g(b, a);
 return a;
}
void fuzz(int *a, int *b, int *c) {
 int t = *a + *b + *c;
 *a = t - *a;
 *b = t - *b;
 *c = t - *c;
}
int main(void) {
 printf("a=%d\n", h(14, 8));
 printf("b=%d\n", h(10, 25));
 int x=5, y=6, z=7;
 fuzz(&x, &y, &z);
 printf("x=%d, y=%d, z=%d\n", x, y, z);
 fuzz(&z, &y, &x);
 printf("x=%d, y=%d, z=%d\n", x, y, z);
 return 0;
}