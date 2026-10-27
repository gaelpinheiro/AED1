#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* cria_aluno(char nome[], int matricula) {
    Aluno* aluno = malloc(sizeof(Aluno));

    if (aluno == NULL)
        return NULL;

    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->num_disciplinas = 0;

    return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno == NULL || disciplina == NULL)
        return;

    if (aluno->num_disciplinas >= 10)
        return;

    for (int i = 0; i < aluno->num_disciplinas; i++) {
        if (aluno->disciplinas[i]->codigo == disciplina->codigo)
            return;
    }

    aluno->disciplinas[aluno->num_disciplinas] = disciplina;
    aluno->num_disciplinas++;
}

void exclui_aluno(Aluno* aluno) {
    free(aluno);
}