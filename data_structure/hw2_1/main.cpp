#include "Queue.h"
#include <stdio.h>
int main() {
    Queue* q = create();
    printf ("Queue is empty :");
    printf("%s\n", isEmpty (q) ? "true" : "false");
    enqueue(q, 10);
    printf("1: Front element is %d\n", peek(q));
    enqueue(q, 20);
    printf("2: Front element is %d\n", peek(q));
    enqueue(q, 30);
    printf("3: Front element is %d\n", peek(q));
    dequeue(q);
    printf("4: Front element is %d\n", peek(q));
    printf("5: Front element is %d\n", dequeue(q));
    printf("6: Front element is %d\n", peek(q));
    destroy(q);
    return 0;
}
