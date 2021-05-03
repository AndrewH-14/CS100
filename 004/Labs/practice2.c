#include <stdio.h>

int main() {

    // read F from user
    //      prompt
    //      variable
    //      read it in
    printf("Enter the temp in F to convert to C:\n");
    double tempF;
    scanf("%lf", &tempF);

    // do math

    double tempC = (tempF - 32) * (5.0/9.0);

    // output answer

    printf("When F=%lf, C=%lf\n", tempF, tempC);

    return 0;
}