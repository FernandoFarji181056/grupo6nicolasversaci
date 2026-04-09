#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include"tp_1_recursividad.h"



int ejecutar_TP1_EJ01() {
    char palabra[100];

    //pido una palabra
    printf("Ingrese una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);
    //elimino el salto de linea que toma fgets
    palabra[strcspn(palabra, "\n")] = '\0';

    if (palindromo(palabra)) {
        printf("%s es palindromo\n", palabra);
    } else {
        printf("%s no es palindromo\n", palabra);
    }

    return 0;
}
