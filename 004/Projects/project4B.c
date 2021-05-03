#include <stdio.h>
#include <stdlib.h>

int readData(char filename[], double sepal_lengths[], double petal_lengths[], int labels[], int length[]);
void display(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length);
double mean(double values[], int labels[], int filter, int length);
double stddev(double values[], int labels[], int filter, int length);
void stats(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length);
double distance(double a1, double b1, double c1, double d1, double a2, double b2, double c2, double d2);
int nearestNeighbor(double sepal_lenghts[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length, double sepal_length, double sepal_width, double petal_length, double petal_width);
double accuracy(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length, double sepal_lengths_test[], double sepal_widths_test[], double petal_lengths_test[], double petal_widths_test[], int labels_test[], int length_test);

int main(int argc, char *argv[]) {

    


    return 0;
}