#ifndef FILA_H
#define FILA_H

typedef struct No No;

typedef struct Fila {
    No *inicio;
    No *fim;
} Fila;

/* Inicializa a fila */
void inicializar(Fila *fila);

/* Verifica se a fila está vazia */
int estaVazia(Fila *fila);

/* Insere uma pessoa no final da fila */
int enqueue(Fila *fila, int valor);

/* Remove a primeira pessoa da fila */
int dequeue(Fila *fila, int *valor);

/* Consulta a primeira pessoa */
int front(Fila *fila, int *valor);

/* Consulta a última pessoa */
int back(Fila *fila, int *valor);

/* Exibe todos os elementos */
void imprimirFila(Fila *fila);

/* Conta os elementos */
int contarElementos(Fila *fila);

/* Libera toda a memória */
void liberarFila(Fila *fila);

#endif