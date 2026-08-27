#include <stdio.h>
#include <stdlib.h>

 int main(void) {
    int  linhas, colunas;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    int **matriz = malloc(linhas * sizeof(int *));

    if (matriz == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int));

         if (matriz[i] == NULL) {
            printf("Erro na alocacao de memoria.\n");
            return 1;
        }
    }

      printf("\nDigite os elementos da matriz:\n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

       printf("\nMatriz original:\n");

       for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

      printf("\nMatriz transposta:\n");

        for (int j = 0; j < colunas; j++) {
        for (int i = 0; i < linhas; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

      for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}