#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, n, x, y;
    double soma, nota;
    double maiorNota, menorNota, mediaTurma, somaDasMedias = 0;

    // Variáveis para ordenação
    char tempNome[50];
    double tempMedia;
    int i, j;

    printf("Quantidade de alunos na turma: ");
    scanf("%d", &a);

    printf("Quantidade de avaliações: ");
    scanf("%d", &n);

    char nomes[a][50];
    double medias[a];

    for (x = 0; x < a; x++) // Nome dos alunos
    {
        getchar(); // Limpa o Buffer
        printf("\nNome do aluno %d: ", x + 1);
        fgets(nomes[x], 50, stdin);
        nomes[x][strcspn(nomes[x], "\n")] = '\0'; // troca o \n por \0 para não quebrar a linha

        soma = 0;

        for (y = 0; y < n; y++) // Notas
        {
            printf("Digite a %dª nota: ", y + 1);
            scanf("%lf", &nota);
            soma = soma + nota;
        }

        medias[x] = soma / n;
        somaDasMedias = somaDasMedias + medias[x];

        if (x == 0)// Define o primeiro aluno como marco inicial
        { 

            maiorNota = medias[x];
            menorNota = medias[x];
        }
        else
        {
            if (medias[x] > maiorNota)
            {
                maiorNota = medias[x];
            }
            if (medias[x] < menorNota)
            {
                menorNota = medias[x];
            }
        }
    }

    for (i = 0; i < a - 1; i++)// Ordena os nomes em ordem alfabética
    { 
        for (j = i + 1; j < a; j++)
        {

            if (strcmp(nomes[i], nomes[j]) > 0)// Checa se o nome precisa ser trocado
            { 

                // Troca os Nomes usando strcpy e variável temporária
                strcpy(tempNome, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], tempNome);

                // Troca a média x para acompanhar o aluno x
                tempMedia = medias[i];
                medias[i] = medias[j];
                medias[j] = tempMedia;
            }
        }
    }

    printf("\n--- Lista de alunos ---\n");

    for (x = 0; x < a; x++)
    {
        printf("Nome: %-10s | Media: %.2lf | ", nomes[x], medias[x]);

        if (medias[x] >= 6)
        {
            printf("Aprovado.\n");
        }
        else
        {
            printf("Reprovado.\n");
        }
    }

    mediaTurma = somaDasMedias / a;

    printf("\n--- Estatisticas da turma ---\n");
    printf("Media da turma: %.2lf\n", mediaTurma);
    printf("Maior nota: %.2lf\n", maiorNota);
    printf("Menor nota: %.2lf\n", menorNota);

    return 0;
}