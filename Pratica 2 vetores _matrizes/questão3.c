# include<stdio.h>
# include<stdlib.h>
#include<time.h.>
int main(void){
    int n;
    printf(" digite a odem da matri:");
    sacnf("%",&n);
    int**matri = malloc(n*sieof(int*));
    if(matriz==null){
        printf(" erro na alocaçao de memoria.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matriz[i] = malloc(n * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro na alocacao de memoria.\n");
            return 1;
        }
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}