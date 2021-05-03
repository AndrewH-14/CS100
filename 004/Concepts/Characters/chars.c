#include <stdio.h>
#include <ctype.h>

int main() {

    char ch = 'A';
    // scanf("%c", &ch); reads whitespace
    scanf(" %c", &ch); // skips whitespace
    printf("You entered '%c'\n", ch);

    char a = 'I', b = 'B', c = 'M';
    printf("%c %c %c\n", a, b, c);
    printf("%d %d %d\n", a, b, c);
    printf("%c %c %c\n", a - 1, b + 1, c + 32);

    if (isupper(ch)) {
        printf("%c is an uppercase char\n", ch);
        char l = tolower(ch);
        printf("%c lowered\n", l);

    }


return 0;
}