#include <stdio.h>

int inv(int flag)
{
	return ~flag;
}

int main(void)
{
	printf("Tecle ENTER para prosseguir...");
	fgetc(stdin);
	for (int i = 0; i < 16; i++) printf("inv(%d 0x%x) = %d 0x%x\n", i, i, inv(i), inv(i) );
	int val = 31;
	int pos = 4;
	printf("inverte o bit %d de %d = 0x%x: ", pos, val, val);
	val = val ^ (1 << pos);
	printf("%d 0x%x\n", val, val);
	printf("inverte o bit %d de %d = 0x%x: ", pos, val, val);
	val = val ^ (1 << pos);
	printf("%d 0x%x\n", val, val);

	return 0;
}