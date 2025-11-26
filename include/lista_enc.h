#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

typedef struct SDL_Texture SDL_Texture;
typedef struct node{
	SDL_Texture* inf;
	struct node* prox;
	struct node* ant;
}NODE;
typedef NODE* LISTA_ENC;

void cria_lista (LISTA_ENC* pl);
void ins (LISTA_ENC*pl, SDL_Texture*t);
void ret (LISTA_ENC*pl);
SDL_Texture* busca (LISTA_ENC l, int k);

#endif
