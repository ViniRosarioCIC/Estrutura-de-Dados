#include <stdio.h>
#include <stdlib.h>
#include "espelhado.h"

int main (){

    int N;
    printf("Digite a quantidade de numeros do conjunto: \n");
    scanf("%d", &N);

    int *vetor = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        printf("Digite um numero: \n");
        scanf("%d", &vetor[i]);

    }

    int qEspelhados = verifica_espelhados(vetor, N);

    printf("Quantidade de espelhados: %d", qEspelhados);

    free(vetor);
    return 0;
}