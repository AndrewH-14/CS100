#include <stdio.h>
#include <string.h>
int main(void) {
 int a, b;
 char str[10] = "TIDE";
 int x = strlen(str) - 1;
 for (a=0; a<4; a++) {
 for (b=0; b<4; b++) {
 if (a==0) printf("%c", str[b]);
 else if (b==0) printf("%c", str[a]);
 else if (b==x) printf("%c", str[x-a]);
 else if (a==x) printf("%c", str[x-b]);
 else printf(" ");
 }
 printf("\n");
 }
 return 0;
}