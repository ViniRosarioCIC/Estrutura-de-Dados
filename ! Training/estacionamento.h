#pragma once

#define MAX_VEICULOS 150

typedef struct {

    char placa [10];
    char modelo [40];
    int ano;
    
} Veiculo;

void registrar_veiculo (Veiculo **lista_veiculos, int *total);

void listar_veiculos (Veiculo *lista_veiculos, int total);

void buscar_veiculo (Veiculo *lista_veiculos, int total);

void remover_veiculo (Veiculo **lista_veiculos, int *total);

