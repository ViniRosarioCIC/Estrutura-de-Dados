#include <stdio.h>

int main() {
    int n, numero, original, invertido, digito;
    int contagem = 0;

    // Lê a quantidade de números
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &numero);
        
        original = numero;
        invertido = 0;
        
        // Inverte o número usando matemática básica
        while (original > 0) {
            digito = original % 10;
            invertido = (invertido * 10) + digito;
            original = original / 10;
        }
        
        // Verifica se é espelhado
        if (numero == invertido) {
            contagem++;
        }
    }

    if (contagem > 0) {
        printf("Numeros espelhados: %d\n", contagem);
    } else {
        printf("Nenhum numero espelhado\n");
    }

    return 0;
}