#include <stdio.h>
#include <stdlib.h>
#include "espelhado.h"

int verifica_espelhados (int xvetor[], int tamanho){

    int num_original, espelhado, digito, contagem = 0;
    for(int i = 0; i < tamanho; i ++){
        espelhado = 0;
        num_original = xvetor[i];
        
        while(num_original > 0){
            digito = num_original % 10;
            espelhado = (espelhado * 10) + digito;
            num_original = num_original / 10;

        }

        if(num_original == espelhado){
            contagem++;
        }
    }

    return contagem;

}