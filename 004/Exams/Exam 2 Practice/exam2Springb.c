#include <stdio.h>
#include <string.h>

int commonStart(char str1[], char str2[]);

int main(void) {
char str1[50], str2[50];

printf("Enter two strings : ");
scanf("%s %s", str1, str2);
printf("\nThere are %d common letters at start of %s and %s\n\n",
commonStart(str1, str2), str1, str2 );

return 0;
}

 int commonStart(char str1[], char str2[]) {

     int count = 0;
     for(int i = 0; i < strlen(str1); i++) {
         if(str1[i] == str2[i]) {
             count++;
         }
     }
     
    return count;
}