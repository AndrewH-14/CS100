#include <stdio.h>
void f(int a[], int b) {
 int m=b/2;
 for (int i=0; i<m; i++)
 if (a[i]<a[m+i]) a[i]=a[m+i];
}
int main(void) {
 char str1[]="QUICK", str2[]="TWINS";
 for (int a=0; a<5; a++) {
 for (int b=0; b<5; b++)
 if (a==b)
 printf("%c", str2[4-a]);
 else if (a+b==4)
 printf("%c", str1[a]);
 else
 printf("-");
 printf("\n");
 }
 int x[8]={42, 40, 41, 50, 43, 47, 44, 46};
 int c=8;
 while (c>1) {
 f(x, c);
 c=c/2;
 printf("(%d)", x[0]);
 }
 return 0;
}