#include <stdio.h>
#include <stdlib.h>

/*Dados los números enteros m y n, construir una función recursiva que devuelva el 
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener 
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta “n” 
cifras decimales (si es necesario), donde “n” es un valor entre 1 a 10 a ingresar como 
precisión de la división.*/

// 🔹 1. División entera (restas sucesivas)
int division_entera(int m, int n, int *resto) {
    // Caso base
    if (m < n) {
        *resto = m;
        return 0;
    }

    return 1 + division_entera(m - n, n, resto);
}

// 🔹 2. Parte decimal
void division_decimal(int resto, int n, int contador, int cant_decimales) {
    // Caso base
    if (resto == 0 || contador == cant_decimales) {
        return;
    }

    resto = resto * 10;

    int digito = 0;
    while (resto >= n) {
        resto -= n;
        digito++;
    }

    printf("%d", digito);

    // Llamada recursiva
    division_decimal(resto, n, contador + 1, cant_decimales);
}

void ejecutar_TP1_EJ04(){
    int m = 22, n = 3;
    int cant_decimales = 5;
    int resto;

    int cociente = division_entera(m, n, &resto);

    printf("%d", cociente);

    if (resto != 0) {
        printf(".");
        division_decimal(resto, n, 0, cant_decimales);
    }
    system("pause");
    //return 0;
}