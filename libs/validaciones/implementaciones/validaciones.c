#include <stdio.h>
#include"../headers/validaciones.h"

// En este archivo guardo las validaciones necesarias para cada archivo


/*  Esta función solicita un ingreso por teclado
    y valida si es un número
    si es afirmativo lo retorna
    si no lo es continua pidiendo ingresos hasta que lo sea
    El parámetro que recibe es el texto que acompaña al ingreso del número
*/
int solicitarEntero(char *texto) {
    int numero;
    int estado;

    do {
        printf("%s\n", texto);
        estado = scanf("%d", &numero);

        // Si scanf no devuelve 1, no se ingresó un entero
        if (estado != 1) {
            printf("Error: Entrada no válida.\n");
            // Limpiar el búfer de entrada para evitar bucles infinitos
            while (getchar() != '\n');
        }
    } while (estado != 1); // Continuar hasta que la entrada sea válida

    return numero;
}


/*  Esta función utiliza la de solicitarEntero,
    valida que el número buscado esté dentro de un rango
    ademas del texto a mostrar recibe como parametros el valor inicial y final
    si esta dentro del rango lo retorna
    si no lo es continua pidiendo ingresos hasta lo esté
*/
int solicitarEnteroEntre(char *texto, int inicial, int fnal) {

    int i = solicitarEntero(texto);
    while (i < inicial || i > fnal) {
        printf("Error: El número ingresado debe estar entre %d y %d.\n", inicial, fnal);
        i = solicitarEntero(texto);
    };
    return i;

}
