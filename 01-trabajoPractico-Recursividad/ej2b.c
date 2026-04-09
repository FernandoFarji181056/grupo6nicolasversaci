#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#include "tp_1_recursividad.h"

// Funci�n recursiva para multiplicar, del tp recursividad ej 2
int producto(int n, int m) {
    // Caso base: cualquier n�mero por 0 es 0
    if (m == 0) {
        return 0;
    }
    // Caso base: cualquier n�mero por 1 es el mismo n�mero
    else if (m == 1) {
        return n;
    }
    // Caso recursivo: n + (n * (m-1))
    else {
        return n + producto(n, m - 1);
    }
}
