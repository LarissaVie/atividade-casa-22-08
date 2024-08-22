#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char esporte[50];
    int idade;
    float altura;
} Atleta;

Atleta encontrarAtletaMaisAlto(Atleta atletas[], int numAtletas) {
    Atleta maisAlto = atletas[0];
    for (int i = 1; i < numAtletas; i++) {
        if (atletas[i].altura > maisAlto.altura) {
            maisAlto = atletas[i];
        }
    }
    return maisAlto;
}

Atleta encontrarAtletaMaisVelho(Atleta atletas[], int numAtletas) {
    Atleta maisVelho = atletas[0];
    for (int i = 1; i < numAtletas; i++) {
        if (atletas[i].idade > maisVelho.idade) {
            maisVelho = atletas[i];
        }
    }
    return maisVelho;
}

int main() {
    Atleta atletas[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do atleta %d: ", i + 1);
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';

        printf("Digite o esporte do atleta %d: ", i + 1);
        fgets(atletas[i].esporte, sizeof(atletas[i].esporte), stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';

        printf("Digite a idade do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].idade);

        printf("Digite a altura do atleta %d (em metros): ", i + 1);
        scanf("%f", &atletas[i].altura);
        getchar();
    }

    Atleta atletaMaisAlto = encontrarAtletaMaisAlto(atletas, 5);
    Atleta atletaMaisVelho = encontrarAtletaMaisVelho(atletas, 5);

    printf("\nAtleta mais alto:\nNome: %s\nEsporte: %s\nAltura: %.2f metros\n", atletaMaisAlto.nome, atletaMaisAlto.esporte, atletaMaisAlto.altura);
    printf("Atleta mais velho:\nNome: %s\nEsporte: %s\nIdade: %d anos\n", atletaMaisVelho.nome, atletaMaisVelho.esporte, atletaMaisVelho.idade);

    return 0;
}
