#include <stdio.h>
#include <stdlib.h>
void f(char *str, char *s1, char *s2, int z) {
int a = 0, b = 0;
while ( a < (z-1) ) {
 str[a] = s1[b];
 str[a+1] = s2[b];
a = a + 2;
b = b + 1;
 }
 str[z-1] = '\0';
 return;
}
int main(void) {
 char *s1 = malloc ( sizeof(char) * 7 );
 f(s1, "ABC", "XYZ", 7);
 printf("%s\n", s1);
 return 0;
}