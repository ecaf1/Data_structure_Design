#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include "../Only_point_h/Building.h"

/**
 * @brief Escreve o arquivo descomprimido.
 * 
 * @param bt A raiz da árvore de Huffman.
 * @param entrada O arquivo de entrada comprimido.
 * @param saida O arquivo de saída descomprimido.
 * @param lixo A quantidade de bits de preenchimento no arquivo comprimido.
 */
void write_decompress(Tree *bt, FILE *entrada, FILE *saida, int lixo);

/**
 * @brief Verifica a validade do arquivo a ser descomprimido.
 * 
 * @param nome O nome do arquivo a ser verificado.
 * @return Retorna 1 se o arquivo é válido, caso contrário retorna 0.
 */
int verification(char *nome);

/**
 * @brief Realiza a descompressão do arquivo.
 */
void decompress();

#endif // DECOMPRESS_H
