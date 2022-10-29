#include<stdio.h>

int main() {

	int num = 0, n1, n2, n3;

	printf("----------------------------\n");
	printf("Escreva um numero de 1 a 3 :\n");
	scanf("%d", &num);

	switch (num) {
	case 1:
		printf("Numero incorreto!\n", &n1);
		break;
	case 2:
		printf("Numero incorreto!\n", &n2);
		break;
	case 3:
		printf("Parabens numero correto!\n", &n3);
		break;
	default:
		Printf("ERRO!!!\n");
		break;
	}
}