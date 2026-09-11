#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void verificar_dois_int (int *xNum, int *yNum){

    if(scanf("%d %d", xNum, yNum) != 2){
        printf("Entrada invalida! Encerrando programa...\n");
        exit(1);

    }
    
}

void trocar_valores (int *xNum, int *yNum){

    int aux = *xNum;
    *xNum = *yNum;
    *yNum = aux;

}