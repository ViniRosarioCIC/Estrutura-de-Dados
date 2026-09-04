#include <stdio.h>
#include <string.h>

// 1. Declaração da estrutura conforme especificado
typedef struct {
    int matricula;
    char nome[51];
    int tarefas;
    float horas;
    float produtividade;
} Funcionario;

int main() {
    int n;
    
    // 2. Validação da quantidade de funcionários (entre 1 e 30)
    do {
        scanf("%d", &n);
    } while (n < 1 || n > 30);
    
    Funcionario funcs[30]; // Vetor de struct
    float soma_produtividade = 0;
    int idx_maior_prod = 0;
    
    // 3. Leitura e processamento dos dados
    for (int i = 0; i < n; i++) {
        scanf("%d", &funcs[i].matricula);
        // O espaço antes do % garante que limpará o \n residual do buffer
        scanf(" %[^\n]", funcs[i].nome);
        scanf("%d", &funcs[i].tarefas);
        
        // Validação das horas trabalhadas (maiores que zero)
        do {
            scanf("%f", &funcs[i].horas);
        } while (funcs[i].horas <= 0);
        
        // 4. Cálculo do índice de produtividade
        funcs[i].produtividade = funcs[i].tarefas / funcs[i].horas;
        soma_produtividade += funcs[i].produtividade;
        
        // Encontra o índice do funcionário com a maior produtividade
        if (i == 0 || funcs[i].produtividade > funcs[idx_maior_prod].produtividade) {
            idx_maior_prod = i;
        }
    }
    
    // 5. Exibição da tabela de funcionários
    printf("LISTA DE FUNCIONÁRIOS\n");
    for (int i = 0; i < n; i++) {
        printf("Matrícula: %d\n", funcs[i].matricula);
        printf("Nome: %s\n", funcs[i].nome);
        printf("Tarefas: %d\n", funcs[i].tarefas);
        printf("Horas: %.1f\n", funcs[i].horas);
        printf("Produtividade: %.2f\n", funcs[i].produtividade);
        if (i < n - 1) {
            printf("\n");
        }
    }
    printf("\n");
    
    // Cálculos finais para o relatório
    float media_produtividade = soma_produtividade / n;
    int acima_da_media = 0;
    
    for (int i = 0; i < n; i++) {
        if (funcs[i].produtividade >= media_produtividade) {
            acima_da_media++;
        }
    }
    
    // 6. Informações gerais
    printf("Funcionario mais produtivo: %s\n", funcs[idx_maior_prod].nome);
    printf("Produtividade media da empresa: %.2f\n", media_produtividade);
    printf("Funcionarios com produtividade igual ou superior a media: %d\n", acima_da_media);
    
    return 0;
}