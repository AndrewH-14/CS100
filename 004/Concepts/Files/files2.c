#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter a filename:\n");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Failed to open file\n");

        return 1;
    }

    int sum = 0;
    int count = 0;
    int num;
    while (1) {
        fscanf(fp, "%d", &num);
        if (feof(fp)) break;
        //printf("Read %d\n", num);
        sum += num;
        count++;
    }
    fclose(fp);
    double avg = (double)sum / count;

    FILE *outFile = fopen("output.txt", "w");
    if (!outFile) {
        printf("Faile to open output file\n");
        return 2;
    }
    fprintf(outFile, "sum=%d, avg=%lf\n", sum, avg);

    return 0;
}