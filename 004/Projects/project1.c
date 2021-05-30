#include <stdio.h>
#include <math.h>

// To run in LINUX run gcc project1.c -lm

int main () {
    int numCups;
    int numCandy;
    int numPopcorn;
    int numWater;

    scanf("%d %d %d %d", &numCups, &numCandy, &numPopcorn, &numWater);
    
    int numCupsNeeded, numCandyNeeded, numPopcornNeeded, numWaterNeeded;

    numCupsNeeded = 1000 - numCups;
    numCandyNeeded = 1000 - numCandy;
    numPopcornNeeded = 1000 - numPopcorn;
    numWaterNeeded = 1000 - numWater;
    printf("You need to buy %d cups, %d candy bars, %d bags of popcorn, and %d\nbottles of water\n", numCupsNeeded, numCandyNeeded, numPopcornNeeded, numWaterNeeded);
    
    double costCups = 0, costCandy = 0, costPopcorn = 0, costWater = 0, totalCost = 0;

    costCups = numCupsNeeded * 0.05;
    costCandy = numCandyNeeded * 0.30;
    costPopcorn = numPopcornNeeded * 0.20;
    costWater = numWaterNeeded * 0.50;

    totalCost = costCups + costCandy + costPopcorn + costWater;

    totalCost = totalCost * 100;

    int costDollars = 0;
    int costCents = 0;

    costDollars = totalCost / 100;
    costCents = (int)round(totalCost) % 100;
    printf("This will cost %d dollars and %d cents\n", costDollars, costCents);

    double avgCups, avgCandy, avgPopcorn, avgWater;
    avgCups = numCupsNeeded / 7.0;
    avgCandy = numCandyNeeded / 7.0;
    avgPopcorn = numPopcornNeeded / 7.0;
    avgWater = numWaterNeeded / 7.0;
    printf("On average you sold %lf cups, %lf candy bars, %lf\nbags of popcorn, and %lf bottles of water per day\n", avgCups, avgCandy, avgPopcorn, avgWater);

}