#include "../include/pilha_matrix.h"
#include <stdlib.h>
#include <stdio.h>

/* cópia profunda da matriz */
static Matrix* clone_matrix_internal(const Matrix* src){
    if (!src) return NULL;
    Matrix* dst = create_matrix(src->linhas, src->colunas);
    if (!dst) return NULL;
    for (size_t i = 0; i < src->linhas; ++i)
        for (size_t j = 0; j < src->colunas; ++j)
            dst->data[i][j] = src->data[i][j];
    return dst;
}

void cria_pilha_m(PILHA_M* p){
    *p = NULL;
}

void push_m(PILHA_M* p, const Matrix* m){
    NODO_M* novo = (NODO_M*)malloc(sizeof(NODO_M));
    if (!novo){
        printf("Erro! Memoria insuficiente na pilha de matrizes!\n");
        return;
    }
    novo->inf  = clone_matrix_internal(m);  // snapshot do kernel
    novo->next = *p;
    *p = novo;
}

Matrix* pop_m(PILHA_M* p){
    if (!p || !*p){
        printf("Pilha de matrizes vazia!\n");
        return NULL;
    }
    NODO_M* aux = *p;
    Matrix* ret = aux->inf;
    *p = aux->next;
    free(aux);
    return ret;
}

int pilha_m_vazia(PILHA_M p){
    return (p == NULL);
}

