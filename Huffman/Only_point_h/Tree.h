/**
 * @file tree.h
 * @brief Arquivo de cabeçalho para o Tipo de Dado Abstrato Árvore
 *
 * Este arquivo fornece a API e as estruturas de dados necessárias para uma árvore binária
 * que armazena caracteres e suas respectivas frequências.
 */

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * @typedef BYTE
 * @brief Uma definição de tipo para um byte.
 */
typedef unsigned char BYTE;

/** 
 * @struct _tree
 * @brief Uma estrutura para os nós da árvore.
 *
 * Esta estrutura representa um nó na árvore binária.
 * Contém uma contagem de frequência, um caractere e ponteiros para o
 * próximo nó, filho à esquerda e filho à direita.
 */
typedef struct _tree Tree;

struct _tree {
    int frequency;  /**< Frequência do caractere */
    BYTE character; /**< O caractere armazenado no nó */
    Tree *next;     /**< Ponteiro para o próximo nó na lista */
    Tree *left;     /**< Ponteiro para o filho à esquerda */
    Tree *right;    /**< Ponteiro para o filho à direita */
};

/**
 * @brief Cria um novo nó para a árvore.
 * 
 * @param character Caractere a ser armazenado no nó.
 * @param frequency Frequência do caractere.
 * @return Um ponteiro para o novo nó.
 */
Tree* creat_node(BYTE character, int frequency);

/**
 * @brief Escreve a árvore no cabeçalho de um arquivo.
 * 
 * @param root Ponteiro para a raiz da árvore.
 * @param size Ponteiro para o tamanho do cabeçalho.
 * @param header Ponteiro para o arquivo onde o cabeçalho será escrito.
 */
void write_Tree(Tree *root, int *size, FILE *header);

#endif // TREE_H
