#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main(void) {
    Disciplina* d1 = cria_disciplina("Algoritmos", 101);
    Disciplina* d2 = cria_disciplina("Calculo", 102);

    Aluno* a1 = cria_aluno("joao", 2026001);

    if (d1 == NULL || d2 == NULL || a1 == NULL) {
        exclui_disciplina(d1);
        exclui_disciplina(d2);
        exclui_aluno(a1);
        return 1;
    }

    matricula_disciplina(a1, d1);
    matricula_disciplina(a1, d2);

    printf("Aluno: %s\n", a1->nome);
    printf("Matricula: %d\n", a1->matricula);

    printf("Disciplinas matriculadas:\n");

    for (int i = 0; i < a1->num_disciplinas; i++) {
        printf("%s - Codigo: %d\n",
               a1->disciplinas[i]->nome,
               a1->disciplinas[i]->codigo);
    }

    exclui_aluno(a1);
    exclui_disciplina(d1);
    exclui_disciplina(d2);

    return 0;
}