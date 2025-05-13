#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;
Node* create();
Node* insert(Node* root, int key);
Node* search(Node* root, int key);
Node* findMin(Node* node);
Node* deleteNode(Node* root, int key);
Node* balancing(Node* root);
void traversal(Node* root);
int height(Node* root);
int getBalance(Node* root);
Node* rotateRight(Node* root);
Node* rotateLeft(Node* root);

Node* create(){
    return NULL;
}

Node* search(Node* root, int key) {
    if(root == NULL){
        return NULL;
    }
    else{
        if(key < root -> key){
            return search(root -> left, key);
        }
        else if(key > root -> key){
            return search(root -> right, key);
        }
        else{
            return root;
        }
    }
}

Node* findMin(Node* node) {
    Node* current = node;
    while(current != NULL && current -> left != NULL){
        current = current -> left;
    }
    return current;
}

void traversal(Node* root) {
    if(root != NULL){
        traversal(root -> left);
        printf("%d ", root -> key);
        traversal(root -> right);
    }
    return;
}

int height(Node* root) {
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}

int getBalance(Node* root) {
    if(root == NULL){
        return 0;
    }
    else{
        return height(root -> left) - height(root -> right);
    }
}

Node* rotateRight(Node* root) {
    Node* node1 = root -> left;
    Node* node2 = node1 -> right;
    node1 -> right = root;
    root -> left = node2;
    return node1;
}

Node* rotateLeft(Node* root) {
    Node* node1 = root -> right;
    Node* node2 = node1 -> left;
    node1 -> left = root;
    root -> right = node2;
    return node1;
}

Node* balancing(Node* root) {
    if(getBalance(root) > 1 && getBalance(root -> left) >=0){
        return rotateRight(root);
    }
    else if(getBalance(root) > 1 && getBalance(root -> left) < 0){
        root -> left = rotateLeft(root -> left);
        return rotateRight(root);
    }
    else if(getBalance(root) < -1 && getBalance(root -> right) <= 0){
        return rotateLeft(root);
    }
    else if(getBalance(root) < -1 && getBalance(root -> right) > 0){
        root -> right = rotateRight(root -> right);
        return rotateLeft(root);
    }
    return root;
}

Node* insert(Node* root, int key) {
    if(root == NULL){
        root = (Node *)malloc(sizeof(Node));
        root -> key = key;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    else{
        if(key < root -> key){
            root -> left = insert(root -> left, key);
        }
        else if(key > root -> key){
            root -> right = insert(root -> right, key);
        }
        else{
            return root;
        }
        return balancing(root);
    }
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL){
        return NULL;
    }
    if(key < root -> key){
        root -> left = deleteNode(root -> left, key);
    }
    else if(key > root -> key){
        root -> right = deleteNode(root -> right, key);
    }
    else{
        if(root -> left == NULL){
            Node* node = root -> right;
            free(root);
            return node;
        }
        else if(root -> right == NULL){
            Node* node = root -> left;
            free(root);
            return node;
        }
        else{
            Node* node = findMin(root -> right);
            root -> key = node -> key;
            root -> right = deleteNode(root -> right, node -> key);
        }
    }
    return balancing(root);
}
