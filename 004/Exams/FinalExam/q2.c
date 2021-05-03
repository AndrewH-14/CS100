#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _gradebook {
    char** assignment_names;
    double** grades;
    int num_assignments; // Columns
    int num_students; // Rows
} Gradebook;

double assignmentAverage(Gradebook* gradebook, char* assignment_name) {
    int column = 0;
    for (int i = 0; i < gradebook->num_assignments; i++) {
        if (strcmp(gradebook->assignment_names[i], assignment_name) == 0) {
            break;
        }
        else if (i == (gradebook->num_assignments - 1)) {
            return -1;
        }
        column++;
    }

    double sum = 0;
    //double totalSum = 0;

    for (int i = 0; i < gradebook->num_students; i++) {
        sum = sum + gradebook->grades[i][column];
    }
    // printf("%lf\n", sum);
    // printf("%d", gradebook->num_students);

    return ((double)sum / gradebook->num_students);

}

int main() {
    // Make an example gradebook
    char* assignment1 = "HW1";
    char* assignment2 = "HW2";
    char* assignment_names[2] = {assignment1, assignment2};

    double row1[2] = {85, 90};
    double row2[2] = {70.5, 99.5};
    double row3[2] = {50.8, 72};
    double* grades[3] = {row1, row2, row3};

    Gradebook gradebook = {assignment_names, grades, 2, 3};

    // Find the average of HW2
    double hw2_average = assignmentAverage(&gradebook, "HW2");

    printf("HW2 Average: %.2lf\n", hw2_average);

    return 0;
}
