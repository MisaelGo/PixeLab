// pilha_acao.c
#include <stdlib.h>
#include <stdio.h>
#include "../include/pilha_acao.h"

void cria_pilha_acao(PILHA_ACAO* p){
    *p = NULL;
}

int pilha_acao_vazia(PILHA_ACAO p){
    return (p == NULL);
}

void push_acao(PILHA_ACAO* p, ACAO_TIPO t){
    NODO_ACAO* novo = (NODO_ACAO*)malloc(sizeof(NODO_ACAO));
    if (!novo){
        printf("Erro! Memória insuficiente em push_acao!\n");
        exit(1);
    }
    novo->tipo = t;
    novo->prox = *p;
    *p = novo;
}

ACAO_TIPO pop_acao(PILHA_ACAO* p){
    if (*p == NULL){
        printf("Erro! pop_acao em pilha vazia!\n");
        exit(2);
    }
    NODO_ACAO* aux = *p;
    ACAO_TIPO t = aux->tipo;
    *p = aux->prox;
    free(aux);
    return t;
}

