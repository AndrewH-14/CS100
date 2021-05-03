#include <stdio.h>

int main() {

printf("Enter your data:\n");
int userInput[50] = { 0 };
int i = 0;
int count = 0;
FILE *good; 
good = fopen("good", "w");
FILE *bad;
bad = fopen("bad", "w");

while (!feof(stdin)) {
    scanf("%d", &userInput[i]);
    count++;
    i++;
}

fprintf(good, "%d\n", userInput[0]);
// int tempVal = userInput[0];
// printf("%d", userInput[0]);

for(int i = 1; i < count; i++) {
    if(userInput[i] > userInput[i - 1]) {
        fprintf(good, "%d\n", userInput[i]);
    }
    else {
        fprintf(bad, "%d\n", userInput[i]);
    }
    //tempVal = userInput[i];
}
fclose(good);
fclose(bad);

    return 0;
}