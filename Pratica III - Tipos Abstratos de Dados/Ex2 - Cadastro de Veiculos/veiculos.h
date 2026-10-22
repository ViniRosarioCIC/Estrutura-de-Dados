#pragma once

#define MAX_VEICULOS 150

typedef struct {

    char [10];
    char modelo[50];
    int ano;
    
} Veiculo;

void registrar_veiculo (Veiculo **estacionamento, int *total);

void listar_veiculos (Veiculo *estacionamento, int total);

void buscar_veiculo(Veiculo *estacionamento, int total);

void remover_veiculo(Veiculo **estacionamento, int *total);

