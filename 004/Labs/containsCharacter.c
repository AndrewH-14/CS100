#include <stdio.h>
#include <string.h>

int main(void) {

   int numWords;
   char words[20][10];
   char searchCharacter;
   scanf("%d", &numWords);

   for (int i = 0; i < numWords; i++) {
       scanf("%s", words[i]);
   }
   scanf(" %c", &searchCharacter);
   
   for (int i = 0; i < numWords; i++) {
       if (strchr(words[i], searchCharacter)) {
       printf("%s\n", words[i]);
        }
   }

   return 0;
}