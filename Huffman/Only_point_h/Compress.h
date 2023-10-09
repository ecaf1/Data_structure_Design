#ifndef COMPRESS_H
#define COMPRESS_H

#include "../Only_point_h/Building.h"

/**
 * @brief Conta a frequência de cada byte em um arquivo.
 * 
 * @param arquivo Arquivo de entrada.
 * @param array Array para armazenar as frequências.
 */
void frequency_count(FILE* arquivo, int* array);

/**
 * @brief Adiciona um bit a um byte em uma posição específica.
 * 
 * @param c_saida O byte onde o bit será adicionado.
 * @param pos A posição onde o bit será adicionado.
 * @return O byte modificado.
 */
BYTE add_bit(BYTE c_saida, short int pos);

/**
 * @brief Executa a compressão.
 */
void compress();

/**
 * @brief Escreve os dados comprimidos em um arquivo de saída.
 * 
 * @param tabela A tabela de consulta para os códigos de Huffman.
 * @param arquivo O arquivo de entrada a ser comprimido.
 * @param saida O arquivo de saída onde os dados comprimidos serão escritos.
 * @param tree_size O tamanho da árvore de Huffman.
 */
void write_compress(BYTE tabela[][150], FILE* arquivo, FILE* saida, int tree_size);

/**
 * @brief Cria uma tabela de consulta para os códigos de Huffman.
 * 
 * @param tabela A tabela para armazenar os códigos de Huffman.
 * @param bt A raiz da árvore de Huffman.
 * @param string Uma string temporária para conter cada código de Huffman.
 * @param position A posição atual na string temporária.
 */
void creat_table(BYTE tabela[][150], Tree* bt, BYTE *string, int position);

#endif // COMPRESS_H
