// pilha_acao.h
#ifndef PILHA_ACAO_H
#define PILHA_ACAO_H

typedef enum {
    ACAO_SUGESTAO,
    ACAO_KERNEL,
    ACAO_APLICAR
} ACAO_TIPO;

typedef struct nodo_acao {
    ACAO_TIPO tipo;
    struct nodo_acao* prox;
} NODO_ACAO;

typedef NODO_ACAO* PILHA_ACAO;

void cria_pilha_acao(PILHA_ACAO* p);
int  pilha_acao_vazia(PILHA_ACAO p);
void push_acao(PILHA_ACAO* p, ACAO_TIPO t);
ACAO_TIPO pop_acao(PILHA_ACAO* p);

#endif

