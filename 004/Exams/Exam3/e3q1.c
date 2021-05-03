#include <stdio.h>
#include <stdlib.h>

typedef struct _duration {
    int hours;
    int minutes;
} Duration;

Duration* subtract(Duration* d1, Duration* d2) {
    int totalMin1 = 0;
    int totalMin2 = 0;
    int minDiff = 0;
    totalMin1 = (d1->hours * 60) + d1->minutes;
    totalMin2 = (d2->hours * 60) + d2->minutes;

    Duration *d = (Duration*)malloc(sizeof(Duration));

    minDiff = totalMin1 - totalMin2;
    d->hours = minDiff / 60;
    d->minutes = minDiff % 60;

    return d;
}

// Example main. You only need to write 'subtract', but this is here to help you test.
int main() {
    Duration a = {5, 30}; // Struct shorthand for 5 hours, 30 minutes
    Duration b = {1, 55}; // Struct shorthand for 1 hour, 55 minutes

    Duration* d = subtract(&a, &b);

    printf("%d:%d\n", d->hours, d->minutes);
    
    // Expected output:
    // 3:35
}