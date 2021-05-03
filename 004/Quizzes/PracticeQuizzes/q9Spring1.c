#include <stdio.h>
typedef struct item {
int value;
struct item *next;
} Item;

int main(void) {
    Item a, b, c;
    a.value = 1; a.next = &b;
    b.value = 1; b.next = &c;
    c.value = 1; c.next = &a;
    Item *ptr = &a;
    for (int z=2; z<7; z++) {
        ptr->value = ptr->value * z;
        ptr = ptr->next;
    }
    printf("%d and %d and %d\n",
    a.value, b.value, c.value);
    return 0;
}