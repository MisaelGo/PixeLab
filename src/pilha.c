#include "../include/pilha.h"
#include <stdlib.h>

void cria_pilha(PILHA* p) { *p = NULL; }

void push(PILHA* p, SDL_Texture* t){
	if (*p && (*p)->inf == t){
		return;
	}
    NODO* n = (NODO*)malloc(sizeof(NODO));
    if(!n) return;
    n->inf  = t;
    n->next = *p;
    *p = n;
}

/* peek/topo: não remove; retorna NULL se vazia */
SDL_Texture* top(PILHA p){
    return p ? p->inf : NULL;
}

/* pop: remove e DEVOLVE a textura; retorna NULL se vazia */
SDL_Texture* pop(PILHA* p){
	if(!p || !*p) return NULL;          /* pilha vazia */
    NODO* n = *p;
    if (n->next){
    	SDL_Texture* t = n->next->inf;            /* devolve ao chamador */
    	*p = n->next;
    	free(n);
    	return t;
	}else{
    	return n->inf;
	}
}

