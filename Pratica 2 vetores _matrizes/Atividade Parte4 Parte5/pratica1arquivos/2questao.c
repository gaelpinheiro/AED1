# include<stdio.h>
# include<stdlib.h>

int main() {
    int N;
    int i;
    char nome[100];
    float nota1, nota2, nota3;

    FILE *arquivo;

    arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);

        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        fprintf(arquivo, "Nome: %s\n", nome);
        fprintf(arquivo, "Nota 1: %.2f\n", nota1);
        fprintf(arquivo, "Nota 2: %.2f\n", nota2);
        fprintf(arquivo, "Nota 3: %.2f\n\n", nota3);
    }

    fclose(arquivo);

    printf("\nDados armazenados com sucesso!\n");

    return 0;
}