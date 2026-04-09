#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char numero[] = "12345678";

    agregarSeparadorMiles(numero);
    system("pause");
    //return 0;
}