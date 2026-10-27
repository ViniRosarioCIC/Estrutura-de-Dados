#pragma once

typedef struct {

    int inicio;
    int fim;

} Intervalo;

void adicionar_intervalo(Intervalo **lista_intervalos, int *total_intervalos, int inicio, int fim);

void verificar_ponto(Intervalo *lista_intervalos, int total_intervalos, int ponto);
