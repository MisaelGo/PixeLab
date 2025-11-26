#include "../include/texts.h"
#include "../include/destroy.h"

void texts (AppContext *p,char local[],float tamanho,char msg_fonte[],const char frase[],char msg_surface[],SDL_Texture** text,char msg_text[],int r,int g,int b,int a){
	p->font = TTF_OpenFont (local,tamanho);
	if (!p->font){
		printf ("Erro no carregamento da %s: %s\n",msg_fonte,SDL_GetError());
		destroy (p);
		exit (6);
	}
	printf ("%s carregada com sucesso!\n",msg_fonte);
	
	SDL_Color color = {r,g,b,a};
	p->titleSurface = TTF_RenderText_Blended (p->font, frase,strlen(frase),color);
	if (!p->titleSurface){
		printf ("Erro na transformacao do %s: %s\n",msg_surface,SDL_GetError());
		destroy (p);
		exit (4);
	}
	printf ("Transformacao do %s com sucesso!\n",msg_surface);
	
	*text = SDL_CreateTextureFromSurface (p->renderer, p->titleSurface);
	if (!*text){
		printf ("Erro na criacao da textura do %s: %s\n",msg_text,SDL_GetError());
		destroy (p);
		exit (5);
	}
	printf ("Criacao da textura do %s com sucesso!\n",msg_text);
	SDL_DestroySurface (p->titleSurface);
	p->titleSurface = NULL;
	TTF_CloseFont (p->font);
	p->font = NULL;
}
