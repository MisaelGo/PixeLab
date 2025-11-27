# PixeLab
Aplicativo em C com SDL3 para editar uma matriz 3x3 (kernel) e aplicar filtros de convolução em uma imagem.

Este projeto é uma aplicação gráfica desenvolvida em C + SDL3, que permite:

✅ Editar matrizes 3×3 manualmente
✅ Aplicar filtros de convolução em imagens
✅ Criar / editar / testar kernels personalizados
✅ Trocar linhas, somar linhas, multiplicar por escalar
✅ Visualizar todo o processo com retângulos, destaques, botões e interface interativa
✅ Desfazer operações através de uma pilha de ações
✅ Exibir mensagens informativas ao usuário

O software foi construído com foco em aprendizado de álgebra linear, processamento de imagens e interfaces gráficas SDL3.

📦 Funcionalidades
🟦 1. Editor de Matriz 3×3
Cada célula pode ser editada clicando e digitando.
Aceita números entre -10 e 10.
Valida entrada, evita valores inválidos.
Cada célula possui borda de seleção.
Linhas podem ser destacadas ao clicar em botões dedicados.

🔁 2. Operações Elementares de Linha
Trocar linhas (Li ↔ Lj)
Somar linhas (Li ← Li + k·Lj)
Multiplicar linha por escalar (Li ← k·Li)
Destaque visual da linha ativa ou destino.
Mensagens claras guiando o usuário.

🎨 3. Filtros de Convolução em Imagem
Desfoque (3x3)
Nitro / Sharpen
Laplace
Emboss
Detecção de bordas
Kernel personalizado editado pelo usuário

📥 4. Pilha de Desfazer
Guarda histórico das matrizes aplicadas.
Ao desfazer, restaura a matriz, não só o filtro.
Totalmente integrada com SDL_Textures.

📝 5. Mensagens Informativas
Textos dinâmicos explicam qualquer operação.
Atualiza automaticamente quando o usuário age.
Não sobrepõe textos (renderização limpa).

🔧 Requisitos
Antes de compilar, instale:
✔️ SDL3
✔️ SDL3_ttf
✔️ SDL3_image
✔️ MinGW (ou outro compilador C)
✔️ Dev-C++ (opcional – funciona no Makefile também)

📁 Estrutura do Projeto
ProjetosSDL/
│
├── src/                # Arquivos .c
│   ├── main.c
│   ├── algebra.c
│   ├── convolve.c
│   ├── destroy.c
│   ├── images.c
│   ├── init.c
│   ├── lista_enc.c
│   ├── pilha.c
│   ├── pilha_acao.c
│   ├── pilha_matrix.c
│   └── texts.c
│
├── include/            # Arquivos .h
│   ├── main.h
│   ├── algebra.h
│   ├── convolve.h
│   ├── destroy.h
│   ├── images.h
│   ├── init.h
│   ├── lista_enc.h
│   ├── pilha.h
│   ├── pilha_acao.h
│   ├── pilha_matrix.h
│   └── texts.h
│
├── assets/             # Imagens usadas no app
│
├── font/               # Fontes TTF
│
├── Makefile.win        # Makefile gerado pelo Dev-C++
└── README.md           # Este arquivo

▶️ Como Compilar
Faça clone:
git clone https://github.com/seu-usuario/ProjetosSDL.git
cd ProjetosSDL

Compile usando Make:
mingw32-make -f Makefile.win
Ou abra TesteSDL.dev no Dev-C++ e clique em Compile & Run.

🖥️ Como Usar o Software
1️⃣ Editando a Matriz
Clique sobre qualquer célula.
Digite valores entre -10 e 10.
Pressione Enter para aplicar.
Valores inválidos são ignorados.

2️⃣ Operações Elementares
Botões incluem:
Li ↔ Lj — trocar linhas
Li ← Li + k·Lj — soma de linhas
Li ← k·Li — multiplicação por escalar
Aplicar matriz na imagem
O software sempre exibe instruções claras sobre o que fazer.

3️⃣ Criar e Testar Filtros
Basta editar os valores e pressionar Aplicar.

4️⃣ Desfazer
Pressionar o botão de Undo restaura a última matriz aplicada.

💡 Tecnologias Utilizadas
C (C11)
SDL3
SDL3_ttf
SDL3_image
Sistema de renderização por SDL_FRect
Estruturas dinâmicas (pilha, lista encadeada)
Convolução em imagens
Ambiente gráfico

🧠 Por que este projeto é útil?
Ele serve para:
Estudar álgebra linear com visualização real.
Aprender convolução, filtros, edge detection, blur, etc.
Treinar conceitos de interface gráfica SDL3.
Entender persistência de estado com pilha de ações.
Criar kernels personalizados e ver o efeito instantaneamente.

Sinta-se livre para modificar, estudar e melhorar

🙏 Agradecimentos

Obrigado por utilizar e estudar este projeto!
Qualquer melhoria, ideia ou bug, envie uma issue ou pull request.
