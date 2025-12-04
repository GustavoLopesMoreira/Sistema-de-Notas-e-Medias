#include <stdio.h>
#include <string.h>

typedef struct { // Cria a estrutura aluno
    char nome[50];
    double notas[10];
    double media;
} Aluno;


double maiorMedia(Aluno turma[], int n) { // Função para armazenar maior média
    double maior = turma[0].media;
    for (int i = 1; i < n; i++) {
        if (turma[i].media > maior) maior = turma[i].media;
    }
    return maior;
}

double menorMedia(Aluno turma[], int n) { // Função para armazenar menor média
    double menor = turma[0].media;
    for (int i = 1; i < n; i++) {
        if (turma[i].media < menor) menor = turma[i].media;
    }
    return menor;
}

double mediaTurma(Aluno turma[], int n) { // Função para armazenar a  média da turma
    double somaTotal = 0;
    for (int i = 0; i < n; i++) {
        somaTotal += turma[i].media;
    }
    return somaTotal / n;
}

int main() {
    int quantidadeAlunos, quantidadeProvas, i, j;
    double soma;

    printf("Quantidade de alunos: ");
    scanf("%d", &quantidadeAlunos);

    printf("Quantidade de avaliações: ");
    scanf("%d", &quantidadeProvas);
    getchar(); // Limpa o buffer

    Aluno turma[quantidadeAlunos]; // Cria o vetor structs para organizar o bloco com as informações

 
    for (i = 0; i < quantidadeAlunos; i++) {
        printf("\nNome do %dº aluno: ", i + 1);
        fgets(turma[i].nome, 50, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0; // Limpa o buffer

        soma = 0;
        for (j = 0; j < quantidadeProvas; j++) {
            printf("Digite a %dª nota: ", j + 1);
            scanf("%lf", &turma[i].notas[j]);
            getchar(); // Limpa o buffer
            soma += turma[i].notas[j];
        }
        turma[i].media = soma / quantidadeProvas;
    }

    
    Aluno temp; // Variável temporária do tipo Aluno (pacote completo)

    for (int x = 0; x < quantidadeAlunos - 1; x++) {
        for (int y = 0; y < quantidadeAlunos - x - 1; y++) {
            
            if (strcmp(turma[y].nome, turma[y + 1].nome) > 0) { 
         // Compara os nomes e quando for ordenar, //troca o bloco inteiro(Nome, notas e medias)

                temp = turma[y];
                turma[y] = turma[y + 1];
                turma[y + 1] = temp;
            }
        }
    }

  
    printf("\n Lista de chamada \n");

    for (i = 0; i < quantidadeAlunos; i++) {
        printf("Aluno: %s | Media: %.2lf | Notas: ", turma[i].nome, turma[i].media);

        for (j = 0; j < quantidadeProvas; j++) {
            printf("%.2lf", turma[i].notas[j]);
            if (j < quantidadeProvas - 1) {
                printf(", ");
            }
        }

        if (turma[i].media >= 7) {
            printf("| Aprovado\n");
        } else {
            printf("| Reprovado\n");
        }
    }

  
    printf("\n Estatisticas gerais da turma \n");
    printf("Maior Media: %.2lf\n", maiorMedia(turma, quantidadeAlunos));
    printf("Menor Media: %.2lf\n", menorMedia(turma, quantidadeAlunos));
    printf("Media Geral da Turma: %.2lf\n", mediaTurma(turma, quantidadeAlunos));

    return 0;
}
