#include <stdio.h>
# include<stdlib.h>
int main(void) {

      int matricula;
       char nome[100];
      float nota;

    FILE *arquivo;

    
    arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    
     for (int i = 0; i < 5; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &matricula);

        printf("Nome: ");
        scanf(" %[^\n]", nome);

        printf("Nota final: ");
        scanf("%f", &nota);

        
        fprintf(arquivo, "%d %s %.1f\n", matricula, nome, nota);
    }

    
    fclose(arquivo);

    
    arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    printf("\n===== ALUNOS CADASTRADOS =====\n");

    
    while (fscanf(arquivo, "%d %99[^\n] %f", &matricula, nome, &nota) == 3) {
        printf("Matricula: %d | Nome: %s | Nota: %.1f\n",
               matricula, nome, nota);
    }

    
    fclose(arquivo);

    return 0;
}