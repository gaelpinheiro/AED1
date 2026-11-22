#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = pilha_cria();

    if (p == NULL) {
        printf("Erro ao criar pilha!\n");
        return 1;
    }

    pilha_push(p, 10.5);
    pilha_push(p, 20.5);
    pilha_push(p, 30.5);
    pilha_push(p, 40.5);

    printf("Pilha criada e preenchida!\n");

    while (!pilha_vazia(p)) {
        printf("Elemento removido: %.1f\n", pilha_pop(p));
    }

    pilha_libera(p);

    printf("Pilha liberada!\n");

    return 0;
}