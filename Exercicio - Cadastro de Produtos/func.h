#pragma once

typedef struct {
    int Codigo;
    char Nome[30];
    float Preco;

} Produto;

Produto* alocar_vetor (int tamanho);

void ler_dados(Produto* vetor, int tamanho);

void exibir_produtos (Produto* vetor, int tamanho);

