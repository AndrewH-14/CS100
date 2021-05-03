#include <stdio.h>
int main(void) {
 char word[10];
 scanf("%s", word);
 int nums[10];
 for (int a=1; a<=6; a++) {
 scanf("%d", &nums[a]);
 }
 for (int a=1; a<=5; a++) {
 printf("<%c>", word[nums[a]]);
 }
 printf("\n");
 for (int a=1; a<=3; a++) {
 nums[0]=nums[a];
 nums[a]=nums[a+3];
 nums[a+3]=nums[0];
 }
 for (int a=1; a<=5; a++) {
 printf("<%c>", word[nums[a]]);
 }
 printf("\n");
 return 0;
}