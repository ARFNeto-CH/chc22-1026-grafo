#ifndef GRAFO_H_
#define GRAFO_H_

#include "grafo.h"
#include "fila.h"
#include "pilha.h"

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void bfs(grafo_t *g, int fonte);
void mostra_bfs(grafo_t *g);
void dfs(grafo_t *g, int fonte);
void mostra_dfs(grafo_t *g);

grafo_t *ler_dados_csv(char *nome_do_arquivo);

#endif /* GRAFO_H_ */
