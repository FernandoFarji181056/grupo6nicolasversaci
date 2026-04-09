#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "../../tp_1_recursividad.h"
#include"tp_1_recursividad.h"
#include"ej1aux.h"


/*  Funci�n recursiva que recibe como par�metros
    la cadena de texto a determinar y los int de inicio y fin
    retorna true si es palindromo
    y falso si no lo es
*/
bool esPalindromo(char str[], int inicio, int fin) {
    // Caso base: si los �ndices se cruzan, es pal�ndromo
    if (inicio >= fin) {
        return true;
    }

    // Si los caracteres extremos son diferentes, no es palindromo
    if (str[inicio] != str[fin]) {
        return false;
    }

    // Llamada recursiva avanzando el inicio y retrocediendo el fin
    return esPalindromo(str, inicio + 1, fin - 1);
}

// Funci�n del tp recursividad ej 1
bool palindromo(char str[]) {
    int len = strlen(str);
    if (len == 0) return true; // Una cadena vac�a es pal�ndromo
    return esPalindromo(str, 0, len - 1);
}
