#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"


int main(void) {

	grafo_t* g;

	g = ler_dados_csv("grafos_teste.csv");

	bfs(g, 0);
	mostra_bfs(g);

	puts("\n");

	dfs(g, 0);
	mostra_dfs(g);

	libera_grafo(g);

	return EXIT_SUCCESS;
}
