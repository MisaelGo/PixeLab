#include "../include/destroy.h"

void destroy (AppContext *p){
	for (int i = 0; i<9;i++){
		SDL_DestroyTexture (p->Elements[i]);
		p->Elements[i] = NULL;	
	}
	
	SDL_DestroyTexture (p->imageTextureTestSug4);
	p->imageTextureTestSug4 = NULL;
	
	SDL_DestroyTexture (p->imageTextureTestSug3);
	p->imageTextureTestSug3 = NULL;
	
	SDL_DestroyTexture (p->imageTextureTestSug2);
	p->imageTextureTestSug2 = NULL;
	
	SDL_DestroyTexture (p->imageTextureTestSug1);
	p->imageTextureTestSug1 = NULL;
	
	SDL_DestroyTexture (p->EscalarTexture);
	p->EscalarTexture = NULL;
	
	SDL_DestroyTexture (p->MatrixTexture);
	p->MatrixTexture = NULL;
	
	SDL_DestroyTexture (p->ColchetesMatrixTexture);
	p->ColchetesMatrixTexture = NULL;
	
	SDL_DestroyTexture (p->DesfazerTexture);
	p->DesfazerTexture = NULL;
	
	SDL_DestroyTexture (p->DesfazerTextureShadow);
	p->DesfazerTextureShadow = NULL;
	
	SDL_DestroyTexture (p->EscalonarTexture);
	p->EscalonarTexture = NULL;
	
	SDL_DestroyTexture (p->EscalonarTextureShadow);
	p->EscalonarTextureShadow = NULL;
	
	SDL_DestroyTexture (p->TrocaMultTexture);
	p->TrocaMultTexture = NULL;
	
	SDL_DestroyTexture (p->TrocaMultTextureShadow);
	p->TrocaMultTextureShadow = NULL;
	
	SDL_DestroyTexture (p->MultEscalarTexture);
	p->MultEscalarTexture = NULL;
	
	SDL_DestroyTexture (p->MultEscalarTextureShadow);
	p->MultEscalarTextureShadow = NULL;
	
	SDL_DestroyTexture (p->TrocaLinhaTexture);
	p->TrocaLinhaTexture = NULL;
	
	SDL_DestroyTexture (p->TrocaLinhaTextureShadow);
	p->TrocaLinhaTextureShadow = NULL;
	
	SDL_DestroyTexture (p->OperacoesTextureShadow);
	p->OperacoesTextureShadow = NULL;
	
	SDL_DestroyTexture (p->buttonTextureClick);
	p->buttonTextureClick = NULL;
	
	SDL_DestroyTexture (p->buttonTextureHover);
	p->buttonTextureHover = NULL;
	
	SDL_DestroyTexture (p->buttonTexture);
	p->buttonTexture = NULL;
	
	SDL_DestroyTexture (p->OperacoesTexture);
	p->OperacoesTexture = NULL;
	
	SDL_DestroyTexture (p->OperacoesTextureShadow);
	p->OperacoesTextureShadow = NULL;
	
	SDL_DestroyTexture (p->instruction1Texture);
	p->instruction1Texture = NULL;
	
	SDL_DestroyTexture (p->instruction1TextureShadow);
	p->instruction1TextureShadow = NULL;
	
	SDL_DestroyTexture (p->suggestionTexture);
	p->suggestionTexture = NULL;
	
	SDL_DestroyTexture (p->suggestionTextureShadow);
	p->suggestionTextureShadow = NULL;
	
	SDL_DestroyTexture (p->titleTexture);
	p->titleTexture = NULL;
	
	SDL_DestroyTexture (p->titleTextureShadow);
	p->titleTextureShadow = NULL;
	
	SDL_DestroyTexture (p->imageTextureTest);
	p->imageTextureTest = NULL;
	
	SDL_DestroyTexture (p->bubbleTextureDisabled);
	p->bubbleTextureDisabled = NULL;
	
	SDL_DestroyTexture (p->imageTexture);
	p->imageTexture = NULL;
	
	SDL_DestroyRenderer (p->renderer);
	p->renderer = NULL;
	
	SDL_DestroyWindow (p->window);
	p->window = NULL;
	
	TTF_Quit();
	
    SDL_Quit();
}
