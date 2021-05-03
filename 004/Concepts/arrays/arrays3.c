#include <stdio.h> 
#include <math.h>

int main() {

    // read in how many numbers
    int len;
    printf("How many numbers are being entered:\n");
    scanf("%d", &len);

    // read in N numbers
    printf("Enter %d numbers to do stats on:\n", len);
    int arr[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    // calculate the mean
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    double avg = (double)sum / len;
    printf("The average is %lf\n", avg);

    // calculate varience: sum ( (i - mean)^2 )
    double varience = 0;
    for (int i = 0; i < len; i++) {
        double diff = arr[i] - avg;
        varience += diff * diff;
    }
    varience /= len;
    printf("The varience is %lf\n", varience);

    // calculate std dev
    double stdDev = sqrt(varience);
    int stdDeviationRounded = round(stdDev);
    printf("The standard deviation is %d\n", stdDeviationRounded);

    return 0;
}