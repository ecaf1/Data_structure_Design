// AVLTree.h
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node_avl {
    int value;
    int h;
    struct Node_avl* left;
    struct Node_avl* right;
} Node_avl;

Node_avl* create_empty_binary_tree_avl();
Node_avl* create_node_avl(int value);
int h(Node_avl* node);
void update_height(Node_avl* node);
Node_avl* rotate_left(Node_avl* node);
Node_avl* rotate_right(Node_avl* node);
Node_avl* balance(Node_avl* node);
Node_avl* insertNode_avl(Node_avl* node, int value, int *counter);
Node_avl* search_avl(Node_avl* root, int value);
void printInOrder_avl(Node_avl* root);
void printPreOrder_avl(Node_avl* root);

#endif // AVL_TREE_H
