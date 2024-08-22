#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALUNOS 5

typedef struct {
    int matricula;
    char nome[100];
    float notas[3];
} Aluno;

float calcularMedia(const float notas[3]) {
    return (notas[0] + notas[1] + notas[2]) / 3;
}

void exibirAluno(const Aluno *a) {
    printf("Nome: %s\n", a->nome);
    printf("Notas: %.2f, %.2f, %.2f\n", a->notas[0], a->notas[1], a->notas[2]);
}

int main() {
    Aluno alunos[NUM_ALUNOS];
    Aluno alunoComMaiorMedia;
    float maiorMedia = -1;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite o numero de matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        getchar();
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[0]);
        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[1]);
        printf("Digite a nota 3 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notas[2]);

        float media = calcularMedia(alunos[i].notas);
        if (media > maiorMedia) {
            maiorMedia = media;
            alunoComMaiorMedia = alunos[i];
        }
    }

    printf("\nAluno com a maior media:\n");
    exibirAluno(&alunoComMaiorMedia);

    return 0;
}
