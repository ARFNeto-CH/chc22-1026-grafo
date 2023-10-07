```C
                if (salario >= 5646.81) {
                    inss = salario - 621.04;
                }
 ```

Isso não é o que você queria escrever. Nada tem a ver com `C++` esse problema. O teto de contribuição que está no enunciado é de 621.04. Esse é o valor do desconto para qualquer valor acima desses 5646.81 como você escreveu. Então escreva o certo para esse caso:

```C
    inss = 621.04;
```

Mas não é só isso
```C
	if (salario <= 1693.72) {
		inss = salario * 0.08;
	}
	else
		if (salario >= 1693.73 && salario <= 2822.90) {
			inss = salario * 0.09;
		}
		else
			if (salario >= 2822.91 && salario <= 5646.80) {
				inss = salario * 0.11;
			}
			else
				if (salario >= 5646.81) {
					inss = salario - 621.04;
				}
```
Veja bem o que escreveu... É fato conhecido que se o salário não é <= 1693.72 ele é maior. Porque testou de novo TODOS os intervalos? Isso deve custar boa parte de sua nota --- se eu corrigir seu programa. Não pode acabar de testar se é <= e depois testar se é >=...

Veja como é mais simples:

```C
	float inss = 621.04; // teto do desconto
	if (salario <= 1693.72)
		inss = salario * 0.08;
	else
		if (salario <= 2822.90)
			inss = salario * 0.09;
		else
			if (salario <= 5646.80)
				inss = salario * 0.11;
```

É o mesmo caso do IR: ou é isento ou paga. Veja

```C
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
```

E na saída não pode usar um monte de printf() de uma linha a invés de um printf() de várias linhas. Não é esperto e vai levar umas 20x mais tempo. Além de ficar um inferno para alinhar os dados.

Veja o simples:

```C
	// extrato
    printf("\
    Desconto INSS:    %8.2f\n\
    Desconto IR:      %8.2f\n\
    Voce vai receber: %8.2f",
	inss, ir, (salario - ir - inss));
```

Note que não precisa do valor do saldo a receber já que não vai usar para nada.

E assim tem um EXEMPLO

```C
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
```

Que mostra por exemplo

```none
Informe seu salario bruto: 6000.25

    Salario:           6000.25
    Desconto INSS:      621.04
    Desconto IR:       1650.07
    Voce vai receber:  3729.14
```
Seu programa tem vários problemas ainda.

Se está programando em `C++` e até incluiu `iostream` faça o simples e use `cout`. `C` e `C++` são linguagens muito diferentes e não ajuda nada usar partes de `C` nesses programas. Não use `printf()`. Se pode e prefere apenas escreva em `C`. Isso vale também para o uso de `scanf()` a menos que precise realmente do scanner. `scanf()` é um scanner de todo modo. Para simplesmente ler valores use `cin`.

Se vai usar `scanf()` leia o manual e entenda que `scanf()` retorna um `int`. SEMPRE teste o retorno.

Como está aprendendo, se acostume a mostrar na tela os valores do que leu. Muitas vezes pode ter surpresas. MOSTRE o valor lido para o salário.

Se não usa a linha de comando não declare os parâmetros. Use só 

```C
    int main(void)
```

Claro que você devia usar porque é muito chato num programa que lê um único valor ter que rodar o programa, esperar um prompt, digitar o salário e teclar ENTER. Mesmo que tenha que ler depois só coloque isso depois d eseu programa estar testado. Só vai perder tempo. No geral NUNCA escreva um programa interativo. 

Inicialize todas as variáveis e declare uma por linha. É grátis. E nem todos seus programas vão ter 20 linhas.

Escreva em torno dos dados.







	printf("Informe seu salario bruto:");
	scanf("%f", &salario);

	if (salario <= 1693.72) {
		inss = salario * 0.08;
	}
	else

		if (salario >= 1693.73 && salario <= 2822.90) {
			inss = salario * 0.09;
		}
		else
			if (salario >= 2822.91 && salario <= 5646.80) {
				inss = salario * 0.11;
			}
			else
				if (salario >= 5646.81) {
					inss = salario - 621.04;
				}
	if (salario >= 1903.99 && salario <= 2826.65) {
		ir = salario * 0.075;
	}
	else
		if (salario >= 2826.66 && salario <= 3751.05) {
			ir = salario * 0.15;
		}
		else
			if (salario >= 3751.06 && salario <= 4664.68) {
				ir = salario * 0.225;
			}
			else
				if (salario >= 4664.69) {
					ir = salario * 0.275;
				}


	sal_liquido = (salario - inss) - ir;

	printf("\nDesconto INSS: %8.2f", inss);
	printf("\nDesconto IR: %8.2f", ir);
	printf("\nVoce vai receber: %8.2f", sal_liquido);


	return 0;
}
```

