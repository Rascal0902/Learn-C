#include "List.h"
#include <stdio.h>
int main() {
    List* list = create();
    append(list, 10);
    append(list, 20);
    append(list, 30);
    printf("Entry at index 0: %d\n", getEntry(list, 0));
    printf("Entry at index 1: %d\n", getEntry(list, 1));
    printf("Entry at index 2: %d\n", getEntry(list, 2));
    insert(list, 1, 15);

    printf("list size: %d\n", size(list));
    printf("Entry at index 2: %d\n", getEntry(list, 2));
    update(list, 2, 25);
    printf("Entry at index 2: %d\n", getEntry(list, 2));
    printf("list size: %d\n", size(list));
    deleteEntry(list, 1);
    printf("Entry at index 2: %d\n", getEntry(list, 2));
    printf("list size: %d\n", size(list));
    traversal(list);
    destroy(list);
    return 0;
}
