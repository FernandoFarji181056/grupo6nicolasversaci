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

    Cola C = cargarColaManual(1, 1000);

    int opcion;
    int clave;
    int posicion;

    TipoElemento X;

    do {

        printf("\n");
        printf("EJERCICIO 2 - OPERACIONES CON COLAS\n\n");

        printf("1 - Buscar elemento\n");
        printf("2 - Insertar elemento en posicion\n");
        printf("3 - Eliminar elemento\n");
        printf("4 - Contar elementos\n");
        printf("5 - Copiar cola\n");
        printf("6 - Invertir cola\n");
        printf("0 - Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:

                printf("Ingrese clave a buscar: ");
                scanf("%d", &clave);

                if (c_ej2_existeclave(C, clave)) {

                    printf("La clave SI existe en la cola\n");

                } else {

                    printf("La clave NO existe en la cola\n");
                }

                break;

            case 2:

                printf("Ingrese posicion ordinal: ");
                scanf("%d", &posicion);

                printf("Ingrese elemento a insertar: ");
                scanf("%d", &clave);

                X = te_crear(clave);

                c_ej2_colarelemento(C, posicion, X);

                printf("Cola actualizada:\n");
                c_mostrar(C);

                break;

            case 3:

                printf("Ingrese clave a eliminar: ");
                scanf("%d", &clave);

                c_ej2_sacarelemento(C, clave);

                printf("Cola actualizada:\n");
                c_mostrar(C);

                break;

            case 4:

                printf("Cantidad de elementos: %d\n",
                       c_ej2_contarelementos(C));

                break;

            case 5: {

                Cola copia = c_ej2_copiar(C);

                printf("Copia de la cola:\n");

                c_mostrar(copia);

                break;
            }

            case 6: {

                Cola invertida = c_ej2_invertir(C);

                printf("Cola invertida:\n");

                c_mostrar(invertida);

                break;
            }

            case 0:

                printf("Saliendo...\n");

                break;

            default:

                printf("Opcion invalida\n");
        }

    } while (opcion != 0);

    printf("\nComplejidades:\n");
    printf("- Buscar elemento: O(n)\n");
    printf("- Insertar elemento: O(n)\n");
    printf("- Eliminar elemento: O(n)\n");
    printf("- Contar elementos: O(n)\n");
    printf("- Copiar cola: O(n)\n");
    printf("- Invertir cola: O(n)\n");

    system("pause");
    
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

    int min_cola = 1;
    int max_cola = 1000;
    
    printf("================================================\n");
    printf("           Elegiste el ejercicio 3\n");
    printf("================================================\n");
    
    printf("EJERCICIO 3 - COMPARAR COLAS\n\n");

    Cola C1 = cargarColaManual( min_cola, max_cola);

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

    int min_cola= 1;
    int max_cola=1000;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 4\n");
    printf("======================================================\n");
    
    printf("EJERCICIO 4 - ELEMENTOS NO REPETIDOS EN UNA COLA\n\n");

    Cola C = cargarColaManual(min_cola, max_cola);

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

    int min_cola=2;
    int max_cola=1000;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 5\n");
    printf("======================================================\n");
    
    printf("EJERCICIO 5 - DIVISORES TOTALES Y PARCIALES\n\n");

    Cola C = cargarColaManual(2, 1000);

    printf("\nCOLA ORIGINAL:\n");
    c_mostrar(C);

    Cola resultado = c_ej5_divisortotal(C);

    printf("\nDIVISORES ENCONTRADOS:\n\n");

    while (!c_es_vacia(resultado)) {

        TipoElemento x = c_desencolar(resultado);

        bool esTotal = *((bool*) x->valor);

        if (esTotal) {

            printf("%d -> DIVISOR TOTAL\n", x->clave);

        } else {

            printf("%d -> DIVISOR PARCIAL\n", x->clave);
        }
    }

    printf("\nVERIFICAMOS QUE LA COLA ORIGINAL NO FUE MODIFICADA:\n");
    c_mostrar(C);

    printf("\n");
    printf("Complejidad algoritmica: O(n^2)\n");
    printf("Para cada elemento de la cola se recorre nuevamente toda la cola.\n");

    system("pause");
    
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
