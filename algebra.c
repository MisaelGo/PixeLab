#include "../include/algebra.h"
/*
int main() {
    size_t num_cols, num_rows;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%zu", &num_rows);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%zu", &num_cols);
    clear_input_buffer();

    if (num_rows <= 0 || num_cols <= 0) {
        printf("Apenas numeros positivos sao validos.\n");
        return 1;
    }

    Matrix* minha_matriz = create_matrix(num_rows, num_cols);

    if (minha_matriz == NULL) {
        fprintf(stderr, "Falha ao criar a matriz. A sair.\n");
        return 1;
    }

    printf("\n--- Insercao de Elementos ---\n");
    printf("Digite os %zu elementos da matriz.\n", num_rows * num_cols);
	*/
    /* loop para pedir cada elemento ao usuário */
    //char prompt[256];
    //for (size_t i = 0; i < num_rows; i++) {
        //for (size_t j = 0; j < num_cols; j++) {
            //snprintf(prompt, sizeof(prompt /*sizeof(char)*/), "Digite o valor para a posicao [%zu][%zu]: ", i + 1, j + 1);
            //ler_double(prompt, &(minha_matriz->data[i][j]));
            
            // double valor_digitado; 
            // printf("Digite o valor para a posicao [%zu][%zu]: ", i+1, j+1);
            
            //scanf("%lf", &valor_digitado);
            //clear_input_buffer();

            //ins_elem_matrix(minha_matriz, i, j, valor_digitado);
        //}
    //}
	
    //int opcao;

    //do {
        /* mostra a matriz final */
        /*printf("\n--- Matriz Preenchida ---\n");
        print_matrix(minha_matriz);

        printf("\n--- Menu de Operacoes ---\n");
        printf("1: Trocar linhas da matriz\n");
        printf("2: Multiplicar por escalar\n");
        printf("3: Escalonar a matriz (RREF)\n");
        printf("4: Sair e liberar a memoria\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        clear_input_buffer();
        
        switch(opcao) {
            case 1: {
                size_t linha1, linha2;
                printf("Digite a primeira linha que deseja trocar (de 1 a %zu): ", num_rows);
                scanf("%zu", &linha1);
                clear_input_buffer();
                printf("Digite a segunda linha que deseja trocar (de 1 a %zu): ", num_rows);
                scanf("%zu", &linha2);
                clear_input_buffer();
                
                swap_rows(minha_matriz, (linha1 - 1), (linha2 - 1));
                break;
            }
            case 2: {
                size_t linha;
                double escalar; 
                printf("Digite a linha que deseja multiplicar (de 1 a %zu): ", num_rows);
                scanf("%zu", &linha);
                clear_input_buffer();
                if (linha > num_rows || linha < 1){
                    fprintf(stderr, "ERRO: Linha invalida. Deve estar entre 1 e %zu.\n", num_rows);
                } else {
                    printf("Digite o escalar: ");
                    scanf("%lf", &escalar); 
                    clear_input_buffer();
                
                    scale_row(minha_matriz, (linha - 1), escalar);
                    printf("\nLinha multiplicada!\n");
                }
                break;
            }
            case 3:{
                to_rref(minha_matriz);
                printf("\nMatriz escalonada com sucesso!\n");
                break;
            }
            case 4: {
                free_matrix(minha_matriz);
                printf("\nMemoria liberada com sucesso! A sair...\n");
                break;
            }
            default:
                printf("\nOpcao invalida! Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}*/



Matrix* create_matrix(size_t linhas, size_t colunas) {
    size_t i;
    if (linhas == 0 || colunas == 0) {
        fprintf(stderr, "ERRO: Linhas e colunas da matriz nao podem ser zero.\n");
        return NULL;
    }

    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    if (!m) {
        fprintf(stderr, "ERRO: Nao foi possivel alocar memoria para a estrutura Matrix.\n");
        return NULL;
    }
    m->linhas = linhas;
    m->colunas = colunas;
    m->data = NULL;
    m->block = NULL; 

    if (linhas > MATRIX_LIMIT / sizeof(double*)) {
        fprintf(stderr, "ERRO: Tamanho da matriz muito grande para alocar ponteiros de linha.\n");
        free(m);
        return NULL;
    }

    m->data = (double**)malloc(linhas * sizeof(double*));
    if (!m->data) {
        fprintf(stderr, "ERRO: Nao foi possivel alocar memoria para as linhas.\n");
        free(m);
        return NULL;
    }

    if (linhas * colunas > MATRIX_LIMIT) {
         fprintf(stderr, "ERRO: Overflow de tamanho. Ordem da matriz muito grande.\n");
         free(m->data);
         free(m);
         return NULL;
    }
    size_t num_elements = linhas * colunas;

    m->block = (double*)calloc(num_elements, sizeof(double));
    if (!m->block) {
        fprintf(stderr, "ERRO: Nao foi possivel alocar memoria para os elementos da matriz.\n");
        free(m->data); 
        free(m);
        return NULL;
    }

    for (i = 0; i < linhas; i++) {
        m->data[i] = m->block + (i * colunas);
    }

    return m;
}

void free_matrix(Matrix* m) {
    
    if (m == NULL) {
        return;
    }

    free(m->block);
    free(m->data);
    free(m);
}


int ins_elem_matrix(Matrix* m, size_t i, size_t j, double num) {
    
    if (m == NULL || m->data == NULL) {
        fprintf(stderr, "ERRO! Matriz nula ou nao inicializada!\n");
        return 0;
    }

    if (i >= m->linhas || j >= m->colunas) {
        fprintf(stderr, "ERRO: Indices [%zu][%zu] estao fora dos limites da matriz.\n", i, j);
        return 0;
    }

    m->data[i][j] = num;

    return 1;
}

void print_matrix(Matrix* m){
    for (size_t i = 0; i < m->linhas; i++) {
        printf("\n[");
        for (size_t j = 0; j < m->colunas; j++) {
            printf(" %6.2f", m->data[i][j]);
        }
        printf(" ]");
    }
    printf("\n");
}

void swap_rows(Matrix* m, size_t r1, size_t r2) {

    if (m == NULL || m->data == NULL) {
        fprintf(stderr, "ERRO: Matriz nula ou nao inicializada!\n");
        return;
    }

    if (r1 >= m->linhas || r2 >= m->linhas) {
        fprintf(stderr, "ERRO: Linha(s) [%zu, %zu] invalidas para troca.\n", r1 + 1, r2 + 1);
        return;
    }

    if (r1 == r2) {
        return;
    }

    double* temp = m->data[r1];
    m->data[r1] = m->data[r2];
    m->data[r2] = temp;
}

void scale_row(Matrix* m, size_t r, double scalar) {
	size_t j;
    if (m == NULL || m->data == NULL) {
        fprintf(stderr, "ERRO: Matriz nula ou nao inicializada!\n");
        return;
    }
    if (r >= m->linhas) {
        fprintf(stderr, "ERRO: Linha [%zu] invalida para escalar.\n", r);
        return;
    }

    if (fabs(scalar - 1.0) < EPSILON) {
        return;
    }

    for (j = 0; j < m->colunas; j++) {
        m->data[r][j] *= scalar;
        // limpeza do resto da conta
        if (fabs(m->data[r][j]) < EPSILON)
            m->data[r][j] = 0.0;
    }
}

void add_rows(Matrix* m, size_t target_row, size_t source_row, double scalar) {
	size_t j;
     if (m == NULL || m->data == NULL) {
        fprintf(stderr, "ERRO: Matriz nula ou nao inicializada!\n");
        return;
    }
    if (target_row >= m->linhas || source_row >= m->linhas) {
        fprintf(stderr, "ERRO: Linha(s) [%zu, %zu] invalidas para soma.\n", target_row, source_row);
        return;
    }
    
    if (fabs(scalar) < EPSILON) {
        return;
    }

    for (j = 0; j < m->colunas; j++) {
        m->data[target_row][j] += scalar * m->data[source_row][j];
        // limpeza do resto da conta
        if (fabs(m->data[target_row][j]) < EPSILON) {
            m->data[target_row][j] = 0.0;
        }
    }
}

size_t find_pivot_row(Matrix *m, size_t col, size_t start_row){
    if (!m || !m->data || start_row >= m->linhas || col >= m->colunas){
        fprintf(stderr, "\nERRO! Parametros invalidos para achar o pivot!\n");
        return SIZE_MAX;
    }
        
    size_t best_row = start_row;
    double best_value = fabs(m->data[start_row][col]);

    for(size_t i = start_row + 1; i < m->linhas; i++){
        double current_value = fabs(m->data[i][col]);
        if(current_value > best_value){
            best_value = current_value;
            best_row = i;
        }
        print_matrix(m);
    }
    
    if (best_value <= EPSILON){
        return SIZE_MAX; // nenhum pivô válido (não-nulo) encontrado
    }
        
    return best_row;
}

// void to_rref(Matrix *m){
//     if(!m || !m->data) {
//         fprintf(stderr, "\nERRO: Matriz nula ou nao inicializada!\n");
//         return;
//     }
    
//     size_t lead_row = 0;
//     size_t num_cols = m->colunas;
//     size_t num_rows = m->linhas;

//     while(lead_row < num_rows && lead_row < num_cols) {
        
//         size_t pivot_col = lead_row;
//         size_t pivot_row = find_pivot_row(m, pivot_col, lead_row);
        
//         if (pivot_row == SIZE_MAX){ //nenhum pivô na columa, tenta a proxima linha/coluna
//             lead_row++; 
//             continue;
//         }

//         // trocar a linha do pivô para a posição 'lead_row'
//         if (lead_row != pivot_row){
//             swap_rows(m, lead_row, pivot_row);
//         }

//         // escalar a linha do pivô para que o pivô seja 1
//         double pivot_value = m->data[lead_row][pivot_col];
//         if (fabs(pivot_value) > EPSILON) {
//              double pivot_inverse = 1.0 / pivot_value;
//              scale_row(m, lead_row, pivot_inverse);
//         }

//         // zerar todos os outros elementos na coluna do pivô
//         for(size_t r = 0; r < num_rows; r++){
//             if(r == lead_row)
//                 continue; // não eliminar a própria linha do pivô
            
//             double factor = m->data[r][pivot_col];
//             if (fabs(factor) > EPSILON) {
//                 add_rows(m, r, lead_row, -factor);
//             }
//             print_matrix(m);
//         }   
//         lead_row++;
//         print_matrix(m);
//     }
// }

void to_rref(Matrix *m){
    if(!m || !m->data) {
        fprintf(stderr, "\nERRO: Matriz nula ou nao inicializada!\n");
        return;
    }
    
    size_t lead_row = 0; 
    size_t pivot_col = 0; 
    size_t num_cols = m->colunas;
    size_t num_rows = m->linhas;

    while(lead_row < num_rows && pivot_col < num_cols) { 
        
        size_t pivot_row_found = find_pivot_row(m, pivot_col, lead_row);
        
        if (pivot_row_found == SIZE_MAX){ 
            pivot_col++; 
            continue;
        }

        if (lead_row != pivot_row_found){
            swap_rows(m, lead_row, pivot_row_found);
        }

        double pivot_value = m->data[lead_row][pivot_col];
        double pivot_inverse = 1.0 / pivot_value;
        scale_row(m, lead_row, pivot_inverse);
        
        for(size_t r = 0; r < num_rows; r++){
            if(r == lead_row)
                continue; 
            
            double factor = m->data[r][pivot_col];
            if (fabs(factor) > EPSILON) {
                add_rows(m, r, lead_row, -factor);
            }
        } 
        
        lead_row++;
        pivot_col++;
    } 
}

void clear_input_buffer() {
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );
}

int ler_double(const char *prompt, double *out){
    printf("%s", prompt);
    while (scanf("%lf", out) != 1){
        fprintf(stderr, "Entrada invalida! Tente novamente: ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // flush
    }
    return 0;
}
