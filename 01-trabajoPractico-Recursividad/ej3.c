#include <stdio.h>


#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"

// el ejercicio 3 del tp recursividad
int ejecutar_TP1_EJ03() {
    int inicial = 0;
    int fnal = 40;
    int k = solicitarEnteroEntre("Ingrese el termino a buscar(entre 0 y 40): ", inicial , fnal);

    printf("El %d-esimo numero de Fibonacci es: %d\n", k, terminoSeridFibonacci(k));

    return 0;
}
