#include <stdio.h>
int main(void) {
 int nums[10] = { 3,1,4,1,5,9,2,6,5,3 };
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