
typedef struct No {
    int dado;
    struct No *proximo;
} No;

// Estrutura da pilha
typedef struct Pilha {
    No *topo;
} Pilha;

// Declaração das funções
void inicializar(Pilha *pilha);
int estaVazia(Pilha *pilha);
void push(Pilha *pilha, int valor);
int pop(Pilha *pilha, int *valor);
int peek(Pilha *pilha, int *valor);
void imprimirPilha(Pilha *pilha);
int contarElementos(Pilha *pilha);
void liberarPilha(Pilha *pilha);

