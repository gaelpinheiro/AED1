#include <stdio.h>
#include "geometria.h"

int main(void) {

       float raio;
        float baseTriangulo, alturaTriangulo;
       float baseRetangulo, alturaRetangulo;

         printf("Digite o raio do circulo: ");
       scanf("%f", &raio);

      printf("Digite a base do triangulo: ");
      scanf("%f", &baseTriangulo);

    printf("Digite a altura do triangulo: ");
    scanf("%f", &alturaTriangulo);

    printf("Digite a base do retangulo: ");
    scanf("%f", &baseRetangulo);

    printf("Digite a altura do retangulo: ");
    scanf("%f", &alturaRetangulo);

    printf("\nArea do circulo: %.2f\n", areaCirculo(raio));
      printf("Area do triangulo: %.2f\n",
           areaTriangulo(baseTriangulo, alturaTriangulo));
    printf("Area do retangulo: %.2f\n",
           areaRetangulo(baseRetangulo, alturaRetangulo));

    return 0;
}