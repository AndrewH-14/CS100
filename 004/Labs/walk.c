#include <stdio.h>

int main() {
    int sh, sm, eh, em;

    printf("Enter the start time:\n");
    scanf("%d %d", &sh, &sm);
    printf("Enter the end time:\n");
    scanf("%d %d", &eh, &em);

    double distance = ((eh-sh)+(em-sm) / 60.0) * 4.0;
    printf("You have walked %lf miles\n", distance);

    return 0;
}