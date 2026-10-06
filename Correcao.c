#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    // Continua lendo até encontrar o final da entrada (EOF)
    while (scanf("%d", &N) == 1) {
        
        // Alocação dinâmica solicitando espaço exato para N inteiros
        int *seq1 = malloc(N * sizeof(int));
        int *seq2 = malloc(N * sizeof(int));

        // Regra de ouro da verificação: checa se a memória foi alocada com sucesso
        if (seq1 == NULL || seq2 == NULL) {
            printf("Erro de alocacao de memoria! Encerrando programa...\n");
            exit(1); 
        }

        // Leitura da primeira sequência
        for (int i = 0; i < N; i++) {
            scanf("%d", &seq1[i]);
        }

        // Leitura da segunda sequência
        for (int i = 0; i < N; i++) {
            scanf("%d", &seq2[i]);
        }

        // Realiza a soma cruzada e imprime o resultado
        for (int i = 0; i < N; i++) {
            // Soma o elemento atual da seq1 com o elemento oposto da seq2
            int soma = seq1[i] + seq2[N - 1 - i];
            
            printf("%d", soma);
            
            // Adiciona um espaço após cada número, exceto no último
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n"); // Quebra de linha ao final de cada caso de teste

        // Liberação manual obrigatória da memória alocada
        free(seq1);
        free(seq2);
    }

    return 0;
}