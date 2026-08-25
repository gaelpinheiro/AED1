#include<stdipo.h>
#include<stdlib.h>

int main( void) {


      char **frutas = NULL;
      float *precos = NULL;
      int quantidade = 0;
       char opcao;

        do {
        // Aumenta o espaço para mais uma fruta
          quantidade++;

        frutas = realloc(frutas, quantidade * sizeof(char *));
        precos = realloc(precos, quantidade * sizeof(float));

          // Aloca espaço para o nome da fruta
        frutas[quantidade - 1] = malloc(50 * sizeof(char));

        printf("Digite o nome da fruta: ");
        scanf("%49s", frutas[quantidade - 1]);

        printf("Digite o preco da fruta: ");
        scanf("%f", &precos[quantidade - 1]);

          printf("Deseja cadastrar outra fruta? (s/n): ");
           scanf(" %c", &opcao);

       } while (opcao == 's' || opcao == 'S');

      // Mostra as frutas cadastradas
    printf("\n--- Frutas cadastradas ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("%s - R$ %.2f\n", frutas[i], precos[i]);
    }

         // Liberando a memória
       for (int i = 0; i < quantidade; i++) {
        free(frutas[i]);
    }

     free(frutas);
    free(precos)

