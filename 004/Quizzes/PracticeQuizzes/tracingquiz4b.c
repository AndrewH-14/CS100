#include <stdio.h>
int main(void) {
 int x = 0, y = 0, z = 0;
 while (1) {
    int num;
    scanf("%d", &num);
    if (num == 0) break;
    if (-5<=num && num<=5)
        y = y + 1;
     else
        z = z + 1;
    x = x + 1;
    printf("x=%d, y=%d, z=%d\n", x, y, z);
 }
 return 0;
}