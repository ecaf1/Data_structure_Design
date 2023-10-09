/**
 * @file your_file_name.c  // Substitua com o nome real do seu arquivo
 * @brief Implementação das funções de construção e manipulação de Árvores de Huffman.
 *
 * Este arquivo contém a implementação das funções necessárias para construir e manipular Árvores de Huffman,
 * bem como criar strings Huffman e reconstruir a árvore a partir de um arquivo.
 */

#include "../Only_point_h/Tree.h"
#include "../Only_point_h/Queue.h"

/**
 * @brief Função para tratar exceções durante a leitura de arquivo.
 * 
 * @param arquivo Ponteiro para o arquivo que está sendo lido.
 * @return Um ponteiro para a Árvore de Huffman em caso de sucesso, ou NULL em caso de falha.
 */
Tree *func_exception(FILE *arquivo);  // WRITE: FILE -> TREE

/**
 * @brief Reconstrói a Árvore de Huffman a partir de um arquivo.
 * 
 * @param arquivo Ponteiro para o arquivo que contém a Árvore de Huffman.
 * @return Um ponteiro para a Árvore de Huffman reconstruída.
 */
Tree* rebuild_huffman_tree(FILE *arquivo);

/**
 * @brief Constrói a Árvore de Huffman com base em um array de frequências.
 * 
 * @param array Ponteiro para o array de inteiros que contém as frequências dos caracteres.
 * @return Um ponteiro para a Árvore de Huffman construída.
 */
Tree* build_huffman_tree(int *array);

/**
 * @brief Constrói a Árvore de Huffman a partir de uma fila de prioridades.
 * 
 * @param pq Ponteiro para a fila de prioridades que contém os nós para construir a árvore.
 * @return Um ponteiro para a Árvore de Huffman construída.
 */
Tree *build_Tree(priority_queue *pq);

/**
 * @brief Cria uma string Huffman e escreve no cabeçalho de um arquivo.
 * 
 * @param huffman Ponteiro para a Árvore de Huffman que será utilizada para criar a string.
 * @param header Ponteiro para o arquivo onde o cabeçalho será escrito.
 * @return O tamanho da string Huffman criada.
 */
int creating_huffman_string(Tree *huffman, FILE *header);
