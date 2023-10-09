#include "../Only_point_h/Decompress.h"

/** 
 * @brief Realiza a descompressão de um arquivo.
 * 
 * @param bt Ponteiro para a raiz da árvore de Huffman.
 * @param entrada Ponteiro para o arquivo de entrada.
 * @param saida Ponteiro para o arquivo de saída.
 * @param lixo Tamanho do lixo presente no arquivo de entrada.
 */
void write_decompress(Tree *bt, FILE *entrada, FILE *saida, int lixo){
    Tree *aux = bt;
    BYTE character, aux1;
    int i;

    fscanf(entrada, "%c", &character);
    aux1 = character;

    while(fscanf(entrada, "%c", &character) != EOF){
        for(i = 7; i >= 0; i--){
            if(aux->left == NULL && aux->right == NULL){
                fprintf(saida,"%c",aux->character);
                aux = bt;
            }
            if(aux1 & 1<<i)
                aux = aux->right;
            else
                aux = aux->left;
        }
        aux1 = character;
    }
    for(i = 7; lixo <= 8; lixo++, i--){
        if(aux->left == NULL && aux->right == NULL){
            fprintf(saida,"%c",aux->character);
            aux = bt;
        }
        if(aux1 & 1<<i)
            aux = aux->right;
        else
            aux = aux->left;
    }
    return;
}

/** 
 * @brief Verifica se o arquivo é válido para descompressão.
 * 
 * @param nome Nome do arquivo para verificação.
 * @return 0 se o arquivo é válido, 1 caso contrário.
 */
int verification(char *nome){
    int condition = 0,i,j,size = strlen(nome);
    char *huff;
    huff = ".huff";

    for(i = size-1,j = 4 ; i>size-6 ; i--,j--)
        if(huff[j] != nome[i]) condition = 1;

    if(condition){
        printf("Nao se trata de um arquivo compactado.\nArquivos compactados devem ter a extensao: .huff\n");
        system("pause||echo");
    }
    return condition;
}

/** 
 * @brief Inicia o processo de descompressão de um arquivo.
 * 
 * Realiza a leitura dos nomes dos arquivos de entrada e saída, verifica a validade do arquivo de entrada e chama a função write_decompress para realizar a descompressão.
 */
void decompress(){
    char nome_entrada[100], nome_saida[100];
    FILE *arquivo_entrada;
    FILE *arquivo_saida;
    BYTE character;
    int lixo, size_tree = 0, i;
    Tree *bt = NULL;

    while(1){
        system("cls||clear");
        printf("Digite o nome do arquivo:\n");
        scanf("%[^\n]s", nome_entrada);
        getchar();

        arquivo_entrada = fopen(nome_entrada, "rb");
        if(arquivo_entrada == NULL){
            printf("O nome do arquivo ou caminho invalido!\n Tente novamente... :)");
            system("pause||echo");
            continue;
        }
        if(verification(nome_entrada)) continue;
        printf("O nome do arquivo de saida:\n");
        scanf("%[^\n]s", nome_saida);
        getchar();
        break;
    }

    system("cls||clear");
    printf("Aguarde ...\n");

    // LÊ TAMANHO DO LIXO
    fscanf(arquivo_entrada, "%c", &character);
    lixo = character>>5;

    // LÊ O TAMANHO DA ARVORE
    size_tree = character & 0b00011111;
    size_tree = size_tree << 8;
    fscanf(arquivo_entrada, "%c", &character);
    size_tree = size_tree | character;

    system("cls||clear");
    printf("Aguarde ... :)\n");

    if(size_tree == 2) bt = (Tree*)func_exception(arquivo_entrada);
    else bt = rebuild_huffman_tree(arquivo_entrada);

    arquivo_saida = fopen(nome_saida, "wb");

    write_decompress(bt, arquivo_entrada, arquivo_saida, lixo);

    printf(" Concluido!\n");

    fclose(arquivo_saida);
    fclose(arquivo_entrada);
    return;
}
