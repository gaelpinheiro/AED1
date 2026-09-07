#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA 800
#define ALTURA_JANELA  600
#define TAM_CELULA     40   // tamanho de cada célula da grade (matriz)


typedef struct {
    Vector2 pos;
    Vector2 vel;
    float   raio;
    Color   cor;
} Bola;

/* ---------------------------------------------------------------
 * cria uma MATRIZ dinâmica de inteiros (linhas x colunas)
 * Retorna um ponteiro para ponteiro (int **): cada posição do
 * vetor externo aponta para um vetor de inteiros (uma linha).
 * --------------------------------------------------------------- */
int **criarMatriz(int linhas, int colunas) {

    // aloca o vetor de ponteiros (um ponteiro por linha)
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) return NULL;

    for (int i = 0; i < linhas; i++) {
        // aloca cada linha como um vetor de inteiros
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++) {
            // preenche com 0 ou 1 aleatoriamente (dois "tipos" de célula)
            matriz[i][j] = GetRandomValue(0, 1);
        }
    }
    return matriz;
}

/* libera a memória da matriz: primeiro cada linha, depois o vetor de linhas */
void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);   // libera cada linha
    }
    free(matriz);           // libera o vetor de ponteiros
}

/* desenha a matriz na tela, célula por célula */
void desenharMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            Color cor = (matriz[i][j] == 1) ? (Color){20, 40, 70, 255}
                                             : (Color){15, 30, 55, 255};
            DrawRectangle(j * TAM_CELULA, i * TAM_CELULA,
                           TAM_CELULA - 2, TAM_CELULA - 2, cor);
        }
    }
}

/* ---------------------------------------------------------------
 * cria o vetor dinâmico de bolas
 * --------------------------------------------------------------- */
Bola *criarBolas(int quantidade) {
    Bola *bolas = (Bola *)malloc(quantidade * sizeof(Bola));
    if (bolas == NULL) return NULL;

    for (int i = 0; i < quantidade; i++) {
        // usar (bolas + i) é o mesmo que &bolas[i]: aqui acessamos
        // o campo via ponteiro para deixar explícito o conceito.
        Bola *b = (bolas + i);
        b->pos = (Vector2){ GetRandomValue(50, LARGURA_JANELA - 50),
                             GetRandomValue(50, ALTURA_JANELA - 50) };
        b->vel = (Vector2){ (float)GetRandomValue(-4, 4),
                             (float)GetRandomValue(-4, 4) };
        b->raio = (float)GetRandomValue(10, 25);
        b->cor  = (Color){ GetRandomValue(100,255), GetRandomValue(100,255),
                            GetRandomValue(100,255), 255 };
    }
    return bolas;
}

/* atualiza a posição de UMA bola: recebe um PONTEIRO para a struct,
 * então as alterações afetam diretamente o vetor original (sem cópia) */
void atualizarBola(Bola *b) {
    b->pos.x += b->vel.x;
    b->pos.y += b->vel.y;

    // rebate nas bordas
    if (b->pos.x - b->raio < 0 || b->pos.x + b->raio > LARGURA_JANELA)
        b->vel.x *= -1;
    if (b->pos.y - b->raio < 0 || b->pos.y + b->raio > ALTURA_JANELA)
        b->vel.y *= -1;
}


/* 
 * EXERCÍCIO 1
 *  */

/* inicializa uma nova bola */
void inicializarBola(Bola *b) {
    b->pos = (Vector2){ GetRandomValue(50, LARGURA_JANELA - 50),
                         GetRandomValue(50, ALTURA_JANELA - 50) };

    b->vel = (Vector2){ (float)GetRandomValue(-4, 4),
                         (float)GetRandomValue(-4, 4) };

    b->raio = (float)GetRandomValue(10, 25);

    b->cor = (Color){ GetRandomValue(100,255),
                       GetRandomValue(100,255),
                       GetRandomValue(100,255), 255 };
}


/* 
 * EXERCÍCIO 2
 *  */

/* marca a célula onde a bola está */
void marcarCelula(Bola *b, int **grade, int linhas, int colunas) {

    int coluna = (int)(b->pos.x / TAM_CELULA);
    int linha  = (int)(b->pos.y / TAM_CELULA);

    if (linha >= 0 && linha < linhas &&
        coluna >= 0 && coluna < colunas) {

        grade[linha][coluna] = 1;
    }
}


/* conta quantas células já foram visitadas */
int contarVisitadas(int **grade, int linhas, int colunas) {

    int contador = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            if (grade[i][j] == 1) {
                contador++;
            }
        }
    }

    return contador;
}


/* desenha novamente as células visitadas
 * sem alterar a função original desenharMatriz */
void desenharCelulasVisitadas(int **grade, int linhas, int colunas) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            if (grade[i][j] == 1) {

                Color corVisitada = (Color){80, 120, 180, 255};

                DrawRectangle(j * TAM_CELULA,
                              i * TAM_CELULA,
                              TAM_CELULA - 2,
                              TAM_CELULA - 2,
                              corVisitada);
            }
        }
    }
}


int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA,
               "Ponteiros e Alocacao Dinamica - raylib");
    SetTargetFPS(60);

    int linhas   = ALTURA_JANELA / TAM_CELULA;
    int colunas  = LARGURA_JANELA / TAM_CELULA;
    int **grade  = criarMatriz(linhas, colunas);   // matriz dinâmica

    int quantidadeBolas = 12;
    Bola *bolas = criarBolas(quantidadeBolas);      // vetor dinâmico


    /* 
     * EXERCÍCIO 2
     * A matriz original continua sendo criada aleatoriamente.
     * Aqui apenas zeramos todas as células para que:
     * 0 = não visitada
     * 1 = visitada
     *  */
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            grade[i][j] = 0;
        }
    }


    while (!WindowShouldClose()) {


        /* 
         * EXERCÍCIO 1
         * ADICIONAR UMA BOLA COM ESPAÇO
         *  */
        if (IsKeyPressed(KEY_SPACE)) {

            quantidadeBolas++;

            Bola *temp = realloc(bolas,
                                  quantidadeBolas * sizeof(Bola));

            if (temp != NULL) {

                bolas = temp;

                inicializarBola(&bolas[quantidadeBolas - 1]);

            } else {

                quantidadeBolas--;
            }
        }


        /* 
         * EXERCÍCIO 1
         * REMOVER UMA BOLA COM BACKSPACE
         *  */
        if (IsKeyPressed(KEY_BACKSPACE)) {

            if (quantidadeBolas > 0) {

                quantidadeBolas--;

                if (quantidadeBolas == 0) {

                    free(bolas);
                    bolas = NULL;

                } else {

                    Bola *temp = realloc(bolas,
                                          quantidadeBolas * sizeof(Bola));

                    if (temp != NULL) {
                        bolas = temp;
                    }
                }
            }
        }


        // percorre o vetor usando aritmética de ponteiros:
        // (bolas + i) aponta para o i-ésimo elemento do vetor
        for (int i = 0; i < quantidadeBolas; i++) {

            atualizarBola(bolas + i);


            /* 
             * EXERCÍCIO 2
             * Marca a célula por onde a bola passou
             * */
            marcarCelula(bolas + i,
                         grade,
                         linhas,
                         colunas);
        }


        /* 
         * EXERCÍCIO 2
         * Conta as células visitadas
         *  */
        int visitadas = contarVisitadas(grade, linhas, colunas);


        BeginDrawing();

            ClearBackground(RAYWHITE);

            desenharMatriz(grade, linhas, colunas);


            /* 
             * EXERCÍCIO 2
             * Destaca as células visitadas
             *  */
            desenharCelulasVisitadas(grade, linhas, colunas);


            for (int i = 0; i < quantidadeBolas; i++) {
                DrawCircleV(bolas[i].pos,
                            bolas[i].raio,
                            bolas[i].cor);
            }


            DrawText("Matriz (int**) e vetor de structs (Bola*) alocados com malloc",
                     10, 10, 18, WHITE);

            DrawText("Pressione ESC para sair",
                     10, ALTURA_JANELA - 25, 16, WHITE);


            /* 
             * EXERCÍCIO 1
             *  */
            DrawText("ESPACO = adicionar | BACKSPACE = remover",
                     10, 35, 18, WHITE);

            DrawText(TextFormat("Bolas: %d", quantidadeBolas),
                     10, 60, 18, WHITE);


            /* 
             * EXERCÍCIO 2
             *  */
            DrawText(TextFormat("Celulas visitadas: %d", visitadas),
                     10, 85, 18, WHITE);

        EndDrawing();
    }


    // libera TODA a memória alocada dinamicamente antes de encerrar
    free(bolas);
    liberarMatriz(grade, linhas);

    CloseWindow();
    return 0;
}