#ifndef PILHA_MATRIX_H
#define PILHA_MATRIX_H

#include "../include/algebra.h"   // para ter o tipo Matrix

typedef struct nodo_m {
    Matrix* inf;
    struct nodo_m* next;
} NODO_M;

typedef NODO_M* PILHA_M;

void cria_pilha_m(PILHA_M* p);
void push_m(PILHA_M* p, const Matrix* m);
Matrix* pop_m(PILHA_M* p);
int pilha_m_vazia(PILHA_M p);

#endif

