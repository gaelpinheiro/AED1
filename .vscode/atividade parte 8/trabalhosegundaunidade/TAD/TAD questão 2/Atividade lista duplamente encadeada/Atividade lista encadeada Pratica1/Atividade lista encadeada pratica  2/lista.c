#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct lista2 {
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
} Lista2;

Lista2* lst2_cria(void) {
    return NULL;
}

void lst2_libera(Lista2* l) {
    Lista2 *p = l;

    while (p != NULL) {
        Lista2 *t = p->prox;
        free(p);
        p = t;
    }
}

Lista2* lst2_insere(Lista2* l, int v) {
    Lista2 *novo = malloc(sizeof(Lista2));

    if (novo == NULL)
        return l;

    novo->info = v;
    novo->ant = NULL;
    novo->prox = l;

    if (l != NULL)
        l->ant = novo;

    return novo;
}

Lista2* lst2_retira(Lista2* l, int v) {
    Lista2 *p = l;

    while (p != NULL && p->info != v)
        p = p->prox;

    if (p == NULL)
        return l;

    if (p->ant != NULL)
        p->ant->prox = p->prox;
    else
        l = p->prox;

    if (p->prox != NULL)
        p->prox->ant = p->ant;

    free(p);

    return l;
}

int lst2_vazia(Lista2* l) {
    return l == NULL;
}

Lista2* lst2_busca(Lista2* l, int v) {
    Lista2 *p = l;

    while (p != NULL) {
        if (p->info == v)
            return p;

        p = p->prox;
    }

    return NULL;
}

void lst2_imprime(Lista2* l) {
    Lista2 *p = l;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }

    printf("\n");
}

   
typedef struct NoCirc {
    int info;
    struct NoCirc *prox;
} NoCirc;

typedef struct ListaCirc {
    NoCirc *inicio;
} ListaCirc;

void lcirc_imprime(ListaCirc* l) {
    if (l == NULL || l->inicio == NULL)
        return;

    NoCirc *p = l->inicio;

    do {
        printf("%d ", p->info);
        p = p->prox;
    } while (p != l->inicio);

    printf("\n");
}
   QUESTOES 3 E 4 - LISTA CIRCULAR DUPLA
   

typedef struct No2Circ {
    int info;
    struct No2Circ *ant;
    struct No2Circ *prox;
} No2Circ;

typedef struct Lista2Circ {
    No2Circ *inicio;
} Lista2Circ;

void l2circ_imprime_rev(Lista2Circ* l) {
    if (l == NULL || l->inicio == NULL)
        return;

    No2Circ *p = l->inicio->ant;

    do {
        printf("%d ", p->info);
        p = p->ant;
    } while (p != l->inicio->ant);

    printf("\n");
}

void l2circ_insere(Lista2Circ* l, int v) {
    No2Circ *novo = malloc(sizeof(No2Circ));

    if (novo == NULL)
        return;

    novo->info = v;

    if (l->inicio == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
    } else {
        No2Circ *ultimo = l->inicio->ant;

        novo->prox = l->inicio;
        novo->ant = ultimo;

        ultimo->prox = novo;
        l->inicio->ant = novo;
    }
}


/* QUESTAO 4 - RETIRAR ELEMENTO */

void l2circ_retira(Lista2Circ* l, int v) {
    if (l == NULL || l->inicio == NULL)
        return;

    No2Circ *p = l->inicio;

    do {
        if (p->info == v) {

            if (p->prox == p) {
                l->inicio = NULL;
            } else {
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;

                if (p == l->inicio)
                    l->inicio = p->prox;
            }

            free(p);
            return;
        }

        p = p->prox;

    } while (p != l->inicio);
}

   QUESTAO 5 - LISTA DE FUNCIONARIOS
   

typedef struct funcionario {
    char depto;
    int mat;
    char nome[81];
    float salario;
} Funcionario;

typedef struct ListaFunc {
    Funcionario info;
    struct ListaFunc *prox;
} ListaFunc;


float lstfunc_folha_pagto(ListaFunc* l, char depto) {
    float total = 0;

    ListaFunc *p = l;

    while (p != NULL) {
        if (p->info.depto == depto)
            total += p->info.salario;

        p = p->prox;
    }

    return total;
}

#define PI 3.14159265358979323846

typedef struct {
    float b;
    float h;
} Retangulo;

typedef struct {
    float b;
    float h;
} Triangulo;

typedef struct {
    float r;
} Circulo;


typedef enum {
    RETANGULO,
    TRIANGULO,
    CIRCULO
} TipoObjeto;


typedef struct ListaHet {
    TipoObjeto tipo;

    union {
        Retangulo ret;
        Triangulo tri;
        Circulo circ;
    } objeto;

    struct ListaHet *prox;
} ListaHet;


/* CALCULAR AREA DO RETANGULO */

static float ret_area(Retangulo* r) {
    return r->b * r->h;
}


/* CALCULAR AREA DO TRIANGULO */

static float tri_area(Triangulo* t) {
    return (t->b * t->h) / 2;
}

/* CALCULAR AREA DO CIRCULO */

static float circ_area(Circulo* c) {
    return PI * c->r * c->r;
}

/* CRIAR RETANGULO */

ListaHet* cria_ret(float b, float h) {
    ListaHet *novo = malloc(sizeof(ListaHet));

    if (novo == NULL)
        return NULL;

    novo->tipo = RETANGULO;
    novo->objeto.ret.b = b;
    novo->objeto.ret.h = h;
    novo->prox = NULL;

    return novo;
}

ListaHet* cria_tri(float b, float h) {
    ListaHet *novo = malloc(sizeof(ListaHet));

    if (novo == NULL)
        return NULL;

    novo->tipo = TRIANGULO;
    novo->objeto.tri.b = b;
    novo->objeto.tri.h = h;
    novo->prox = NULL;

    return novo;
}

ListaHet* cria_circ(float r) {
    ListaHet *novo = malloc(sizeof(ListaHet));

    if (novo == NULL)
        return NULL;

    novo->tipo = CIRCULO;
    novo->objeto.circ.r = r;
    novo->prox = NULL;

    return novo;
}

static float area(ListaHet* p) {
    if (p->tipo == RETANGULO)
        return ret_area(&p->objeto.ret);

    if (p->tipo == TRIANGULO)
        return tri_area(&p->objeto.tri);

    if (p->tipo == CIRCULO)
        return circ_area(&p->objeto.circ);

    return 0;
}


float max_area(ListaHet* l) {
    if (l == NULL)
        return 0;

    float maior = area(l);

    ListaHet *p = l->prox;

    while (p != NULL) {
        float atual = area(p);

        if (atual > maior)
            maior = atual;

        p = p->prox;
    }

    return maior;
}

void adicionar_funcionario(ListaFunc **l, char depto,
                           int mat, char nome[], float salario) {
    ListaFunc *novo = malloc(sizeof(ListaFunc));

    if (novo == NULL)
        return;

    novo->info.depto = depto;
    novo->info.mat = mat;
    strcpy(novo->info.nome, nome);
    novo->info.salario = salario;

    novo->prox = *l;
    *l = novo;
}

void adicionar_objeto(ListaHet **l, ListaHet *novo) {
    if (novo == NULL)
        return;

    if (*l == NULL) {
        *l = novo;
        return;
    }

    ListaHet *p = *l;

    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;
}

int main(void) {

    /* QUESTAO 1 */

    printf("\nQUESTAO 1 - LISTA DUPLA\n");

    Lista2 *l = lst2_cria();

    l = lst2_insere(l, 10);
    l = lst2_insere(l, 20);
    l = lst2_insere(l, 30);

    lst2_imprime(l);

    printf("Busca 20: %s\n",
           lst2_busca(l, 20) != NULL ? "Encontrado" : "Nao encontrado");

    l = lst2_retira(l, 20);

    printf("Depois da remocao: ");
    lst2_imprime(l);

    printf("Lista vazia: %d\n", lst2_vazia(l));

    lst2_libera(l);


    printf("\nQUESTAO 2 - LISTA CIRCULAR SIMPLES\n");

    NoCirc n1 = {10, NULL};
    NoCirc n2 = {20, NULL};
    NoCirc n3 = {30, NULL};

    n1.prox = &n2;
    n2.prox = &n3;
    n3.prox = &n1;

    ListaCirc lc = {&n1};

    lcirc_imprime(&lc);


    printf("\nQUESTOES 3 E 4 - LISTA CIRCULAR DUPLA\n");

    Lista2Circ ld = {NULL};

    l2circ_insere(&ld, 10);
    l2circ_insere(&ld, 20);
    l2circ_insere(&ld, 30);

    printf("Ordem reversa: ");
    l2circ_imprime_rev(&ld);

    l2circ_retira(&ld, 20);

    printf("Depois de retirar 20: ");
    l2circ_imprime_rev(&ld);


    /* QUESTAO 5 */

    printf("\nQUESTAO 5 - FUNCIONARIOS\n");

    ListaFunc *lf = NULL;

    adicionar_funcionario(&lf, 'A', 1, "Ana", 2000);
    adicionar_funcionario(&lf, 'B', 2, "Joao", 3000);
    adicionar_funcionario(&lf, 'A', 3, "Maria", 2500);

    printf("Folha do departamento A: R$ %.2f\n",
           lstfunc_folha_pagto(lf, 'A'));


    /* QUESTAO 6 */

    printf("\nQUESTAO 6 - OBJETOS GEOMETRICOS\n");

    ListaHet *lh = NULL;

    adicionar_objeto(&lh, cria_ret(10, 5));
    adicionar_objeto(&lh, cria_tri(10, 6));
    adicionar_objeto(&lh, cria_circ(3));

    printf("Maior area: %.2f\n", max_area(lh));


    /* LIBERAR MEMORIA */

    while (ld.inicio != NULL)
        l2circ_retira(&ld, ld.inicio->info);

    while (lf != NULL) {
        ListaFunc *temp = lf;
        lf = lf->prox;
        free(temp);
    }

    while (lh != NULL) {
        ListaHet *temp = lh;
        lh = lh->prox;
        free(temp);
    }

    return 0;
}