#include <stdio.h>
#include "pilha.h"

float topo(Pilha* p) {
    if (p == NULL || pilha_vazia(p)) {
        return 0.0f;
    }

    Pilha* aux = pilha_cria();

    if (aux == NULL) {
        return 0.0f;
    }

    float valor = pilha_pop(p);

    while (!pilha_vazia(p)) {
        float elemento = pilha_pop(p);
        pilha_push(aux, elemento);
    }

    while (!pilha_vazia(aux)) {
        float elemento = pilha_pop(aux);
        pilha_push(p, elemento);
    }

    pilha_push(p, valor);

    pilha_libera(aux);

    return valor;
}

void concatena_pilhas(Pilha* p1, Pilha* p2) {
    if (p1 == NULL || p2 == NULL || p1 == p2) {
        return;
    }

    Pilha* aux = pilha_cria();

    if (aux == NULL) {
        return;
    }

    while (!pilha_vazia(p2)) {
        float elemento = pilha_pop(p2);
        pilha_push(aux, elemento);
    }

    while (!pilha_vazia(aux)) {
        float elemento = pilha_pop(aux);
        pilha_push(p1, elemento);
    }

    pilha_libera(aux);
}

int main() {

    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria();

    if (p1 == NULL || p2 == NULL) {
        printf("Erro ao criar pilhas!\n");
        pilha_libera(p1);
        pilha_libera(p2);
        return 1;
    }

    pilha_push(p1, 1.0);
    pilha_push(p1, 4.5);
    pilha_push(p1, 2.1);

    pilha_push(p2, 9.8);
    pilha_push(p2, 3.1);
    pilha_push(p2, 7.2);

    printf("QUESTAO 2 A - TOPO DA PILHA\n");

    printf("Elemento do topo: %.1f\n", topo(p1));

    printf("\nQUESTAO 2 B - CONCATENACAO\n");

    concatena_pilhas(p1, p2);

    printf("Elementos da pilha P1:\n");

    while (!pilha_vazia(p1)) {
        printf("%.1f\n", pilha_pop(p1));
    }

    printf("Pilha P2 vazia: %s\n",
           pilha_vazia(p2) ? "SIM" : "NAO");

    pilha_libera(p1);
    pilha_libera(p2);

    return 0;
}