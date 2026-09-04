#include <stdio.h>

int main() {
    int n;
    
    // Leitura do nível da torre
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Casos base: níveis 1 e 2 sempre retornam 1
    if (n == 1 || n == 2) {
        printf("Energia: 1\n");
        return 0;
    }

    // Variáveis para a abordagem iterativa
    int anterior = 1; // Representa F(N-2)
    int atual = 1;    // Representa F(N-1)
    int proximo;      // Representa F(N)

    // Calcula a partir do nível 3 até o nível N desejado
    for (int i = 3; i <= n; i++) {
        proximo = anterior + atual; // Soma os dois de baixo
        anterior = atual;           // O que era atual vira o anterior
        atual = proximo;            // O atual passa a ser o novo valor calculado
    }

    // Impressão da saída conforme exigido pelo problema
    printf("Energia: %d\n", atual);

    return 0;
}