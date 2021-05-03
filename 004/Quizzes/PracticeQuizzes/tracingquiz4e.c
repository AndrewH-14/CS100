#include <stdio.h>
int main(void) {
 int num, x = 0, y = 1;
 scanf("%d", &num);
 while ( num != 0 ) {
    if ( (num>25) || (num<-25) )
        x = x + 1;
    if ( num > 0 )
        y = y * 2;
    scanf("%d", &num);
 }
 printf("%d and %d and %d\n", num, x, y);
 return 0;
}