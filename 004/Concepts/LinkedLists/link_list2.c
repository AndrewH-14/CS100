#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//5.5x^4 + 2.5x^2 + 17.3x + 9 -> NULL

//Structure to hold each term in our polynomial
//Node for our linked list
typedef struct _term {
    double coef;
    int degree;
    struct _term* next;
} Term;

//creates a term structure from parameter
Term* createTerm(double coef_in, int degree_in) {
    Term* tempTerm = (Term*)malloc(sizeof(Term));
    tempTerm->coef = coef_in;
    (*tempTerm).degree = degree_in;
    tempTerm->next = NULL;

    return tempTerm;
}

void printTerm(Term* term) {
    if (term == NULL) {
        printf("That Term Doesn't Exist!\n");
    }
    else {
        if (term->degree == 0) {
            printf("%.1lf", term->coef);
        }
        else if (term->degree == 1) {
            printf("%.1lfx", term->coef);
        }
        else {
            printf("%.1lfx^%d", term->coef, term->degree);
        }
    }
}

//print off the entire polynomial as we would see it in a math textbook
void printPoly(Term* head) {
    for (Term* current = head; current != NULL; current = current->next) {
        //current is whatever Term we are currently looking at
        printTerm(current);

        if (current->next != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

//counts how many terms are in a polynomial
int countTerms(Term* head) {
    int counter = 0;
    for (Term* current = head; current != NULL; current = current->next) {
        counter++;
    }
    return counter;
}

//Search for a term given the degree of that term
Term* searchTerm(Term* head, int degree) {
    for (Term* current = head; current != NULL; current = current->next) {
        //If the degree of the current term is the degree we are looking for, we have found the term
        if (current->degree == degree) {
            return current;
        }
    }
    printf("Couldn't find a term with degree %d\n", degree);
    return NULL;
}

//Evaluates a single term
double evalTerm(Term* term, double x) {
    return term->coef * (pow(x, term->degree));
}

//Evaluates a polynomial using a linked list and an input for x
double evalPoly(Term* head, double x) {
    double result = 0.0;
    for (Term* current = head; current != NULL; current = current->next) {
        result += evalTerm(current, x);
    }
    return result;
}

int main() {

    Term* x4 = createTerm(5.5, 4);
    Term* x2 = createTerm(2.5, 2);
    Term* x1 = createTerm(17.3, 1);
    Term* x0 = createTerm(9.0, 0);

    x4->next = x2;
    x2->next = x1;
    x1->next = x0;

    printPoly(x4);
    printf("There are %d term in the polynomial\n", countTerms(x4));

    Term* myX2Term = searchTerm(x4, 2);
    Term* myX3Term = searchTerm(x4, 3);

    printTerm(myX2Term);
    printf("\n");
    printTerm(myX3Term);
    printf("\n");

    printf("The polynomial evalutes to %.2lf when passed %d for the value of x\n", evalPoly(x4, 2.0), 2);

    Term* x3 = createTerm(-2.0, 3);
    x4->next = x3;
    x3->next = x1;

    printPoly(x4);
    printf("The polynomial evalutes to %.2lf when passed %d for the value of x\n", evalPoly(x4, 2.0), 2);

    return 0;
}