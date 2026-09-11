#include <stdio.h>
#include <stdlib.h>

int main (){

    int tam_seq;

    printf("Digite um tamanho para a sequencia: \n");

    while(scanf("%d", &tam_seq) == 1){
        
        int *vetor1 = malloc(tam_seq * sizeof(int));
        int *vetor2 = malloc(tam_seq * sizeof(int));
        int *resultado = malloc(tam_seq * sizeof(int));

        if(vetor1 == NULL || vetor2 == NULL || resultado == NULL){
            printf("Erro ao alocar a memoria! Encerrando o programa...");
            exit(1);
        }

        for(int i= 0; i < tam_seq; i++){
            printf("Digite um valor para a posicao [%d] do vetor 1: \n", i);
            scanf("%d", &vetor1[i]);
        }

        for(int i = 0; i < tam_seq; i++){
            printf("Digite um valor para a posicao [%d] do vetor 2\n", i);
            scanf("%d", &vetor2[i]);
        }

        int tam_col;
        printf("Digite o tamanho da coluna da matriz: \n");
        scanf("%d", &tam_col);

        for(int i = 0; i < tam_seq; i++){
            resultado[i] = vetor1[i] + vetor2[i];
        }

        for(int i =0; i < tam_seq; i++){

            printf("%d", resultado[i]);

            // Controle do espaço ou quebra de linha com base na coluna atual (X)
            if ((i + 1) % tam_col == 0) {
                printf("\n"); // Quebra a linha ao atingir o número máximo de colunas X
            } else if (i < tam_seq - 1) {
                printf(" ");  // Adiciona espaço entre os números da mesma linha
            }
        }
        
        // Se a última linha ficar incompleta (não bateu com múltiplo de X), pula uma linha
        if (tam_seq % tam_col != 0) {
            printf("\n");
        
        }

    free(vetor1);
    free(vetor2);
    free(resultado);

    }

    
    return 0;
}
