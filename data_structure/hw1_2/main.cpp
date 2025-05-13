#include <stdio.h>
#include "Barbell.h"
int main() {
    Barbell* b = create();
    printf("Initial barbell weight: %d kg\n", weight(b));
    push_left(b, 20);
    printf("Barbell weight: %d kg\n", weight(b));
    push_right(b, 15);
    printf("Barbell weight: %d kg\n", weight(b));
    push_left(b, 5);
    push_right(b, 20);
    printf("Barbell weight: %d kg\n", weight(b));
    printf("Left weight: %d kg\n", weight_left(b));
    printf("Right weight: %d kg\n", weight_right(b));
    pop_left(b);
    printf("Barbell weight: %d kg\n", weight(b));
    pop_right(b);
    printf("Barbell weight: %d kg\n", weight(b));
    printf("Left weight: %d kg\n", weight_left(b));
    printf("Right weight: %d kg\n", weight_right(b));
    return 0;
}
