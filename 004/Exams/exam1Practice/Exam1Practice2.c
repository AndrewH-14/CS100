#include <stdio.h>

int main () {

    int n;
    double weightOunces, Cost = 0;
    printf("How many packages to be mailed? ");
    scanf("%d\n", &n);
    printf("Enter weights of these %d packages: ", n);
    for (int i = 0;i < n; i++) {
        scanf("%lf", &weightOunces);
        if (weightOunces <= 4) {
            Cost = Cost + 3.5;
        }
        else if (weightOunces <= 8) {
            Cost = Cost + 3.75;
        }
        else if (weightOunces <= 9) {
            Cost = Cost + 4.10;
        }
        else if (weightOunces <= 10) {
            Cost = Cost + 4.45;
        }
        else if (weightOunces <= 11) {
            Cost = Cost + 4.80;
        }
        else if (weightOunces <= 12) {
            Cost = Cost + 5.15;
        }
        else if (weightOunces <= 13) {
            Cost = Cost + 5.50;
        }
    }
    printf("%lf", Cost);
  
  
    return 0;
}