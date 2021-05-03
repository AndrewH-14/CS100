#include <stdio.h>
#include <string.h>
int main(void) {
 int a, b;
 char s1[20], s2[20];
 scanf("%s%s", s1, s2);
 b = strlen(s1);
 for (a=0; a<b; a=a+1)
 if (s1[a]!='a')
 printf("%c", s1[a]);
 printf("\n");
 a = strlen(s2)-1;
 while (a>=0) {
 printf("%c", s2[a]);
 a = a - 2;
 }
 printf("\n");
 return 0;
}