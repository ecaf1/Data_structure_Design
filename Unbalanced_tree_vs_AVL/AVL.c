/**
 * @file   AVL.c
 * @author Edeilson Costa 
 * @date   Qualquer dia 
 * @brief  Este arquivo contém funções para manipular uma árvore AVL.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um nó em uma árvore binária.
 */
typedef struct Node {
    int value;
    int h;
    struct Node* left;
    struct Node* right;
}Node;

/**
 * @brief Cabesaarios 
*/
Node* create_empty_binary_tree();
Node* create_binary_tree(int item, Node *left, Node *right);
int is_empty(Node *bt);
int h(Node *bt);
int balance_factor(Node *bt);
Node* rotate_left(Node *bt);
Node* rotate_right(Node *bt);
Node* add(Node *bt, int item);


/**
 * @brief Cria um novo nó vazio.
 * 
 * @return Ponteiro vazio para o novo nó criado.
 */
Node* create_empty_binary_tree(){
    return NULL;
}

/**
 * @brief Cria um novo nó com o valor especificado.
 * @param value Valor a ser armazenado no novo nó.
 * @param value Valor a ser armazenado no novo nó.
 * @return Ponteiro vazio para o novo nó criado.
 */
Node* create_binary_tree(int item, Node *left, Node *right) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = item;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

int is_empty(Node *bt) {
    return (bt == NULL);
}

int h(Node *bt) {
    if (is_empty(bt)) {
        return -1;
    }
    int hl = h(bt->left);
    int hr = h(bt->right);
    return 1 + (hl > hr ? hl : hr);
}

int balance_factor(Node *bt) {
    if (bt == NULL) return 0;
    else if ((bt->left != NULL) && (bt->right != NULL)) return (bt->left->h - bt->right->h);
    else if ((bt->left != NULL) && (bt->right == NULL)) return (1 + bt->left->h);
    else return (-bt->right->h - 1);
}

Node* rotate_left(Node *bt){
    Node *subtree_root = NULL;
    if (bt != NULL && bt->right != NULL) {
        subtree_root = bt->right;
        bt->right = subtree_root->left;
        subtree_root->left = bt;
    }
    subtree_root->h = h(subtree_root);
    bt->h = h(bt);
    return subtree_root;
}

/**
 * @brief Cria um novo nó com o valor especificado.
 * 
 * @param value Valor a ser armazenado no novo nó.
 * @return Ponteiro para o novo nó criado.
 */
Node* creatNode(int value){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->value = value;
    newNode->h = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * @brief Insere um novo nó com o valor especificado na árvore binária.
 * 
 * @param root Ponteiro duplo para a raiz da árvore.
 * @param value Valor a ser inserido.
 */
void insertNode(Node** root, int value){
    if (*root == NULL){
        *root = creatNode(value);
        return;
    }

    if(value < (*root)->value){
        insertNode(&((*root)->left), value);
    }
    else{
        insertNode(&((*root)->right), value);
    }
}

/**
 * @brief Procura um nó com o valor especificado na árvore.
 * 
 * @param root Ponteiro para a raiz da árvore.
 * @param value Valor a ser procurado.
 * @return Ponteiro para o nó encontrado, ou NULL se o valor não for encontrado.
 */
Node *search(Node* root, int value){
    if(root == NULL) return NULL;
    if(root->value == value) return root;
    if(root->value < value) return search(root->right, value);
    else return search(root->left, value);
    
}

/**
 * @brief Imprime os valores dos nós da árvore em ordem crescente.
 * 
 * @param root Ponteiro para a raiz da árvore.
 */
void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

/**
 * @brief Calcula a altura do Node.
 * @param Node para calcular a altura 
 * @return Altura do node
*/
int h(Node* node){
    return (node == NULL) ? 0 : node->h;
}


/**
 * @brief Rotacionar arvore para direita.
 * @param node the node to rotate
 * @return A pointer to the new root node after rotation
*/
Node* rightRotate(Node* node){
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    // Update h
    node->h = 1 + fmax(h(node->left), h(node->right));
    newRoot->h = 1 + fmax(h(newRoot->left), h(newRoot->right));

    return newRoot;
}

/**
 * @brief Performs a left rotation.
 * @param node The node to rotate.
 * @return A pointer to the new root node after rotation.
 */
Node* leftRotate(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    // Update heights
    node->h = 1 + fmax(h(node->left), h(node->right));
    newRoot->h = 1 + fmax(h(newRoot->left), h(newRoot->right));

    return newRoot;
}

/**
 * @brief Balances a node in the AVL tree.
 * @param node The node to balance.
 * @return A pointer to the new root node after balancing.
 */
Node* balance(Node* node) {
    int balanceFactor = height(node->left) - height(node->right);

    // Left heavy
    if (balanceFactor > 1) {
        if (height(node->left->left) >= height(node->left->right)) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    // Right heavy
    if (balanceFactor < -1) {
        if (height(node->right->right) >= height(node->right->left)) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

int main(){
    Node* root = NULL;
    
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);
    
    printInOrder(root);
    return 0;
}