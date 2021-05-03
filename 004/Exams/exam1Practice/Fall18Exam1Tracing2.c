#include <stdio.h>
#include <string.h>
int main(void) {
 char str1[20], str2[20];
 scanf("%s%s", str1, str2);
 int a = strlen(str1);
 int b = strlen(str2);
 if (a<=b) {
 for (int i=0; i<a; i++)
 printf("%c%c", str2[i], str1[i]);
 printf("\n");
 for (int i=b-1; i>=a; i--)
 printf("%c", str2[i]);
 printf("\n");
 }
 else {
 for (int i=0; i<b; i++)
 printf("%c%c", str1[i], str2[i]);
 printf("\n");
 for (int i=a-1; i>=b; i--)
 printf("%c", str1[i]);
 printf("\n");
 }
 return 0;
}
