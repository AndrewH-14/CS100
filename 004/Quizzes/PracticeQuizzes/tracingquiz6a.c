#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
 int a = atoi(argv[2]);
 int b = atoi(argv[3]);
int c = atoi(argv[4]);
 for (int i=a; i<=b; i=i+c)
 printf("%c", argv[1][i]);
printf("\n");
 for (int i=b; i>=a; i=i-c)
 printf("%c", argv[1][i]);
printf("\n");
 return 0;
}