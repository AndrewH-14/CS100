#include <stdio.h>
#include <string.h>
void fOne(char s[], int a, int b) {
 for (int z=a; z<=b; z++)
 printf("%c", s[z]);
 printf("\n");
 return;
}
int fTwo(char s[], char ch) {
 int x=0, y, z = strlen(s);
 for (y=0; y<z; y++)
 if ( s[y] == ch) x++;
 return x;
}
int main(void) {
 char str[10] = "ROLLTIDE";
 fOne(str, 0, 4);
 fOne(str, 3, 5);
 printf("%d\n", fTwo(str, 'L') );
 printf("%d\n", fTwo(str, 'T') );
 return 0;
}