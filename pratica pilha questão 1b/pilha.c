#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    float dado;
    struct no *proximo;
} No;

struct pilha {
    No *topo;
};

Pilha* pilha_cria(void) {
    Pilha* p = malloc(sizeof(Pilha));

    if (p == NULL) {
        return NULL;
    }

    p->topo = NULL;

    return p;
}

void pilha_push(Pilha* p, float v) {
    if (p == NULL) {
        return;
    }

    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->dado = v;
    novo->proximo = p->topo;

    p->topo = novo;
}

float pilha_pop(Pilha* p) {
    if (p == NULL || pilha_vazia(p)) {
        return 0.0f;
    }

    No* aux = p->topo;

    float valor = aux->dado;

    p->topo = aux->proximo;

    free(aux);

    return valor;
}

int pilha_vazia(Pilha* p) {
    return p == NULL || p->topo == NULL;
}

void pilha_libera(Pilha* p) {
    if (p == NULL) {
        return;
    }

    while (!pilha_vazia(p)) {
        pilha_pop(p);
    }

    free(p);
}