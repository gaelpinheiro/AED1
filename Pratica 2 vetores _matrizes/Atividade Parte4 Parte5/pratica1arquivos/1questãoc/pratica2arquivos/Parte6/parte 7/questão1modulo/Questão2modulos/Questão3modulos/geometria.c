#include "geometria.h"

float areaCirculo(float raio) {
    return 3.14159 * raio * raio;
}

float areaTriangulo(float base, float altura) {
    return (base * altura) / 2;
}

float areaRetangulo(float base, float altura) {
    return base * altura;
}