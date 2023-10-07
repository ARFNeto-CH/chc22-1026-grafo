#include <cstdio>
int main(void)
{
	// salario?
	float salario = 0.;
 	printf("Informe seu salario bruto: ");
	if (1 != scanf("%f", &salario)) return -1;
	printf("\n    Salario:          %8.2f\n", salario);
	// inss
	float inss = 621.04;
	if (salario <= 1693.72)
		inss = salario * 0.08;
	else
		if (salario <= 2822.90)
			inss = salario * 0.09;
		else
			if (salario <= 5646.80)
				inss = salario * 0.11;
	// ir
	float ir = 0.; // isento
	if (salario >= 1903.99)
		if (salario <= 2826.65)
    		ir = salario * 0.075;
	    else
		    if (salario <= 3751.05) 
			    ir = salario * 0.15;
		    else
			if (salario <= 4664.68)
				ir = salario * 0.225;
			else
				ir = salario * 0.275;
	// extrato
    printf("\
    Desconto INSS:    %8.2f\n\
    Desconto IR:      %8.2f\n\
    Voce vai receber: %8.2f",
	inss, ir, (salario - ir - inss));
	return 0;
}