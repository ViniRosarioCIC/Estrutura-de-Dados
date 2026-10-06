#ifndef HEADER_H
#define HEADER_H

// Struct
struct expressao {
    char descricao[81];
    struct expressao *prox, *ant;
};
typedef struct expressao Expressao;

// Declaração das funções
void registrar_historico(const char *consulta);
int consultar_expressao(Expressao **inicio, Expressao **fim, int *tamanho, int capacidade, const char *busca);
void exibir_crescente(Expressao *inicio);
void exibir_decrescente(Expressao *fim);
void exibir_historico(int n);
void liberar_memoria(Expressao *inicio);

#endif