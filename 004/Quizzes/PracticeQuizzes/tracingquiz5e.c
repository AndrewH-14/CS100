#include <stdio.h>
#include <string.h>
int main(void) {
 char str[10];
 int a, nums[5];
 scanf("%s", str);
 for (a=0; a<5; a++) {
 scanf("%d", &nums[a]);
 }
 for (a=0; a<5; a++) {
 printf("%c\n", str[ nums[a] ]);
 }
 return 0;
}