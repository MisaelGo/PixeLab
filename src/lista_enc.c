#include "../include/lista_enc.h"


void cria_lista (LISTA_ENC* pl){
	*pl = NULL;
}

SDL_Texture* busca (LISTA_ENC l, int k){
	for (;k>1;l=l->prox,k--);
	return l->inf;
}

void ins (LISTA_ENC*pl, SDL_Texture*t){
	if (*pl){
		NODE*aux = *pl;
		for(;aux->prox;aux=aux->prox);
		if (aux->inf == t)
			return;
	}
	NODE* novo;
	novo = (NODE*)malloc (sizeof(NODE));
	if (!novo){
		printf ("Erro! Memoria Insuficiente!\n");
		return;
	}
	novo->inf = t;
	if (!*pl){
		novo->prox = NULL;
		novo->ant = NULL;
		*pl = novo;
	}else{
		NODE*aux = *pl;
		for (;aux->prox;aux=aux->prox);
		aux->prox = novo;
		novo->ant = aux;
		novo->prox = NULL;
	}
}

void ret (LISTA_ENC*pl){
	if (!*pl){
		printf ("Erro na retirada!\n");
		return;
	}
	NODE*aux = *pl;
	for (;aux->prox;aux=aux->prox);
	if (aux->ant){
		aux->ant->prox = aux->prox;	
	}
	else{
		*pl = NULL;
	}
	free (aux);
}
