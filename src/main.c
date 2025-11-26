#include "../include/main.h"
#include "../include/init.h"
#include "../include/destroy.h"
#include "../include/pilha.h"
#include <locale.h>
#include "../include/lista_enc.h"
#include "../include/convolve.h"
#include "../include/pilha_matrix.h"
#include "../include/pilha_acao.h"

size_t isPressed1 = 0,isPressed2 = 0,isPressed3 = 0,isPressed4 = 0,isPressed5 = 0, isPressed6 = 0, isPressed7 = 0, isPressed8 = 0, isPressed9 = 0,
       isPressed10 = 0, isPressed11 = 0,isPressed12 = 0, isPressed13 = 0, isPressed14 = 0, isPressed15 = 0;
int t1=0,t2=0,t3=0, t4=0, t5=0, t6=0, t7 = 0, t8=0;
int cellEditing = -1;       
char cellBuffer[9][32];
int linhaSelecionada = -1;
int trocaLinhasEmAndamento = 0;
int primeiraLinhaTroca = -1;
int escalarEditing = 0;
char escalarBuffer[32] = "1.00";
double escalarAtual = 1.0;
int escalarFirstEdit = 0; 
int modoTrocaAtivo = 0;
int linhaTrocaA = -1;
int linhaTrocaB = -1;
int modoSomaAtivo = 0;
int linhaSomaA = -1;
int linhaSomaB = -1;
char infoBuffer[128] = "";
SDL_Texture* infoTexture = NULL;
int matrizPreenchida = 0;

int main(void) {
	AppContext context = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	EFFECTS effects = {0,0,0,0,0};
	PILHA pilha;
	PILHA_M pilha_matrizes;
	PILHA_ACAO pilha_acoes;
	LISTA_ENC lista;
	LISTA_ENC aux;
	int cont = 0;	
	setlocale (LC_CTYPE,"Portuguese_Brazil");
	init (&context);
	cria_pilha (&pilha);
	cria_pilha_m(&pilha_matrizes);
	cria_pilha_acao(&pilha_acoes);
	//push (&pilha,context.imageTextureTest);
	cria_lista (&lista);
	aux = lista;
	bool running = true;
	SDL_Event event;
	SDL_FRect backgroundRect = {0.0f,0.0f,1280.0f,720.0f};
	SDL_FRect bubbleRectDisabledShadow = {378.0f,102.0f,344.5f,80.0f};
	SDL_FRect bubbleRectDisabled = {380.0f,-50.0f,344.5f,344.5f};
	SDL_FRect imageRectTestShadow = {297.0f,203.0f,512.0f,341.333f};
	SDL_FRect imageRectTest = {300.0f,200.0f,512.0f,341.333f};
	SDL_FRect buttonRect1 = {950.0f,10.0f,172.25f,172.25f};
	SDL_FRect buttonRectHover1 = {950.0f,10.0f,172.25f,172.25f};
	SDL_FRect buttonRectClick1 = {950.0f,10.0f,172.25f,172.25f};
	SDL_FRect buttonRect2 = {1115.0f,10.0f,172.25f,172.250f};
	SDL_FRect buttonRectHover2 = {1115.0f,10.0f,172.25f,172.250f};
	SDL_FRect buttonRectClick2 = {1115.0f,10.0f,172.25f,172.250f};
	SDL_FRect buttonRect3 = {950.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRectHover3 = {950.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRectClick3 = {950.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRect4 = {1115.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRectHover4 = {1115.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRectClick4 = {1115.0f,100.0f,172.25f,172.250f};
	SDL_FRect buttonRect5 = {1030.0f,190.0f,172.25f,172.250f};
	SDL_FRect buttonRectHover5 = {1030.0f,190.0f,172.25f,172.250f};
	SDL_FRect buttonRectClick5 = {1030.0f,190.0f,172.25f,172.250f};
	SDL_FRect AplicarRectShadow = {1065.0f, 665.0f, 100.0f, 30.0f};
	SDL_FRect AplicarRect       = {1067.0f, 663.0f, 100.0f, 30.0f};
	SDL_FRect buttonRect6       = {1030.0f, 590.0f, 172.25f, 172.25f};
	SDL_FRect buttonRectHover6  = {1030.0f, 590.0f, 172.25f, 172.25f};
	SDL_FRect buttonRectClick6  = {1030.0f, 590.0f, 172.25f, 172.25f};
	SDL_Texture* aplicarTexture = NULL;
	SDL_Texture* aplicarTextureShadow = NULL;
	SDL_FRect titleRectShadow = {7.0f,-7.0f,400.0f,100.0f};
	SDL_FRect titleRect = {10.0f,-10.0f,400.0f,100.0f};
	SDL_FRect suggestionRectShadow = {33.0f,87.0f,100.0f,25.0f};
	SDL_FRect suggestionRect = {35.0f,85.0f,100.0f,25.0f};
	SDL_FRect instruction1RectShadow = {399.0f,127.0f,300.0f,25.0f};
	SDL_FRect instruction1Rect = {401.0f,125.0f,300.0f,25.0f};
	SDL_FRect OperacoesRectShadow = {1047.0f,7.0f,130.0f,45.0f};
	SDL_FRect OperacoesRect = {1049.0f,5.0f,130.0f,45.0f};
	SDL_FRect TrocaLinhaRectShadow = {992.0f,87.0f,80.0f,30.0f};
	SDL_FRect TrocaLinhaRect = {994.0f,85.0f,80.0f,30.0f};
	SDL_FRect MultEscalarRectShadow = {1152.0f,87.0f,90.0f,30.0f};
	SDL_FRect MultEscalarRect = {1154.0f,85.0f,90.0f,30.0f};
	SDL_FRect TrocaMultRectShadow = {979.0f,177.0f,110.0f,30.0f};
	SDL_FRect TrocaMultRect = {981.0f,175.0f,110.0f,30.0f};
	SDL_FRect EscalonarRectShadow = {1151.0f,177.0f,100.0f,30.0f};
	SDL_FRect EscalonarRect = {1153.0f,175.0f,100.0f,30.0f};
	SDL_FRect DesfazerRectShadow = {1065.0f,265.0f,100.0f,30.0f};
	SDL_FRect DesfazerRect = {1067.0f,263.0f,100.0f,30.0f};
	SDL_FRect ColchetesMatrixRect = {955.0f,395.0f,314.0f,314.0f};
	SDL_FRect MatrixRect = {950.0f,400.0f,344.0f,344.0f};
	SDL_FRect EscalarRect = {1200.0f,350.0f,50.0f,50.0f};
	SDL_FRect infoRect = {435.0f,125.0f,230.0f,25.0f};
	SDL_Texture* escalarTexture = NULL;
	SDL_FRect imageRectTestSug1Shadow = {19.0f,133.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug1Hover = {22.0f,130.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug1 = {22.0f,130.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug2Shadow = {19.0f,243.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug2Hover = {22.0f,240.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug2 = {22.0f,240.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug3Shadow = {19.0f,353.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug3Hover = {22.0f,350.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug3 = {22.0f,350.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug4Shadow = {19.0f,463.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug4Hover = {22.0f,460.0f,128.0f,85.333f};
	SDL_FRect imageRectTestSug4 = {22.0f,460.0f,128.0f,85.333f};
	SDL_FRect imageRectAcomp = {178.0f,603.0f,128.0f,85.333f};
	SDL_FRect r;
	SDL_FRect elements[9] = {
   		{1030, 450, 50, 50},
    	{1095, 450, 50, 50},
    	{1160, 450, 50, 50},
    	{1030, 510, 50, 50},
    	{1095, 510, 50, 50},
    	{1160, 510, 50, 50},
    	{1030, 570, 50, 50},
    	{1095, 570, 50, 50},
    	{1160, 570, 50, 50}
	};
	SDL_FRect rowSquares[3] = {
    {1000.0f, 465.0f, 15.0f, 15.0f},
    {1000.0f, 525.0f, 15.0f, 15.0f},
    {1000.0f, 585.0f, 15.0f, 15.0f}
	};
	SDL_Texture* trocaMsgTexture = NULL;
	const char* trocaMsgTexto = "Clique em dois quadrados de linha para trocar";
	context.kernel_atual = create_matrix(3, 3);
	if (!context.kernel_atual) {
    	printf("Erro ao criar kernel inicial\n");
    	destroy(&context);
    	return 1;
	}
	push_m(&pilha_matrizes, context.kernel_atual);
	atualizar_elementos(&context);
	for (int i = 0; i < 9; ++i) {
    	int r = i / 3;
    	int c = i % 3;
	    snprintf(cellBuffer[i], sizeof(cellBuffer[i]), "%.2f", context.kernel_atual->data[r][c]);
	}
	texts(&context,"font/BodoniFLF.ttf",32.0f,"ScalarElement",escalarBuffer,"ScalarTexture",&escalarTexture,"ScalarTexRef",255,255,255,255);
	atualizaMensagemPadrao(&context);  
	texts(&context,
      "font/BodoniFLF.ttf",
      25.0f,
      "AplicarLabel",
      "Aplicar",
      "AplicarTexture",
      &aplicarTexture,
      "AplicarTexRef",
      255,255,255,255);
	texts(&context,
      "font/BodoniFLF.ttf",
      25.0f,
      "AplicarLabelShadow",
      "Aplicar",
      "AplicarTextureShadow",
      &aplicarTextureShadow,
      "AplicarShadowTexRef",
      0,0,0,255);

	SDL_StartTextInput(context.window);
	
	while (running){
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_EVENT_QUIT:
					running = false;
					break;
				case SDL_EVENT_MOUSE_MOTION:
					effect (&effects,event.motion.x,event.motion.y);
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					if (effects.isHover1 && event.button.button == SDL_BUTTON_LEFT){
						isPressed1 = 1;
					}
					if (effects.isHover2 && event.button.button == SDL_BUTTON_LEFT){
						isPressed2 = 1;
					}
					if (effects.isHover3 && event.button.button == SDL_BUTTON_LEFT){
						isPressed3 = 1;
					}
					if (effects.isHover4 && event.button.button == SDL_BUTTON_LEFT){
						isPressed4 = 1;
					}
					if (effects.isHover5 && event.button.button == SDL_BUTTON_LEFT){
						isPressed5 = 1;
					}
					if (effects.isHover6 && event.button.button == SDL_BUTTON_LEFT){
						isPressed6 = 1;
					}
					if (effects.isHover7 && event.button.button == SDL_BUTTON_LEFT){
						isPressed7 = 1;
					}
					if (effects.isHover8 && event.button.button == SDL_BUTTON_LEFT){
						isPressed8 = 1;
					}
					if (effects.isHover9 && event.button.button == SDL_BUTTON_LEFT){
						isPressed9 = 1;
					}
					if (effects.isHover10 && event.button.button == SDL_BUTTON_LEFT){
						isPressed10 = 1;
					}
					if (effects.isHover11 && event.button.button == SDL_BUTTON_LEFT){
						isPressed11 = 1;
					}
					if (effects.isHover12 && event.button.button == SDL_BUTTON_LEFT){
						isPressed12 = 1;
					}
					if (effects.isHover13 && event.button.button == SDL_BUTTON_LEFT){
						isPressed13 = 1;
					}
					if (effects.isHover14 && event.button.button == SDL_BUTTON_LEFT){
						isPressed14 = 1;
					}
					if (effects.isHover15 && event.button.button == SDL_BUTTON_LEFT){
    					isPressed15 = 1;
					}
					if (event.button.button == SDL_BUTTON_LEFT) {
        				for (int i = 0; i < 9; ++i) {
            				float mx = event.button.x;
            				float my = event.button.y;
            				SDL_FRect r = elements[i];
            				if (mx >= r.x && mx <= r.x + r.w &&
                				my >= r.y && my <= r.y + r.h) {
                				cellEditing = i;
                				escalarEditing = 0; 
                				cellBuffer[i][0] = '\0';
                				break;
           				 	}
							float mx2 = event.button.x;
							float my2 = event.button.y;
							if (mx2 >= EscalarRect.x && mx2 <= EscalarRect.x + EscalarRect.w && my2 >= EscalarRect.y && my2 <= EscalarRect.y + EscalarRect.h) {
    							escalarEditing = 1;
    							escalarFirstEdit = 1;
    							cellEditing = -1;
    							strcpy(infoBuffer, "Digite o escalar e pressione Enter.");
    							texts(&context,"font/BodoniFLF.ttf",25.0f,"InfoLabel",infoBuffer,"InfoTexture",&infoTexture,"InfoTexRef",255,255,255,255);
    							t1 = 0; t2 = 0; t3 = 0; t4 = 0; t5 = 1; t6 = 0; t7 =0; t8 = 0;  
							}
        				}
    				}
if (event.button.button == SDL_BUTTON_LEFT) {
    float mx = event.button.x;
    float my = event.button.y;

    // CÉLULAS (já estava aí, mantém a sua lógica)
    for (int i = 0; i < 9; ++i) {
        SDL_FRect r = elements[i];
        if (mx >= r.x && mx <= r.x + r.w &&
            my >= r.y && my <= r.y + r.h) {
            cellEditing = i;
            escalarEditing = 0;       // não edita escalar ao mesmo tempo
            cellBuffer[i][0] = '\0';
            break;
        }
    }

// QUADRADOS DE LINHA
for (int row = 0; row < 3; ++row) {
    SDL_FRect q = rowSquares[row];
    if (mx >= q.x && mx <= q.x + q.w &&
        my >= q.y && my <= q.y + q.h) {

        if (modoTrocaAtivo) {
            // --- MODO TROCA DE LINHAS (botão 1) ---
            if (linhaTrocaA == -1) {
                linhaTrocaA = row;
            }
            else if (linhaTrocaB == -1 && row != linhaTrocaA) {
                linhaTrocaB = row;

                if (cont < 5) {
                    cont++;
                    push(&pilha, context.imageTextureTest);
                    push_m(&pilha_matrizes, context.kernel_atual);
                    push_acao(&pilha_acoes, ACAO_KERNEL);

                    swap_rows(context.kernel_atual,
                              (size_t)linhaTrocaA,
                              (size_t)linhaTrocaB);

                    atualizar_elementos(&context);
                    aplicar_kernel_na_imagem(&context, &pilha);
                    ins(&lista, context.imageTextureTest);
                }

                snprintf(infoBuffer, sizeof(infoBuffer),
                         "Linhas %d e %d trocadas.",
                         linhaTrocaA + 1, linhaTrocaB + 1);
                texts(&context,
                      "font/BodoniFLF.ttf",
                      25.0f,
                      "InfoLabel",
                      infoBuffer,
                      "InfoTexture",
                      &infoTexture,
                      "InfoTexRef",
                      255,255,255,255);
                t1 = 0; t2 = 0; t3 = 0; t4 = 1; t5 = 0; t6 = 0; t7 =0; t8 = 0;    
                modoTrocaAtivo = 0;
                linhaTrocaA = linhaTrocaB = -1;
            }
        }
        else if (modoSomaAtivo) {
            // --- MODO SOMA DE LINHAS (botão 3) ---
            if (linhaSomaA == -1) {
                // primeira linha clicada = origem
                linhaSomaA = row;
            }
            else if (linhaSomaB == -1 && row != linhaSomaA) {
                // segunda linha clicada = destino
                linhaSomaB = row;

                if (cont < 5) {
                    cont++;
                    push(&pilha, context.imageTextureTest);
                    push_m(&pilha_matrizes, context.kernel_atual);
                    push_acao(&pilha_acoes, ACAO_KERNEL);

                    size_t src = (size_t)linhaSomaA;
                    size_t dst = (size_t)linhaSomaB;
                    double fator = escalarAtual;   // usa o escalar digitado

                    add_rows(context.kernel_atual, src, dst, fator);
                    atualizar_elementos(&context);
                    aplicar_kernel_na_imagem(&context, &pilha);
                    ins(&lista, context.imageTextureTest);
                }

                snprintf(infoBuffer, sizeof(infoBuffer),
                         "Linha %d atualizada com linha %d * %.2f.",
                         linhaSomaA + 1, linhaSomaB + 1, escalarAtual);
                texts(&context,
                      "font/BodoniFLF.ttf",
                      25.0f,
                      "InfoLabel",
                      infoBuffer,
                      "InfoTexture",
                      &infoTexture,
                      "InfoTexRef",
                      255,255,255,255);

                // sai do modo soma e limpa seleção visual
                modoSomaAtivo = 0;
                linhaSomaA = linhaSomaB = -1;
            }
        }
        else {
            // MODO NORMAL: seleção de linha para multiplicar (botão 2)
            if (linhaSelecionada == row) {
                linhaSelecionada = -1;
            } else {
                linhaSelecionada = row;
            }
            // aqui NÃO mexemos na mensagem, ela fica a padrão/última operação
        }

        break;
    }
}
}

					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					if (effects.isHover1 && isPressed1 == 1){
						isPressed1 = 0;
					}
					if (effects.isHover2 && isPressed2 == 1){
						isPressed2 = 0;
					}
					if (effects.isHover3 && isPressed3 == 1){
						isPressed3 = 0;
					}
					if (effects.isHover4 && isPressed4 == 1){
						isPressed4 = 0;
					}
					if (effects.isHover5 && isPressed5 == 1){
						isPressed5 = 0;
					}
					if (effects.isHover6 && isPressed6 == 1){
						isPressed6 = 0;
					}
					if (effects.isHover7 && isPressed7 == 1){
						isPressed7 = 0;
					}
					if (effects.isHover8 && isPressed8 == 1){
						isPressed8 = 0;
					}
					if (effects.isHover9 && isPressed9 == 1){
						isPressed9 = 0;
					}
					if (effects.isHover10 && isPressed10 == 1){
						isPressed10 = 0;
					}
					if (effects.isHover11 && isPressed11 == 1){
						isPressed11 = 0;
					}
					if (effects.isHover12 && isPressed12 == 1){
						isPressed12 = 0;
					}
					if (effects.isHover13 && isPressed13 == 1){
						isPressed13 = 0;
					}
					if (effects.isHover14 && isPressed14 == 1){
						isPressed14 = 0;
					}
					if (effects.isHover15 && isPressed15 == 1){
    					isPressed15 = 0;
					}
					break;
case SDL_EVENT_TEXT_INPUT:
    // edição das células da matriz
    if (cellEditing != -1) {
        const char *txt = event.text.text;

        for (int k = 0; txt[k] != '\0'; ++k) {
            char ch = txt[k];

            if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-') {

                size_t len = strlen(cellBuffer[cellEditing]);
                if (len + 1 < sizeof(cellBuffer[cellEditing])) {

                    char tmp[32];
                    memcpy(tmp, cellBuffer[cellEditing], len);
                    tmp[len] = ch;
                    tmp[len + 1] = '\0';

                    if (strcmp(tmp, "-") == 0 ||
                        strcmp(tmp, ".") == 0 ||
                        strcmp(tmp, "-.") == 0) {

                        strcpy(cellBuffer[cellEditing], tmp);
                        texts(&context,
                              "font/BodoniFLF.ttf",
                              32.0f,
                              "tmpElement",
                              cellBuffer[cellEditing],
                              "tmpElementTexture",
                              &context.Elements[cellEditing],
                              "tmpElementTexRef",
                              255, 255, 255, 255);

                    } else {
                        double v = atof(tmp);
                        if (v >= -10.0 && v <= 10.0) {
                            strcpy(cellBuffer[cellEditing], tmp);
                            texts(&context,
                                  "font/BodoniFLF.ttf",
                                  32.0f,
                                  "tmpElement",
                                  cellBuffer[cellEditing],
                                  "tmpElementTexture",
                                  &context.Elements[cellEditing],
                                  "tmpElementTexRef",
                                  255, 255, 255, 255);
                        }
                    }
                }
            }
        }
    }
    // edição do ESCALAR
else if (escalarEditing) {
    const char *txt = event.text.text;

    // se é a primeira tecla dessa edição, limpa antes de começar a escrever
    if (escalarFirstEdit) {
        escalarBuffer[0] = '\0';
        escalarFirstEdit = 0;
    }

    for (int k = 0; txt[k] != '\0'; ++k) {
        char ch = txt[k];

        if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-') {

            size_t len = strlen(escalarBuffer);
            if (len + 1 < sizeof(escalarBuffer)) {

                char tmp[32];
                memcpy(tmp, escalarBuffer, len);
                tmp[len] = ch;
                tmp[len + 1] = '\0';

                if (strcmp(tmp, "-") == 0 ||
                    strcmp(tmp, ".") == 0 ||
                    strcmp(tmp, "-.") == 0) {

                    strcpy(escalarBuffer, tmp);
                    texts(&context,
                          "font/BodoniFLF.ttf",
                          24.0f,
                          "ScalarElement",
                          escalarBuffer,
                          "ScalarTexture",
                          &escalarTexture,
                          "ScalarTexRef",
                          255,255,255,255);

                } else {
                    double v = atof(tmp);
                    if (v >= -10.0 && v <= 10.0) {
                        strcpy(escalarBuffer, tmp);
                        texts(&context,
                              "font/BodoniFLF.ttf",
                              24.0f,
                              "ScalarElement",
                              escalarBuffer,
                              "ScalarTexture",
                              &escalarTexture,
                              "ScalarTexRef",
                              255,255,255,255);
                    }
                }
            }
        }
    }
}

    break;
case SDL_EVENT_KEY_DOWN:
    // edição das células da matriz
    if (cellEditing != -1) {

        if (event.key.scancode == SDL_SCANCODE_BACKSPACE) {
            size_t len = strlen(cellBuffer[cellEditing]);
            if (len > 0) {
                cellBuffer[cellEditing][len - 1] = '\0';
            }

            const char* toRender;
            if (cellBuffer[cellEditing][0] == '\0') {
                toRender = " ";
            } else {
                toRender = cellBuffer[cellEditing];
            }

            texts(&context,
                  "font/BodoniFLF.ttf",
                  32.0f,
                  "tmpElement",
                  toRender,
                  "tmpElementTexture",
                  &context.Elements[cellEditing],
                  "tmpElementTexRef",
                  255,255,255,255);
        }
        else if (event.key.scancode == SDL_SCANCODE_RETURN ||
                 event.key.scancode == SDL_SCANCODE_KP_ENTER) {

            int idx = cellEditing;
            cellEditing = -1;

            double v;
            if (cellBuffer[idx][0] == '\0' ||
                strcmp(cellBuffer[idx], "-")  == 0 ||
                strcmp(cellBuffer[idx], ".")  == 0 ||
                strcmp(cellBuffer[idx], "-.") == 0) {
                v = 0.0;
            } else {
                v = atof(cellBuffer[idx]);
            }

            if (v < -10.0) v = -10.0;
            if (v >  10.0) v =  10.0;

            int r = idx / 3;
            int c = idx % 3;
            context.kernel_atual->data[r][c] = v;
            matrizPreenchida = 1;

            snprintf(cellBuffer[idx], sizeof(cellBuffer[idx]), "%.2f", v);

            texts(&context,
                  "font/BodoniFLF.ttf",
                  32.0f,
                  "tmpElement",
                  cellBuffer[idx],
                  "tmpElementTexture",
                  &context.Elements[idx],
                  "tmpElementTexRef",
                  255,255,255,255);
        }
    }
    // edição do ESCALAR
    else if (escalarEditing) {

        if (event.key.scancode == SDL_SCANCODE_BACKSPACE) {
            size_t len = strlen(escalarBuffer);
            if (len > 0) {
                escalarBuffer[len - 1] = '\0';
            }

            const char* toRender;
            if (escalarBuffer[0] == '\0') {
                toRender = " ";
            } else {
                toRender = escalarBuffer;
            }

            texts(&context,
                  "font/BodoniFLF.ttf",
                  24.0f,
                  "ScalarElement",
                  toRender,
                  "ScalarTexture",
                  &escalarTexture,
                  "ScalarTexRef",
                  255,255,255,255);
        }
else if (event.key.scancode == SDL_SCANCODE_RETURN ||
         event.key.scancode == SDL_SCANCODE_KP_ENTER) {

    escalarEditing = 0;
    escalarFirstEdit = 0;  // só pra garantir

    double v;
    if (escalarBuffer[0] == '\0' ||
        strcmp(escalarBuffer, "-")  == 0 ||
        strcmp(escalarBuffer, ".")  == 0 ||
        strcmp(escalarBuffer, "-.") == 0) {
        v = 1.0; // padrão
    } else {
        v = atof(escalarBuffer);
    }

    if (v < -10.0) v = -10.0;
    if (v >  10.0) v =  10.0;

    escalarAtual = v;

    snprintf(escalarBuffer, sizeof(escalarBuffer), "%.2f", escalarAtual);

    texts(&context,
          "font/BodoniFLF.ttf",
          24.0f,
          "ScalarElement",
          escalarBuffer,
          "ScalarTexture",
          &escalarTexture,
          "ScalarTexRef",
          255,255,255,255);
}


    break;
}
}
		SDL_SetRenderDrawColor (context.renderer,15,15,15,255);
		SDL_RenderClear (context.renderer);
		SDL_RenderTexture (context.renderer,context.imageTexture,NULL,&backgroundRect);
		SDL_RenderFillRect (context.renderer,&imageRectTestShadow);
		SDL_RenderTexture (context.renderer,context.imageTextureTest,NULL,&imageRectTest);
		SDL_RenderFillRect (context.renderer,&bubbleRectDisabledShadow);
		SDL_RenderTexture (context.renderer,context.bubbleTextureDisabled,NULL,&bubbleRectDisabled);			
if (effects.isHover1){
    SDL_RenderTexture (context.renderer,context.buttonTextureHover,NULL,&buttonRectHover1);
    if (isPressed1){
        SDL_RenderTexture (context.renderer,context.buttonTextureClick,NULL,&buttonRectClick1);

        if (!modoTrocaAtivo) {
            // Inicia o modo de escolha das linhas
            modoTrocaAtivo = 1;
            linhaTrocaA = linhaTrocaB = -1;

            strcpy(infoBuffer, "Clique em dois quadrados de linha para trocar.");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
            t1 = 0; t2 = 0; t3 = 1; t4 = 0, t5 = 0, t6 =0; t7 = 0; t8=0 ;  
        } else {
            // Cancela o modo troca
            modoTrocaAtivo = 0;
            linhaTrocaA = linhaTrocaB = -1;

            strcpy(infoBuffer, "Troca de linha cancelada.");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
        }

        isPressed1 = 0;
    }
}else{
    SDL_RenderTexture (context.renderer,context.buttonTexture,NULL,&buttonRect1);	
}
	
if (effects.isHover2){
    SDL_RenderTexture (context.renderer,context.buttonTextureHover,NULL,&buttonRectHover2);
    if (isPressed2){
        SDL_RenderTexture (context.renderer,context.buttonTextureClick,NULL,&buttonRectClick2);

        // Verifica se há uma linha selecionada
        if (linhaSelecionada < 0 || linhaSelecionada > 2) {
            strcpy(infoBuffer, "Escolha uma linha e clique em Li<-k*Li.");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
                  t1 = 0; t2 = 0; t3 = 0; t4 = 0, t5 = 0, t6 = 1; t7 = 0;t8=0;
        } else {
            // Há linha selecionada; usa escalarAtual
            if (cont < 5) {
                cont++;
                push(&pilha, context.imageTextureTest);
                push_m(&pilha_matrizes, context.kernel_atual);
                push_acao(&pilha_acoes, ACAO_KERNEL);

                size_t linha = (size_t)linhaSelecionada;
                double escalar = escalarAtual;

                scale_row(context.kernel_atual, linha, escalar);
                atualizar_elementos(&context);
                aplicar_kernel_na_imagem(&context, &pilha);
                ins(&lista, context.imageTextureTest);

// multiplicação feita, limpa seleção e volta mensagem padrão
linhaSelecionada = -1;
atualizaMensagemPadrao(&context);

            }
        }

        isPressed2 = 0;
    }
}else{
    SDL_RenderTexture (context.renderer,context.buttonTexture,NULL,&buttonRect2);	
}


// BOTÃO 3 — TrocaMult: dst += escalarAtual * src (modo guiado)
if (effects.isHover3){
    SDL_RenderTexture (context.renderer,context.buttonTextureHover,NULL,&buttonRectHover3);
    if (isPressed3){
        SDL_RenderTexture (context.renderer,context.buttonTextureClick,NULL,&buttonRectClick3);

        if (!modoSomaAtivo) {
            // Só deixa entrar no modo se a matriz já foi editada pelo menos uma vez
            if (!matrizPreenchida) {
                strcpy(infoBuffer, "Digite a matriz e o escalar.");
                texts(&context,
                      "font/BodoniFLF.ttf",
                      25.0f,
                      "InfoLabel",
                      infoBuffer,
                      "InfoTexture",
                      &infoTexture,
                      "InfoTexRef",
                      255,255,255,255);
                t1 = 1; t2 = 0; t3 = 0; t4 = 0, t5 = 0, t6 = 0; t7 = 0; t8 = 0;
            } else {
                // Inicia o modo de soma de linhas
                modoSomaAtivo = 1;
                linhaSomaA = -1;
                linhaSomaB = -1;
                linhaSelecionada = -1; // não conflitar com seleção do botão 2

                strcpy(infoBuffer, "Clique na linha destino e depois na linha origem.");
                texts(&context,
                      "font/BodoniFLF.ttf",
                      25.0f,
                      "InfoLabel",
                      infoBuffer,
                      "InfoTexture",
                      &infoTexture,
                      "InfoTexRef",
                      255,255,255,255);
                t1 = 0; t2 = 0; t3 = 0; t4 = 0, t5 = 0, t6 = 0; t7 = 0; t8 = 1;
            }
        } else {
            // Cancela o modo soma
            modoSomaAtivo = 0;
            linhaSomaA = linhaSomaB = -1;

            strcpy(infoBuffer, "Selecione uma das opcoes ao lado.");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
            t1 = 0; t2 = 0; t3 = 0; t4 = 0, t5 = 0, t6 = 0, t7=1;t8=0;
        }

        isPressed3 = 0;
    }
}else{
    SDL_RenderTexture (context.renderer,context.buttonTexture,NULL,&buttonRect3);    
}

		if (effects.isHover4){
			SDL_RenderTexture (context.renderer,context.buttonTextureHover,NULL,&buttonRectHover4);
			if (isPressed4){
				SDL_RenderTexture (context.renderer,context.buttonTextureClick,NULL,&buttonRectClick4);
				if (cont< 5){
					cont++;
					push(&pilha, context.imageTextureTest);
    	    		push_m(&pilha_matrizes, context.kernel_atual);
    	    		push_acao(&pilha_acoes, ACAO_KERNEL);
					to_rref(context.kernel_atual);
					atualizar_elementos(&context);
					aplicar_kernel_na_imagem(&context, &pilha);
					ins(&lista, context.imageTextureTest);
				}
				isPressed4 = 0;
			}
		}else{
			SDL_RenderTexture (context.renderer,context.buttonTexture,NULL,&buttonRect4);	
		}
if (effects.isHover5){
    SDL_RenderTexture(context.renderer, context.buttonTextureHover, NULL, &buttonRectHover5);
    if (isPressed5){
        SDL_RenderTexture(context.renderer, context.buttonTextureClick, NULL, &buttonRectClick5);

        if (!pilha_acao_vazia(pilha_acoes) && pilha != NULL){
            // qual foi a última ação?
            ACAO_TIPO tipo = pop_acao(&pilha_acoes);

            // sempre desfaz imagem
            SDL_Texture* prev_tex = pop(&pilha);
            if (prev_tex){
                context.imageTextureTest = prev_tex;
            }

            // só desfaz matriz se a ação mexeu no kernel
if ((tipo == ACAO_KERNEL) && pilha_matrizes != NULL) {
    Matrix* prev_mat = pop_m(&pilha_matrizes);
    if (prev_mat) {
        if (context.kernel_atual && context.kernel_atual != prev_mat) {
            free_matrix(context.kernel_atual);
        }
        context.kernel_atual = prev_mat;
        atualizar_elementos(&context);
    }
}

            ret(&lista);
            if (cont > 0) cont--;
        }

        isPressed5 = 0;
    }
		}else{
    		SDL_RenderTexture(context.renderer, context.buttonTexture, NULL, &buttonRect5);
		}
// BOTÃO 6 — Aplicar: aplica o kernel atual na imagem
if (effects.isHover15){
    SDL_RenderTexture(context.renderer, context.buttonTextureHover, NULL, &buttonRectHover6);
    if (isPressed15){
        SDL_RenderTexture(context.renderer, context.buttonTextureClick, NULL, &buttonRectClick6);

        if (!matrizPreenchida) {
            // ainda não teve ENTER em nenhuma célula
            strcpy(infoBuffer, "Digite a matriz e o escalar.");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
            t1 = 1; t2 = 0; t3 = 0; t4 = 0; t5 = 0; t6 = 0; t7 = 0;   t8=0;
        } else if (cont < 5) {
            // aplica o kernel atual na imagem
            cont++;
            push(&pilha, context.imageTextureTest);
            //push_m(&pilha_matrizes, context.kernel_atual);
            push_acao(&pilha_acoes, ACAO_APLICAR);

            aplicar_kernel_na_imagem(&context, &pilha);
            ins(&lista, context.imageTextureTest);

            strcpy(infoBuffer, "Matriz Aplicada");
            texts(&context,
                  "font/BodoniFLF.ttf",
                  25.0f,
                  "InfoLabel",
                  infoBuffer,
                  "InfoTexture",
                  &infoTexture,
                  "InfoTexRef",
                  255,255,255,255);
                t1 = 0; t2 = 1; t3 = 0; t4 = 0, t5 = 0; t6 = 0; t7 = 0;  t8=0;
        }

        isPressed15 = 0;
    }
} else {
    SDL_RenderTexture(context.renderer, context.buttonTexture, NULL, &buttonRect6);
}
SDL_FRect escalarBorder = EscalarRect;

// margens para aumentar o comprimento/altura do contorno
float marginX = 5.0f;  // aumenta comprimento horizontal
float marginY = 2.0f;  // aumenta altura vertical

escalarBorder.x -= marginX;
escalarBorder.w += marginX * 2;
escalarBorder.y -= marginY;
escalarBorder.h += marginY * 2;

SDL_SetRenderDrawColor(context.renderer, 15, 15,15, 255);
SDL_RenderRect(context.renderer, &escalarBorder);
// campo do ESCALAR
if (escalarEditing) {
    // Modo edição ? mais escuro
    SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 50);
    SDL_RenderFillRect(context.renderer, &escalarBorder);

    //SDL_SetRenderDrawColor(context.renderer, 15, 15, 15, 255);
    //SDL_RenderRect(context.renderer, &EscalarRect);
} 
else {
    //SDL_SetRenderDrawColor(context.renderer, 15, 15, 15, 255); // borda cinza clara
    //SDL_RenderRect(context.renderer, &EscalarRect);
}

// texto dentro do EscalarRect (não do border)
if (escalarTexture) {
    SDL_RenderTexture(context.renderer, escalarTexture, NULL, &EscalarRect);
}

		SDL_RenderTexture (context.renderer,context.ColchetesMatrixTexture,NULL,&ColchetesMatrixRect);
		SDL_RenderTexture (context.renderer,context.titleTextureShadow,NULL,&titleRectShadow);
		SDL_RenderTexture (context.renderer,context.titleTexture,NULL,&titleRect);
		SDL_RenderTexture (context.renderer,context.suggestionTextureShadow,NULL,&suggestionRectShadow);
		SDL_RenderTexture (context.renderer,context.suggestionTexture,NULL,&suggestionRect);
		SDL_RenderTexture (context.renderer,context.instruction1TextureShadow,NULL,&instruction1RectShadow);
		SDL_RenderTexture (context.renderer,context.instruction1Texture,NULL,&instruction1Rect);
		SDL_RenderTexture (context.renderer,context.OperacoesTextureShadow,NULL,&OperacoesRectShadow);
		SDL_RenderTexture (context.renderer,context.OperacoesTexture,NULL,&OperacoesRect);
		SDL_RenderTexture (context.renderer,context.TrocaLinhaTextureShadow,NULL,&TrocaLinhaRectShadow);
		SDL_RenderTexture (context.renderer,context.TrocaLinhaTexture,NULL,&TrocaLinhaRect);
		SDL_RenderTexture (context.renderer,context.MultEscalarTextureShadow,NULL,&MultEscalarRectShadow);
		SDL_RenderTexture (context.renderer,context.MultEscalarTexture,NULL,&MultEscalarRect);
		SDL_RenderTexture (context.renderer,context.TrocaMultTextureShadow,NULL,&TrocaMultRectShadow);
		SDL_RenderTexture (context.renderer,context.TrocaMultTexture,NULL,&TrocaMultRect);
		SDL_RenderTexture (context.renderer,context.EscalonarTextureShadow,NULL,&EscalonarRectShadow);
		SDL_RenderTexture (context.renderer,context.EscalonarTexture,NULL,&EscalonarRect);
		SDL_RenderTexture (context.renderer,context.DesfazerTextureShadow,NULL,&DesfazerRectShadow);
		SDL_RenderTexture (context.renderer,context.DesfazerTexture,NULL,&DesfazerRect);
if (aplicarTextureShadow) {
    SDL_RenderTexture(context.renderer, aplicarTextureShadow, NULL, &AplicarRectShadow);
}
if (aplicarTexture) {
    SDL_RenderTexture(context.renderer, aplicarTexture, NULL, &AplicarRect);
}
		SDL_SetRenderDrawColor(context.renderer, 38, 73, 143, 255);
		SDL_RenderFillRect (context.renderer,&imageRectTestSug1Shadow);
		SDL_RenderFillRect (context.renderer,&imageRectTestSug2Shadow);
		SDL_RenderFillRect (context.renderer,&imageRectTestSug3Shadow);
		SDL_RenderFillRect (context.renderer,&imageRectTestSug4Shadow);
		SDL_RenderTexture (context.renderer,context.imageTextureTestSug1,NULL,&imageRectTestSug1);
		SDL_SetRenderDrawBlendMode(context.renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 60);
		if (effects.isHover6){
			SDL_RenderFillRect (context.renderer,&imageRectTestSug1Hover);
			if (isPressed6){
				SDL_RenderTexture (context.renderer,context.imageTextureTestSug1,NULL,&imageRectTestSug1);
				if (cont< 5 && context.imageTextureTest != context.imageTextureTestSug1){
					cont++;
					push(&pilha, context.imageTextureTest);
					push_acao(&pilha_acoes, ACAO_SUGESTAO);
					context.imageTextureTest = context.imageTextureTestSug1;	
					ins(&lista, context.imageTextureTest);    
				}
				isPressed6 = 0;
			}
		}
		SDL_RenderTexture (context.renderer,context.imageTextureTestSug2,NULL,&imageRectTestSug2);
		if (effects.isHover7){
			SDL_RenderFillRect (context.renderer,&imageRectTestSug2Hover);
			if (isPressed7){
				SDL_RenderTexture (context.renderer,context.imageTextureTestSug2,NULL,&imageRectTestSug2);
				if (cont< 5 && context.imageTextureTest != context.imageTextureTestSug2){
					cont++;
					push(&pilha, context.imageTextureTest);
					push_acao(&pilha_acoes, ACAO_SUGESTAO);
					context.imageTextureTest = context.imageTextureTestSug2;
					ins(&lista, context.imageTextureTest); 
				}
				isPressed7 = 0;
			}
		}
		SDL_RenderTexture (context.renderer,context.imageTextureTestSug3,NULL,&imageRectTestSug3);
		if (effects.isHover8){
			SDL_RenderFillRect (context.renderer,&imageRectTestSug3Hover);
			if (isPressed8){
				SDL_RenderTexture (context.renderer,context.imageTextureTestSug3,NULL,&imageRectTestSug3);
				if (cont< 5 && context.imageTextureTest != context.imageTextureTestSug3){
					cont++;
					push(&pilha, context.imageTextureTest);           
					push_acao(&pilha_acoes, ACAO_SUGESTAO);
					context.imageTextureTest = context.imageTextureTestSug3;
					ins(&lista, context.imageTextureTest);    
				}
				isPressed8 = 0;
			}
		}
		SDL_RenderTexture (context.renderer,context.imageTextureTestSug4,NULL,&imageRectTestSug4);
		if (effects.isHover9){
			SDL_RenderFillRect (context.renderer,&imageRectTestSug4Hover);
			if (isPressed9){
				SDL_RenderTexture (context.renderer,context.imageTextureTestSug4,NULL,&imageRectTestSug4);
				if (cont< 5 && context.imageTextureTest != context.imageTextureTestSug4){
					cont++;
					push(&pilha, context.imageTextureTest);            
					push_acao(&pilha_acoes, ACAO_SUGESTAO);
					context.imageTextureTest = context.imageTextureTestSug4;
					ins(&lista, context.imageTextureTest);    
				}
				isPressed9 = 0;
			}
		}
		aux = lista;
		r = imageRectAcomp;
		while (aux){
			SDL_RenderTexture (context.renderer,aux->inf,NULL,&r);
			aux = aux->prox;
			r.x += r.w + 22;
		}
		r = imageRectAcomp;
		if (effects.isHover10 && cont>=1){
			SDL_RenderFillRect (context.renderer,&r);
			if (isPressed10){
				SDL_Texture* a = busca (lista,1);
				SDL_RenderTexture (context.renderer,a,NULL,&r);
				context.imageTextureTest = a;
				isPressed10 = 0;
			}
		}
		r.x += r.w + 22;
		if (effects.isHover11 && cont>=2){
			SDL_RenderFillRect (context.renderer,&r);
			if (isPressed11){
				SDL_Texture* a = busca (lista,2);
				SDL_RenderTexture (context.renderer,a,NULL,&r);
				context.imageTextureTest = a;
				isPressed11 = 0;
			}
		}
		r.x += r.w + 22;
		if (effects.isHover12 && cont>=3){
			SDL_RenderFillRect (context.renderer,&r);
			if (isPressed12){
				SDL_Texture* a = busca (lista,3);
				SDL_RenderTexture (context.renderer,a,NULL,&r);
				context.imageTextureTest = a;
				isPressed12 = 0;
			}
		}
		r.x += r.w + 22;
		if (effects.isHover13 && cont>=4){
			SDL_RenderFillRect (context.renderer,&r);
			if (isPressed13){
				SDL_Texture* a = busca (lista,4);
				SDL_RenderTexture (context.renderer,a,NULL,&r);
				context.imageTextureTest = a;
				isPressed13 = 0;
			}
		}
		r.x += r.w + 22;
		if (effects.isHover14 && cont==5){
			SDL_RenderFillRect (context.renderer,&r);
			if (isPressed14){
				SDL_Texture* a = busca (lista,5);
				SDL_RenderTexture (context.renderer,a,NULL,&r);
				context.imageTextureTest = a;
				isPressed14 = 0;
			}
		}
for (int row = 0; row < 3; ++row) {
    if (modoTrocaAtivo && (row == linhaTrocaA || row == linhaTrocaB)) {
        // quadrados envolvidos na troca de linhas (botão 1)
        SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(context.renderer, &rowSquares[row]);
    }
    else if (modoSomaAtivo && (row == linhaSomaA || row == linhaSomaB)) {
        // quadrados envolvidos na soma de linhas (botão 3)
        SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(context.renderer, &rowSquares[row]);
    }
    else if (!modoTrocaAtivo && !modoSomaAtivo && row == linhaSelecionada) {
        // seleção simples (para multiplicar por escalar — botão 2)
        SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(context.renderer, &rowSquares[row]);
    }
    else {
        // contorno padrão
        SDL_SetRenderDrawColor(context.renderer, 200, 200, 200, 255);
        SDL_RenderRect(context.renderer, &rowSquares[row]);
    }
}

if (linhaSelecionada >= 0 && linhaSelecionada < 3) {
    int row = linhaSelecionada;
    int idxStart = row * 3;
    int idxEnd   = row * 3 + 2;

    SDL_FRect rline;
    float paddingX = 10.0f;
    float paddingY = 5.0f;

    rline.x = elements[idxStart].x - paddingX;
    rline.y = elements[idxStart].y - paddingY;
    rline.w = (elements[idxEnd].x + elements[idxEnd].w + paddingX) - rline.x;
    rline.h = elements[idxStart].h + 2 * paddingY;

    SDL_SetRenderDrawColor(context.renderer, 255, 255, 0, 255); // amarelo
    SDL_RenderRect(context.renderer, &rline);
}

		for (int i = 0; i < 9; ++i) {
    		if (i == cellEditing) {
        		SDL_SetRenderDrawBlendMode(context.renderer, SDL_BLENDMODE_BLEND);
        		SDL_SetRenderDrawColor(context.renderer, 15, 15, 15, 15);
        		for (int t = 0; t < 9; t++) {
SDL_FRect r = {
    elements[i].x - 4,
    elements[i].y,
    elements[i].w + 9,
    elements[i].h
};
    SDL_RenderFillRect(context.renderer, &r);
}
    		}
SDL_SetRenderDrawColor(context.renderer, 15, 15, 0, 255);

for (int t = 0; t < 9; t++) {
SDL_FRect r = {
    elements[i].x - 4,
    elements[i].y,
    elements[i].w + 9,
    elements[i].h
};
    SDL_RenderRect(context.renderer, &r);
}

    		SDL_RenderTexture(context.renderer, context.Elements[i], NULL, &elements[i]);
		}
		
if (trocaLinhasEmAndamento) {
    if (!trocaMsgTexture) {
        texts(&context,
              "font/BodoniFLF.ttf",
              25.0f,
              "TrocaMsg",
              trocaMsgTexto,
              "TrocaMsgTexture",
              &trocaMsgTexture,
              "TrocaMsgRef",
              255,255,255,255);
    }

    SDL_FRect msgRect = { 420.0f, 140.0f, 440.0f, 30.0f };
    SDL_RenderTexture(context.renderer, trocaMsgTexture, NULL, &msgRect);
}
// Mensagem de instrução ao usuário
if (infoTexture) {
	if (t1){
		SDL_RenderTexture(context.renderer, infoTexture, NULL, &infoRect);	
	}
	else{
		if (t2){
			SDL_FRect aux = {470.0f,125.0f,170.0f,25.0f};
			SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);
		}
		else{
			if (t3){
		        SDL_FRect aux = {400.0f,125.0f,310.0f,25.0f};
			    SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);	
			}
			else{
				if (t4){
					SDL_FRect aux = {430.0f,125.0f,250.0f,25.0f};
			    	SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);
				}
				else{
					if (t5){
						SDL_FRect aux = {430.0f,125.0f,250.0f,25.0f};
			    	    SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);
					}
					else{
						if (t6){
							SDL_FRect aux = {415.0f,125.0f,280.0f,25.0f};
			    	        SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);	
						}
						else{
							if (t7){
								SDL_FRect aux = {415.0f,125.0f,280.0f,25.0f};
			    	            SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);
							}
							else{
								if (t8){
									SDL_FRect aux = {400.0f,125.0f,300.0f,25.0f};
			    	                SDL_RenderTexture(context.renderer, infoTexture, NULL, &aux);	
								}
							}
						}
					}
				}
			}
		}
	}
}

		SDL_RenderPresent (context.renderer);
		SDL_Delay (16);
	}
}
	printf ("O usuario fechou a janela! Encerrando o programa...");
	
	SDL_StopTextInput(context.window);
	destroy(&context);
    
    return 0;
}

void effect (EFFECTS* e,double x, double y){
	if (x>970.0 && x<1098.25 && y>74.0 && y<132.25){
		//printf ("%.2f %0.2f ",event.motion.x,event.motion.y);
		e->isHover1 = 1;
	}else{
		e->isHover1 = 0;
	}
	if (x>=1135.0 && x<=1263.25 && y>=74.0 && y<=132.25){
		//printf ("%.2f %0.2f ",x,y);
		e->isHover2 = 1;
	}else{
		e->isHover2 = 0;
	}
	if (x>=970.0 && x<=1098.25 && y>=164.0 && y<=222.25){
		//printf ("%.2f %0.2f ",x,y);
		e->isHover3 = 1;
	}else{
		e->isHover3 = 0;
	}
	if (x>=1135.0 && x<=1263.25 && y>=164.0 && y<=222.25){
		//printf ("%.2f %0.2f ",x,y);
		e->isHover4 = 1;
	}else{
		e->isHover4 = 0;
	}
	if (x>=1050.0 && x<=1178.25 && y>=254.0 && y<=310.25){
		//printf ("%.2f %0.2f ",x,y);
		e->isHover5 = 1;
	}else{
		e->isHover5 = 0;
	}
	if (x>=22.0 && x<=150.0 && y>=130.0 && y<=215.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover6 = 1;
	}else{
		e->isHover6 = 0;
	}
	if (x>=22.0 && x<=150.0 && y>=240.0 && y<=325.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover7 = 1;
	}else{
		e->isHover7 = 0;
	}
	if (x>=22.0 && x<=150.0 && y>=350.0 && y<=435.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover8 = 1;
	}else{
		e->isHover8 = 0;
	}
	if (x>=22.0 && x<=150.0 && y>=460.0 && y<=545.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover9 = 1;
	}else{
		e->isHover9 = 0;
	}
	if (x>=178.0 && x<=305.0 && y>=610.0 && y<=695.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover10 = 1;
	}else{
		e->isHover10 = 0;
	}
	if (x>=320.0 && x<=455.0 && y>=610.0 && y<=695.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover11 = 1;
	}else{
		e->isHover11 = 0;
	}
	if (x>=477.0 && x<=610.0 && y>=610.0 && y<=695.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover12 = 1;
	}else{
		e->isHover12 = 0;
	}
	if (x>=628.0 && x<=758.0 && y>=610.0 && y<=695.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover13 = 1;
	}else{
		e->isHover13 = 0;
	}
	if (x>=778.0 && x<=906.0 && y>=610.0 && y<=695.333){
	//printf ("%.2f %0.2f ",x,y);
		e->isHover14 = 1;
	}else{
		e->isHover14 = 0;
	}
// HOVER do Aplicar
if (x >= 1050.0 && x <= 1050.0 + 125.25 &&
    y >= 654.0  && y <= 654.0  + 52.25) {
    e->isHover15 = 1;
} else {
    e->isHover15 = 0;
}
}


void atualizaMensagemPadrao(AppContext* ctx) {
    if (matrizPreenchida) {
        strcpy(infoBuffer, "Selecione uma das opcoes ao lado.");
        t1 = 0; t2 = 0; t3 = 0; t4 = 0, t5 = 0, t6 = 0, t7=1;
    } else {
        strcpy(infoBuffer, "Digite a matriz e o escalar.");
        t1 = 1; t2 = 0; t3 = 0; t4 = 0;   
    }

    texts(ctx,
          "font/BodoniFLF.ttf",
          25.0f,
          "InfoLabel",
          infoBuffer,
          "InfoTexture",
          &infoTexture,
          "InfoTexRef",
          255,255,255,255);
}


