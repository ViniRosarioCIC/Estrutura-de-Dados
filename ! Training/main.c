#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){


    int q;
    printf("Digite quantos produtos serao cadastrados: ");
    scanf("%d", &q);

    Produto* lista = aloca_vetor(q);

    le_produtos(lista, q);

    exibe_produtos(lista, q);

    free(lista);

    return 0;
}