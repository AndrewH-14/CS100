#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

   char userStr[50];
   scanf("%s", userStr);
   int strLength = strlen(userStr);
   int i = 0;

   while (i < strLength) {
      if ((isdigit(userStr[i])) && (i == strLength - 1)) {
         printf("yes\n");   
      }
      else if ((isdigit(userStr[i]) == 0)) {
          printf("no\n");
      }
      ++i;
   }
   
   return 0;
}
