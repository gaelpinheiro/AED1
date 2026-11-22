#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define CAPACIDADE_INICIAL 2

struct pilha {
    float *dados;
    int topo;
    int capacidade;
};

Pilha* pilha_cria(void) {
    Pilha* p = malloc(sizeof(Pilha));

    if (p == NULL) {
        return NULL;
    }

    p->dados = malloc(CAPACIDADE_INICIAL * sizeof(float));

    if (p->dados == NULL) {
        free(p);
        return NULL;
    }

    p->topo = -1;
    p->capacidade = CAPACIDADE_INICIAL;

    return p;
}

void pilha_push(Pilha* p, float v) {
    if (p == NULL) {
        return;
    }

    if (p->topo + 1 == p->capacidade) {
        int novaCapacidade = p->capacidade * 2;

        float* novo = realloc(
            p->dados,
            novaCapacidade * sizeof(float)
        );

        if (novo == NULL) {
            return;
        }

        p->dados = novo;
        p->capacidade = novaCapacidade;
    }

    p->topo++;
    p->dados[p->topo] = v;
}

float pilha_pop(Pilha* p) {
    if (p == NULL || pilha_vazia(p)) {
        return 0.0f;
    }

    float valor = p->dados[p->topo];

    p->topo--;

    return valor;
}

int pilha_vazia(Pilha* p) {
    return p == NULL || p->topo == -1;
}

void pilha_libera(Pilha* p) {
    if (p != NULL) {
        free(p->dados);
        free(p);
    }
}