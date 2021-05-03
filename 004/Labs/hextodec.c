#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

    char str[10];
    scanf("%s", str);
    int n = strlen(str) - 1;
    long valFinal = 0;
    for (int i = 0; i < strlen(str); i++) {
        int val;
       if ((str[i] >= '0') && (str[i] <= '9')) {
           val = str[i] - '0';
       }
       else if ((str[i] >= 'A') && (str[i] <= 'F')) {
           val = str[i] - 'A' + 10;
       }
       valFinal = valFinal + pow(16,n) * val;
       n = n - 1;
    }
    printf("The hex number %s is equal to %ld in base 10", str, valFinal);

    return 0;
}