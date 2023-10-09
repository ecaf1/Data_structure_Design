/**
 * @file tree.c
 * @brief Arquivo de implementação para o Tipo de Dado Abstrato Árvore
 *
 * Este arquivo fornece a implementação das funções definidas no arquivo de cabeçalho tree.h.
 */

#include "../Only_point_h/Tree.h"

/**
 * @brief Cria e retorna um novo nó da árvore de Huffman.
 * 
 * Esta função recebe um caractere e uma frequência inteira como argumentos,
 * aloca um novo nó dinamicamente e inicializa seus campos com os valores recebidos.
 * 
 * @param character O caractere a ser armazenado no nó.
 * @param frequencia A frequência do caractere.
 * @return Um ponteiro para o novo nó criado.
 */
Tree* creat_node(BYTE character, int frequencia) {

    Tree *new_node = (Tree*) malloc(sizeof(Tree));
    new_node->character = character;
    new_node->frequency = frequencia;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/**
 * @brief Escreve a árvore de Huffman em um arquivo de cabeçalho.
 * 
 * Esta função recebe um ponteiro para a raiz da árvore, um ponteiro para um inteiro
 * que será utilizado para calcular o tamanho da árvore, e um ponteiro para o arquivo
 * de cabeçalho. A função percorre a árvore em pré-ordem e escreve cada nó no arquivo de cabeçalho.
 * 
 * @param root Ponteiro para a raiz da árvore.
 * @param size Ponteiro para o inteiro que será atualizado com o tamanho da árvore.
 * @param header Ponteiro para o arquivo onde o cabeçalho será escrito.
 */
void write_Tree(Tree *root, int *size, FILE *header) {

    if (root->left == NULL && root->right == NULL) {

        if (root->character == '\\' || root->character == '*') {
            BYTE aux = '\\';
            (*size)++;
            fprintf(header, "%c", aux);
        }

        (*size)++;
        fprintf(header, "%c", root->character);

        return;
    }
    
    (*size)++;
    fprintf(header, "%c", root->character);

    if (root->left != NULL) {
        write_Tree(root->left, size, header);
    }
    if (root->right != NULL) {
        write_Tree(root->right, size, header);
    }
}
