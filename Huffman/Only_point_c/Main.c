#include "../Only_point_h/Compress.h"
#include "../Only_point_h/Decompress.h"

/** 
 * @brief Função principal que oferece a escolha entre compressão e descompressão.
 * 
 * Mostra um menu para o usuário, permitindo que ele escolha entre comprimir e descomprimir um arquivo. Em seguida, chama a função correspondente.
 */
int main(){

    int option; // Variável para armazenar a opção do usuário

    while(1){ // Loop infinito até que uma opção válida seja escolhida

        // Exibe o menu para o usuário
        printf("\tEscolha:\n");
        printf("\tDigite 1 para comprimir.\n");
        printf("\tDigite 2 para descomprimir.\n");
        printf("\t>> ");
        scanf("%d",&option); // Lê a opção do usuário
        getchar(); // Limpa o buffer

        // Avalia a opção escolhida pelo usuário
        if(option == 1){
            compress(); // Chama a função para compressão
            system("pause||echo"); // Pausa para visualização
            break; // Sai do loop
        }
        else if(option == 2){
            decompress(); // Chama a função para descompressão
            system("pause||echo"); // Pausa para visualização
            break; // Sai do loop
        }
        else{
            system("cls||clear"); // Limpa a tela
            printf("Opcao invalida! Tente Novamente.\n"); // Mensagem para opção inválida
        }
    }

    getchar(); // Mantém o console aberto até que o usuário pressione Enter
    return 0; // Finaliza o programa
}
