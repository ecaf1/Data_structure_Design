#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_empty_binary_tree() {
    return NULL;
}

Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insertNode(Node* node, int value, int *counter) {
    (*counter)++;
    if (node == NULL) return create_node(value);
    if (value <= node->value) node->left = insertNode(node->left, value, counter);
    else node->right = insertNode(node->right, value, counter);
    return node;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->value == value) return root;
    if (root->value < value)  return search(root->right, value);
    return search(root->left, value);
}

void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

void printPreOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
/*
int main() {
    
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 70);
    root = insertNode(root, 80);
    root = insertNode(root, 90);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printPreOrder(root);
    printf("\n");
    Node* found = search(root, 40);
    if (found != NULL) {
        printf("Valor %d encontrado na árvore.\n", found->value);
    } else {
        printf("Valor não encontrado na árvore.\n");
    }
    
    return 0;
}
*/
