#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 100
typedef struct HORA
{
	int h;
	int m;
}hr;
typedef struct data
{
	int dia;
	int mes;
	int ano;
}DATA;
typedef struct dados
{
	int numero;
	char atividade[50];
	char estado;
	float tempo;
	DATA data;
	hr hora;
}Atleta;
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
	return(op);
}
int existe(Atleta Guardar[], int quantidade, int numero)
{
	int i;
	for (i = 0; i < quantidade; i++)
	{
		if (Guardar[i].numero == numero) return(i);
	}
	return(-1);
}
int guardar(Atleta Guardar[], int posicao, Atleta a)
{
	if ((posicao >= 0) && (posicao < TAM) && (existe(Guardar, posicao, a.numero) == -1))
	{
		Guardar[posicao] = a;
		return(1);
	}
	else return(0);
}
Atleta lerplaneamento()
{
	Atleta a;
	int res;
	do
	{
		res = 0;
		printf("Numero?"); res += scanf("%d", &a.numero); while ((getchar()) != '\n');
		printf("Data de inicio(dd/mm/ano)?"); res += scanf("%d %d %d", &a.data.dia, &a.data.mes, &a.data.ano); while ((getchar()) != '\n');
		printf("Hora de Inicio?"); res += scanf("%d %d", &a.hora.h, &a.hora.m); while ((getchar()) != '\n');
		printf("Data fim de atividade(dd/mm/ano)?"); res += scanf("%d %d %d", &a.data.dia, &a.data.mes, &a.data.ano); while ((getchar()) != '\n');
		printf("Hora de fim de atividade?"); res += scanf("%d %d", &a.hora.h, &a.hora.m); while ((getchar()) != '\n');
		printf("Atividade?"); res += scanf("%[^\n]", a.atividade); while ((getchar()) != '\n');
		printf("tempo?"); res += scanf("%2f", &a.tempo); while ((getchar()) != '\n');
		a.estado = 1;
		return(a);
	} while (res != 7);
}
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
		case 1:   a = lerplaneamento();
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
		case 4: break;
		case 5: break;
		default:
			;
		}
	} while (opcao != 0);
}