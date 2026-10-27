#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

Disciplina* cria_disciplina(char nome[], int codigo) {
    Disciplina* disciplina = malloc(sizeof(Disciplina));

    if (disciplina == NULL)
        return NULL;

    strcpy(disciplina->nome, nome);
    disciplina->codigo = codigo;

    return disciplina;
}

void exclui_disciplina(Disciplina* disciplina) {
    free(disciplina);
}