#include <stdio.h>

int codigos[100005];

int main(){
    int nCodigos;
    
    printf("Digite a quantidade de codigos");
    scanf("%d", &nCodigos);

    for(int i = 0; i <= nCodigos; i++){
        printf("Digite um codigo: \n");
        scanf("%d", &codigos[i]);
    }


}