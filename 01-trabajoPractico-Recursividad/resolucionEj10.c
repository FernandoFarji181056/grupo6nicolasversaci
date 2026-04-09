#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//Ejercicio 10
/*
10.  Se dice que N es un número explosivo cuando éste explota en varios fragmentos más 
chicos que él, dada una bomba B. Si se tiene que N es el número y B la bomba, tales 
que N es mayor que B, se puede hacer que N explote en dos números N1 = N / B 
(división entera) y N2 = N - (N / B). 
Pero B es una bomba que produce una reacción en cadena, si N1 o N2 son mayores que 
B, estos también explotan con la regla anterior, hasta que se encuentre que el número 
no es mayor que B; entonces se dice que ya no se puede explotar el número. 
Escribe una función recursiva que retorne una lista con los pedazos del número N, 
dado que se tiene la bomba B.

Ejemplos: 
Número: 10 
Bomba: 3 
explosion(10, 3) => [3 2 1 1 3] 
Número: 20 
Bomba: 5 
explosion(20, 5) => [4 3 2 2 1 1 1 1 5]

NOTA: Se utilizará el valor -1 como entero que indica el final del arreglo devuelto por la función.
*/


int* explosion (int n, int b){
    int* arreglo;
    
    // CASO BASE: si n no es mayor que b
        if (n <= b) {
        arreglo = (int*)malloc(2 * sizeof(int));
        arreglo[0] = n;
        arreglo[1] = -1;
        return arreglo;
    }
    // CASO RECURSIVO: n > b
    int n1 = n / b;      // división entera
    int n2 = n - n1;

    // Obtener los fragmentos de n1 y n2 recursivamente
    int* fragmentosN1 = explosion(n1, b);
    int* fragmentosN2 = explosion(n2, b);

    // Contar cuántos elementos tiene fragmentosN1
    int contadorN1 = 0;
    while (fragmentosN1[contadorN1] != -1) {
        contadorN1++;
    }

    // Contar cuántos elementos tiene fragmentosN2
    int contadorN2 = 0;
    while (fragmentosN2[contadorN2] != -1) {
        contadorN2++;
    }

    // Crear nuevo arreglo: fragmentosN1 + fragmentosN2
    arreglo = (int*)malloc((contadorN1 + contadorN2 + 1) * sizeof(int));

    // Copiar fragmentosN1
    for (int i = 0; i < contadorN1; i++) {
        arreglo[i] = fragmentosN1[i];
    }
    
    // Copiar fragmentosN2
    for (int i = 0; i < contadorN2; i++) {
        arreglo[contadorN1 + i] = fragmentosN2[i];
    }
    // Agregar el -1 al final
    arreglo[contadorN1 + contadorN2] = -1;

    // Liberar memoria de los arreglos temporales
    free(fragmentosN1);
    free(fragmentosN2);

    return arreglo;

}