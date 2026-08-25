# include<stdio.h>
# include<stdlib.h>



int main( void) {

    int **matriz;

    // Alocando as 3 linhas
    matriz  = malloc(3 * sizeof(int *));

    // alocando as tres colunas de cada linha
    for (int i = 0; i < 3; i++) {
        matriz[i] = malloc(3 * sizeof(int));
    }

    // Preenchendo a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = i * 3 + j;
        }
    }

    //  Imprimindo a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // liberando a memoria
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}