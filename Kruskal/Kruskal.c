#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @struct Edege
 * @brief Representa uma aresta em um grafico poderado.
 * 
 * Essa estrutura é usada para representar uma única aresta em um grafo ponderado.
 * Cada aresta tem um vértice de origem(src), um vértice de destino (dest) e um peso (weight)
*/
typedef struct Edge{
    int src, dest, weight;
}Edge;

/**
 * @struct Subset
 * @brief Representa um conjunto disjunto em uma estrutura de dados Union-Find.
 *
 * Essa estrutura é usada para implementar um conjunto disjunto na estrutura de dados Union-Find. 
 * Cada objeto `Subset` mantém informações sobre o conjunto a que pertence um elemento.
 */
typedef struct Subset {
    int parent, rank;
}Subset;

int find(Subset subsets[], int i){
    if (subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if  (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void BubbleSortEdge(Edge edges[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void shuffle(struct Edge edges[], int n) {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Edge temp = edges[i];
        edges[i] = edges[j];
        edges[j] = temp;
    }
}

int main(){
    int V = 9; // Número de vértices
    int E = 17; // Número de arestas é agora 12
    struct Edge edges[E];

    // Definindo as arestas e os seus pesos
    edges[0].src = 1;  edges[0].dest = 3;  edges[0].weight = 9;
    edges[1].src = 1;  edges[1].dest = 4;  edges[1].weight = 6;
    edges[2].src = 1;  edges[2].dest = 2;  edges[2].weight = 10;
    edges[3].src = 1;  edges[3].dest = 5;  edges[3].weight = 12;
    edges[4].src = 2;  edges[4].dest = 5;  edges[4].weight = 8;
    edges[5].src = 3;  edges[5].dest = 4;  edges[5].weight = 7;
    edges[6].src = 3;  edges[6].dest = 6;  edges[6].weight = 5;
    edges[7].src = 4;  edges[7].dest = 6;  edges[7].weight = 8;
    edges[8].src = 4;  edges[8].dest = 7;  edges[8].weight = 7;
    edges[9].src = 4;  edges[9].dest = 5;  edges[9].weight = 8;
    edges[10].src = 5; edges[10].dest = 7; edges[10].weight = 4;  
    edges[11].src = 5; edges[11].dest = 9; edges[11].weight = 13;
    edges[12].src = 6; edges[12].dest = 7; edges[12].weight = 14;
    edges[13].src = 6; edges[13].dest = 8; edges[13].weight = 6;
    edges[14].src = 7; edges[14].dest = 8; edges[14].weight = 8;
    edges[15].src = 7; edges[15].dest = 9; edges[15].weight = 8;
    edges[16].src = 8; edges[16].dest = 9; edges[16].weight = 10;
    shuffle(edges, E); 
    BubbleSortEdge(edges, E);
    for (int i = 0; i < E; i++) {
        printf("Edge (%d, %d, %d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
    Subset* subsets = (Subset*) malloc((V+1) * sizeof(Subset));
    for (int v = 0; v <= V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    Edge result[V-1];
    int e = 0, i = 0;
    while (e < V-1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }
    printf("Arestas da AGM:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    
    free(subsets);
    return 0;
}