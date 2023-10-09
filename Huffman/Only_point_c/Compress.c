#include "../Only_point_h/Compress.h"

/**
 * @brief Conta a frequência de cada caractere no arquivo.
 * 
 * @param arquivo Ponteiro para o arquivo a ser lido.
 * @param array Array para armazenar a frequência de cada caractere.
 */
void frequency_count(FILE* arquivo, int* array) {
    BYTE character;
    while ((fscanf(arquivo, "%c", &character)) != EOF) {
        ++array[character];
    }
}

/**
 * @brief Adiciona um bit ao BYTE de saída na posição especificada.
 * 
 * @param c_saida BYTE de saída.
 * @param pos Posição onde adicionar o bit.
 * @return BYTE modificado.
 */
BYTE add_bit(BYTE c_saida, short int pos) {
    return (c_saida | (1 << (7 - pos)));
}

/**
 * @brief Escreve os dados comprimidos no arquivo de saída.
 * 
 * @param tabela Tabela de codificação de Huffman.
 * @param arquivo Arquivo de entrada.
 * @param saida Arquivo de saída.
 * @param tree_size Tamanho da árvore de Huffman.
 */
void write_compress(BYTE tabela[][150], FILE* arquivo, FILE* saida, int tree_size) {
    BYTE aux, character = 0, cond = 1;
    short int size = 0, position = 0;

    while ((fscanf(arquivo, "%c", &aux)) != EOF) {
        position = 0;
        while (tabela[aux][position] != '\0') {
            if (size == 8) {
                fprintf(saida, "%c", character);
                size = 0;
                character = 0;
            }
            if (tabela[aux][position] & 1) character = add_bit(character, size);
            ++size;
            ++position;
        }
    }
    BYTE lixo = (8 - size) << 5;
    fprintf(saida, "%c", character);
    fseek(saida, 0, SEEK_SET);
    lixo = lixo | tree_size >> 8;
    fprintf(saida, "%c", lixo);
    lixo = tree_size & 255;
    fprintf(saida, "%c", lixo);
}

/**
 * @brief Cria uma tabela de codificação de Huffman a partir da árvore de Huffman.
 * 
 * @param tabela Tabela de codificação.
 * @param bt Ponteiro para a árvore de Huffman.
 * @param string String temporária para armazenar códigos de Huffman.
 * @param position Posição na string temporária.
 */
void creat_table(BYTE tabela[][150], Tree* bt, BYTE* string, int position) {
    if (bt->left == NULL && bt->right == NULL) {
        string[position] = '\0';
        strncpy(tabela[bt->character], string, position + 1);
        return;
    }
    if (bt->left != NULL) {
        string[position] = '0';
        creat_table(tabela, bt->left, string, position + 1);
    }
    if (bt->right != NULL) {
        string[position] = '1';
        creat_table(tabela, bt->right, string, position + 1);
    }
}

/**
 * @brief Função principal para compressão.
 * 
 * Solicita ao usuário os nomes dos arquivos de entrada e saída, lê o arquivo de entrada,
 * constrói a árvore de Huffman e escreve os dados comprimidos no arquivo de saída.
 */
void compress() {
    char nome_entrada[200], nome_saida[200], aux[150];
    int frequency[256] = {0};
    FILE* arquivo;
    FILE* novo_arquivo;
    
    while (1) {
        printf("Digite o nome do arquivo: ");
        scanf("%[^\n]s", nome_entrada);
        getchar();
        arquivo = fopen(nome_entrada, "rb");
        if (arquivo == NULL) {
            printf("O nome do arquivo ou caminho é inválido!\n Tente novamente... :)");
            continue;
        }
        printf("Digite o nome do arquivo de saída:\n");
        scanf("%[^\n]s", nome_saida);
        getchar();
        break;
    }
    
    strcat(nome_saida, ".huff");
    frequency_count(arquivo, frequency);
    fseek(arquivo, 0, SEEK_SET);
    printf("Aguarde ... :)\n");
    Tree* bt = build_huffman_tree(frequency);
    BYTE tabela[256][150];
    creat_table(tabela, bt, aux, 0);
    novo_arquivo = fopen(nome_saida, "wb");
    int size_tree = creating_huffman_string(bt, novo_arquivo);
    write_compress(tabela, arquivo, novo_arquivo, size_tree);
    printf("Concluído!");
    fclose(arquivo);
    fclose(novo_arquivo);
}
