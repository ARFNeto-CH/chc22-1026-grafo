#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define MAX_ATL 20

typedef struct
{
    char hh;
    char mm;
    char ss;
} Hora;

typedef struct
{
    char dia;
    char mes;
    short ano;
} Data;

typedef struct
{
    char hh;
    char mm;
    float fss;
} Marca;

typedef struct
{
    int numero;
    char atividade[50];
    char estado[2];
    Data data;
    Hora hora;
    Marca marca;
} Atleta;

typedef struct
{
    unsigned N;
    unsigned cap;
    Atleta atl[MAX_ATL];
} Atletas;

Atleta* fab_atleta();

int existe(Atleta Guardar[], int quantidade, int numero);
int guardar(Atleta Guardar[], int posicao, Atleta a);
Atleta lerplaneamento();
int menu();

int main()
{
    Atleta Dados[TAM];
    Atleta a;
    int quantidade = 0;
    int opcao, resultado;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            a = lerplaneamento();
            resultado = guardar(Dados, quantidade, a);
            if (resultado == 1)
            {
                printf("Dados Inseridos\n");
                quantidade++;
            }
            break;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:;
        }
    } while (opcao != 0);
}

int existe(Atleta Guardar[], int quantidade, int numero)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        if (Guardar[i].numero == numero)
            return (i);
    }
    return (-1);
}

int guardar(Atleta Guardar[], int posicao, Atleta a)
{
    if ((posicao >= 0) && (posicao < TAM) && (existe(Guardar, posicao, a.numero) == -1))
    {
        Guardar[posicao] = a;
        return (1);
    }
    else
        return (0);
}

Atleta lerplaneamento()
{
    Atleta a;
    int res;
    do
    {
        res = 0;
        /*
        printf("Numero?"); res += scanf("%d", &a.numero); while ((getchar()) !=
        '\n'); printf("Data de inicio(dd/mm/ano)?"); res += scanf("%d %d %d",
        &a.data.dia, &a.data.mes, &a.data.ano); while ((getchar()) != '\n');
        printf("Hora de Inicio?"); res += scanf("%d %d", &a.hora.hh, &a.hora.mm);
        while ((getchar()) != '\n'); printf("Data fim de atividade(dd/mm/ano)?");
        res += scanf("%d %d %d", &a.data.dia, &a.data.mes, &a.data.ano); while
        ((getchar()) != '\n'); printf("Hora de fim de atividade?"); res += scanf("%d
        %d", &a.hora.hh, &a.hora.mm); while ((getchar()) != '\n');
        printf("Atividade?"); res += scanf("%[^\n]", a.atividade); while
        ((getchar()) != '\n'); printf("tempo?"); res += scanf("%2f", &a.hora.ss);
        while ((getchar()) != '\n'); a.estado[0] = 1;
        */
    } while (res != 7);
    return (a);
}

int menu()
{
    int op;
    do
    {
        printf("1-Inserir atividade\n");
        printf("2-Quantidade de Praticantes num determinado periodo\n");
        printf("3 -Listagem de Praticantes em um determinado periodo \n");
        printf("4-Atividades Realizadas por praticante em um determinado periodo\n");
        printf("5- Media de tempos de cada praticante\n");
        printf("0-Sair\n");
        printf("Opcao?");
        scanf("%d", &op);
    } while ((op < 0) || (op > 10));
    return (op);
}
