#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

/* #define DEBUG */

struct listas_enc {
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista){
    return lista->cabeca;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  * @param  elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

void add_cabeca(lista_enc_t *lista, no_t* elemento){
	if (lista == NULL || elemento == NULL){
	        fprintf(stderr,"add_cabeca: ponteiros invalidos");
	        exit(EXIT_FAILURE);
	    }

	   #ifdef DEBUG
	   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
	   #endif // DEBUG

	   //lista vazia
	   if (lista->tamanho == 0)
	   {
	        #ifdef DEBUG
	        printf("add_cauda: add primeiro elemento: %p\n", elemento);
	        #endif // DEBUG

	        lista->cauda = elemento;
	        lista->cabeca = elemento;
	        lista->tamanho++;

	        desligar_no(elemento);
	   }
	   else {
	        // Remove qualquer ligacao antiga
	        desligar_no(elemento);
	        // Liga cabeça da lista com novo elemento
	        ligar_nos(elemento, lista->cabeca);

	        lista->cabeca = elemento;
	        lista->tamanho++;
	   }


}

void *remover_cabeca(lista_enc_t *lista){

	no_t *cabeca = obter_cabeca(lista); //cria no auxliar
		if(cabeca != NULL){
			lista ->cabeca = obter_proximo(cabeca);// redireciona a cabeça para o no seguinte
			lista->tamanho--;

			if(lista->tamanho == 0){ //Se o tamanho for zero joga nulo na cauda
				lista->cauda = NULL;
			}
			return cabeca;
		}

		return NULL;
}


int lista_vazia(lista_enc_t* lista){

	if(lista->tamanho == 0||lista == NULL)
		{
			return 1;
		}
		return 0;
}
