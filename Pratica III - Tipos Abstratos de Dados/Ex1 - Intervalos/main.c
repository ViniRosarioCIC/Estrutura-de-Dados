#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main (){

    Intervalo *intervalos = NULL;
    
    int total_intervalos=0;

    int opcao;

    //Construindo MENU
    do {

        printf("\n============= MENU ==============\n");
        printf("\n1 - Adicionar intervalo ");
        printf("\n2 - Verificar ponto ");
        printf("\n0 - Sair ");
        printf("\n===================================\n");
        printf("\nEscolha uma opcao: ");

        while (scanf("%d", &opcao) != 1){
            printf("\nDigite uma opcao valida! ");

                while(getchar() != '\n');

        }

    switch (opcao) {

        case 1: { 
            int inicio, fim;
            printf("Insira o inicio e o fim do intervalo: ");
            if(scanf("%d %d", &inicio, &fim) == 2){
                adicionar_intervalo(&intervalos, &total_intervalos, inicio, fim);
            
        } break;

        }

        case 2: {

            int ponto;
            printf("\nDigite um ponto para procurar: ");
            if(scanf("%d", &ponto) == 1){
                verificar_ponto(intervalos, total_intervalos, ponto);
            }
            break;
        }
        case 0: 
            break;

        default:
        printf("\nOpcao invalida. \n");
        break;
        
        }

    } while (opcao != 0);

    liberar_intervalos(intervalos);

    return 0;

}