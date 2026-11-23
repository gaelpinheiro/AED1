#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct No {
    int dado;
    struct No *proximo;
};


void inicializar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int estaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

int enqueue(Fila *fila, int valor) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = valor;
    novo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    return 1;
}

int dequeue(Fila *fila, int *valor) {
    No *aux;

    if (estaVazia(fila)) {
        return 0;
    }

    aux = fila->inicio;
    *valor = aux->dado;

    fila->inicio = aux->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(aux);

    return 1;
}

int front(Fila *fila, int *valor) {
    if (estaVazia(fila)) {
        return 0;
    }

    *valor = fila->inicio->dado;

    return 1;
}

int back(Fila *fila, int *valor) {
    if (estaVazia(fila)) {
        return 0;
    }

    *valor = fila->fim->dado;

    return 1;
}

void imprimirFila(Fila *fila) {
    No *aux = fila->inicio;

    if (estaVazia(fila)) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nPessoas aguardando: ");

    while (aux != NULL) {
        printf("%d", aux->dado);

        if (aux->proximo != NULL) {
            printf(" -> ");
        }

        aux = aux->proximo;
    }

    printf("\n");
}

int contarElementos(Fila *fila) {
    int quantidade = 0;
    No *aux = fila->inicio;

    while (aux != NULL) {
        quantidade++;
        aux = aux->proximo;
    }

    return quantidade;
}

void liberarFila(Fila *fila) {
    No *aux;

    while (fila->inicio != NULL) {
        aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(aux);
    }

    fila->fim =NULL;
}