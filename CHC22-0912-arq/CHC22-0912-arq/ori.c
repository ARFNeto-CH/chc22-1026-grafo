#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// STRUCT DO ALUNO
typedef struct aluno {
    int id_aluno;
    char nm_aluno[50];
} arq_aluno;

// VARIÁVEIS GLOBAIS
int quant_alunos = 0;
arq_aluno arq_alunos[24];
int escolha;

// FUNÇÃO CONSULTA POR ID
void consulta() {
    FILE* entrada = fopen("alunos.txt", "r");
    int id;

    if (entrada == NULL) {
        printf("Erro na leitura do arquivo...\n");
    }
    else {
        printf("\n------BUSCA DE ALUNOS------\n");
        printf("Digite o id do aluno: ");
        scanf("%i", &id);
        getchar();

        for (int i = 1; i <= quant_alunos; i++) {
            if (id == arq_alunos[i].id_aluno) {
                printf("Aluno: %s\n", arq_alunos[i].nm_aluno);
            }
            else if (id != arq_alunos[i].id_aluno)
                printf("Aluno não existe na base!\n");
        }
        printf("---------------------------\n");
    }
    fclose(entrada);
}

// FUNÇÃO RELATÓRIO
void relatorio() {
    FILE* entrada = fopen("alunos.txt", "r");

    for (int i = 1; i <= 24; i++) {
        fscanf(entrada, "%d", &arq_alunos[i].id_aluno);
        fscanf(entrada, "%s", &arq_alunos[i].nm_aluno[50]);
    }

    if (entrada == NULL) {
        printf("Erro na leitura do arquivo...\n");
    }
    else {
        struct tm* data_hora_atual;
        time_t segundos;
        time(&segundos);
        data_hora_atual = localtime(&segundos);
        int i;

        printf("_____________________________\n");
        printf("\n");
        printf("----RELATÓRIO DE ALUNOS----\n");
        printf("___________________________\n");
        printf("---------------------------\n");
        printf("|   ID   |      NOME      |\n");

        for (int i = 1; i <= quant_alunos; i++) {
            printf("|   %d\t |", arq_alunos[i].id_aluno);
            printf("     %s\t  |", arq_alunos[i].nm_aluno);
        }

        printf("\n-----------------------------\n");
        printf("_______________________________ Gerado em %d/%d/%d %i:%i:%i\n",
            data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1,
            data_hora_atual->tm_year + 1900, data_hora_atual->tm_hour,
            data_hora_atual->tm_min, data_hora_atual->tm_sec);
    }

    fclose(entrada);
}

int main() {
    do {
        setlocale(LC_ALL, "");
        struct tm* data_hora_atual;
        time_t segundos;
        time(&segundos);
        data_hora_atual = localtime(&segundos);
        printf("Acesso em %d/%d/%d %i:%i:%i\n", data_hora_atual->tm_mday,
            data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900,
            data_hora_atual->tm_hour, data_hora_atual->tm_min,
            data_hora_atual->tm_sec);

        printf("--MENU PRINCIPAL--\n");
        printf("------------------\n");
        printf("| [1] - Consultar por id |\n| [2] - Relatório        |\n| [3] - "
            "Sair             |\n");
        printf("------------------\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            consulta();
            break;
        case 2:
            relatorio();
            break;
        }
    } while (escolha != 3);
    return 0;
}