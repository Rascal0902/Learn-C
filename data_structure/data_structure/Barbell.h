#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

List* create();
void append(List* list, int value);
void insert(List* list, int index, int value);
void deleteEntry(List* list, int index);
int getEntry(List* list, int index);
void update(List* list, int index, int value);
void traversal(List* list);
int size(List* list);
void destroy(List* list);

List* create() {
    List* list = (List*)malloc(sizeof(List));
    list->head = nullptr;
    list->size = 0;
    return list;
}

void append(List* list, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = nullptr;

    if (list->head == nullptr) {
        list->head = node;
    }
    else {
        Node* currentNode = list->head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }

    list->size++;
    return;
}

void insert(List* list, int index, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;

    if (index == 0) {
        node->next = list->head;
        list->head = node;
    }
    else {
        Node* currentNode = list->head;
        int currentIndex = 0;
        while (currentIndex < index - 1) {
            currentNode = currentNode->next;
            currentIndex += 1;
        }
        node->next = currentNode->next;
        currentNode->next = node;
    }

    list->size++;
    return;
}

void deleteEntry(List* list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }
    if (index == 0) {
        Node* node = list->head;
        list->head = list->head->next;
        free(node);
    }
    else {
        Node* currentNode = list->head;
        int currentIndex = 0;
        while (currentIndex < index - 1) {
            currentNode = currentNode->next;
            currentIndex += 1;
        }
        Node* node = currentNode->next;
        currentNode->next = node->next;
        free(node);
    }

    list->size--;
    return;
}

int getEntry(List* list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    Node* currentNode = list->head;
    int currentIndex = 0;
    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex += 1;
    }
    return currentNode->data;
}

void update(List* list, int index, int value) {
    Node* currentNode = list->head;
    int currentIndex = 0;
    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex += 1;
    }
    currentNode->data = value;
    return;
}

void traversal(List* list) {
    Node* currentNode = list->head;
    int currentIndex = 0;
    while (currentNode != nullptr) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
        currentIndex += 1;
    }
    printf("\n");
    return;
}

int size(List* list) {
    return list->size;
}

void destroy(List* list) {
    Node* node = list->head;
    Node* nextNode;
    while (node != nullptr) {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(list);
    return;
}
