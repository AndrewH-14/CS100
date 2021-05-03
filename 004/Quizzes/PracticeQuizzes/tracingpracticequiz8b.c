#include <stdio.h>
#include <stdlib.h>
char *function(char ch, int len) {
 char *str = malloc(sizeof(char)*(len+1));
 char *ptr=str;
 for (int a=0; a<len; a++) {
 *ptr = ch+a;
 ptr++;
 }
 *ptr = '\0';
 return str;
}
int main(void) {
 char *s1=function('r', 5);
 printf("s1=%s\n", s1);
 char *s2=function('I', 3);
 printf("s2=%s\n", s2);
 free(s1); free(s2);
 return 0;
}