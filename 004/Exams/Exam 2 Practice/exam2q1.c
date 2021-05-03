#include <stdio.h>
#include <stdlib.h>

int bigSpenders(int totals[], int length) {
    int numPeople = 0;

    for (int i = 0; i < length; i++) {
        if (totals[i] >= 10000) {
            numPeople++;
        }
    }

    return numPeople;
}

void showArray(int totals[], int length) {
    printf("[ ");
    for (int i = 0; i < length; i++) {
        printf("%d ", totals[i]);
    }
    printf("]\n");
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./a.out FILENAME");
        return 1;
    }
    FILE *f1 = fopen(argv[1], "r");

    if (!f1) {
        printf("File %s does not exist", argv[1]);
        return 1;
    }
    //FILE *f1 = fopen(argv[1], "r");
    int numPeople = 0;
    int numItems = 0;
    int sum = 0;
    int cost = 0;
    int numBig = 0;
    
    fscanf(f1, "%d", &numPeople);
    int totals[numPeople];

    for (int i = 0; i < numPeople; i++) {
        fscanf(f1, "%d", &numItems);
        for (int j = 0; j < numItems; j++) {
            fscanf(f1, "%d", &cost);
            sum = sum + cost;
        }
        totals[i] = sum;
        sum = 0;
    }
    showArray(totals, numPeople);
    numBig = bigSpenders(totals, numPeople);

    if (numBig == 1) {
        printf("%d big spender\n", numBig);
    }
    else {
        printf("%d big spenders\n", numBig);
    }

    return 0;
}