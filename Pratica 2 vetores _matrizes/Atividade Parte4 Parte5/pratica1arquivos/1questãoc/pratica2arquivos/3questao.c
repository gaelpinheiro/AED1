#include <stdio.h>
#include <stdlib.h>

   typedef struct {
    int codigo, quantidade;
    char nome[50];
    float preco;
} Produto;

void listar() {
    FILE *arq = fopen("produtos.txt", "r");
    Produto p;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while (fscanf(arq, "%d %49s %d %f",
                  &p.codigo, p.nome, &p.quantidade, &p.preco) == 4)
        printf("%d %s %d %.2f\n",
               p.codigo, p.nome, p.quantidade, p.preco);

    fclose(arq);
}

void consultar() {
    FILE *arq = fopen("produtos.txt", "r");
    Produto p;
    int codigo, achou = 0;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &codigo);

    while (fscanf(arq, "%d %49s %d %f",
                  &p.codigo, p.nome, &p.quantidade, &p.preco) == 4) {

        if (p.codigo == codigo) {
            printf("%d %s %d %.2f\n",
                   p.codigo, p.nome, p.quantidade, p.preco);
            achou = 1;
            break;
        }
    }

    if (!achou)
        printf("Produto nao encontrado!\n");

    fclose(arq);
}

void alterar() {
    FILE *arq = fopen("produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    Produto p;
    int codigo, nova;

    if (arq == NULL || temp == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &codigo);

    printf("Nova quantidade: ");
    scanf("%d", &nova);

    while (fscanf(arq, "%d %49s %d %f",
                  &p.codigo, p.nome, &p.quantidade, &p.preco) == 4) {

        if (p.codigo == codigo)
            p.quantidade = nova;

        fprintf(temp, "%d %s %d %.2f\n",
                p.codigo, p.nome, p.quantidade, p.preco);
    }

    fclose(arq);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    printf("Arquivo atualizado!\n");
}

void total() {
    FILE *arq = fopen("produtos.txt", "r");
    Produto p;
    float soma = 0;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while (fscanf(arq, "%d %49s %d %f",
                  &p.codigo, p.nome, &p.quantidade, &p.preco) == 4)
        soma += p.quantidade * p.preco;

    fclose(arq);

    printf("Valor total: R$ %.2f\n", soma);
}

int main() {
    int op;

    do {
        printf("\n1 - Listar\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar quantidade\n");
        printf("4 - Valor total\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: listar(); break;
            case 2: consultar(); break;
            case 3: alterar(); break;
            case 4: total(); break;
            case 5: break;
            default: printf("Opcao invalida!\n");
        }

    } while (op != 5);

    return 0;
}