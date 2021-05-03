#include <stdio.h>

int main() {

    int userInput;
    scanf("%d\n", &userInput);
    int max = userInput;
    int min = userInput;
while (!feof(stdin)) {
    scanf("%d\n", &userInput);
    if (userInput > max) {
        max = userInput;
    }
    else if (userInput < min) {
        min = userInput;
    }
}
printf("Range of input = %d", max - min);

    return 0;
}