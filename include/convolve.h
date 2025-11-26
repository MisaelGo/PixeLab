#ifndef CONVOLVE_H
#define CONVOLVE_H

#include <SDL3/SDL.h>
#include "../include/algebra.h"  /* usa Matrix como kernel */
#include "../include/texts.h"
#include "../include/pilha.h"
#include "../include/main.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Carrega BMP, aplica um kernel (Matrix NxN) e devolve uma SDL_Texture RGBA32 */
SDL_Texture* sdl_convolve_image(
    SDL_Renderer* renderer,
    const char* bmp_path,
    const Matrix* kernel,
    double scale,   /* ex.: 1.0 / soma(kernel) p/ normalizar */
    double bias,    /* ex.: 0.0; use 128.0 p/ emboss, etc. */
    int clamp_edges /* 1 = espelha/clampa, 0 = ignora fora (zero-padding) */
);

/* Helpers para criar/usar kernels */
Matrix* create_kernel_from_array(const double* data, size_t n); /* n x n */
Matrix* create_kernel_from_string_array(const char** data, size_t n);
void aplicar_kernel_na_imagem(AppContext* ctx, PILHA* pilha);
void atualizar_elementos(AppContext* p);
/*void promoverTroca (char** data, size_t n);*/
double  kernel_norm_divisor(const Matrix* k); /* soma dos coeficientes */
SDL_Texture* apply_convolution_filter(
    SDL_Renderer* renderer,
    SDL_Texture** target_texture,
    const char* bmp_path,
    const Matrix* kernel,
    double scale,
    double bias,
    int clamp_edges
);

Matrix* create_kernel_blur3x3(void);
Matrix* create_kernel_sharpen(void);
Matrix* create_kernel_highboost(void);
Matrix* create_kernel_emboss(void);

#ifdef __cplusplus
}
#endif

#endif

