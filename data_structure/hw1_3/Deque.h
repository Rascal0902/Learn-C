#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
     char* items;
     int front;
     int rear;
     int size;
     int capacity;
} Deque;

Deque* create();
bool isEmpty(Deque* dq);
bool isFull(Deque* dq);
int size(Deque* dq);
void addFront(Deque* dq, int value);
void addRear(Deque* dq, int value);
int deleteFront(Deque* dq);
int deleteRear(Deque* dq);
void destroy(Deque* dq);

Deque* create() {
    Deque *s = (Deque *)malloc(sizeof(Deque));
    s -> items = (char *)malloc(sizeof(char)*MAX);
    s -> front = 0;
    s -> rear = 0;
    s -> size = 0;
    s -> capacity = MAX;
    return s;
}

bool isEmpty(Deque* dq) {
    if (dq -> size == 0){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Deque* dq) {
    if (dq -> size == dq -> capacity){
        return true;
    }
    else{
        return false;
    }
}

int size(Deque* dq) {
    return dq -> size;
}

void destroy(Deque* dq){
    free(dq -> items);
    free(dq);
}

void addFront(Deque* dq, int value) {
    if (isFull(dq)){
        printf("Cannot addFront Deque is full.");
        return;
    }
    dq -> front = (dq -> front - 1 + dq -> capacity) % (dq -> capacity);
    int idx = dq -> front;
    dq -> items[idx] = value;
    dq -> size += 1;
    return;
}

void addRear(Deque* dq, int value) {
    if (isFull(dq)){
        printf("Cannot addrear. Deque is full.");
        return;
    }
    int idx = dq -> rear;
    dq -> items[idx] = value;
    dq -> rear = (dq -> rear + 1) % (dq -> capacity);
    dq -> size += 1;
    return;
}

int deleteFront(Deque* dq) {
    if (isEmpty(dq)){
        printf("Cannot deleteFront. Deque is Empty");
        return -1;
    }
    int item = dq -> items[dq -> front];
    dq -> size -= 1;
    dq -> front = (dq -> front + 1) % (dq -> capacity);
    return item;
}

int deleteRear(Deque* dq) {
    if (isEmpty(dq)){
        printf("Cannot deleteFront. Deque is Empty");
        return -1;
    }
    dq -> rear = (dq -> rear - 1 + dq -> capacity) % (dq -> capacity);
    int item = dq -> items[dq -> rear];
    dq -> size -= 1;
    return item;
}
