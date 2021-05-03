#include <stdio.h>
#include <stdlib.h>
int print(char *ptr, int n) {
 for (int i=n; i>0; i=i/10)
 printf("(%c)", *(ptr+i%10));
 printf("\n");
}
int main(int argc, char **argv) {
 print(*(argv+1), atoi(*(argv+3)));
 print(*(argv+2), atoi(*(argv+4)));
 return 0;
}
