#include "../include/images.h"
#include "../include/destroy.h"

void images (AppContext *p,SDL_Texture** text,char local[], char msg_surface[], char msg_texture []){
	p->imageSurface = SDL_LoadBMP (local);
	if (!p->imageSurface){
		printf ("Erro no carregamento da %s: %s\n",msg_surface,SDL_GetError());
		destroy (p);
		exit (4);
	}
	printf ("%s carregada com sucesso!\n",msg_surface);
	
	*text = SDL_CreateTextureFromSurface (p->renderer,p->imageSurface);
	if (!*text){
		printf ("Erro na criacao da %s: %s\n",msg_texture, SDL_GetError());
		destroy (p);
		exit (5);
	} 
	SDL_DestroySurface (p->imageSurface);
	p->imageSurface = NULL;
	printf ("%s criada com sucesso!\n", msg_texture);
}
