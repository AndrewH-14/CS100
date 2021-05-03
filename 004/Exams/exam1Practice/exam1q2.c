#include <stdio.h>

int main() {

int i = 0;
int x = 0;
int points;
printf("Enter maximum x: ");
scanf("%d", &x);

for (int i = 0; i <= x; i++) {
    if ((((i % 3) == 0) || (i % 2)) && (i > 5)) {
        points = points + 1;
    }
}
printf("%d points count", points);

    return 0;
}