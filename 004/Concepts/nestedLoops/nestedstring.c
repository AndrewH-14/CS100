#include <stdio.h>

int main () {

    int max = -1;
    int min = 51;
    char buf[50];
    while (1) {
        scanf("%s", buf);
        if (feof(stdin)) break;

        int len = 0;
        while (1) {
            char ch = buf[len];
            if (ch == '/0') break;
            len++;
        }
        if (len > max) max = len;
        if (len < min) min = len;
    }

    printf("max=%d\nmin=%d\n", max, min);
    return 0;
}