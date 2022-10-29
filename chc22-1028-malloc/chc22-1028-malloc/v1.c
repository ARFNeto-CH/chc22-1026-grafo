#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  	int*    o = (int*) malloc(sizeof(int));
	int*    p = (int*) malloc(sizeof(int));

	*o = 50;
	*p = 5050;
	printf("*o = %d, *p = %d (esperados 50 e 5050)\n", *o, *p);
	free(o);
	free(p);
	return 0;
}