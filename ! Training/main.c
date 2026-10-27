#include <stdio.h>
#include <stdlib.h>
#include "intervalo.h"

int main (){


int opcao;
int total_intervalos = 0;
Intervalo *lista_intervalos = NULL;

do {

    printf("\n====================");
    printf("\n\tMENU");
    printf("\n====================");

    printf("\n1 - Adicionar Intervalo");
    printf("\n2 - Verificar Ponto");
    printf("\n0 - Sair");

    printf("\n\nDigite uma opcao: ");
    while(scanf("%d", &opcao) != 1){
        printf("Erro! Digite uma opcao valida: ");

            while(getchar() != '\n');
    }

    switch(opcao){

        case 1: {
            int inicio, fim;
            printf("\nDigite um valor para o inicio do intervalo: ");
            scanf("%d", &inicio);
            printf("\n\nDigite um valor para o fim do intervalo: ");
            scanf("%d", &fim);
            adicionar_intervalo(&lista_intervalos, &total_intervalos, inicio, fim);


        } break;
        
        
        case 2: {
            int ponto;
            printf("\nDigite um ponto para começar a busca: ");
            scanf("%d", &ponto);
            verificar_ponto(lista_intervalos, total_intervalos, ponto);
            
        } break;

        case 0: {
            printf("\nFinalizando programa...\n");
        } break;

        default: {
            printf("\nOpcao invalida! Selecione uma opcao correta: \n");

        } break;
            
    }


} while(opcao != 0);

    free(lista_intervalos);

    return 0;
}