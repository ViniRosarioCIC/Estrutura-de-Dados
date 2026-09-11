#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){

    int x, y;

    printf("Digite dois valores para a troca: ");

    verificar_dois_int(&x, &y);

    printf("Valores iniciais: %d %d\n", x ,y);
    
    trocar_valores(&x, &y);

    printf("Valores apos a troca: %d, %d\n", x , y);

return 0;
}

