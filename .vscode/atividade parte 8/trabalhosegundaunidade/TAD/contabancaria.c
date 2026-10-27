#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

     ContaBancaria* cria_conta(char titular[], int numero, float saldo) {
    ContaBancaria* conta = malloc(sizeof(ContaBancaria));

    if (conta == NULL) return NULL;

    strcpy(conta->titular, titular);
    conta->numero = numero;
    conta->saldo = saldo;

    return conta;
}

   void deposita(ContaBancaria* conta, float valor) {
    if (conta != NULL && valor > 0)
          conta->saldo += valor;
}

   int saca(ContaBancaria* conta, float valor) {
    if (conta == NULL || valor <= 0 || conta->saldo < valor)
        return 0;

    conta->saldo -= valor;
    return 1;
}

  int transfere(ContaBancaria* origem, ContaBancaria* destino, float valor) {
    if (origem == NULL || destino == NULL || valor <= 0 ||
        origem->saldo < valor)
        return 0;

    origem->saldo -= valor;
    destino->saldo += valor;
    return 1;
  }

   float consulta_saldo(ContaBancaria* conta) {
    if (conta == NULL) return -1;
    return conta->saldo;
 }

 void exclui_conta(ContaBancaria* conta) {
    free(conta);
 }