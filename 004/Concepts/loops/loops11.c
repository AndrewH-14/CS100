#include <stdio.h>

int main () {

    // prompt
    // read in until 0
    // print num neg & pos

    printf("Enter a series of integers terminated by the number 0\n");

    int val;
    int pos = 0;
    int neg = 0;
    scanf("%d", &val); // init
    while (val != 0) { // test
        if (val > 0) {
            pos++;
        }
        else if (val < 0) {
            neg++;
        }

        scanf("%d", &val); // update
    }

    printf("You entered %d positives & %d negatives\n", pos, neg);

    return 0;
}