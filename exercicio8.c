#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data dataNascimento;
} Pessoa;

int ehMaisNova(Data d1, Data d2) {
    if (d1.ano > d2.ano) return 1;
    if (d1.ano < d2.ano) return 0;
    if (d1.mes > d2.mes) return 1;
    if (d1.mes < d2.mes) return 0;
    return d1.dia > d2.dia;
}

int main() {
    Pessoa pessoas[6];
    Pessoa maisNova, maisVelha;

    for (int i = 0; i < 6; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';
        
        printf("Digite o dia de nascimento da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].dataNascimento.dia);
        printf("Digite o mes de nascimento da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].dataNascimento.mes);
        printf("Digite o ano de nascimento da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].dataNascimento.ano);
        getchar();
    }

    maisNova = maisVelha = pessoas[0];

    for (int i = 1; i < 6; i++) {
        if (ehMaisNova(pessoas[i].dataNascimento, maisNova.dataNascimento)) {
            maisNova = pessoas[i];
        }
        if (!ehMaisNova(pessoas[i].dataNascimento, maisVelha.dataNascimento)) {
            maisVelha = pessoas[i];
        }
    }

    printf("\nPessoa mais nova:\nNome: %s\nData de Nascimento: %02d/%02d/%04d\n", 
           maisNova.nome, maisNova.dataNascimento.dia, 
           maisNova.dataNascimento.mes, maisNova.dataNascimento.ano);

    printf("Pessoa mais velha:\nNome: %s\nData de Nascimento: %02d/%02d/%04d\n", 
           maisVelha.nome, maisVelha.dataNascimento.dia, 
           maisVelha.dataNascimento.mes, maisVelha.dataNascimento.ano);

    return 0;
}
