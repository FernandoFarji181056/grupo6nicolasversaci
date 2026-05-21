#include <stdio.h>
#include"../headers/validaciones.h"

// En este archivo guardo las validaciones necesarias para cada archivo


/*  Esta función la voy a usar para validar ingresos de carga manual
    recibe como parámetros 2 enteros con el minimo y el máximo del rango y un puntero a entero
    retorna lo siguiente: 1: válido; 0: usuario ingresó x; -1: error
*/
int pedirEnteroRango(int min, int max, int* valor) {

    char input[100];

    char extra;

    int numero;

    int valido = 0;

    while (!valido) {

        fgets(input, sizeof(input), stdin);

        // opción salir con x
        if ((input[0] == 'x' || input[0] == 'X') && input[1] == '\n') {

            return 0;
        }

        // validar entero
        if (sscanf(input, "%d %c", &numero, &extra) == 1) {

            // validar rango
            if (numero >= min && numero <= max) {

                *valor = numero;

                valido = 1;

            } else {

                printf("Error: fuera de rango [%d-%d]\n", min,max
                );
            }

        } else {

            printf(
                "Error: ingreso invalido\n"
            );
        }
    }

    return 1;
}


/*  Esta función solicita un ingreso por teclado
    y valida si es un número
    si es afirmativo lo retorna
    si no lo es continua pidiendo ingresos hasta que lo sea
    El parámetro que recibe es el texto que acompaña al ingreso del número
*/

int solicitarEntero(const char *mensaje) {

    char input[100];

    int numero;

    char extra;

    int valido = 0;

    while (!valido) {

        printf("%s", mensaje);

        fgets(input, sizeof(input), stdin);

        // valido que haya un entero
        if (sscanf(input, "%d %c", &numero, &extra) == 1) {

            valido = 1;

        } else {

            printf("Error: debe ingresar un numero entero\n");
        }
    }

    return numero;
}


/*  Esta función utiliza la de solicitarEntero,
    valida que el número buscado esté dentro de un rango
    ademas del texto a mostrar recibe como parametros el valor inicial y final
    si esta dentro del rango lo retorna
    si no lo es continua pidiendo ingresos hasta lo esté
*/
int solicitarEnteroEntre(const char *texto, int inicial, int fnal) {

    int i = solicitarEntero(texto);
    while (i < inicial || i > fnal) {
        printf("Error: El número ingresado debe estar entre %d y %d.\n", inicial, fnal);
        i = solicitarEntero(texto);
    }
    return i;

}
