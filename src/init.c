#include "../include/init.h"
#include "../include/texts.h"
#include "../include/images.h"
#include "../include/destroy.h"
#include "../include/convolve.h"


void init (AppContext* p){
	if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Nao foi possivel inicializar o SDL: %s\n", SDL_GetError());
        exit (1);
    }
    printf("SDL inicializado!\n");
    
    if (!TTF_Init()){
    	printf ("Erro na inicialização do SDL_TTF: %s\n",SDL_GetError());
    	destroy (p);
    	exit (1);
	}
	printf ("SDL_TTF inicializado com sucesso!\n");
    
    p->window = SDL_CreateWindow ("PixeLab", 1280, 720, 0);
	if (!p->window){
		printf ("Erro na criação da Janela: %s\n",SDL_GetError());
		destroy (p);
		exit (2);
	}
	printf ("Janela Criada com Sucesso!\n");
	
	p->renderer = SDL_CreateRenderer (p->window,NULL);
	if (!p->renderer){
		printf ("Erro na criação do renderizador: %s\n",SDL_GetError());
		destroy (p);
		exit (3);
	}
	printf ("Renderizador criado com sucesso!\n");
	
	images (p,&(p->imageTexture),"assets/fundo.bmp", "Imagem do fundo", "Textura do fundo");
	images (p,&(p->bubbleTextureDisabled),"assets/Balao_mensagem_desativado.bmp", "Imagem do bubbleTextureDisabled", "Textura do bubbleTextureDisabled");
	images (p,&(p->imageTextureTest),"assets/monarch.bmp", "Imagem do imageTextureTest", "Textura do imageTextureTest");
	images (p,&(p->buttonTexture),"assets/botao_normal.bmp", "Imagem do ButtonTexture", "Textura do ButtonTexture");
	images (p,&(p->buttonTextureHover),"assets/botao_hover.bmp", "Imagem do ButtonTextureHover", "Textura do ButtonTextureHover");
	images (p,&(p->buttonTextureClick),"assets/botao_clicado.bmp", "Imagem do ButtonTextureClick", "Textura do ButtonTextureClick");
	images (p,&(p->ColchetesMatrixTexture),"assets/Colchetes_matriz.bmp", "Imagem do ColchetesMatrixTexture", "Textura do ColchetesMatrixTexture");
	images (p,&(p->MatrixTexture),"assets/Matriz_3x3.bmp", "Imagem do MatrixTexture", "Textura do MatrixTexture");
	images (p,&(p->EscalarTexture),"assets/Colchetes_escalar.bmp", "Imagem do EscalarTexture", "Textura do EscalarTexture");
	
	texts (p,"font/BodoniFLF.ttf",100,"Fonte para o title","PixeLab","TitleShadow em imagem",&(p->titleTextureShadow),"titleShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",100,"Fonte para o title","PixeLab","Title em imagem",&(p->titleTexture),"title",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",25.0,"Fonte para o suggestion","Sugestoes","suggestionTextureShadow em imagem",&(p->suggestionTextureShadow),"suggestionTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",25.0,"Fonte para o suggestion","Sugestoes","suggestionTexture em imagem",&(p->suggestionTexture),"suggestionTexture",255,255,255,255);
	//texts (p,"font/BodoniFLF.ttf",25.0,"Fonte para a instruction1","Selecione uma das operacoes ao lado","instruction1TextureShadow em imagem",&(p->instruction1TextureShadow),"instruction1TextureShadow",10,10,10,255);
	//texts (p,"font/BodoniFLF.ttf",25.0,"Fonte para a instruction1","Selecione uma das operacoes ao lado","instruction1Texture em imagem",&(p->instruction1Texture),"instruction1Texture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",45.0,"Fonte para Operacoes","Operacoes","Operacoes em imagem",&(p->OperacoesTextureShadow),"OperacoesTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",45.0,"Fonte para Operacoes","Operacoes","Operacoes em imagem",&(p->OperacoesTexture),"OperacoesTexture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesTrocaLinha","Li <-> Lj","OperacoesTrocaLinha em imagem",&(p->TrocaLinhaTextureShadow),"TrocaLinhaTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesTrocaLinha","Li <-> Lj","OperacoesTrocaLinha em imagem",&(p->TrocaLinhaTexture),"TrocaLinhaTexture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesMultEscalar","Li <- k*Li","OperacoesMultEscalar em imagem",&(p->MultEscalarTextureShadow),"MultEscalarTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesMultEscalar","Li <- k*Li","OperacoesMultEscalar em imagem",&(p->MultEscalarTexture),"MultEscalarTexture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesTrocaMult","Li <- Li + k*Lj","OperacoesTrocaMult em imagem",&(p->TrocaMultTextureShadow),"TrocaMultTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesTrocaMult","Li <- Li + k*Lj","OperacoesTrocaMult em imagem",&(p->TrocaMultTexture),"TrocaMultTexture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesEscalonar","Escalonar","OperacoesEscalonar em imagem",&(p->EscalonarTextureShadow),"EscalonarTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para OperacoesEscalonar","Escalonar","OperacoesEscalonar em imagem",&(p->EscalonarTexture),"EscalonarTexture",255,255,255,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para Desfazer","Desfazer","Desfazer em imagem",&(p->DesfazerTextureShadow),"DesfazerTextureShadow",10,10,10,255);
	texts (p,"font/BodoniFLF.ttf",30.0,"Fonte para Desfazer","Desfazer","Desfazer em imagem",&(p->DesfazerTexture),"DesfazerTexture",255,255,255,255);
	texts(p,
      "font/BodoniFLF.ttf",
      30.0f,
      "AplicarLabel",
      "Aplicar",
      "AplicarTexture",
      &(p->AplicarTexture),
      "AplicarTexRef",
      255,255,255,255);
    texts(p,
      "font/BodoniFLF.ttf",
      30.0f,
      "AplicarLabel",
      "Aplicar",
      "AplicarTexture",
      &(p->AplicarTextureShadow),
      "AplicarTexRef",
      255,255,255,255);
	
	Matrix* k = create_kernel_highboost();
	double s = kernel_norm_divisor(k);
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
	);
	free_matrix(k);
	
	Matrix* k2 = create_kernel_emboss();
	double s2 = kernel_norm_divisor(k2);
	double scale2 = (fabs(s2) < 1e-12) ? 1.0 : 1.0 / s2;
	double bias2 = (fabs(s2) < 1e-12) ? 128.0 : 0.0;
	
	apply_convolution_filter(
	    p->renderer,
	    &p->imageTextureTestSug2,
	    "assets/monarch.bmp",
	    k2,
	    scale2,
	    bias2,
	    1
	);
	free_matrix(k2);
	
	Matrix* k3 = create_kernel_sharpen();
	double s3 = kernel_norm_divisor(k3);
	double scale3 = (fabs(s3) < 1e-12) ? 1.0 : 1.0 / s3;
	double bias3 = (fabs(s3) < 1e-12) ? 128.0 : 0.0;
	
	apply_convolution_filter(
	    p->renderer,
	    &p->imageTextureTestSug3,
	    "assets/monarch.bmp",
	    k3,
	    scale3,
	    bias3,
	    1
	);
	free_matrix(k3);
	
	Matrix* k4 = create_kernel_blur3x3();
	double s4 = kernel_norm_divisor(k4);
	double scale4 = (fabs(s4) < 1e-12) ? 1.0 : 1.0 / s4;
	double bias4 = (fabs(s4) < 1e-12) ? 128.0 : 0.0;
	
	apply_convolution_filter(
	    p->renderer,
	    &p->imageTextureTestSug4,
	    "assets/monarch.bmp",
	    k4,
	    scale4,
	    bias4,
	    1
	);
	free_matrix(k4);
}
