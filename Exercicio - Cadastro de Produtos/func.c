#include <stdio.h>
#include <stdlib.h>
#include "func.h"

Produto* alocar_vetor (int tamanho){

    Produto* vetor = (Produto*) malloc(tamanho * sizeof(Produto));

    if(vetor == NULL){
        printf("Erro ao alocar memoria! Encerrando programa...");
        exit(1);
    }

    return vetor;
}

void ler_dados(Produto* vetor, int tamanho){

    printf("\n======== CADASTRANDO PRODUTOS ========\n");
    for(int i = 0; i < tamanho; i++){
        printf("\nProduto [%d] -----------", i+1);

            printf("\nDigite o codigo do produto: ");
            scanf("%d", &vetor[i].Codigo);
            printf("\nDigite o nome do produto: ");
            scanf(" %[^\n]", vetor[i].Nome);
            printf("\nDigite preco do produto: ");
            scanf("%f", &vetor[i].Preco);   
    }
}

void exibir_produtos(Produto* vetor, int tamanho){

    printf("\n======== TABELA DE PRODUTOS ========\n");
    for(int i = 0; i < tamanho; i++){
        printf("\n\nProduto [%d] -----------", i+1);

            printf("\nCodigo: %d", vetor[i].Codigo);
            printf("\nNome: %s", vetor[i].Nome);
            printf("\nPreco: %.2f", vetor[i].Preco);    
    }   
}