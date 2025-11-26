#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 
#include <limits.h>
#include <math.h>
#define MATRIX_LIMIT 1000
#define EPSILON 1e-12

typedef struct {
    double** data;   // Ponteiro para os ponteiros das linhas
    double* block;   // Ponteiro para o bloco de dados contíguo
    size_t linhas, colunas;        // Número de linhas e colunas da matriz
} Matrix;

// Funcoes de alocacao/liberacao
Matrix* create_matrix(size_t linas, size_t colunas); // Criar Matriz
void free_matrix(Matrix* m); // Liberar Matriz

// Funcoes de insercao de elementos
int ins_elem_matrix(Matrix* m, size_t i, size_t j, double num); // inserção dos elementos da matriz

// Funcoes de manipulacao da matriz
void swap_rows(Matrix* m, size_t r1, size_t r2);    // Trocar linhas
void scale_row(Matrix* m, size_t r, double scalar); // Multiplicar por escalar
void add_rows(Matrix* m, size_t target_row, size_t source_row, double scalar); // Somar linhas no sentido de: Li -> Li + 2Lj
size_t find_pivot_row(Matrix *m, size_t col, size_t start_row); // Adicionado para melhorar a implemetação da função to_rref
void to_rref(Matrix* m); // Escalonamento completo de Matrizes

// Etc
int ler_double(const char *prompt, double *out); // Funcao para entrada de elementos robusta
void print_matrix(Matrix* m); // Adicionei para ajudar a visualizar
void clear_input_buffer(); //Adicionada para evitar problemas com o buffer cheio

#endif
