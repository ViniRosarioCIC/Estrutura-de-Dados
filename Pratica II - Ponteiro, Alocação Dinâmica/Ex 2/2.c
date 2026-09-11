#include <stdio.h>
#include <stdlib.h>

int main(){

    int nSequencias;

    printf("Digite o tamanho das sequencias: \n");

    while(scanf("%d", &nSequencias) == 1){

        int *seq1 = malloc(nSequencias * sizeof(int));
        int *seq2 = malloc(nSequencias * sizeof(int));

        if (seq1 == NULL || seq2 == NULL){
            printf("Erro de alocaçao de memoria! Encerrando programa...");
            exit(1);
        }

        for(int i=0; i < nSequencias; i++){
            printf("Digite um valor para a gaveta [%d] da sequencia [1]: \n", i+1);
            scanf("%d", &seq1[i]);
        }

        for(int i=0; i< nSequencias; i++){
            printf("Digite um valor para a gaveta [%d] da sequencai [2]: \n", i+1);
            scanf("%d", &seq2[i]);
        }
    
        for(int i = 0; i < nSequencias; i++){
            int soma = seq1[i] + seq2[nSequencias - 1 - i];

            printf("%d", soma);

            if(i < nSequencias - 1){
                printf(" ");
            }
        }
        printf("\n"); // Quebra de linha ao final de cada caso de teste
        free(seq1);
        free(seq2);
    }
 return 0;
}