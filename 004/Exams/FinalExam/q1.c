#include <stdio.h>
#include <stdlib.h>

typedef struct _gradebook {
    int num_students;
    int num_assignments;
    double** grades;
} Gradebook;

Gradebook* readGradebook(char* filename) {
    // Code here
    int numStudents = 0;
    int numAssignments = 0;
    FILE* f1 = fopen(filename, "r");
    fscanf(f1, "%d", &numStudents);
    fscanf(f1, "%d", &numAssignments);

    double** arr = (double**)malloc(sizeof(double) * numStudents);
    for (int i = 0; i < numStudents; i++) {
        arr[i] = (double* )malloc(sizeof(double) * numAssignments);
    }

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numAssignments; j++) {
            fscanf(f1, "%lf", &arr[i][j]);
        }
    }

    // printf("%d %d\n", numStudents, numAssignments);
    // for (int i = 0; i < numStudents; i++) {
    //     for (int j = 0; j < numAssignments; j++) {
    //         printf("%.2lf ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    Gradebook* gb = (Gradebook*)malloc(sizeof(Gradebook));
    gb->num_students = numStudents;
    gb->num_assignments = numAssignments;
    gb->grades = arr;

    return gb;
}   

int main(int argc, char** argv) {
    // Code here
    Gradebook* gb = readGradebook(argv[1]);

    printf("%d %d\n", gb->num_students, gb->num_assignments);
    for (int i = 0; i < gb->num_students; i++) {
        for (int j = 0; j < gb->num_assignments; j++) {
            printf("%.2lf ", gb->grades[i][j]);
        }
        printf("\n");
    }



    return 0;
}
