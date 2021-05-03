#include <stdio.h>
#include <string.h>

int main() {
char str[50];
int arr[26] = { 0 };
printf("Enter your input:\n");

while (!feof(stdin)) {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char C = str[i];
        int index = C - 'a';
        arr[index] = arr[index] + 1;
    }
}
int missing = 0;
//printf("Missing letters: ");
for (int i = 0; i < 26; i++) {
    if (arr[i] == 0) {
        // char m = arr[i] + 'a';
        // printf("%c", m);
        ++missing;
    }
}
if (missing == 0) {
    printf("Your input contains all the letters");
}
else {
    printf("Missing letters: ");
    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
        char m = i + 'a';
        printf("%c ", m);
        }
    }
}

return 0;
}