#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"

int ejecutar_TP1_EJ07() {

    // limito el ingreso entre 1 y 8 ya que es el m�ximo nivel que soluciona mi computadora
    int nivel = solicitarEnteroEntre("Introduce el nivel de la reunion (entre 1 y 8): ", 1, 8);


    // Llamamos a la funci�n recursiva para que me retorne la cadena con la reuni�n
    char *resultado = reunionMafia(nivel);

    // Mostramos la vista generada
    printf("Nivel %d, Vista frontal de la delegaci�n %s\n", nivel, resultado);

    // Liberamos la memoria reservada para la cadena
    free(resultado);

    return 0;
}
