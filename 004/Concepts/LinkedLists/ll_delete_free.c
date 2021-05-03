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

// 0 if equal
// 1 if the left is greater than
// -1 if the left is less than
int compareTerms(Term* left, Term* right) {
    if (left->degree < right->degree) {
        return -1;
    }
    else if (left->degree > right->degree) {
        return 1;
    }
    else {
        if (left->coef < right->coef) {
            return -1;
        }
        else if (left->coef > right->coef) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

Term* addOrderedWithTerm(Term* head, Term* newNode) {
    if (head == NULL) {
        return newNode;
    }
    else if (compareTerms(newNode, head) > 0) {
        newNode->next = head;
        return newNode;
    }
    else {
        Term* prev = head;

        while(prev->next != NULL) {

            if (compareTerms(newNode, prev->next) > 0) {
                break;
            }
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;

        return head;
    }
}

Term* addOrdered(Term* head, double coef_new, int degree_new) {
    Term* newNode = createTerm(coef_new, degree_new);
    return addOrderedWithTerm(head, newNode);
}

void AddOrderedModify(Term** link_list, Term* newTerm) {
    Term* head = addOrderedWithTerm(*link_list, newTerm);
    *link_list = head;
}

Term* deleteTerm(Term* head, int degree) {

    Term* search = searchTerm(head, degree);

    if (searchTerm == NULL) {
        printf("COuld not delete degree %d from the list\n", degree);
        return head;
    }

    if (head == NULL) {
        return NULL;
    }
    else if (head->degree == degree) {
        Term* newHead = head->next;
        free(head);
        return newHead;
    }
    else {
        Term* prev = head;

        while(prev->next != NULL) {

            if (prev->next->degree == degree) {
                break;
            }
            prev = prev->next; 
        }

        Term* toBeDeleted = prev->next;
        prev->next = prev->next->next;
        free(toBeDeleted);

        return head;
    }
}

void freeTerms(Term* head) {
    while (head != NULL) {
        printf("Freeing degree %d...\n", head->degree);
        Term* next = head->next;
        free(head);
        head = next;
    }
}

int main() {

    Term* link_list = NULL;

    // 5.6x6, 7.8x8 1.2x2, 3.4x4
    AddOrderedModify(&link_list, createTerm(5.6, 6));
    AddOrderedModify(&link_list,createTerm(7.8, 8));
    AddOrderedModify(&link_list,createTerm(1.2, 2));
    AddOrderedModify(&link_list,createTerm(3.4, 4));

    printPoly(link_list);
    freeTerms(link_list);
    link_list = NULL;
    printPoly(link_list);


    
    return 0;
}