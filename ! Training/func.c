#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

Produto* aloca_vetor (int quantidade){

    Produto* vetor = malloc(quantidade * sizeof(Produto));

    if (vetor == NULL){
        printf("Erro ao alocar a memoria!\n");
        exit(1);

    }

    return vetor;

}

void le_produtos (Produto* vetor, int quantidade){

    printf("Cadastrando produtos----------\n");
    for(int i = 0; i < quantidade; i++){
        printf("Produto %d\n", i+1);
        printf("\tDigite o codigo: \n");
        scanf("%d", &vetor[i].codigo);
        
        setbuf(stdin, NULL);
        printf("\tDigite o nome: \n");
        scanf(" %29[^\n]", vetor[i].nome);
        printf("\tDigite o preco: \n");
        scanf("%f", &vetor[i].preco);
    }

}

void exibe_produtos(Produto* vetor, int quantidade){

    for(int i = 0; i < quantidade; i++){
        printf("\n=========================\n");
        printf("Produto %d\n", i+1);
        
        printf("\tCodigo: %d\n", vetor[i].codigo);
        printf("\tNome: %s\n", vetor[i].nome);
        printf("\tPreco: %f\n", vetor[i].preco);
    }

}