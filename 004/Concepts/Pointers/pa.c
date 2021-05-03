#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowels(char *str);

int main(void) {

    // read in a string
    char buf[100];
    printf("Enter a string:\n");
    scanf("%s", buf);

    // call a function count the vowels
    int count = countVowels(buf);

    // print the answer
    printf("There are %d vowels in the string\n", count);

    return 0;
}

int countVowels(char *str) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) { // foreach character in str
        char curChar = tolower(*(str + i)); // str[i]
        if (curChar == 'a' || curChar == 'e' || curChar == 'i'
            || curChar == 'o' || curChar == 'u') {
            
            count++;
        }
    }

    return count;
}