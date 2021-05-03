#include <stdio.h>

int main () {

    int grades[11] = { 0 };

    int size = 0;
    int grade;
    while (1) {
        scanf("%d", &grade);
        if (feof(stdin)) break;
        grades[grade]++;
    }

    for(int i = 0; i < 11; i++) {
        printf("The grade %d occurred %d times\n", i, grades[i]);
    }
    printf("\n");

    // int maxOccur = grades[0];
    int maxIndex = 0;
    for (int i = 1; i < 11; i++) {
        if (grades[i] > grades[maxIndex]) {
            // maxOccur = grades[i];
            maxIndex = i;
        }
    }

    printf("%d occured the most at %d times\n", maxIndex, grades[maxIndex]);

    return 0;
}