#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{

	int num = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;

	printf("\
----------------------------\n\
Escreva um numero de 1 a 3 : ");

	int res = scanf("%d", &num);
	if (res != 1) return -1; // nao leu nada
	printf("\nLeu '%d'\n", num);

	switch (num)
	{
	case 1:
		printf("Numero incorreto! n1 = %d\n", n1);
		break;
	case 2:
		printf("Numero incorreto! n2 = %d\n", n2);
		break;
	case 3:
		printf("Parabens numero correto! n3 = %d\n", n3);
		break;
	default:
		printf("ERRO!!!\n");
		break;
	}; // switch

	return 0;
}