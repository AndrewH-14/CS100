#include <stdio.h>
int main(void) {
 int nums[10] = { 2,7,1,8,2,8,1,8,2,8 };
 int z = 0;
 for (int a=0; a<=8;a++)
 z = z + nums[a];
 printf("z is %d\n", z);
 int b=0, c=8;
 int d=0;
 while (b < c) {
 d += nums[b] + nums[c];
 b = b + 1;
 c = c - 1;
 }
 if (b==c) d = d + nums[b];
 printf("d is %d\n", d);
 return 0;
}