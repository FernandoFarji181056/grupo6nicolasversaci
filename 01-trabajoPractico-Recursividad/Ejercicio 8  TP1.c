#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"

void backtrack(int conjunto[], int tamaño, int n, int index,
               int sumaActual, int subset[], int subsetSize,
               char *resultado) {

    // Caso base
    if (sumaActual == n) {
        strcat(resultado, "{");

        for (int i = 0; i < subsetSize; i++) {
            char num[10];
            sprintf(num, "%d", subset[i]);
            strcat(resultado, num);

            if (i < subsetSize - 1)
                strcat(resultado, ",");
        }

        strcat(resultado, "} ");
        return;
    }

    // Cortes
    if (index >= tamano || sumaActual > n)
        return;

    // Incluir elemento
    subset[subsetSize] = conjunto[index];
    backtrack(conjunto, tamano, n, index + 1,
              sumaActual + conjunto[index],
              subset, subsetSize + 1, resultado);

    // No incluir elemento
    backtrack(conjunto, tamano, n, index + 1,
              sumaActual,
              subset, subsetSize, resultado);
}


//Función principal
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {

    int *subset = (int *)malloc(tamano * sizeof(int));
    char *resultado = (char *)malloc(1000 * sizeof(char));

    resultado[0] = '\0'; 

    backtrack(conjunto, tamano, n, 0, 0, subset, 0, resultado);

    *output = resultado;

    free(subset);
}