#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    float info;
    struct lista *prox;
} Lista;

Lista* inserirFim(Lista* l, float valor) {
    Lista* novo = malloc(sizeof(Lista));

    novo->info = valor;
    novo->prox = NULL;

    if (l == NULL) {
        return novo;
    }

    Lista* p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }

    p->prox = novo;

    return l;
}

void mostrar(Lista* l) {
    while (l != NULL) {
        printf("%.1f -> ", l->info);
        l = l->prox;
    }

    printf("NULL\n");
}

int maiores(Lista* l, int n) {
    int cont = 0;

    while (l != NULL) {
        if (l->info > n) {
            cont++;
        }
        l = l->prox;
    }

    return cont;
}

Lista* ultimo(Lista* l) {
    if (l == NULL) {
        return NULL;
    }

    while (l->prox != NULL) {
        l = l->prox;
    }

    return l;
}

Lista* contatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) {
        return l2;
    }

    Lista* p = l1;

    while (p->prox != NULL) {
        p = p->prox;
    }

    p->prox = l2;

    return l1;
}

Lista* retira_n(Lista* l, int n) {
    Lista* p;

    while (l != NULL && l->info == n) {
        p = l;
        l = l->prox;
        free(p);
    }

    p = l;

    while (p != NULL && p->prox != NULL) {
        if (p->prox->info == n) {
            Lista* aux = p->prox;
            p->prox = aux->prox;
            free(aux);
        } else {
            p = p->prox;
        }
    }

    return l;
}

int main() {
    Lista* l1 = NULL;
    Lista* l2 = NULL;
    Lista* p;

    l1 = inserirFim(l1, 10);
    l1 = inserirFim(l1, 20);
    l1 = inserirFim(l1, 10);
    l1 = inserirFim(l1, 30);

    l2 = inserirFim(l2, 40);
    l2 = inserirFim(l2, 50);

    printf("Lista 1:\n");
    mostrar(l1);

    printf("\nQuestao 1:\n");
    printf("Maiores que 15: %d\n", maiores(l1, 15));

    printf("\nQuestao 2:\n");
    p = ultimo(l1);

    if (p != NULL) {
        printf("Ultimo valor: %.1f\n", p->info);
    }

    printf("\nQuestao 3:\n");
    l1 = contatena(l1, l2);
    mostrar(l1);

    printf("\nQuestao 4:\n");
    l1 = retira_n(l1, 10);
    mostrar(l1);

    return 0;
}