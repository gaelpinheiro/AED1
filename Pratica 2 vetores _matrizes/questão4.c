#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void) {
       int n;

        printf("Digite o numero de pessoas: ");
        scanf("%d", &n);

       if (n <= 0 || n > 100) {
        printf("Numero de pessoas invalido.\n");
        return 1;
    }

      char (*nomes)[100] = malloc(n * sizeof(*nomes));
     int *idades = malloc(n * sizeof(int));

       if (nomes == NULL || idades == NULL) {
        printf("Erro na alocacao de memoria.\n");
          free(nomes);
          free(idades);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        getchar();

        printf("\nDigite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], 100, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

          printf("Digite a idade: ");
        scanf("%d", &idades[i]);
     }

       printf("\nPessoas cadastradas:\n");

    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Idade: %d\n", nomes[i], idades[i]);
     }

      free(nomes);
      free(idades);

    return 0;
}