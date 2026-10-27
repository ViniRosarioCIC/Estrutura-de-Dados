#include <stdio.h>
#include <stdlib.h>
#include "intervalo.h"

void adicionar_intervalo(Intervalo **lista_intervalos, int *total_intervalos, int inicio, int fim){

    Intervalo *aux = realloc(*lista_intervalos, (*total_intervalos + 1) * sizeof(Intervalo));

    if(aux == NULL){
        printf("Erro ao alocar memoria! Encerrando programa...\n");
        exit(1);
    }

    *lista_intervalos = aux;

    
(*lista_intervalos)[*total_intervalos].inicio = inicio;
(*lista_intervalos)[*total_intervalos].fim = fim;
(*total_intervalos)++;

}


void verificar_ponto(Intervalo *lista_intervalo, int total_intervalos, int ponto){

    int aux = 0;
    for(int i = 0; i < total_intervalos; i++){
        if(ponto >= lista_intervalo[i].inicio && ponto <= lista_intervalo[i].fim){
            printf("\nPonto dentro do intervalo [%d, %d].\n", lista_intervalo[i].inicio, lista_intervalo[i].fim);
            aux = 1;
        }
    }
    if(aux == 0){
        printf("\nFora de todos os intervalos!");

    }

}