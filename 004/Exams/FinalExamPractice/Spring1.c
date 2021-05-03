#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    FILE* f1 = fopen(argv[2], "r");
    FILE* f2 = fopen(argv[3], "r");
    FILE* f3 = fopen(argv[4], "r");
    int numData = atoi(argv[1]);
    int data1, data2, data3;
    int badData1 = 0, badData2 = 0, badData3 = 0;
    int unknownData = 0;

    for (int i = 0; i < numData; i++) {
        fscanf(f1, "%d", &data1);
        fscanf(f2, "%d", &data2);
        fscanf(f3, "%d", &data3);

        if (data1 == data2 && data1 == data3) {
            continue;
        }
        else if (data1 == data2) {
            badData3++;
        }
        else if (data1 == data3) {
            badData2++;
        }
        else if (data2 == data3) {
            badData1++;
        }
        else {
            unknownData++;
        }
    }

    printf("Data1 has %d possible bad values\n", badData1);
    printf("Data2 has %d possible bad values\n", badData2);
    printf("Data3 has %d possible bad values\n", badData3);
    printf("THere are 1 unknwon cases\n", unknownData);


    return 0;
}