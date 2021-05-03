#include <stdio.h>

int main() {

int sh, eh, sm, em;
double milesWalked;
printf("Enter the start time:");
scanf("%d %d", &sh, &sm);
printf("Enter the end time:");
scanf("%d %d", &eh, &em);

milesWalked = ((eh - sh) + (em - sm) / 60.0) * 4;
printf("%lf", milesWalked);

    return 0;
}