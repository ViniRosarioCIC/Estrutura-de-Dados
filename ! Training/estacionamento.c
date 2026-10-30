#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamento.h"


void registrar_veiculo (Veiculo **lista_veiculos, int *total){

    if(*total >= MAX_VEICULOS){
        printf("O total de veiculos foi atingido (Max.150)!!!\n");
        return;
    }

    Veiculo *aux = realloc (*lista_veiculos, (*total + 1) * sizeof(Veiculo)); //reallocando

    if (aux == NULL){
        printf("Erro ao alocar memoria! Encerrando...\n");
        exit(1);
    }

    *lista_veiculos = aux;

    printf("\n--- CADASTRANDO VEICULO N.%d -----\n", (*total) + 1);

    printf("Digite a placa: \n");
    scanf("%9s", (*lista_veiculos)[*total].placa);

    printf("Digite o modelo: \n");
    scanf(" %39[^\n]", (*lista_veiculos)[*total].modelo );

    printf("Digite o ano de fabricacao: \n");
    scanf("%d", &(*lista_veiculos)[*total].ano);

    (*total)++;
    printf("\n>>> Veiculo registrado com sucesso!!!\n");

}

void listar_veiculos (Veiculo *lista_veiculos, int total){

    if(total == 0){
        printf("O estacionamento esta vazio!\n");
        return;
    }

    printf("\n--- VEICULOS CADASTRADOS ---\n");
    for(int i = 0; i < total; i++){
        printf("Veiculo [%d]\n", i+1);
        printf("Placa: %s\n", lista_veiculos[i].placa );
        printf("Modelo: %s\n", lista_veiculos[i].modelo);
        printf("Ano: %d\n", lista_veiculos[i].ano);
        printf("---\n\n");
    }

}

void buscar_veiculo (Veiculo *lista_veiculos, int total){

    if(total == 0){
        printf("O estacionamento esta vazio!!!\n");
        return;
    }

    char placa_buscada[10];
    printf("\nDigite a placa para buscar: ");
    scanf("%9s", placa_buscada);

    for(int i = 0; i < total; i++){
        // CORREÇÃO 1: Faltava a letra 'c' no strcmp
        if(strcmp(lista_veiculos[i].placa, placa_buscada) == 0){
            printf("\n>>> Veiculo encontrado!\n\n");
            printf("Placa: %s\n", lista_veiculos[i].placa);
            printf("Modelo %s\n", lista_veiculos[i].modelo);
            printf("Ano: %d\n", lista_veiculos[i].ano);
            printf("---\n\n");
            return;
        }
    }
    
    // Opcional: Adicionado aviso caso percorra tudo e não ache
    printf("\n>>> Veiculo com a placa %s nao encontrado.\n", placa_buscada);
}

void remover_veiculo(Veiculo **lista_veiculos, int *total){

    if(*total == 0){
        printf("O estacionamento esta vazio!!!\n");
        return;
    }

    char placa_buscada[10];
    printf("\nDigite a placa para remover: ");
    scanf("%9s", placa_buscada);

    int pos = -1;

    for(int i = 0; i < *total; i++){
        if (strcmp ((*lista_veiculos)[i].placa, placa_buscada) == 0){
            // CORREÇÃO 2: pos deve receber o índice 'i', e não o número fixo '1'
            pos = i; 
            break;
        }
    }

    if(pos == -1){
        printf("\n>>> Veiculo com a placa %s nao foi encontrado\n", placa_buscada);
        return;
    }

    // CORREÇÃO 3: Faltava o ponto e vírgula ';' no final da linha dentro do for
    for(int i = pos; i < *total - 1; i++){
        (*lista_veiculos)[i] = (*lista_veiculos)[i+1]; 
    }

    (*total)--;

    if(*total > 0){
        Veiculo *aux = realloc(*lista_veiculos, (*total) * sizeof(Veiculo));
        if(aux != NULL){
            *lista_veiculos = aux;
        }
    } else {
        // CORREÇÃO 4: O free deve ser feito no conteúdo do ponteiro (*lista_veiculos) e não no ponteiro duplo
        free(*lista_veiculos);
        *lista_veiculos = NULL;
    }

    printf("\n>>> Veiculo removido com sucesso!\n");
}
