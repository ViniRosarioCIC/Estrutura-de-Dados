#ifndef FUNC_H
#define FUNC_H

typedef struct {
    int inicio;
    int fim;
} Intervalo;

void adicionar_intervalo(Intervalo **intervalos, int *total_intervalos, int inicio, int fim);

void verificar_ponto(Intervalo *intervalos, int total_intervalos, int ponto);

void liberar_intervalos(Intervalo *intervalos);

#endif
