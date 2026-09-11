#include <stdio.h>
#include <stdlib.h>

void trocar_valores(int *ptr_x, int *ptr_y) {
    int temp = *ptr_x; // Salva o valor apontado por ptr_x
    *ptr_x = *ptr_y;   // Atribui o valor de ptr_y a ptr_x
    *ptr_y = temp;     // Atribui o valor salvo em temp a ptr_y
}

int main() {
    int x, y;

    // Leitura dos dois valores inteiros
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Entrada inválida! Encerrando programa...\n");
        exit(1); 
    }

    // Exibe os valores antes da troca
    printf("%d %d\n", x, y);

    // Passa os endereços de memória de x e y para a função
    trocar_valores(&x, &y);

    // Exibe os valores após a troca
    printf("%d %d\n", x, y);

    return 0;
}