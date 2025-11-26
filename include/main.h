#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../include/algebra.h"


typedef struct {
	SDL_Window*   window;
	SDL_Renderer* renderer;
	SDL_Surface*  imageSurface;
	SDL_Texture*  imageTexture;
	SDL_Texture*  bubbleTextureDisabled;
	SDL_Texture*  imageTextureTest;
	SDL_Texture*  imageTextureTestSug1;
	SDL_Texture*  imageTextureTestSug2;
	SDL_Texture*  imageTextureTestSug3;
	SDL_Texture*  imageTextureTestSug4;
	SDL_Texture*  buttonTexture;
	SDL_Texture*  buttonTextureHover;
	SDL_Texture*  buttonTextureClick;
	SDL_Texture*  ColchetesMatrixTexture;
	SDL_Texture*  MatrixTexture;
	SDL_Texture*  EscalarTexture;
	TTF_Font*     font;
	SDL_Surface*  titleSurface;
	SDL_Texture*  titleTexture;
	SDL_Texture*  titleTextureShadow;
	SDL_Texture*  suggestionTextureShadow;
	SDL_Texture*  suggestionTexture;
	SDL_Texture*  instruction1TextureShadow;
	SDL_Texture*  instruction1Texture;
	SDL_Texture*  OperacoesTextureShadow;
	SDL_Texture*  OperacoesTexture;
	SDL_Texture*  TrocaLinhaTextureShadow;
	SDL_Texture*  TrocaLinhaTexture;
	SDL_Texture*  MultEscalarTextureShadow;
	SDL_Texture*  MultEscalarTexture;
	SDL_Texture*  TrocaMultTextureShadow;
	SDL_Texture*  TrocaMultTexture;
	SDL_Texture*  EscalonarTextureShadow;
	SDL_Texture*  EscalonarTexture;
	SDL_Texture*  DesfazerTextureShadow;
	SDL_Texture*  DesfazerTexture;
	SDL_Texture*  Elements[9];
	Matrix* kernel_atual;
	SDL_Texture* AplicarTexture;
	SDL_Texture* AplicarTextureShadow;
}AppContext;

typedef struct {
	int isHover1;
	int isHover2;
	int isHover3;
	int isHover4;
	int isHover5;
	int isHover6;
	int isHover7;
	int isHover8;
	int isHover9;
	int isHover10;
	int isHover11;
	int isHover12;
	int isHover13;
	int isHover14;
	int isHover15;
}EFFECTS;

void effect (EFFECTS* e,double x, double y);
void atualizaMensagemPadrao(AppContext* ctx);

#endif
