#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int readData(char filename[], double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length){  
    FILE* f1 = fopen(filename, "r");
    char flowerType[20];
    for(int i = 0; i < length; i++) {
        fscanf(f1, "%lf", &sepal_lengths[i]);
        fscanf(f1, "%lf", &sepal_widths[i]);
        fscanf(f1, "%lf", &petal_lengths[i]);
        fscanf(f1, "%lf", &petal_widths[i]);
        fscanf(f1, "%s", flowerType);
        if(strcmp(flowerType, "Iris-setosa") == 0) {
            labels[i] = 0;
        }
        else if(strcmp(flowerType, "Iris-versicolor") == 0) {
            labels[i] = 1;
        }
        else if(strcmp(flowerType, "Iris-virginica") == 0) {
            labels[i] = 2;
        }
    }
    return 0;
}


void display(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length) {
    for (int i = 0; i < length; i++) {
        printf("(%lf , %lf, %lf, %lf) => %d\n", sepal_lengths[i], sepal_widths[i], petal_lengths[i], petal_widths[i], labels[i]);
    }
}

double mean(double values[], int labels[], int filter, int length) {
    double sum = 0;
    double mean = 0;
    int num = 0;
    for (int i = 0; i < length; i++) {
        if (labels[i] == filter) {
        sum += values[i];
        num++;
        }
    }
    mean = sum / (double)num;

    return mean;
}

double stddev(double values[], int labels[], int filter, int length) {
    double stddev = 0;
    double sum = 0;
    int num = 0;
    double avg = mean(values, labels, filter, length);

    for (int i = 0; i < length; i++) {
        if (labels[i] == filter) {
        sum = sum + pow((values[i] - avg), 2);
        num++;
        }
    }
    stddev = sqrt((sum / num)) * 2;

    return stddev;
}

void stats(double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length) {
    printf("  | Sepal length  |  Sepal width  | Petal length  | Petal width\n");
    printf("0 | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf\n", mean(sepal_lengths, labels, 0, 120), stddev(sepal_lengths, labels, 0, 120), mean(sepal_widths, labels, 0, 120), stddev(sepal_widths, labels, 0, 120), mean(petal_lengths, labels, 0, 120), stddev(petal_lengths, labels, 0, 120), mean(petal_widths, labels, 0, 120), stddev(petal_widths, labels, 0, 120));
    printf("1 | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf\n", mean(sepal_lengths, labels, 1, 120), stddev(sepal_lengths, labels, 1, 120), mean(sepal_widths, labels, 1, 120), stddev(sepal_widths, labels, 1, 120), mean(petal_lengths, labels, 1, 120), stddev(petal_lengths, labels, 1, 120), mean(petal_widths, labels, 1, 120), stddev(petal_widths, labels, 1, 120));
    printf("2 | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf | %.2lf +/- %.2lf\n", mean(sepal_lengths, labels, 2, 120), stddev(sepal_lengths, labels, 2, 120), mean(sepal_widths, labels, 2, 120), stddev(sepal_widths, labels, 2, 120), mean(petal_lengths, labels, 2, 120), stddev(petal_lengths, labels, 2, 120), mean(petal_widths, labels, 2, 120), stddev(petal_widths, labels, 2, 120));
}

double distance(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4) {
    double d = sqrt((pow((a1 - b1), 2)) + (pow((a2 - b2), 2)) + (pow((a3 - b3), 2)) + (pow((a4 - b4), 2)));
    return d;
}

int nearestNeighbor(
    double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[], int labels[], int length,
    double sepal_length, double sepal_width, double petal_length, double petal_width) {

    double dist = 0;
    double newDist;
    int flowerType = labels[0];
    dist = distance(sepal_lengths[0], sepal_length, sepal_widths[0], sepal_width, petal_lengths[0], petal_length, petal_widths[0], petal_width);
    for (int i = 0; i < length; i++) {
        newDist = distance(sepal_lengths[i], sepal_length, sepal_widths[i], sepal_width, petal_lengths[i], petal_length, petal_widths[i], petal_width);
        if (newDist < dist) {
            flowerType = labels[i];
            dist = newDist;
        }
    }

    return flowerType;
}

double accuracy( double sepal_lengths[], double sepal_widths[], double petal_lengths[], double petal_widths[],
    int labels[], int length, double sepal_lengths_test[], double sepal_widths_test[], double petal_lengths_test[],
    double petal_widths_test[], int labels_test[], int length_test) {
    
    double count = 0;
    double acc = 0;

    // for (int i = 0; i < length_test; i++) {
    //     printf("%d\n", labels_test[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < length; i++) {
    //     printf("%d\n", labels[i]);
    // }

    for (int i = 0; i < length_test; i++) {
        double sepal_length = sepal_lengths_test[i];
        double sepal_width = sepal_widths_test[i];
        double petal_length = petal_lengths_test[i];
        double petal_width = petal_widths_test[i];
        int prediction = nearestNeighbor(sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length, sepal_length, sepal_width, petal_length, petal_width);
        
        if (prediction == labels_test[i]) {
            //printf("%d\n", i);
            count++;
        }
        //printf("%d-%d ", prediction, labels_test[i]);
    }
    acc = count / 30.0;   
    //printf("\n%d", count);
    return acc; 
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("Usage: project4 TRAIN_FILE TEST_FILE OPTION");
        return 1;
    }
    FILE* f1 = fopen(argv[1], "r");
    FILE* f2 = fopen(argv[2], "r");
    if (!f1) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    if (!f2) {
        printf("Unable to open file %s\n", argv[2]);
        return 1;
    }

    double sepal_lengths[120], sepal_widths[120], petal_widths[120], petal_lengths[120];
    double sepal_lengths_test[30], sepal_widths_test[30], petal_lengths_test[30], petal_widths_test[30];
    int labels[120], labels_test[30], length = 120, length_test = 30;
    double sepal_length, sepal_width, petal_length, petal_width;
    int prediction;

    readData(argv[1], sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length);
    readData(argv[2], sepal_lengths_test, sepal_widths_test, petal_lengths_test, petal_widths_test, labels_test, length_test);

    for (int i = 3; i < argc; i++) {

        if (strcmp(argv[i], "display") == 0) {
            printf("Training data:\n");
            display(sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length);
            printf("\nTesting data:\n");
            display(sepal_lengths_test, sepal_widths_test, petal_lengths_test, petal_widths_test, labels_test, length_test);
        }
        else if (strcmp(argv[i], "stats") == 0) {
            stats(sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length);
        }
        else if (strcmp(argv[i], "accuracy") == 0) {
            double acc = accuracy(sepal_lengths, sepal_widths, petal_lengths, petal_widths,labels, length, sepal_lengths_test, sepal_widths_test, petal_lengths_test,
                petal_widths_test, labels_test, length_test);
            printf("Test accuracy: %.2lf\n", acc);
        }
        else if (strcmp(argv[i], "classify") == 0) {
            // sepal_length = 7;
            // sepal_width = 3;
            // petal_length = 6;
            // petal_width = 2.5;

            //for (int i = 0; i < length_test; i++) {
                // sepal_length = sepal_lengths_test[i];
                // sepal_width = sepal_widths_test[i];
                // petal_length = petal_lengths_test[i];
                // petal_width = petal_widths_test[i];

                printf("Flower characteristics:\n");
                scanf("%lf\n %lf\n %lf\n %lf", &sepal_length, &sepal_width, &petal_length, &petal_width);
                prediction = nearestNeighbor(sepal_lengths, sepal_widths, petal_lengths, petal_widths, labels, length, sepal_length, sepal_width, petal_length, petal_width);
        
                if (prediction == 0) {
                    printf("Prediction: 0 (Iris-setosa)\n");
                }
                else if (prediction == 1) {
                    printf("Prediction: 1 (Iris-versicolor)\n");
                }
                else {
                    printf("Prediction: 2 (Iris-virginica)\n");
                }
            //}
        }
        else {
            printf("Unknown option\n");
        }
    }

   
    return 0;
}

