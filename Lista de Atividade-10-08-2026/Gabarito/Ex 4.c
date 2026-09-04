#include <stdio.h>

// Declaramos globalmente para evitar estouro de memória com 100.000 elementos
int codigos[100005];

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &codigos[i]);
    }
    
    // Algoritmo Bubble Sort (ordenação simples)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (codigos[j] > codigos[j + 1]) {
                // Troca de lugar
                int aux = codigos[j];
                codigos[j] = codigos[j + 1];
                codigos[j + 1] = aux;
            }
        }
    }
    
    int atual = codigos[0];
    int contagem = 1;
    
    // Conta e imprime as repetições
    for (int i = 1; i < n; i++) {
        if (codigos[i] == atual) {
            contagem++;
        } else {
            printf("%d %d\n", atual, contagem);
            atual = codigos[i];
            contagem = 1;
        }
    }
    
    // Imprime o último código avaliado
    printf("%d %d\n", atual, contagem);
    
    return 0;
}