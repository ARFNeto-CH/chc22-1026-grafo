#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"
#include "pilha.h"

#define INFINITO 65535

struct vertices
{
    int id;         /*!< Identificação numérica do vértice  */
    //int p; // caso seja necessario adicionar o peso

    /*Dados do BFS*/
    int distancia;
    vertice_t *pai;

    /*Dados do BDP*/
    _Bool visitado;
    /* Mais informações, se necessário */
};

struct arestas
{
    int adj;        /*!< Valor booleando. Verdadeiro representa uma adjacência entre dois vértices  */

    /* Mais informações, se necessário */
};

struct grafos
{
    int n_vertices;         /*!< Número de vértices do grafo  */
    vertice_t *vertices;    /*!< Vetor de ponteiros: conjunto V */
    aresta_t **matriz_adj;	/* Matriz de adjacência: conjunto E */
};


void bfs(grafo_t *g, int fonte)
{

    int i;
    fila_t *fila = cria_fila();

    for(i = 0; i < g->n_vertices; i++)
    {
        g->vertices[i].distancia = INFINITO;
        g->vertices[i].pai = NULL;
    }

    g->vertices[fonte].distancia = 0;
    enqueue(&g->vertices[fonte], fila);

    while(!fila_vazia(fila))
    {
        vertice_t *u = dequeue(fila);

        int v;
        int id_u = u->id;

        for(v = 0; v < g->n_vertices; v++)
        {
            if(adjacente(g, id_u, v))
            {

 				if(g->vertices[v].distancia == INFINITO){
					g->vertices[v].distancia = g->vertices[id_u].distancia + 1;
					g->vertices[v].pai = id_u;
					enqueue(&g->vertices[v], fila);

            }
        }
    }
    mostra_bfs(g);
}

void mostra_bfs(grafo_t *g)
{
    int i=0;

    for(i = 0; i < g->n_vertices; i++)
    {
        printf("[%d] [%d]\n",i, g->vertices[i].distancia);
        if(g->vertices[i].pai != NULL)
        {
            printf("Pai de %d [%p]\n",i, g->vertices[i].pai);
        }
    }
}

void dfs(grafo_t *g, int fonte)
{
    int i;
    pilha_t *pilha = cria_pilha();

    for(i = 0; i < g->n_vertices; i++)
    {
        g->vertices[i].visitado = FALSE;
    }
    push(&g->vertices[fonte], pilha);

    while(!pilha_vazia(pilha))
    {
        vertice_t *u = pop(pilha);

        int v;
        int id_u = u->id;

        if(g->vertices[id_u].visitado == FALSE)
        {
            g->vertices[id_u].visitado = TRUE;

            for(v = 0; v < g->n_vertices; v++)
            {
                if(adjacente(g, id_u, v))
                {

                    if(g->vertices[v].visitado == FALSE)
                    {
                        push(&g->vertices[v], pilha);
                    }
                }
            }
        }
    }
    mostra_dfs(g);
}

void mostra_dfs(grafo_t *g)
{
    int i;

    for(i = 0; i < g->n_vertices; i++)
    {
        printf("Vertice %d ",i);
        if(g->vertices[i].visitado == FALSE)
        {
            printf("Não Visitado\n");
        }
        else
        {
            printf("Visitado\n");
        }
    }
}
/**
  * @brief  Cria uma novo grafo estático
  * @param	vertices: quantidade de vértices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
    int i;
    aresta_t **matriz_adj;
    /* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

    if (g == NULL)
    {
        perror("cria_grafo (g)");
        exit(EXIT_FAILURE);
    }

    /* Guarda número total de vértices */
    g->n_vertices = vertices;
    /* Aloca vértices */
    g->vertices = malloc(vertices * sizeof(vertice_t));

    if (g->vertices == NULL)
    {
        perror("cria_grafo (vertices)");
        exit(EXIT_FAILURE);
    }

    /* Zera vetor de vértices */
    memset(g->vertices, 0, vertices * sizeof(vertice_t));


    /* Inicializa ID */
    for ( i = 0; i < vertices; i++ )
    {
        g->vertices[i].id = i;
    }

    /* Aloca 1a dimensão da matriz de adjacência */
    matriz_adj = malloc(vertices * sizeof(aresta_t *));

    if (matriz_adj == NULL)
    {
        perror("cria_grafo (matriz_adj)");
        exit(EXIT_FAILURE);
    }

    /* Aloca 2a dimensão da matriz de adjacência */
    for ( i = 0; i < vertices; i++ )
    {
        matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

        if (matriz_adj[i] == NULL)
        {
            perror("cria_grafo (matriz_adj[i])");
            exit(EXIT_FAILURE);
        }
    }

    g->matriz_adj = matriz_adj;

    return g;
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g)
{
    int i;

    if (g == NULL)
    {
        perror("libera_grafo");
        exit(EXIT_FAILURE);
    }

    for (i=0; i < g->n_vertices; i++)
        free(g->matriz_adj[i]);

    free(g->matriz_adj);
    free(g->vertices);
    free(g);
}

/**
  * @brief  Cria adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v)
{

    if (g == NULL)
    {
        return FALSE;
    }

    if (u > g->n_vertices || v > g->n_vertices )
        return FALSE;

    g->matriz_adj[u][v].adj = TRUE;

    return TRUE;
}

/**
  * @brief  Remove adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v)
{

    if (g == NULL)
    {
        return FALSE;
    }

    if (u > g->n_vertices || v > g->n_vertices)
        return FALSE;

    g->matriz_adj[u][v].adj = FALSE;

    return TRUE;
}

/**
  * @brief  Retorna adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v)
{

    if (u > g->n_vertices || v > g->n_vertices)
        return FALSE;

    return ((g->matriz_adj[u][v].adj));
}


grafo_t *ler_dados_csv(char *nome_do_arquivo)
{
    grafo_t *g;

    int n_vertices;    // numero de arestas
    int u,v;

    FILE *fp =fopen(nome_do_arquivo, "r");
    if (fp==NULL)
    {
        perror("Erro ao ler grafo");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", &n_vertices);

    g = cria_grafo(n_vertices);    // criou as bolinhas p/ as arestas


    //ingnora a primeira linha
    //fgets(info, 128, fp);

    //obtem os dados do arquivo selecionado
    while (fscanf(fp, "%d,%d\n", &u, &v) == 2)
    {
        cria_adjacencia(g, u, v);
        cria_adjacencia(g, v, u);
    }

    fclose(fp);

    return g;
}
