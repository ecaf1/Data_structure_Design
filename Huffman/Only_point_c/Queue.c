/**
 * @file queue.c
 * @brief Arquivo de implementação para a fila de prioridades baseada na Árvore.
 *
 * Este arquivo fornece a implementação das funções definidas no arquivo de cabeçalho queue.h.
 */

#include "../Only_point_h/Queue.h"

/**
 * @brief Cria e retorna um novo objeto de fila de prioridades.
 * 
 * Esta função aloca espaço na memória para uma nova fila de prioridades e inicializa sua cabeça como NULL.
 * 
 * @return Um ponteiro para a nova fila de prioridades criada.
 */
priority_queue* creat_priority_queue() {
    priority_queue *new_pq = (priority_queue*) malloc(sizeof(priority_queue));
    new_pq->head = NULL;
    return new_pq;
}

/**
 * @brief Remove e retorna o nó de maior prioridade (menor frequência) da fila de prioridades.
 * 
 * @param pq Ponteiro para a fila de prioridades da qual o nó será removido.
 * @return Um ponteiro para o nó removido. Retorna NULL se a fila estiver vazia.
 */
Tree* dequeue(priority_queue *pq) {
    if (pq->head == NULL) return NULL;

    Tree *aux = pq->head;
    pq->head = pq->head->next;
    aux->next = NULL; // Desconecta o nó removido da fila
    return aux;
}

/**
 * @brief Insere um novo nó na fila de prioridades, mantendo a ordem de frequência.
 * 
 * Esta função insere um nó na fila de prioridades de acordo com a sua frequência.
 * Se a fila está vazia ou o nó tem frequência maior ou igual à cabeça da fila,
 * o novo nó torna-se a nova cabeça da fila.
 * 
 * @param new_node Ponteiro para o novo nó a ser inserido.
 * @param pq Ponteiro para a fila de prioridades onde o nó será inserido.
 */
void enqueue(Tree *new_node, priority_queue *pq) {
    if (pq->head == NULL || pq->head->frequency >= new_node->frequency) {
        new_node->next = pq->head;
        pq->head = new_node;
        return;
    }

    Tree *aux = pq->head;
    while (aux->next != NULL && aux->next->frequency < new_node->frequency) {
        aux = aux->next;
    }

    new_node->next = aux->next;
    aux->next = new_node;
    return;
}
