#include "../include/convolve.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

static inline Uint32 get_px(Uint8* base, int pitch, int x, int y){
    return *(Uint32*)(base + (size_t)y * pitch + (size_t)x * 4);
}
static inline void set_px(Uint8* base, int pitch, int x, int y, Uint32 argb){
    *(Uint32*)(base + (size_t)y * pitch + (size_t)x * 4) = argb;
}
static inline int clampi(int v, int lo, int hi){
    return v < lo ? lo : (v > hi ? hi : v);
}

Matrix* create_kernel_from_array(const double* data, size_t n){
    Matrix* k = create_matrix(n, n);
    if(!k) return NULL;
    for(size_t i=0;i<n;i++)
        for(size_t j=0;j<n;j++)
            k->data[i][j] = data[i*n + j];
    return k;
}

Matrix* create_kernel_from_string_array(const char** data, size_t n){
    Matrix* k = create_matrix(n, n);
    if(!k) return NULL;

    for(size_t i = 0; i < n*n; i++){
        k->data[i / n][i % n] = atof(data[i]);
    }

    return k;
}

double kernel_norm_divisor(const Matrix* k){
    double s = 0.0;
    for(size_t i=0;i<k->linhas;i++)
        for(size_t j=0;j<k->colunas;j++)
            s += k->data[i][j];
    return (fabs(s) < EPSILON) ? 1.0 : s;
}

SDL_Texture* sdl_convolve_image(SDL_Renderer* renderer,
                                const char* bmp_path,
                                const Matrix* kernel,
                                double scale,
                                double bias,
                                int clamp_edges){
    if(!renderer || !bmp_path || !kernel) return NULL;

    SDL_Surface* src = SDL_LoadBMP(bmp_path);
    if(!src){
        SDL_Log("LoadBMP failed: %s", SDL_GetError());
        return NULL;
    }

    /* Trabalhamos em RGBA32 */
    SDL_Surface* rgba = SDL_ConvertSurface(src, SDL_PIXELFORMAT_RGBA32);
    SDL_DestroySurface(src);
    if(!rgba){
        SDL_Log("ConvertSurfaceFormat failed: %s", SDL_GetError());
        return NULL;
    }

    SDL_Surface* dst = SDL_CreateSurface(rgba->w, rgba->h, SDL_PIXELFORMAT_RGBA32);
    if(!dst){
        SDL_Log("CreateSurface failed: %s", SDL_GetError());
        SDL_DestroySurface(rgba);
        return NULL;
    }

    SDL_LockSurface(rgba);
    SDL_LockSurface(dst);

    Uint8* sp = (Uint8*)rgba->pixels;
    Uint8* dp = (Uint8*)dst->pixels;
    const int sw = rgba->w, sh = rgba->h, spitch = rgba->pitch, dpitch = dst->pitch;

    const int kN = (int)kernel->linhas; /* assume quadrado */
    const int kR = kN / 2;

    for(int y=0; y<sh; y++){
        for(int x=0; x<sw; x++){
            double accA=0.0, accR=0.0, accG=0.0, accB=0.0;

            for(int ky=0; ky<kN; ky++){
                for(int kx=0; kx<kN; kx++){
                    int ix = x + (kx - kR);
                    int iy = y + (ky - kR);

                    if(clamp_edges){
                        ix = clampi(ix, 0, sw-1);
                        iy = clampi(iy, 0, sh-1);
                    }else{
                        if(ix<0 || iy<0 || ix>=sw || iy>=sh) continue;
                    }

                    const double kval = kernel->data[ky][kx];
                    const Uint32 pix = get_px(sp, spitch, ix, iy);
                    const Uint8 a = (pix >> 24) & 0xFF;
                    const Uint8 r = (pix >> 16) & 0xFF;
                    const Uint8 g = (pix >>  8) & 0xFF;
                    const Uint8 b = (pix      ) & 0xFF;

                    accA += a * kval;
                    accR += r * kval;
                    accG += g * kval;
                    accB += b * kval;
                }
            }

            double Ra = accA * scale + bias;
            double Rr = accR * scale + bias;
            double Rg = accG * scale + bias;
            double Rb = accB * scale + bias;

            Uint8 oa = (Uint8)(Ra < 0 ? 0 : (Ra > 255 ? 255 : Ra));
            Uint8 or_ = (Uint8)(Rr < 0 ? 0 : (Rr > 255 ? 255 : Rr));
            Uint8 og  = (Uint8)(Rg < 0 ? 0 : (Rg > 255 ? 255 : Rg));
            Uint8 ob  = (Uint8)(Rb < 0 ? 0 : (Rb > 255 ? 255 : Rb));

            Uint32 out = ((Uint32)oa<<24) | ((Uint32)or_<<16) | ((Uint32)og<<8) | (Uint32)ob;
            set_px(dp, dpitch, x, y, out);
        }
    }

    SDL_UnlockSurface(dst);
    SDL_UnlockSurface(rgba);
    SDL_DestroySurface(rgba);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, dst);
    SDL_DestroySurface(dst);
    return tex;
}

SDL_Texture* apply_convolution_filter(
    SDL_Renderer* renderer,
    SDL_Texture** target_texture,
    const char* bmp_path,
    const Matrix* kernel,
    double scale,
    double bias,
    int clamp_edges
) {
    if (!renderer || !target_texture || !kernel || !bmp_path)
        return NULL;

    /* Aplica o filtro via convolução */
    SDL_Texture* filtered = sdl_convolve_image(
        renderer,
        bmp_path,
        kernel,
        scale,
        bias,
        clamp_edges
    );

    if (filtered) {
        if (*target_texture)
            SDL_DestroyTexture(*target_texture);
        *target_texture = filtered;
    }

    return filtered;
}
/*void promoverTroca (char** data, size_t n){
	Matrix* k = create_kernel_from_string_array(data, n);
	swap_rows(k, 0, 1);
	free_matrix(k);
}*/
	/*double s = kernel_norm_divisor(k);
	double scale = (fabs(s) < 1e-12) ? 1.0 : 1.0 / s;
	double bias = (fabs(s) < 1e-12) ? 128.0 : 0.0;
	apply_convolution_filter(
	    p->renderer,
	    &p->imageTextureTestSug1,
	    "assets/monarch.bmp",
	    k,
	    scale,
	    bias,
	    1
	);*/

/* --- Kernels clássicos de convolução --- */

Matrix* create_kernel_blur3x3(void) {
    const double data[] = {
        1, 2, 1,
        2, 4, 2,
        1, 2, 1
    };
    return create_kernel_from_array(data, 3);
}

Matrix* create_kernel_sharpen(void) {
    const double data[] = {
         0, -1,  0,
        -1,  5, -1,
         0, -1,  0
    };
    return create_kernel_from_array(data, 3);
}

Matrix* create_kernel_emboss(void) {
    const double data[] = {
        -2, -1,  0,
        -1,  1,  1,
         0,  1,  2
    };
    return create_kernel_from_array(data, 3);
}

Matrix* create_kernel_highboost(void) {
    const double data[] = {
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    };
    return create_kernel_from_array(data, 3);
}

void atualizar_elementos(AppContext* p)
{
    for (int i = 0; i < 9; i++) {
        double v = p->kernel_atual->data[i / 3][i % 3];

        char buffer[32];
        sprintf(buffer, "%.2f", v);

        texts(p, "font/BodoniFLF.ttf", 30.0,
              "Fonte para Elemento",
              buffer,
              "Elemento em imagem",
              &(p->Elements[i]),
              "ElementsTexture",
              255,255,255,255);
    }
}

void aplicar_kernel_na_imagem(AppContext* ctx, PILHA* pilha)
{
    // TODO: ajuste o caminho da imagem ORIGINAL que você quer filtrar
    const char* caminho_imagem = "assets/monarch.bmp";

    SDL_Texture* filtered = sdl_convolve_image(
        ctx->renderer,
        caminho_imagem,
        ctx->kernel_atual,
        1.0,   // scale (pode ajustar depois)
        0.0,   // bias
        1      // clamp bordas
    );

    if (!filtered) {
        printf("Erro na convolucao: %s\n", SDL_GetError());
        return;
    }

    // Atualiza a textura exibida no centro
    ctx->imageTextureTest = filtered;
}
