#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;


Queue* create();
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);
void destroy(Queue* q);

Queue* create() {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue -> front = NULL;
    queue -> rear = NULL;
    return queue;
}

bool isEmpty(Queue* q) {
    if(q -> front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(Queue* q, int value) {
    Node* node = (Node *)malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;
    if(isEmpty(q)){
        q -> rear = node;
        q -> front = node;
    }
    else{
        q -> rear -> next = node;
        q -> rear = node;
    }
    return;
}

int dequeue(Queue* q) {
    if(isEmpty(q)){
        printf("Cannot dequeue. queue is Empty. \n");
        return -1;
    }

    Node* node = q -> front;
    int data = node -> data;
    q -> front = q -> front -> next;

    if(q -> front == NULL){
        q -> rear = NULL;
    }
    free(node);
    return data;
}

int peek(Queue* q) {
    if(isEmpty(q)){
        printf("Cannot peek. queue is Empty. \n");
        return -1;
    }

    return q -> front -> data;
}

void destroy(Queue* q) {
    Node* node;
    while(q -> front != NULL){
        node = q -> front;
        q -> front = q -> front -> next;
        free(node);
    }

    free(q);
    return;
}
