#include <stdio.h>
#include <stdlib.h>
#include "estacionamento.h" // Importa o nosso módulo

int main() {
    Veiculo *lista_veiculos = NULL; 
    int total_veiculos = 0;
    int opcao;

    do {
        // Menu de opções[cite: 2]
        printf("\n=====================================\n");
        printf("       CONTROLE DE ESTACIONAMENTO    \n");
        printf("=====================================\n");
        printf("1. Registrar Veiculo\n");
        printf("2. Listar Veiculos\n");
        printf("3. Buscar Veiculo pela Placa\n");
        printf("4. Remover Veiculo pela Placa\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida! Encerrando o sistema...\n");
            // Limpeza de buffer de segurança antes de sair
            while(getchar() != '\n'); 
            break;
        }

        switch (opcao) {
            case 1:
                registrar_veiculo(&lista_veiculos, &total_veiculos);
                break;
            case 2:
                listar_veiculos(lista_veiculos, total_veiculos);
                break;
            case 3:
                buscar_veiculo(lista_veiculos, total_veiculos);
                break;
            case 4:
                remover_veiculo(&lista_veiculos, &total_veiculos);
                break;
            case 5:
                printf("\nEncerrando a aplicacao...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    // Limpeza da memória alocada dinamicamente ao sair
    if (lista_veiculos != NULL) {
        free(lista_veiculos);
        printf("Memoria liberada com sucesso.\n");
    }

    return 0;
}
