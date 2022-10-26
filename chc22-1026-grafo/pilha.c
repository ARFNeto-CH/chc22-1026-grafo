#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
	    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t)); // aloca memoria pra pilha
		pilha->dados = criar_lista_enc(); // e cria a lista

		return pilha;
}


//adiciona elemento
void push(void* dado, pilha_t *pilha)
{
	lista_enc_t *lista = retorna_lista(pilha);//acessa a lista
	no_t *no = criar_no(dado); // cria o dado
	add_cabeca(lista,no);  // armazena o dado na cabeça

}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
	if(pilha_vazia(pilha)){
		fprintf(stderr,"pilha_vazia");
		return NULL;
		}
		no_t *no;
		no = remover_cabeca(pilha->dados); // retira a cabeça
		void *dado = obter_dado(no);  // pega os dados
		free(no); // libera o nó
		return dado; // retorna os dados retirados
}


void libera_pilha(pilha_t* pilha)
{
	free(pilha->dados);
	free(pilha);
}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}

lista_enc_t *retorna_lista(pilha_t *pilha){
	return pilha -> dados;
}
