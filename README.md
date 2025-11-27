<div align="center">
  <h1>PixeLab</h1>
  <p><strong>Aplicativo em C + SDL3</strong> para editar uma matriz 3×3 (kernel) e aplicar filtros de convolução em imagens.</p>
</div>

<hr/>

<div>
  <h2>👥 Créditos e Colaboradores</h2>

  <p>Este projeto foi desenvolvido com a dedicação e contribuição de várias pessoas talentosas:</p>

  <ul>
    <li><strong>Misael Gomes</strong> — Desenvolvedor principal do software, responsável pelo funcionamento geral do PixeLab.</li>

  <li><strong>Vitor</strong> — Implementação do arquivo <code>algebra.c</code>, incluindo estruturação das funções e lógica inicial.</li>

  <li><strong>Henrique</strong> — Implementação do arquivo <code>algebra.c</code>, incluindo estruturação das funções e lógica inicial.</li>

   <li><strong>Alyyson</strong> — Responsável pelos cálculos matemáticos do <code>algebra.c</code> e por todos os testes relacionados às operações da álgebra.</li>

  <li><strong>Lícia Lucena</strong> — Designer oficial do software, trabalhando na interface visual, estilo e aparência geral do PixeLab.</li>
  </ul>
</div>


<hr/>

<div>
  <h2>✨ Visão Geral</h2>
  <p>O PixeLab foi desenvolvido com foco em:</p>

  <ul>
    <li>Álgebra Linear</li>
    <li>Processamento de Imagens</li>
    <li>Interfaces Gráficas em SDL3</li>
  </ul>

  <p>Principais Recursos:</p>

  <ul>
    <li>✔️ Editor de matriz 3×3 interativo</li>
    <li>✔️ Aplicação de filtros de convolução</li>
    <li>✔️ Kernels personalizados</li>
    <li>✔️ Operações elementares de linha</li>
    <li>✔️ Destaques visuais e interface gráfica</li>
    <li>✔️ Desfazer com pilha de ações</li>
    <li>✔️ Mensagens informativas dinâmicas</li>
  </ul>
</div>

<hr/>

<div>
  <h2>📦 Funcionalidades Detalhadas</h2>

  <h3>1. Editor de Matriz 3×3</h3>
  <ul>
    <li>Células clicáveis e editáveis</li>
    <li>Valores permitidos: -10 a 10</li>
    <li>Validação automática</li>
    <li>Destaque por seleção</li>
    <li>Destaque de linhas completas</li>
  </ul>

  <h3>2. Operações Elementares de Linha</h3>
  <ul>
    <li>Trocar linhas (Li ↔ Lj)</li>
    <li>Somar linhas (Li ← Li + k·Lj)</li>
    <li>Multiplicar linha (Li ← k·Li)</li>
    <li>Feedback visual imediato</li>
    <li>Mensagens orientando o usuário</li>
  </ul>

  <h3>3. Filtros de Convolução</h3>
  <ul>
    <li>Desfoque (Blur)</li>
    <li>Sharpen / Nitro</li>
    <li>Laplace</li>
    <li>Emboss</li>
    <li>Detecção de Bordas</li>
    <li>Kernel 3×3 totalmente personalizável</li>
  </ul>

  <h3>4. Sistema de Desfazer</h3>
  <ul>
    <li>Armazena todas as matrizes aplicadas</li>
    <li>Undo restaura a matriz exata usada</li>
    <li>Integrado com SDL_Texture</li>
  </ul>

  <h3>5. Mensagens Informativas</h3>
  <ul>
    <li>Textos dinâmicos</li>
    <li>Explicações de cada ação</li>
    <li>Nunca sobrepõe texto na tela</li>
  </ul>
</div>

<hr/>

<div>
  <h2>🔧 Requisitos</h2>
  <ul>
    <li>SDL3</li>
    <li>SDL3_ttf</li>
    <li>SDL3_image</li>
    <li>MinGW ou outro compilador C</li>
    <li>Dev-C++ (opcional)</li>
  </ul>
</div>

<hr/>

<div>
  <h2>📁 Estrutura do Projeto</h2>

  <pre>
ProjetosSDL/
│
├── src/
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
├── include/
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
├── assets/
├── font/
├── Makefile.win
└── README.md
  </pre>
</div>

<hr/>

<div>
  <h2>▶️ Como Compilar</h2>

  <h3>Via Makefile</h3>
  <pre>
git clone https://github.com/seu-usuario/ProjetosSDL.git
cd ProjetosSDL
mingw32-make -f Makefile.win
  </pre>

  <h3>Via Dev-C++</h3>
  <p>Abra <strong>TesteSDL.dev</strong> e clique em <strong>Compile & Run</strong>.</p>
</div>

<hr/>

<div>
  <h2>🖥️ Como Usar</h2>

  <h3>1️⃣ Editando a Matriz</h3>
  <ul>
    <li>Clique na célula</li>
    <li>Digite o valor</li>
    <li>Pressione Enter</li>
    <li>Erros são automaticamente ignorados</li>
  </ul>

  <h3>2️⃣ Operações de Linha</h3>
  <ul>
    <li>Trocar</li>
    <li>Somar</li>
    <li>Multiplicar</li>
    <li>Aplicar matriz na imagem</li>
  </ul>

  <h3>3️⃣ Criar e Testar Filtros</h3>
  <ul>
    <li>Edite os valores 3×3</li>
    <li>Clique em Aplicar</li>
  </ul>

  <h3>4️⃣ Desfazer</h3>
  <ul>
    <li>Pressione Undo</li>
    <li>A matriz anterior é restaurada fielmente</li>
  </ul>
</div>

<hr/>

<div>
  <h2>💡 Tecnologias Utilizadas</h2>
  <ul>
    <li>C (C11)</li>
    <li>SDL3</li>
    <li>SDL3_ttf</li>
    <li>SDL3_image</li>
    <li>Renderização com SDL_FRect</li>
    <li>Estruturas dinâmicas (pilhas, listas)</li>
    <li>Convolução 3×3</li>
  </ul>
</div>

<hr/>

<div>
  <h2>🧠 Por Que é Útil?</h2>
  <ul>
    <li>Visualização real de álgebra linear</li>
    <li>Entendimento profundo de kernels</li>
    <li>Treinamento de GUI com SDL3</li>
    <li>Arquitetura com estado persistente</li>
    <li>Criação de filtros personalizados</li>
  </ul>
</div>

<hr/>

<div>
  <h2>🤝 Contribuições</h2>
  <p>Sinta-se à vontade para enviar issues, sugestões e pull requests.</p>
</div>

<hr/>

<div>
  <h2>🙏 Agradecimentos</h2>
  <p>Obrigado por usar e estudar este projeto!</p>
</div>

