#include "Stack.h"
#include <stdio.h>
int main() {
    Stack* s = create();
    printf("Stack is empty: ");
    printf(isEmpty(s) ? "true\n" : "false\n");
    push(s, 10);
    printf("Top element is %d\n", peek(s));
    push(s, 20);
    push(s, 30);
    int data = pop(s);
    printf("Popped element is %d\n", data);
    printf("Now, top element is %d\n", peek(s));
    return 0;
}
