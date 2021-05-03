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

//add a term at the front of the list
Term* addAtFront(Term* head, double coef_new, int degree_new) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coef = coef_new;
    newTerm->degree = degree_new;
    newTerm->next = head;

    return newTerm;
}

//adds the new term to the front of our list and returns our new list
Term* addAtFrontWithTerm(Term* head, Term* newTerm) {
    newTerm->next = head;
    return newTerm;
}

//Add to the front of the linked list and modify the list in place
void addAtFrontModify(Term** link_list, Term* newTerm) {
    newTerm->next = *link_list;
    *link_list = newTerm;
}

void addAtBack(Term* head, double coef_new, int degree_new) {
     for (Term* current = head; current != NULL; current = current->next) {
        if (current->next == NULL) {
            current->next = createTerm(coef_new, degree_new);
            break;
        }
    } 
    // Term* current;
    // for (current = head; current->next != NULL; current = current->next);
    // current->next = createTerm(coef_new, degree_new);
}

void addAtBackWithTerm(Term* head, Term* newTerm) {
    for (Term* current = head; current != NULL; current = current->next) {
        if (current->next == NULL) {
            current->next = newTerm;
            break;
        }
    }
}

int main() {

    Term* link_list = createTerm(5.5, 4);
    addAtBackWithTerm(link_list, createTerm(2.5, 2));
    addAtBackWithTerm(link_list, createTerm(17.3, 1));
    addAtBackWithTerm(link_list, createTerm(9.0, 0));  
    
    printPoly(link_list);


    return 0;
}