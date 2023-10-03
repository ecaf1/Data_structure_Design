#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_empty_binary_tree();
Node* create_node(int value);
Node* insertNode(Node* node, int value, int *count);
Node* search(Node* root, int value);
void printInOrder(Node* root);
void printPreOrder(Node* root);

#endif // BINARY_TREE_H
