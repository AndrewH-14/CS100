#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

FILE* f1 = fopen(argv[1], "r");
FILE* three = fopen("three.dat", "w");
FILE* five = fopen("five.dat", "w");
FILE* both = fopen("both.dat", "w");
int num;
int numThree = 0;
int numFive = 0;
int numBoth = 0;
int numInput = 0;

while(!feof(f1)) {

    fscanf(f1, "%d", &num);

    if (((num % 3) == 0) && ((num % 5) == 0)) {
        fprintf(both, "%d ", num);
        numBoth++;
        // numThree++;
        // numFive++;
    }
    else if ((num % 3) == 0) {
        fprintf(three, "%d ", num);
        numThree++;
    }
    else if ((num % 5) == 0) {
        fprintf(five, "%d ", num);
        numFive++;
    }
    numInput++;
}

printf("%d out of %d integers are divisible by three only.\n", numThree, numInput);
printf("%d out of %d integers are divisible by five only.\n", numFive, numInput);
printf("%d out of %d integers are divisible by three and five.\n", numBoth, numInput);

    return 0;
}