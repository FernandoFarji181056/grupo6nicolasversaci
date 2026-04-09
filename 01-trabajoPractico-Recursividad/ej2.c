#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"
#include"ej2.h"

//este es el main del tp recursividad ej 2

int ejecutar_TP1_EJ02() {
    int num1 = solicitarEntero("Ingrese el primer numero:");
    int num2 = solicitarEntero("Ingrese el segundo numero");
    printf("Resultado: %d\n", producto(num1, num2));
    return 0;
}
