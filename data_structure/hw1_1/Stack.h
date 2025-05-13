#define MAX 100

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

Stack* create();
void push(Stack* s, int item);
int pop(Stack* s);
int peek(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void destroy(Stack* s);

Stack* create(){
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
