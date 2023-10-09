/**
 * @file queue.h
 * @brief Arquivo de cabeçalho para a fila de prioridades com base na Árvore
 *
 * Este arquivo contém a definição da estrutura e das funções de uma fila de prioridades,
 * que são utilizadas para manipular nós da árvore de Huffman.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../Only_point_h/Tree.h"

/**
 * @struct priority_q
 * @brief Estrutura para fila de prioridades.
 *
 * Esta estrutura representa a fila de prioridades utilizada para manipular
 * nós da árvore de Huffman. Contém um ponteiro para a cabeça da lista de nós.
 */
typedef struct priority_q priority_queue;

struct priority_q {
    Tree *head; /**< Ponteiro para o primeiro nó da fila de prioridades */
};

/**
 * @brief Cria uma nova fila de prioridades e retorna o ponteiro para ela.
 * 
 * @return Um ponteiro para a nova fila de prioridades criada.
 */
priority_queue* creat_priority_queue();

/**
 * @brief Insere um nó na fila de prioridades de acordo com a sua frequência.
 * 
 * @param node Ponteiro para o nó da árvore a ser inserido.
 * @param pq Ponteiro para a fila de prioridades onde o nó será inserido.
 */
void enqueue(Tree *node, priority_queue *pq);

/**
 * @brief Remove e retorna o nó com menor frequência da fila de prioridades.
 * 
 * @param pq Ponteiro para a fila de prioridades da qual o nó será removido.
 * @return Um ponteiro para o nó removido.
 */
Tree* dequeue(priority_queue *pq);

#endif // QUEUE_H
