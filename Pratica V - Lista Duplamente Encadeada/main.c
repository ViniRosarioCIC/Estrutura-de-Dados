#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h" // Inclui as declarações das suas funções

int main() {
    Expressao *inicio = NULL;
    Expressao *fim = NULL;
    int tamanho_atual = 0;
    int capacidade_maxima;

    // O programa deve solicitar o tamanho máximo ao usuário logo no início
    printf("Digite a capacidade maxima da lista de ranking: ");
    if (scanf("%d", &capacidade_maxima) != 1 || capacidade_maxima <= 0) {
        printf("Entrada invalida! Encerrando...\n");
        exit(1);
    }
    getchar(); // Limpar o buffer do teclado

    int opcao;
    do {
        printf("\n==========================================\n");
        printf("1. Consultar uma expressao\n");
        printf("2. Exibir todas as expressoes em ordem crescente de ranking\n");
        printf("3. Exibir todas as expressoes em ordem decrescente de ranking\n");
        printf("4. Exibir o historico das ultimas N consultas\n");
        printf("5. Encerrar o programa\n");
        printf("==========================================\n");
        printf("Escolha uma opcao: ");
        
        if(scanf("%d", &opcao) != 1) {
            printf("Opcao invalida. Encerrando...\n");
            break;
        }
        getchar();

        switch (opcao) {
            case 1: {
                char busca[81];
                printf("Digite a expressao consultada (max 80 caracteres): ");
                fgets(busca, 81, stdin);
                busca[strcspn(busca, "\n")] = '\0'; 
                
                int pos_final = consultar_expressao(&inicio, &fim, &tamanho_atual, capacidade_maxima, busca);
                printf("=> Expressao processada! Posicao final no ranking: %d\n", pos_final);
                break;
            }
            case 2:
                exibir_crescente(inicio);
                break;
            case 3:
                exibir_decrescente(fim);
                break;
            case 4: {
                int n;
                printf("Quantas ultimas consultas deseja exibir (N)? ");
                scanf("%d", &n);
                getchar();
                exibir_historico(n);
                break;
            }
            case 5:
                printf("Encerrando o programa e liberando memoria...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    liberar_memoria(inicio);
    return 0;
}