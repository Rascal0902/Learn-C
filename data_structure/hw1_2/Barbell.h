#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

typedef struct {
    Stack* right;
    Stack* left;
    int right_weight;
    int left_weight;
    int initial_weight;
} Barbell;

Barbell* create();

void push_left(Barbell* b, int plate_weight);
void push_right(Barbell* b, int plate_weight);
void pop_left(Barbell* b);
void pop_right(Barbell* b);
int weight(Barbell* b);
int weight_left(Barbell* b);
int weight_right(Barbell *b);

Stack* stack_create();

void push(Stack* s, int item);
int pop(Stack* s);
int peek(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void destroy(Stack* s);

Barbell* create(){
    Barbell* b = (Barbell *)malloc(sizeof(Barbell));
    (*b).right = stack_create();
    (*b).left = stack_create();
    (*b).right_weight = 0;
    (*b).left_weight = 0;
    (*b).initial_weight = 20;
    return b;
}

void push_left(Barbell* b, int plate_weight){
    push((*b).left,plate_weight);
    (*b).left_weight += plate_weight;
    return;
}
void push_right(Barbell* b, int plate_weight){
    push((*b).right,plate_weight);
    (*b).right_weight += plate_weight;
    return;
}
void pop_left(Barbell* b){
    int data = pop((*b).left);
    (*b).left_weight -= data;
    return;
}
void pop_right(Barbell* b){
    int data = pop((*b).right);
    (*b).right_weight -= data;
    return;
}
int weight(Barbell* b){
    return (*b).initial_weight + (*b).left_weight + (*b).right_weight;
}
int weight_left(Barbell* b){
    return (*b).left_weight;
}
int weight_right(Barbell *b){
    return (*b).right_weight;
}

Stack* stack_create(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    (*s).items = (int *) malloc(sizeof(int) * MAX);
    (*s).top = -1;
    (*s).capacity = MAX;

    return s;
}

void push(Stack* s, int item){
    if (isFull(s)){
        printf("Cannot push, Stack is full\n");
        return;
    }
    else{
        (*s).top += 1;
        (*s).items[(*s).top] = item;
        return;
    }

}

int pop(Stack* s){
    if (isEmpty(s)){
        printf("Cannot pop. Stack is empty\n");
        return -1;
    }
    else{
        int data = (*s).items[(*s).top];
        (*s).top -= 1;
        return data;
    }
}

int peek(Stack* s){
    if (isEmpty(s)){
        printf("Cannot peek. Stack is empty\n");
        return -1;
    }
    else{
        return (*s).items[(*s).top];
    }
}

bool isEmpty(Stack* s){
    if ((*s).top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack* s){
    if ((*s).top == (*s).capacity - 1){
        return true;
    }
    else{
        return false;
    }
}

void destroy(Stack* s){
    free((*s).items);
    free(s);
}

