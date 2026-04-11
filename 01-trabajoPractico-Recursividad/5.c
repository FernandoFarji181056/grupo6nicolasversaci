#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*5.	Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de números.*/

// Valida si el string contiene solo números
int esNumero(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void agregarSeparadorMiles(char str[]) {
    int len = strlen(str);

    // 🟢 Caso base
    if (len <= 3) {
        printf("%s", str);
        return;
    }

    // Separar
    char izquierda[100];
    char ultimos[4];

    // copiar izquierda (todo menos últimos 3)
    strncpy(izquierda, str, len - 3);
    izquierda[len - 3] = '\0';

    // copiar últimos 3
    strcpy(ultimos, str + len - 3);

    // 🔁 Recursión
    agregarSeparadorMiles(izquierda);

    // agregar punto + últimos
    printf(".%s", ultimos);
}

void ejecutar_TP1_EJ05(){
    char numero[100];

    printf("Ingrese un numero: ");
    scanf("%s", numero);

    // Validación
    while (!esNumero(numero)) {
        printf("Error. Ingrese solo numeros: ");
        scanf("%s", numero);
    }

    agregarSeparadorMiles(numero);
    printf("\n");

    system("pause");
    //return 0;
}
