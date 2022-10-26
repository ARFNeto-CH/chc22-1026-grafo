#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *dados;
};


//cria uma pilha generica
fila_t * cria_fila (void)
{
   fila_t *fila = malloc(sizeof(fila_t));

   fila->dados = criar_lista_enc();

   return fila;
}


//adiciona elemento
void enqueue(void* dado, fila_t *fila)
{
  no_t *new_no = criar_no(dado);

  add_cauda(fila->dados, new_no);

}

//retira elemento do topo
void *dequeue(fila_t *fila)
{
	if(fila_vazia(fila)){
			fprintf(stderr,"pilha_vazia");
			return NULL;
			}
			no_t *no;
			no = remover_cabeca(fila->dados); // retira a cabeça
			void *dado = obter_dado(no);  // pega os dados
			free(no); // libera o nó
			return dado; // retorna os dados retirados
}


void libera_fila(fila_t* fila)
{
	free(fila->dados);
    free(fila);
}

int fila_vazia(fila_t *fila)
{

	return lista_vazia(fila->dados);

}
