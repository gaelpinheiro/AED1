#include <stdio.h>
#include "contabancaria.h"

int main(void) {
     ContaBancaria* conta1 = cria_conta("Ana", 101, 500);
    ContaBancaria* conta2 = cria_conta("Joao", 102, 200);

    if (conta1 == NULL || conta2 == NULL) {
        exclui_conta(conta1);
        exclui_conta(conta2);
        return 1;
    }

    deposita(conta1, 100);

    if (transfere(conta1, conta2, 150))
        printf("Transferencia realizada!\n");
    else
        printf("Saldo insuficiente!\n");

    printf("Saldo Ana: %.2f\n", consulta_saldo(conta1));
    printf("Saldo Joao: %.2f\n", consulta_saldo(conta2));

    exclui_conta(conta1);
    exclui_conta(conta2);

     return 0;
}