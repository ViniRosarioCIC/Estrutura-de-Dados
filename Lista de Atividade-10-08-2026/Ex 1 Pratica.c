#include <stdio.h> 

int main (){

    int original, espelhado, numero, digito;
    int qNumeros, contador = 0;
    printf("Digite a quantidade de numeros do conjunto: ");
    scanf("%d", &qNumeros);

    for(int i = 0; i < qNumeros; i++){
        printf("Digite um numero: ");
        scanf("%d", &numero);

        original = numero;
        espelhado = 0;

        while(original != 0){
            digito = original % 10;
            espelhado = digito + (espelhado * 10);
            original = original / 10;
        }

        if(numero == espelhado){
            contador++;
        }

    }

    if(contador > 0){
        printf("Numeros espelhados: %d", contador);
    } else {
        printf("Nenhum numero espelhado");
    }
    return 0;

}