#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct paginaweb { int numero; char link[128]; }Pagina;

typedef struct pilha { Pagina pg[MAX]; int topo, fundo; }Pilha;

void inicializa(Pilha* p) { p->topo = 0; p->fundo = p->topo; }

int pilhavazia(Pilha p) { return(p.topo == p.fundo); }

void empilhar(Pilha* p, Pagina pgn) { if (p->fundo < MAX) { p->pg[p->fundo] = pgn; p->fundo++; printf("\nPagina Inserida na Pilha\n"); } else { printf("\nNao e possivel empilhar, pois a Pilha esta cheia\n"); } }

void desempilhar(Pilha* p) { if (!pilhavazia(*p)) { p->fundo--; printf("\nPagina removida da pilha\n\n"); } else { printf("\nNao e possivel desempilhar, pois a pilha esta vazia\n"); } }

void mostrarPilha(Pilha p) {
    int i;

    for (i = 0; i < p.fundo; i++) {
        printf("\nPAGINA [%d] -> NUMERO: %d - LINK: %s\n", i, p.pg[i].numero, p.pg[i].link);
    }
} int main() {
    Pilha URL; Pagina pgn; int opc = 5;

    inicializa(&URL);
    while (opc > 0) {
        printf("\n---------------------MENU----------------\n");
        printf("--------------------1-EMPILHAR-------------\n");
        printf("--------------------2-DESEMPILHAR----------\n");
        printf("--------------------3-MOSTRAR--------------\n");
        printf("--------------------0-SAIR-----------------\n");
        printf("\nOPCAO DESEJADA: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            printf("\nNumero: ");
            scanf("%d", &pgn.numero);
            printf("Link: ");
            scanf("%s", pgn.link);
            empilhar(&URL, pgn);
            break;

        case 2:
            desempilhar(&URL);
            break;

        case 3:
            mostrarPilha(URL);
            break;

        default:
            printf("\nOPCAO INVALIDA!\n");
        }
    }

    return 0;
}