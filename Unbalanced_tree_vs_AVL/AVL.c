#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node_avl {
    int value;
    int h;
    struct Node_avl* left;
    struct Node_avl* right;
} Node_avl;

Node_avl* create_empty_binary_tree_avl() {
    return NULL;
}

Node_avl* create_node_avl(int value) {
    Node_avl* new_node = (Node_avl*) malloc(sizeof(Node_avl));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->h = 1;
    return new_node;
}

int h(Node_avl* node) {
    return (node == NULL) ? 0 : node->h;
}

void update_height(Node_avl* node) {
    if (node) {
        node->h = fmax(h(node->left), h(node->right)) + 1;
    }
}

Node_avl* rotate_left(Node_avl* node) {
    Node_avl* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    update_height(node);
    update_height(new_root);
    return new_root;
}

Node_avl* rotate_right(Node_avl* node) {
    Node_avl* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    update_height(node);
    update_height(new_root);
    return new_root;
}

Node_avl* balance(Node_avl* node) {
    if (node == NULL) return node;
    int balanceFactor = h(node->left) - h(node->right);

    if (balanceFactor > 1) {
        if (h(node->left->left) >= h(node->left->right)) {
            return rotate_right(node);
        } else {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
    }

    if (balanceFactor < -1) {
        if (h(node->right->right) >= h(node->right->left)) {
            return rotate_left(node);
        } else {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
    }

    return node;
}

Node_avl* insertNode_avl(Node_avl* node, int value, int *counter) {
    (*counter)++;
    if (node == NULL) return create_node_avl(value);
    if (value <= node->value) {
        node->left = insertNode_avl(node->left, value, counter);
    } else {
        node->right = insertNode_avl(node->right, value, counter);
    }
    update_height(node);
    return balance(node);
}

Node_avl* search_avl(Node_avl* root, int value) {
    if (root == NULL || root->value == value) return root;
    if (root->value < value) return search_avl(root->right, value);
    return search_avl(root->left, value);
}

void printInOrder_avl(Node_avl* root) {
    if (root == NULL) return;
    printInOrder_avl(root->left);
    printf("%d ", root->value);
    printInOrder_avl(root->right);
}

void printPreOrder_avl(Node_avl* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    printPreOrder_avl(root->left);  
    printPreOrder_avl(root->right); 
}
 /*
int main() {
   
    Node_avl* root = NULL;
    root = insertNode_avl(root, 50);
    root = insertNode_avl(root, 60);
    root = insertNode_avl(root, 70);
    root = insertNode_avl(root, 90);
    root = insertNode_avl(root, 70);
    root = insertNode_avl(root, 60);
    root = insertNode_avl(root, 40);

    printPreOrder(root);
    printf("\n");
    Node_avl* found = search(root, 40);

    if (found != NULL) {
        printf("Valor %d encontrado na árvore.\n", found->value);
    } else {
        printf("Valor não encontrado na árvore.\n");
    }
  
    return 0;
}
  */