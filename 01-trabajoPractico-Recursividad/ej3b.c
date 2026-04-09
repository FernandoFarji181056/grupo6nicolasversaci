#include <stdio.h>


#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"

// Funci�n recursiva para calcular el termino de Fibonacci del ej 3 del tp recursividad
int terminoSeridFibonacci(int n) {
    // Casos base: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Llamada recursiva: F(n) = F(n-1) + F(n-2)
    return terminoSeridFibonacci(n - 1) + terminoSeridFibonacci(n - 2);
}
