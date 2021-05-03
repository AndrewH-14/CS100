#include <stdio.h>

int main() {

    int x;
    int posVal = 0, smallVal = 0;
    printf("Enter integers, ending with ctrl-d\n");
    scanf("%d", &x);
    while (!feof(stdin)) {
        if ((x >= 1) && ((x % 5) == 0)) {
            posVal = posVal + 1;
        }
        if (x < 0 && x > -101) {
            smallVal = smallVal + 1;
        }
        scanf("%d", &x);
    }
    printf("%d postive multiples of 5\n", posVal);
    printf("%d small negative values\n", smallVal);

    return 0;
}