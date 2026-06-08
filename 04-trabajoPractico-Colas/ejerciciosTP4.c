#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "../libs/colas/headers/colas.h"
#include "tp_4_colas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "colas_auxiliares.h"

/*  Esta función pertenece al ejercicio 2
    del TP de colas 
*/

void ejecutar_TP4_EJ02() {

    clearScreen();

    int min_cola=1;
    int max_cola=1000;

    printf("============================================\n");
    printf("           Elegiste el ejercicio 2\n");
    printf("============================================\n");

    Cola C = cargarColaManual(min_cola, max_cola);

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
void ejecutar_TP4_EJ04() {

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
void ejecutar_TP4_EJ05() {

    clearScreen();

    int min_cola=2;
    int max_cola=1000;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 5\n");
    printf("======================================================\n");
    
    printf("EJERCICIO 5 - DIVISORES TOTALES Y PARCIALES\n\n");

    Cola C = cargarColaManual(min_cola, max_cola);

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

void ejecutar_TP4_EJ06() {

    clearScreen();

    int min = 1;
    int max = 1000;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 6\n");
    printf("========================================================\n");

    printf("EJERCICIO 6 - VALORES COMUNES ENTRE PILA Y COLA\n\n");

    printf("CARGA DE PILA\n");
    Pila p = cargarPilaManual(min, max);

    printf("\nCARGA DE COLA\n");
    Cola c = cargarColaManual(min, max);

    printf("\nPILA:\n");
    p_mostrar(p);

    printf("\nCOLA:\n");
    c_mostrar(c);

    Lista resultado = c_ej6_comunesapilaycola(p, c);

    printf("\nRESULTADO:\n");

    if (l_es_vacia(resultado)) {

        printf("No existen valores comunes.\n");

    } else {

        Iterador it = iterador(resultado);

        while (hay_siguiente(it)) {

            TipoElemento x = siguiente(it);

            printf("%d:%s\n",
                   x->clave,
                   (char*) x->valor);
        }
    }

    printf("\nComplejidad algoritmica: O(n*m)\n");

    system("pause");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 6\n");
    printf("=====================================\n");
}



void ejecutar_TP4_EJ07() {
    clearScreen();

    int min_cola = 1;
    int max_cola = 50;

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 7\n");
    printf("En este ejercicio vas a armar 3 colas de clientes para\n");
    printf("sus respectivas cajas, en cada cliente debes ingresar el\n");
    printf("tiempo que demorara su atención.\n");
    printf("Como hay un solo cajero para las 3 cajas tambien deberas\n");
    printf("ingresar el tiempo que estará en cada caja\n");
    printf("========================================================\n");


    // -------------------------
    // Crear colas
    // -------------------------

    Cola c1 = cargarColaManual(min_cola, max_cola);
    Cola c2 = cargarColaManual(min_cola, max_cola);
    Cola c3 = cargarColaManual(min_cola, max_cola);

    
    int Q = solicitarEnteroEntre("Ingresa el tiempo que estara el cajero en cada caja, entre 5 y 15 minutos: ", 5, 15);

    // -------------------------
    // Ejecutar ejercicio
    // -------------------------

    Cola resultado = c_ej7_atenderclientes(c1, c2, c3, Q);

    // -------------------------
    // Mostrar resultado
    // -------------------------

    printf("\nOrden de atencion:\n\n");

    while (!c_es_vacia(resultado)) {

        TipoElemento x = c_desencolar(resultado);

        printf("%s\n", (char*) x->valor);
    }


    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 7\n");
    printf("=====================================\n");

    return;
}


