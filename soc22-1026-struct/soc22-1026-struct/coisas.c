#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAXVENDAS 10

typedef struct venda {
    int refVenda;
    int idCliente;
    int preco;
    int quantidade;
    char categoria[100];
} VENDA;

//vendas pre-defenidas
struct vendas[0] = { 13, 10, 50, 2, "Sapatos" };
struct vendas[1] = { 14, 11, 150, 1, "Sapatilhas" };
struct vendas[2] = { 15, 12, 70, 6, "Cal�as" };

VENDA novaVenda() {
    VENDA vendaTemp;
    fflush(stdin);

    printf("\nIntroduza a referencia de venda: ");
    scanf("%i", &vendaTemp.refVenda); //depois fazer sistema para defenir referencia automaticamente
    printf("\nIntroduza a identifica��o de cliente: ");
    scanf("%i", &vendaTemp.idCliente);
    printf("\nIntroduza o pre�o: ");
    scanf("%i", &vendaTemp.preco);
    printf("\nIntroduza a quantidade: ");
    scanf("%i", &vendaTemp.quantidade);

    int a = 0; //enquanto a = 0 roda o comando dnv
    while (a == 0) {
        printf("\n1 - Camisolas | 2 - Cal�as | 3 - Sapatilhas | 4 - Acess�rios\nIntroduza a categoria: ");
        int opcao;
        scanf("%i", &opcao);
        switch (opcao) {
        case 1:
            strcpy(vendaTemp.categoria, "Camisolas"); a = 1; break;
        case 2:
            strcpy(vendaTemp.categoria, "Cal�as"); a = 1; break;
        case 3:
            strcpy(vendaTemp.categoria, "Sapatilhas"); a = 1; break;
        case 4:
            strcpy(vendaTemp.categoria, "Acess�rios"); a = 1; break;
        default: printf("\nOp��o Invalida!\n"); break;
        }
    }
}

void listarVendas(VENDA vendas[], int qntVendas) {
    int i = 0;
    for (i = 0; i < qntVendas; i++) {
        printf("\nVenda %i - Refer�ncia da venda: %i | Identificador do Cliente: %i | Pre�o: %i� | Quantidade: %i | Categoria do produto: %s\n",
            i++, vendas[i].refVenda, vendas[i].idCliente, vendas[i].preco, vendas[i].quantidade, vendas[i].categoria);
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    VENDA vendas[MAXVENDAS];
    int qntVendas = 0;

    while (1) {
        printf("\n1 - Introduzir venda");
        printf("\n2 - Listar todas as vendas");
        printf("\n3 - Listar todas as vendas de uma categoria especifica");
        printf("\n4 - Modificar pre�o/quantidade de uma venda");
        printf("\nIntroduza a op��o! - ");
        int opcao;
        scanf(" %i", &opcao);

        switch (opcao) {
        case 1:
            vendas[qntVendas] = novaVenda();
            qntVendas++;
            break;
        case 2:
            listarVendas(vendas, qntVendas); break;
        }
    }

    return 0;
}