#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void adicionar_intervalo(Intervalo **intervalos, int *total_intervalos, int inicio, int fim){

    Intervalo *ponteiro_temporario = realloc(*intervalos, (*total_intervalos + 1) * sizeof(Intervalo));

    if(ponteiro_temporario == NULL){
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    *intervalos = ponteiro_temporario;
    (*intervalos)[*total_intervalos].inicio = inicio;
    (*intervalos)[*total_intervalos].fim = fim;

    (*total_intervalos)++;
}

void verificar_ponto(Intervalo *intervalos, int total_intervalos, int ponto){
    int aux = 0;

    for (int i = 0; i < total_intervalos; i++){
        if(ponto >= intervalos[i].inicio && ponto <= intervalos[i].fim){
            printf("\nDentro do intervalo [%d, %d]\n", intervalos[i].inicio, intervalos[i].fim);
            aux = 1;
            break;
        }

        if(!aux){
            printf("\nFora de todos os intervalos: ");
        }
    }
}

void liberar_intervalos(Intervalo *intervalos){

    free(intervalos);

}