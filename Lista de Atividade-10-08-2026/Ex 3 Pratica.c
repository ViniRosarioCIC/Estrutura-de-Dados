#include <stdio.h> 
#include <stdlib.h>

typedef struct{
  int matricula;
  char nome [50];
  int tarefasconcluidas;
  float horastrabalhadas;
  float produtividade;
} Funcionario;

int quantidade_funcionarios (void){
  
  int qFuncionarios;

  if (scanf("%d", &qFuncionarios) != 1){ 
    printf("Digite um numero inteiro!\n");
    exit(1);

  } else if (qFuncionarios > 30){
    printf("Digite no maximo 30 funcionarios!\n");
    exit(1);

  }
  
  return qFuncionarios;

}

float produtividade_funcionario (int tarefas, float horas){
  return tarefas / horas;
}

void ler_dados_funcionarios(Funcionario f [], int nFuncionarios){
  
  for(int i = 0; i < nFuncionarios; i++){
      printf("Digite a matricula do funcionario [%d]: \n", i+1);
      scanf("%d", &f[i].matricula);  
      printf("Digite o nome do funcionario [%d]: \n", i+1);
      scanf(" %[^\n]", f[i].nome);  
      printf("Digite a quantidade de tarefas concluidas pelo funcionario [%d]: \n", i+1);
      scanf("%d", &f[i].tarefasconcluidas);
      printf("Digite a quantidade de horas trabalhadas pelo funcionario [%d]: \n", i+1);
      scanf("%f", &f[i].horastrabalhadas);
      f[i].produtividade = produtividade_funcionario(f[i].tarefasconcluidas, f[i].horastrabalhadas);
  }
}

void imprimir_dados (Funcionario f [], int nFuncionarios){
  
  printf("LISTA DE FUNCIONARIOS\n");
  for(int i = 0; i < nFuncionarios; i++){
    printf("\nMatricula: %d \n",f[i].matricula);  
    printf("Nome: %s \n",f[i].nome);
    printf("Tarefas: %d \n",f[i].tarefasconcluidas);
    printf("Horas: %.1f\n",f[i].horastrabalhadas);
    printf("Produtividade: %.2f\n",f[i].produtividade);
  }
}


int main(){
  
  printf("Digite a quantidade de funcionarios: ");
  
  int qFuncs = quantidade_funcionarios();

  Funcionario x [qFuncs];

  ler_dados_funcionarios(x, qFuncs);

  imprimir_dados(x, qFuncs);

  return 0;
}