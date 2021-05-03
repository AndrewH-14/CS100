#include <stdio.h>
typedef struct item {
int value;
struct item *next;
} Item;

int main(void) {
    Item a, b;
    a.value = 1; a.next = &b;
    b.value = 3; b.next = &a;
    Item *ptr = &a;
    for (int z=1; z<5; z++) {
        ptr->value += ptr->next->value;
        ptr = ptr->next;
    }
    printf("%d and %d\n", a.value, b.value);
    return 0;
}
