# include<stdio.h>
# include <stdilib.h>

typedef struct {
    char nome[50];
    float preco;
} Fruta;

int main() {
    FILE *arquivo;
    Fruta fruta;
    char continuar;

    arquivo = fopen("frutas.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        printf("Digite o nome da fruta: ");
        scanf(" %[^\n]", fruta.nome);

        printf("Digite o preco da fruta: ");
        scanf("%f", &fruta.preco);

        fprintf(arquivo, "%s,%.2f\n", fruta.nome, fruta.preco);

        printf("Deseja cadastrar outra fruta? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Cadastro encerrado.\n");

    fclose(arquivo);

    return 0;
