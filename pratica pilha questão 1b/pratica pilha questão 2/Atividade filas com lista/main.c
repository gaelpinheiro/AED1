#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main() {
    Fila fila;
    int opcao;
    int valor;

    inicializar(&fila);

    do {
        printf("\n=================================\n");
        printf("     SISTEMA DE ATENDIMENTO\n");
        printf("=================================\n");
        printf("1 - Adicionar pessoa\n");
        printf("2 - Chamar proxima pessoa\n");
        printf("3 - Consultar proxima pessoa\n");
        printf("4 - Consultar ultima pessoa\n");
        printf("5 - Exibir fila\n");
        printf("6 - Verificar se esta vazia\n");
        printf("7 - Quantidade de pessoas\n");
        printf("8 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Digite a senha da pessoa: ");
                scanf("%d", &valor);

                if (enqueue(&fila, valor)) {
                    printf("Pessoa %d adicionada com sucesso!\n",
                           valor);
                } else {
                    printf("Erro ao adicionar pessoa.\n");
                }
                break;

            case 2:
                if (dequeue(&fila, &valor)) {
                    printf("Pessoa %d foi chamada.\n", valor);
                } else {
                    printf("A fila esta vazia.\n");
                }
                break;

            case 3:
                if (front(&fila, &valor)) {
                    printf("Proxima pessoa: %d\n", valor);
                } else {
                    printf("A fila esta vazia.\n");
                }
                break;

            case 4:
                if (back(&fila, &valor)) {
                    printf("Ultima pessoa: %d\n", valor);
                } else {
                    printf("A fila esta vazia.\n");
                }
                break;

            case 5:
                imprimirFila(&fila);
                break;

            case 6:
                if (estaVazia(&fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;

            case 7:
                printf("Quantidade de pessoas: %d\n",
                       contarElementos(&fila));
                break;

            case 8:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 8);

    liberarFila(&fila);

    return 0;
}