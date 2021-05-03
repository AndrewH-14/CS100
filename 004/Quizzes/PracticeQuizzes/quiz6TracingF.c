#include <stdio.h>
void fOne(char s[], int a, int b) {
 char ch = s[a];
 s[a] = s[b];
 s[b] = ch;
 return;
}
void fTwo(int a, int b, int *c, int *d) {
 *c = a + b;
 *d = a * b;
 return;
}
int main(void) {
 char str[10] = "CRIMSON";
 fOne(str, 0, 3);
 printf("%s\n", str);
 fOne(str, 6, 4);
 printf("%s\n", str);
 int a=2, b=3, c, d, e, f;
 fTwo(a, b, &c, &d);
 printf("%d and %d\n", c, d);
 fTwo(c, d, &e, &f);
 printf("%d and %d\n", e, f);
 return 0;
}