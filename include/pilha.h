#ifndef PILHA_H
#define PILHA_H

typedef struct SDL_Texture SDL_Texture;

typedef struct nodo {
    SDL_Texture* inf;
    struct nodo* next;
} NODO;

typedef NODO* PILHA;

/* API da pilha de texturas */
void cria_pilha (PILHA* p);
void push       (PILHA* p, SDL_Texture* t);
SDL_Texture* pop(PILHA*  p);
SDL_Texture* top (PILHA p);



#endif /* PILHA_H */
