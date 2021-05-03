#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// char * same as char []
void reverse(char *);
void reverse2(char []);

int main() {
    char *buf = malloc(sizeof(char) * 100);
    printf("Enter a string:\n");
    scanf("%s", buf);

    reverse(buf);
    //reverse2(buf);
    printf("%s\n", buf);

    return 0;
}

// array changes will be saved, pass by reference
// track left and right indices
void reverse(char *str) {
    int len = strlen(str);
    char tempLeft;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        // swap
        tempLeft = *(str + left);
        *(str + left) = *(str + right);
        *(str + right) = tempLeft;
        
        left++;
        right--;
    }
}

// calculate indices
void reverse2(char str[]) {
    int len = strlen(str);
    char tempLeft;
    for (int i = 0; i < len / 2; i++) { // stop at midpoint
        // swap
        tempLeft = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tempLeft;
    }
}