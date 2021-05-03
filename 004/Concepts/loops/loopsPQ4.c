#include <stdio.h>
int main(void) {
 int a, b, x=0, y=0;
 for (a=0; a<5; a++) {
 scanf("%d", &b);
 if (b%5 == 0)
 x = x + b;
 else
 y = y + b;
 }
 printf("%d and %d\n", x, y);
 a = 1, b = 33;
 while (a < 4) {
 b = b / 2;
 printf("%d\n", b);
 a = a + 1;
 }
 return 0;
}