#include <cstdio>
#include <iostream>

float c_inss(float);
float c_ir(float);

int main(void)
{
	float salario = 0.f;
	printf("Informe seu sal bruto: ");
	std::cin >> salario;
	if ( not std::cin.good() ) return -1; // nao leu
	printf("\n\n    %-20s  %8.2f\n", "Salario:", salario);
	// usa as funcoes para inss e ir
	float inss = c_inss(salario);
	float ir = c_ir(salario);
	// extrato
	printf("\
    %-20s  %8.2f\n\
    %-20s  %8.2f\n\
    %-20s  %8.2f\n\n",
    "Desconto INSS:", inss,
	"Desconto IR:", ir,
	"Voce vai receber:", (salario - ir - inss));
	return 0;
}

float c_inss(float sal)
{	// retorna o valor do inss
	float inss = 621.04f;
	if (sal <= 1693.72f)
		inss = sal * 0.08f;
	else
		if (sal <= 2822.90f)
			inss = sal * 0.09f;
		else
			if (sal <= 5646.80f)
				inss = sal * 0.11f;
	return inss;
}

float c_ir(float sal)
{	
	// retorna o valor do ir
	float ir = 0.; // isento
	if (sal >= 1903.99)
		if (sal <= 2826.65)
			ir = sal * 0.075f;
		else
			if (sal <= 3751.05f)
				ir = sal * 0.15f;
			else
				if (sal <= 4664.68f)
					ir = sal * 0.225f;
				else
					ir = sal * 0.275f;
	return ir;
}
