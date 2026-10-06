#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h" // Importa as definições do cabeçalho

// Variáveis globais restritas a este módulo para controle do histórico
char **historico = NULL;
int total_consultas = 0;

void registrar_historico(const char *consulta) {
    historico = realloc(historico, (total_consultas + 1) * sizeof(char*));
    if (historico == NULL) {
        printf("Erro ao alocar memoria para o historico.\n");
        exit(1);
    }
    historico[total_consultas] = malloc(81 * sizeof(char));
    strcpy(historico[total_consultas], consulta);
    total_consultas++;
}

int consultar_expressao(Expressao **inicio, Expressao **fim, int *tamanho, int capacidade, const char *busca) {
    Expressao *atual = *inicio;
    int pos = 1;

    registrar_historico(busca);

    // Procura a expressao na lista
    while (atual != NULL) {
        if (strcmp(atual->descricao, busca) == 0) {
            if (pos == 1) {
                return 1;
            }

            // Expressão encontrada: troca de posição com o nó anterior
            Expressao *anterior = atual->ant;
            Expressao *ant_ant = anterior->ant;
            Expressao *proximo = atual->prox;

            if (ant_ant != NULL) {
                ant_ant->prox = atual;
            } else {
                *inicio = atual;
            }

            if (proximo != NULL) {
                proximo->ant = anterior;
            } else {
                *fim = anterior;
            }

            atual->ant = ant_ant;
            atual->prox = anterior;
            anterior->ant = atual;
            anterior->prox = proximo;

            return pos - 1;
        }
        atual = atual->prox;
        pos++;
    }

    // Caso a lista atinja sua capacidade máxima, remove o menos acessado (último)
    if (*tamanho == capacidade && capacidade > 0) {
        Expressao *remover = *fim;
        if (remover->ant != NULL) {
            *fim = remover->ant;
            (*fim)->prox = NULL;
        } else { 
            *inicio = NULL;
            *fim = NULL;
        }
        free(remover);
        (*tamanho)--;
    }

    // Insere a nova expressão no final da lista[cite: 1]
    Expressao *novo = (Expressao *)malloc(sizeof(Expressao));
    strcpy(novo->descricao, busca);
    novo->prox = NULL;

    if (*inicio == NULL) {
        novo->ant = NULL;
        *inicio = novo;
        *fim = novo;
    } else {
        novo->ant = *fim;
        (*fim)->prox = novo;
        *fim = novo;
    }
    
    (*tamanho)++;
    return *tamanho;
}

void exibir_crescente(Expressao *inicio) {
    Expressao *atual = inicio;
    int pos = 1;
    if (atual == NULL) {
        printf("A lista de ranking esta vazia.\n");
        return;
    }
    printf("\n--- Ranking (Crescente) ---\n");
    while (atual != NULL) {
        printf("%d. %s\n", pos++, atual->descricao);
        atual = atual->prox;
    }
}

void exibir_decrescente(Expressao *fim) {
    Expressao *atual = fim;
    if (atual == NULL) {
        printf("A lista de ranking esta vazia.\n");
        return;
    }
    printf("\n--- Ranking (Decrescente) ---\n");
    while (atual != NULL) {
        printf("- %s\n", atual->descricao);
        atual = atual->ant;
    }
}

void exibir_historico(int n) {
    if (total_consultas == 0) {
        printf("Nenhum historico disponivel.\n");
        return;
    }
    
    int inicio_hist = total_consultas - n;
    if (inicio_hist < 0) inicio_hist = 0; 
    
    printf("\n--- Ultimas %d consultas ---\n", (total_consultas - inicio_hist));
    for (int i = total_consultas - 1; i >= inicio_hist; i--) {
        printf("-> %s\n", historico[i]);
    }
}

void liberar_memoria(Expressao *inicio) {
    Expressao *atual = inicio;
    while (atual != NULL) {
        Expressao *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    for (int i = 0; i < total_consultas; i++) {
        free(historico[i]);
    }
    free(historico);
}