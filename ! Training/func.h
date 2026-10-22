#pragma once


typedef struct {

    int codigo;
    char nome[30];
    float preco;

} Produto;


Produto* aloca_vetor (int quantidade);

void le_produtos(Produto* vetor, int quantidade);

void exibe_produtos (Produto* vetor, int quantidade);