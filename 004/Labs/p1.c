#include <stdio.h>

int main() {

    // read distMiles from user
    //      prompt
    //      variable to put value
    //      read value
    printf("Enter the distance (in miles) to the city:\n");
    double distMiles;
    scanf("%lf", &distMiles);

    //printf("Read in %lf\n", distMiles);

    // do math
    double distInches = distMiles * 5280 * 12;
    double lenPackInches = 7 * 25;
    double numPack = distInches / lenPackInches;

    //output the answer
    printf("The number of Twizzler oackages to reach the city is %lf\n", numPack);

    return 0;
}