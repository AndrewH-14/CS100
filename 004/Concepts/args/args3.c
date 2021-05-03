#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Expected filename as argument\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (!inputFile) {
        printf("Invalid filename\n");
        return 2;
    }

    int sum = 0;
    int count = 0;
    int num;
    while (1) {
        fscanf(inputFile, "%d", &num);
        if (feof(inputFile)) break;
        sum += num;
        count++;
    }
    fclose(inputFile);
    double avg = (double)sum / count;

    if (argc < 3) {
        printf("sum=%d, avg=%lf\n", sum, avg);
    }
    else {
        FILE *outFile = fopen(argv[2], "w");

        if (!outFile) {
            printf("Could not open output file\n");
            return 3;
        }

        fprintf(outFile, "sum=%d, avg=%lf\n", sum, avg);
        fclose(outFile);
    }

    return 0;
}