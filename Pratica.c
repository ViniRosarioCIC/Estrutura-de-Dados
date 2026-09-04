#include <stdio.h>
#include <stdlib.h>

int analisar_valor (void){

  int valor;
  if(scanf("%d", &valor) != 1){
    printf("\nDigite um valor valido! Encerrando o programa...");
    exit(1);
  } return valor;


}

void maior_valor(int quantidade, int vetor[quantidade]){

  int maior;
  maior = vetor[0];
  for(int i = 1; i < quantidade; i++){
    if (maior < vetor[i]){
      maior = vetor[i];
    }
  }
  printf("Maior: %d\n", maior);
}

void soma_elementos (int quantidade, int vetor[]){

  int soma = 0;

  for(int i = 0; i < quantidade; i++){
    soma += vetor[i];
  }
  printf("Soma: %d\n", soma);

}

void analisar_crescente (int quantidade, int vetor[]){

  int aux;
  aux = vetor [0];

  for(int i = 1; i < quantidade; i++){
    if(vetor [i] >= aux){
      aux = vetor[i];
    } else{
      printf("Crescente: Não\n");
      return;
    }
  }
  printf("Crescente: Sim");
}

int main(){

int qSequencias;

  printf("\nDigite a quantidade de sequencias:");
  qSequencias = analisar_valor();

    int qElementos;
    
  
    for(int i = 0; i < qSequencias; i++){
      printf("\nDigite a quantidade de elementos para a sequencia %d: ", i+1);
      qElementos = analisar_valor();
        
      int sequencia [qElementos];

        for(int j =0; j < qElementos; j++){
          printf("\nDigite o elemento [%d] da sequencia [%d]: ", j+1, i+1);
          scanf("%d", &sequencia[j]);
        }

      maior_valor(qElementos, sequencia);
      soma_elementos(qElementos, sequencia);
      analisar_crescente (qElementos, sequencia); 
    }

  return 0;
}