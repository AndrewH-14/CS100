#include <stdio.h>
#include <math.h>

int getInt(char prompt[]);
void getData(char prompt[], int array[], int size);
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev);
void printResults(double mean, double stdDev);

int main(void) {
    int size = getInt("Enter the array size:\n");
    int array[size];
    getData("Enter the numbers:\n", array, size);

    double mean, stdDev;
    calcMeanStdDev(array, size, &mean, &stdDev);
    printResults(mean, stdDev);

    return 0;
}

int getInt(char prompt[]) {

    int size;
    printf("%s", prompt);
    scanf("%d", &size);
    
    return size;
}

void getData (char prompt[], int array[], int size) {

    printf("%s", prompt);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + array[i];
    }
    *pMean = (double)sum / size;
    double val = 0;
    double sumVals = 0;
    for (int i = 0; i < size; i++) {
        val = array[i] - *pMean;
        sumVals = sumVals + (val * val);
    }
    *pStdDev = sqrt(sumVals / size);
}

void printResults(double mean, double stdDev) {
    printf("The mean is %.2lf and the standard deviation is %.2lf\n", mean, stdDev);
}