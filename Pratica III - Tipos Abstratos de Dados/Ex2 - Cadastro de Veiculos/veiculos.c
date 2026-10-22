#include <stdio.h>
#include <stdlib.h>
#include "veiculos.h"
#include <string.h>

void registrar_veiculo(Veiculo **estacionamento, int *total){

    if(*total >= MAX_VEICULOS){
        printf("\nErro: Estacionamento lotado (limite de veiculos atingidos, max:150)");
        return;
    }

    Veiculo *temp = realloc(*estacionamento), (*total + 1) * sizeof(Veiculo);

    if (temp == NULL){
        printf("\nErro ao alocar memoria! Encerrando programa...");
        exit(1);
    }

    *estacionamento = temp;

    printf("\n --- Novo Registro ---\n");
    printf("Digite a placa: ");
    scanf(" %9s", (*estacionamento)[*total].placa);

    printf("\nDigite o modelo: ");
    setbuf(stdin, NULL);
    scanf(" %49[^\n]", (*estacionamento)[*total].modelo)

    printf("\nDigite o ano de fabricacao: ");
    scanf("%d", &(*estacionamento)[*total].modelo);

    (*total)++;
    printf("\n=> Veiculo registrado com sucesso!\n");

}