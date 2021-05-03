#include <stdio.h>
void f(int a[], int b) {
 int m=b/2;
 for (int i=0; i<m; i++)
 if (a[i]<a[m+i]) a[i]=a[m+i];
}
int main(void) {
 char str1[]="CRAZY", str2[]="BLANK";
 for (int a=0; a<5; a++) {
 for (int b=0; b<5; b++)
 if (a==b)
 printf("%c", str2[4-a]);
 else if (a+b==4)
 printf("%c", str1[a]);
 else
 printf("*");
 printf("\n");
 }
 int x[8]={17, 15, 16, 25, 18, 22, 19, 21};
 int c=8;
 while (c>1) {
 f(x, c);
 c=c/2;
 printf("(%d)", x[0]);
 }
 return 0;
}
