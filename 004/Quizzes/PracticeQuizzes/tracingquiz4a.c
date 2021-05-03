#include <stdio.h>
#include <string.h>
int main(void) {
 char word[]="ERASE";
 int n=strlen(word)-1;
 for (int a=0; a<=n; a++) {
    for (int b=0; b<=n; b++) {
        if ( a == 0 )
            printf("%c", word[n-b]);
        else if ( b == 0 )
            printf("%c", word[a]);
        else if ( a == n)
            printf("%c", word[n-b]);
        else if ( b == n)
            printf("%c", word[a]);
        else
            printf("-");
    }
    printf("\n");
 }
 return 0;
}