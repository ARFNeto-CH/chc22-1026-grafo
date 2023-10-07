(https://www.clubedohardware.com.br/forums/topic/1626964-psquisar-por-data-em-c/#comment-8511004)[link]


>> Sou reativamente novo em programacao, estou criando um trabalho em c para a escola em que se tem de inserir dados de atividades desportivas realizadas como numero, data de inicio, atividade, etc mas estou tendo algumas dificuldades em pesquisar/ listar por data, ja andei pesquisando e ate agora n�o encontrei nada similar algu�m consegue ajudar? tambem estou com algumas dificuldades em calcular a media de tempos...

```C
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
```

Porque essas estruturas n�o s�o todas an�nimas? 
Porque uma tem o nome todo em min�sculas e outro em todas mai�sculas?
H� uma conven��o popular em C de reservar apenas a primeira letra em mai�scula para esses nomes. Ou usar algo como um prefixo ou sufixo, como `_t`.

Escreva em torno dos dados

Se os dados s�o Atleta e o grupo de Atletas porque n�o tem isso no programa? Claro que vai fazer falta. Muita falta.

Todos esses programas para iniciantes a partir dos realmente primitivos giram em torno de uma cole��o de dados. com seria chamada em java. Um container, como seria chamado em C++. 

Uma pequena mudan�a em seu programa e ele poderia come�ar assim:
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct {
  char hh;
  char mm;
  char ss;
} Hora;

typedef struct {
  char dia;
  char mes;
  short ano;
} Data;

typedef struct {
  char hh;
  char mm;
  float fss;
} Marca;

typedef struct {
  int numero;
  char atividade[50];
  char estado[2];
  Data data;
  Hora hora;
  Marca marca;
} Atleta;

int existe(Atleta Guardar[], int quantidade, int numero);
int guardar(Atleta Guardar[], int posicao, Atleta a);
Atleta lerplaneamento();
int menu();
```

Dentro de alguma conven��o e agora com as fun��es apenas descritas no in�cio, com `main` como a primeira fun��o, se poss�vel em um arquivo separado.

Mas onde est�o os atletas?

O programa trata um grupo de atletas. Se n�o tiver isso no programa fica tudo mais dif�cil...

Composi��o de dados, encapsulamento, esses s�o os nomes chiques dessas coisas nos livros.

```C
typedef struct
{
    unsigned N;
    unsigned cap;
    Atleta atl[MAX_ATL];
} Atletas;
```

Imagine a diferen�a que isso faria ANTES de come�ar a escrever seu programa.

`Atletas` � seu container. Todas as fun��es operam em Atletas. Encapsulamento.

```C
    Atleta* fab_atleta();
```

Imagine uma fun��o assim, que a cada vez que voc� chama retorna um Atleta. J� pode come�ar a testar o programa em 10 minutos. Antes de tudo

Seu programa n�o est� bom. Tem muitos problemas ainda. Em especial leia sobre scanf() no manual. Est� errado o que escreveu. scanf() retorna -1 em caso de erro, ou o TOTAL de especificadores atendidos.

https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l?view=msvc-170 em portugu�s
