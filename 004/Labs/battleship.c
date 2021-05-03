#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char *argv[]) {

    FILE *f1 = fopen(argv[1], "r");
    double dist;
    double angle; 
    fscanf(f1, "%lf", &dist);
    while(!feof(f1)) {

        angle = asin((dist * 9.8) / pow(70, 2)) / 2 * (180 / PI);
        printf("θ: %.2lf\n", angle);
        fscanf(f1, "%lf", &dist);
    }

    return 0;
}