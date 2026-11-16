#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha pilha;

    int opcao;
    int valor;

    inicializar(&pilha);

    do {

        printf("\n===== MENU DA PILHA =====\n");

        printf("1 - Empilhar (PUSH)\n");
        printf("2 - Desempilhar (POP)\n");
        printf("3 - Consultar topo (PEEK)\n");
        printf("4 - Verificar se esta vazia\n");
        printf("5 - Exibir elementos\n");
        printf("6 - Contar elementos\n");
        printf("7 - Liberar pilha\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Digite o valor: ");
                scanf("%d", &valor);

                push(&pilha, valor);

                break;

            case 2:

                if (pop(&pilha, &valor)) {
                    printf("Elemento removido: %d\n", valor);
                } else {
                    printf("Pilha vazia!\n");
                }

                break;

            case 3:

                if (peek(&pilha, &valor)) {
                    printf("Elemento do topo: %d\n", valor);
                } else {
                    printf("Pilha vazia!\n");
                }

                break;

            case 4:

                if (estaVazia(&pilha)) {
                    printf("A pilha esta vazia!\n");
                } else {
                    printf("A pilha possui elementos!\n");
                }

                break;

            case 5:

                imprimirPilha(&pilha);

                break;

            case 6:

                printf("Quantidade de elementos: %d\n",
                       contarElementos(&pilha));

                break;

            case 7:

                liberarPilha(&pilha);

                printf("Memoria liberada!\n");

                break;

            case 0:

                printf("Encerrando o programa...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarPilha(&pilha);

    return 0;
}