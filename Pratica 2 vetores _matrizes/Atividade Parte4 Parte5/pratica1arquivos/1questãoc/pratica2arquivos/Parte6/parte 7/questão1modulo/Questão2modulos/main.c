 #include <stdio.h>
#include "conversor.h"
  
   int main() {

    float metros;

      printf("Digite o valor em metros: ");
    scanf("%f", &metros);

    printf(" Centimetros:  %.2f\n", metrosParaCentimetros(metros));
    printf(" Quilometros:   %.2f\n", metrosParaQuilometros(metros));
    printf(" Milimetros:   %.2f\n", metrosParaMilimetros(metros));

     return 0;