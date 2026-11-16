#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// 1. Inicializar
void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
}

// 2. Verificar se está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

// 3. Empilhar (PUSH)
void push(Pilha *pilha, int valor) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->dado = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    printf("Elemento inserido!\n");
}

// 4. Desempilhar (POP)
int pop(Pilha *pilha, int *valor) {

    if (estaVazia(pilha)) {
        return 0;
    }

    No *remover = pilha->topo;

    *valor = remover->dado;

    pilha->topo = pilha->topo->proximo;

    free(remover);

    return 1;
}

// 5. Consultar topo (PEEK)
int peek(Pilha *pilha, int *valor) {

    if (estaVazia(pilha)) {
        return 0;
    }

    *valor = pilha->topo->dado;

    return 1;
}

// 6. Exibir elementos
void imprimirPilha(Pilha *pilha) {

    if (estaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    No *atual = pilha->topo;

    printf("\nTOPO\n");

    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

// 7. Contar elementos
int contarElementos(Pilha *pilha) {

    int contador = 0;

    No *atual = pilha->topo;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

// 8. Liberar memória
void liberarPilha(Pilha *pilha) {

    No *atual = pilha->topo;

    while (atual != NULL) {

        No *remover = atual;

        atual = atual->proximo;

        free(remover);
    }

    pilha->topo = NULL;
}