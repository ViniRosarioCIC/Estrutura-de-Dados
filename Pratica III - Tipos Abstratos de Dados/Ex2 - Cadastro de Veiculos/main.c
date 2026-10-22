#include <stdio.h>
#include <stdlib.h>
#include "veiculos.h"

int main (){

    int opcao;
    

    do {

        printf("\n==================================\n");
        printf("\n\tCONTROLE DE ESTACIONAMENTO\n");
        printf("\n==================================\n");
        
        printf("1: Registrar Veiculo");
        printf("\n2: Listar Veiculos");
        printf("\n3: Buscar Veiculo pela Placa");
        printf("\n4: Remover Veiculo pela Placa");
        printf("\n0: Sair");

        printf("\n\nEscolha uma opcao: ");

        while(scanf("%d", &opcao) != 1){
            printf("\nEntrada invalida! Digite novamente: ");

                while(getchar() != '\n');
        }

        switch(opcao) {

            case 1: 
            
            case 2:

            case 3:

            case 4:

            case 0:

            default:
            
        }
    }

}