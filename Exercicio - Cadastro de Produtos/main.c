#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){

    int qtd_produtos;
    printf("\nDigite a quantidade de produtos que serao cadastrados: ");
    scanf("%d", &qtd_produtos);

    Produto* prods = alocar_vetor(qtd_produtos);

    ler_dados(prods, qtd_produtos);

    exibir_produtos(prods, qtd_produtos);


    free(prods);
    
    return 0;
}