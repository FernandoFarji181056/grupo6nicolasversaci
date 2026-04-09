#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp_1_recursividad.h"

// Funci�n recursiva que devuelve la cadena con el formato requerido
// en el ej 6 del tp recursividad
char * reunionMafia(int nivel) {
    // Caso base: nivel 1, muestra (-.-)
    if (nivel == 1) {
        char *cadena = (char *)malloc(5 * sizeof(char)); // espacio para "(-.-)"
        strcpy(cadena, "(-.-)");
        return cadena;
    } else {
        // Llamada recursiva para obtener el patr�n del nivel anterior
        char *subcadena = reunionMafia(nivel - 1);

        // Calculamos el tama�o necesario para la nueva cadena
        int tamano = strlen(subcadena) + 5; // 5 para "(-.)" y ".-)"
        char *cadena = (char *)malloc(tamano * sizeof(char));

        // Construimos la cadena para el nivel actual
        strcpy(cadena, "(-.");
        strcat(cadena, subcadena); // A�adimos la subcadena recursiva
        strcat(cadena, ".-)");

        // Liberamos la memoria de la subcadena, ya que no la necesitamos m�s
        free(subcadena);

        return cadena;
    }
}
