#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAXVENDAS 10

typedef struct
{
    int refVenda;
    int idCliente;
    int preco;
    int quantidade;
    char categoria[100];
} VENDA;

int main(void)
{
    setlocale(LC_ALL, "pt_BR");
    VENDA vendas[MAXVENDAS] =
    {
        [0] =
        {
            .refVenda = 13,
            .idCliente = 10,
            .preco = 50,
            .quantidade = 2,
            .categoria = "Sapatos"
        },
        [1] =
        {
            .refVenda = 14,
            .idCliente = 11,
            .preco = 150,
            .quantidade = 1,
            .categoria = "Sapatilhas"
        },
        [2] =
        {
            .refVenda = 15,
            .idCliente = 12,
            .preco = 70,
            .quantidade = 6,
            .categoria = "Calças"
        }
    };

    /*
    struct vendas[0] = { 13, 10, 50, 2, "Sapatos" };
    struct vendas[1] = { 14, 11, 150, 1, "Sapatilhas" };
    struct vendas[2] = { 15, 12, 70, 6, "Calças" };
     */
    printf("3 primeiras categorias: \"%s\", \"%s\" e \"%s\"\n",
        vendas[0].categoria,
        vendas[1].categoria,
        vendas[2].categoria);
    return 0;
}