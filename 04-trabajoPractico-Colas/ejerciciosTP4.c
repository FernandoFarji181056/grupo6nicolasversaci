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

    int min_pila = 1;
    int max_pila = 1000;
    
    printf("================================================\n");
    printf("           Elegiste el ejercicio 3\n");
    printf("================================================\n");
    
    printf("EJERCICIO 3 - COMPARAR COLAS\n\n");

    Cola C1 = cargarColaManual( min_pila, max_pila);

    printf("\n");

    Cola C2 = cargarColaManual(1, 1000);

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

    system("pause");
 
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

    int min_pila= 1;
    int max_pila=1000;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 4\n");
    printf("======================================================\n");
    
    printf("EJERCICIO 4 - ELEMENTOS NO REPETIDOS EN UNA COLA\n\n");

    Cola C = cargarColaManual(min_pila, max_pila);

    printf("\nCOLA ORIGINAL:\n");
    c_mostrar(C);

    Cola resultado = c_ej4_colanorepetidos(C);

    printf("\nCOLA CON ELEMENTOS NO REPETIDOS:\n");
    c_mostrar(resultado);

    printf("\nVERIFICAMOS QUE LA COLA ORIGINAL NO FUE MODIFICADA:\n");
    c_mostrar(C);

    printf("\n");
    printf("Complejidad algoritmica: O(n^2)\n");
    printf("Para cada elemento de la cola se recorre nuevamente toda la cola.\n");

    system("pause");
    
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
