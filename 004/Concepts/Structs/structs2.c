#include <stdio.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
} Point;

double dist(Point pt1, Point pt2);

int main() {
    struct point pt1;
    Point pt2;
    printf("Enter point1 (x,y):\n");
    scanf("%d%d", &pt1.x, &pt1.y);
    printf("Enter point2 (x,y):\n");
    scanf("%d%d", &pt2.x, &pt2.y);

    double d = dist(pt1, pt2);
    printf("The distance is %lf\n", d);

    return 0;
}

double dist(Point pt1, Point pt2) {
    int diffX = pt2.x - pt1.x;
    int diffY = pt2.y - pt1.y;
    double dist = sqrt(diffX*diffX + diffY*diffY);

    return dist;
}