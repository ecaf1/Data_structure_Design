#include <stdio.h>
#include "AVL.h"
#include "BynaryTree.H"
#include <time.h>

typedef struct {
    int insert_AVL;
    int insert_BinaryTree;
    int item;
    int tree_size;
} Dados;


int main(){
    Dados dados[10000];
    FILE* arquivo = fopen("dados1.csv", "w");
    // Escreve o cabeçalho do CSV
    fprintf(arquivo, "insert_AVL,insert_BinaryTree,interactions,tree_size\n");

    Node* root_BinaryTree = NULL;
    Node_avl* root_avl = NULL;
    for (int i = 0; i < 9900; i++) {
        int cont1 = 0;
        int cont2 = 0;
        int num = rand() % 10000 + 1;
        root_avl = insertNode_avl(root_avl, num, &cont1);
        root_BinaryTree = insertNode(root_BinaryTree, num, &cont2);
        fprintf(arquivo, "%d,%d,%d,%d\n", cont1, cont2, num, i);
    }
    fclose(arquivo);
    return 0;
}