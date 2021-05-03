#include <stdio.h>

int main() {

    int score1, score2, score3, score4;
    scanf("%d %d %d %d", &score1, &score2, &score3, &score4);

    if ((score1 <= score2) && (score1 <= score3) && (score1 <= score4)) {
        double avgScore = (score2 + score3 + score4) / 3.0;
        printf("Entering %d %d %d %d gives an average score of %lf", score1, score2, score3, score4, avgScore);
    }
    else if ((score2 <= score1) && (score2 <= score3) && (score2 <= score4)) {
        double avgScore = (score1 + score3 + score4) / 3.0;
        printf("Entering %d %d %d %d gives an average score of %lf", score1, score2, score3, score4, avgScore);
    }
    else if ((score3 <= score1) && (score3 <= score2) && (score3 <= score4)) {
        double avgScore = (score1 + score2 + score4) / 3.0;
        printf("Entering %d %d %d %d gives an average score of %lf", score1, score2, score3, score4, avgScore);
    }
    else if ((score4 <= score1) && (score4 <= score2) && (score4 <= score3)) {
        double avgScore = (score1 + score2 + score3) / 3.0;
        printf("Entering %d %d %d %d gives an average score of %lf", score1, score2, score3, score4, avgScore);
    }


    return 0;
}