#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct { // cria um struct para agrupar cada aluno com sua nota

    char nome[50];
    double media;
} Aluno;

double maiorNota(Aluno alunos[], int a) { // Define a maior nota

    double maior = alunos[0].media;

    for (int x = 1; x < a; x++) {
        if (alunos[x].media > maior) {
            maior = alunos[x].media;
        }
    }
    return maior;
}

double menorNota(Aluno alunos[], int a) { // Define a menor nota

    double menor = alunos[0].media;

    for (int x = 1; x < a; x++) {
        if (alunos[x].media < menor) {
            menor = alunos[x].media;
        }
    }
    return menor;
}

int compararAlunos(const void *a, const void *b) { // Compara os alunos e organiza em ordem alfabetica

    const Aluno *al1 = (const Aluno *)a;
    const Aluno *al2 = (const Aluno *)b;

    return strcmp(al1->nome, al2->nome);
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int a, n;
    double nota, soma, somaDasMedias = 0;

    printf("Quantidade de alunos na turma: ");
    scanf("%d", &a);

    printf("Quantidade de avaliações: ");
    scanf("%d", &n);

    Aluno alunos[a];

    for (int i = 0; i < a; i++) {

        while (getchar() != '\n'); // Limpa buffer antes de ler o nome

        printf("\nNome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        soma = 0;

        for (int j = 0; j < n; j++) {
            printf("Digite a %dª nota: ", j + 1);
            scanf("%lf", &nota);
            soma += nota;
        }

        alunos[i].media = soma / n;
        somaDasMedias += alunos[i].media;
    }

    qsort(alunos, a, sizeof(Aluno), compararAlunos); // Ordena os nomes 

    printf("\n Lista de alunos  \n");

    for (int i = 0; i < a; i++) {
        
        printf("Nome: %-10s | Media: %.2lf | %s\n",
            alunos[i].nome,
            alunos[i].media,
            alunos[i].media >= 6 ? "Aprovado" : "Reprovado"
        );
    }

    double mediaTurma = somaDasMedias / a;

    printf("\n Estatísticas da turma \n");
    printf("Média da turma: %.2lf\n", mediaTurma);
    printf("Maior média: %.2lf\n", maiorNota(alunos, a));
    printf("Menor média: %.2lf\n", menorNota(alunos, a));

    return 0;
}
