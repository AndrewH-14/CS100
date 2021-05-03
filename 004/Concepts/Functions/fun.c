#include <stdio.h>
#include <math.h>

// return_type name(param1, param2, ... paramN);
double dist(int, int, int, int); // signature

int main() {
    int p1x, p1y, p2x, p2y;
    printf("Enter point1 (x,y):\n");
    scanf("%d%d", &p1x, &p1y);
    printf("Enter point2 (x,y):\n");
    scanf("%d%d", &p2x, &p2y);

    double d = dist(p1x, p1y, p2x, p2y);
    printf("The distance is %lf\n", d);

    return 0;
}

// definition
double dist(int p1x, int p1y, int p2x, int p2y) {
    int diffX = p2x - p1x;
    int diffY = p2y - p1y;
    double dist = sqrt(diffX*diffX + diffY*diffY);

    return dist;
}