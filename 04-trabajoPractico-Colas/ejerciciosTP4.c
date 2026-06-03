#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "../libs/colas/headers/colas.h"
#include "tp_4_colas.h"
#include "../libs/validaciones/headers/validaciones.h"

/*  Esta función pertenece al ejercicio 2
    del TP de colas 
*/

void ejecutar_TP4_EJ02() {

    clearScreen();

    printf("============================================\n");
    printf("           Elegiste el ejercicio 2\n");
    printf("============================================\n");


    printf("\n=====================================\n");
    printf("         FIN DEL EJERCICIO 2\n");
    printf("=====================================\n");

    return;


}

/*  Esta función pertenece al ejercicio 3
    del TP de colas
*/
void ejecutar_TP4_EJ03() {

    clearScreen();


    printf("================================================\n");
    printf("           Elegiste el ejercicio 3\n");
    printf("================================================\n");
    
    printf("EJERCICIO 3 - COMPARAR COLAS\n\n");

    Cola C1 = c_crear();
    Cola C2 = c_crear();

    bool cargaCorrecta;

    cargaCorrecta = cargarColasManual(C1, C2);

    if (cargaCorrecta) {

        printf("\nMOSTRAMOS AMBAS COLAS\n\n");

        printf("Contenido de la primer cola:\n");
        c_mostrar(C1);

        printf("\nContenido de la segunda cola:\n");
        c_mostrar(C2);

        printf("\n");

        bool resultado = c_ej3_iguales(C1, C2);

        if (resultado) {
            printf("LAS COLAS SON IGUALES\n");
        } else {
            printf("LAS COLAS NO SON IGUALES\n");
        }

        printf("\n");
        printf("Complejidad algoritmica: O(n)\n");
        printf("Se recorren ambas colas una sola vez.\n");
    }

    system("pause");
}



// FUNCIONES

bool cargarColasManual(Cola C1, Cola C2) {

    bool salida01 = false;
    bool salida02 = false;

    bool validacion1 = false;
    bool validacion2 = false;

    int entero1;
    int entero2;

    char string1[1000];
    char string2[1000];

    TipoElemento X;

    int min = 1;
    int max = 1000;

    printf("AHORA CARGAREMOS 2 COLAS CON NUMEROS ENTEROS COMPRENDIDOS ENTRE %d Y %d,\n", min, max);
    printf("LAS COLAS NO PUEDEN ESTAR VACIAS,\n");
    printf("LUEGO SE INFORMARA SI LAS COLAS SON IGUALES,\n\n");

    printf("INTRODUZCA NUMEROS ENTEROS PARA CREAR LAS COLAS,\n");
    printf("INGRESE 'x' PARA FINALIZAR LA CARGA\n");


    // CARGA COLA 1

    do {

        printf("\nIngrese un numero entero entre %d y %d para agregar a la primer cola o X para salir: ", min, max);

        fgets(string1, 1000, stdin);

        int longitud1 = strlen(string1);

        string1[longitud1 - 1] = '\0';

        longitud1 = strlen(string1);

        validacion1 = validarEntero(string1);

        if ((string1[0] == 'X' || string1[0] == 'x') && longitud1 == 1) {
            salida01 = true;
        }

        if (validacion1 == false && salida01 == false) {
            printf("La entrada NO fue validada\n");
        }

        if (validacion1) {

            entero1 = (int) strtol(string1, NULL, 10);

            if (entero1 < min || entero1 > max) {

                printf("El numero ingresado no cumple con los requisitos\n");

            } else {

                X = te_crear(entero1);

                c_encolar(C1, X);

                printf("\nContenido actual de la primer cola:\n");
                c_mostrar(C1);
            }
        }

    } while (!salida01);



    // CARGA COLA 2

    printf("\nAHORA CARGAMOS LA SEGUNDA COLA\n");

    do {

        printf("\nIngrese un numero entero entre %d y %d para agregar a la segunda cola o X para salir: ", min, max);

        fgets(string2, 1000, stdin);

        int longitud2 = strlen(string2);

        string2[longitud2 - 1] = '\0';

        longitud2 = strlen(string2);

        validacion2 = validarEntero(string2);

        if ((string2[0] == 'X' || string2[0] == 'x') && longitud2 == 1) {
            salida02 = true;
        }

        if (validacion2 == false && salida02 == false) {
            printf("La entrada NO fue validada\n");
        }

        if (validacion2) {

            entero2 = (int) strtol(string2, NULL, 10);

            if (entero2 < min || entero2 > max) {

                printf("El numero ingresado no cumple con los requisitos\n");

            } else {

                X = te_crear(entero2);

                c_encolar(C2, X);

                printf("\nContenido actual de la segunda cola:\n");
                c_mostrar(C2);
            }
        }

    } while (!salida02);



    if (c_es_vacia(C1) || c_es_vacia(C2)) {

        printf("\nNO PUEDE HABER COLAS VACIAS\n");

        return false;
    }

    return true;
}


    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 3\n");
    printf("=====================================\n");

    return;

}

/*  Esta función pertenece al ejercicio 4
    del TP de colas 
*/
void ejecutar_TP3_EJ04() {

    clearScreen();

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 4\n");
    printf("======================================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 4\n");
    printf("=====================================\n");


    return;

}


/*  Esta función pertenece al ejercicio 5
    del TP de colas
*/
void ejecutar_TP3_EJ05() {

    clearScreen();

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 5\n");
    printf("======================================================\n");


    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 5\n");
    printf("=====================================\n");

    return;

}


void ejecutar_TP3_EJ06() {
    

    printf("Ejercicio 6 \n");

    

    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 5\n");
    printf("=====================================\n");

    return;
}

void ejecutar_TP4_EJ07() {
    

    printf("Ejercicio 7 \n");


    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 7\n");
    printf("=====================================\n");

    return;
}

void ejecutar_TP4_EJ08() {
    

    printf("Ejercicio 8 \n");
    
    
    
    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 8\n");
    printf("=====================================\n");

    return;

}
