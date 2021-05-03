#include <stdio.h>
#include <string.h>

int sameWhenShifted(char *str1, char *str2) {
    //int count = 0;
    char Temp;
    int len = strlen(str1);
    char str[len];
    strcpy(str, str1);

    for (int i = 0; i < strlen(str1); i++) {
        if (strcmp(str, str2) == 0) {
            return i;
        }
        else {
            Temp = str[0];
            for (int j = 0; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
            str[len - 1] = Temp;
        }
        //printf("%s\n", str1);
    }
    return -1;
}


int main(int argc, char *argv[]) {
    char s1[100], s2[100];
    printf("Enter string 1 : ");
    scanf("%s", s1);
    printf("Enter string 2 : ");
    scanf("%s", s2);
    int ans = sameWhenShifted(s1, s2);
    if ( ans != -1 )
        printf("%s shifts %d to get %s\n", s1, ans, s2);
    else
        printf("Cannot build %s from %s\n", s2, s1);

 return 0;
}