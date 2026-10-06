#include <stdio.h>
#include <stdlib.h>

int main (){

    int N;

    printf("Digite um valor para o tamanho das sequencias");
    
    while(scanf("%d", &N) == 1){

        int *sequencia1 = malloc(N * sizeof(int));
        int *sequencia2 = malloc(N * sizeof(int));

        if(sequencia1 == NULL || sequencia2 == NULL){
            printf("Erro! A memoria nao foi alocada!");
            exit(1);
        }

        printf("Preenchendo a primeira sequencia: ");
        for(int i = 0; i < N; i++){
            printf("\nDigite um valor para a posicao [%d]: ", i);
            scanf("%d", &sequencia1[i]);
        }

        printf("Preenchendo a segunda sequencia: ");
        for(int i = 0; i < N; i++){
            printf("\nDigite um valor para a posicao [%d]: ", i);
            scanf("%d", &sequencia2[i]);
            
        }
        
        int soma = 0;
        for(int i = 0; i < N; i++){
            soma = sequencia1[i] + sequencia2[N - i - 1];
             printf("%d", soma);
            
            // Adiciona um espaço após cada número, exceto no último
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n"); // Quebra de linha ao final de cada caso de teste
        
        free(sequencia1);
        free(sequencia2);

    }
}

