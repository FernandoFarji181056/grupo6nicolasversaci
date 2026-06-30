#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "../libs/conjuntos/headers/conjuntos.h"
#include "tp_5_conjuntos.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/listas/headers/listas.h"
#include "conjuntos_auxiliares.h"


void ejecutar_TP5_EJ02() {

    clearScreen();

    int opcion;

    do{

        printf("=====================================\n");
        printf("          EJERCICIO 2\n");
        printf("=====================================\n\n");

        printf("Este ejercicio verifica las operaciones\n");
        printf("entre dos conjuntos numericos.\n\n");

        printf("1 - Union\n");
        printf("2 - Interseccion\n");
        printf("3 - Diferencia\n");
        //printf("4 - Pertenencia\n");
        printf("4 - Pertenencia entre dos conjuntos\n");
        printf("5 - Pertenencia de numero a conjunto\n");
        printf("0 - Volver\n\n");

        opcion = solicitarEnteroEntre("Ingrese una opcion: ",0,4);

        clearScreen();

        switch(opcion){

        case 1:{

            Conjunto A = cto_crear();
            Conjunto B = cto_crear();

            printf("CARGA DEL CONJUNTO A\n\n");
            cargarConjunto(A);

            printf("\nCARGA DEL CONJUNTO B\n\n");
            cargarConjunto(B);

            Conjunto U = c_ej2_union(A,B);

            printf("\nCONJUNTO A\n");
            cto_mostrar(A);

            printf("\nCONJUNTO B\n");
            cto_mostrar(B);

            printf("\nUNION\n");
            cto_mostrar(U);

            system("pause");
            clearScreen();
            break;
        }

        case 2:{

            Conjunto A = cto_crear();
            Conjunto B = cto_crear();

            printf("CARGA DEL CONJUNTO A\n\n");
            cargarConjunto(A);

            printf("\nCARGA DEL CONJUNTO B\n\n");
            cargarConjunto(B);

            Conjunto I = c_ej2_interseccion(A,B);

            printf("\nCONJUNTO A\n");
            cto_mostrar(A);

            printf("\nCONJUNTO B\n");
            cto_mostrar(B);

            printf("\nINTERSECCION\n");
            cto_mostrar(I);

            system("pause");
            clearScreen();
            break;
        }

        case 3:{

            Conjunto A = cto_crear();
            Conjunto B = cto_crear();

            printf("CARGA DEL CONJUNTO A\n\n");
            cargarConjunto(A);

            printf("\nCARGA DEL CONJUNTO B\n\n");
            cargarConjunto(B);

            Conjunto D = c_ej2_diferencia(A,B);

            printf("\nCONJUNTO A\n");
            cto_mostrar(A);

            printf("\nCONJUNTO B\n");
            cto_mostrar(B);

            printf("\nDIFERENCIA (A-B)\n");
            cto_mostrar(D);

            system("pause");
            clearScreen();
            break;
        }

        case 4:{

            Conjunto A = cto_crear();
            Conjunto B = cto_crear();

            printf("CARGA DEL CONJUNTO A\n\n");
            cargarConjunto(A);

            printf("\nCARGA DEL CONJUNTO B\n\n");
            cargarConjunto(B);

            Conjunto P = c_ej2_pertenencia(A,B);

            printf("\nCONJUNTO A\n");
            cto_mostrar(A);

            printf("\nCONJUNTO B\n");
            cto_mostrar(B);

            printf("\nELEMENTOS DE A QUE PERTENECEN A B\n");
            cto_mostrar(P);

            system("pause");
            clearScreen();
            break;
        }
        case 5: {
            Conjunto A = cto_crear();

            printf("Carga del conjunto:\n\n");
            cargarConjunto(A);

            int clave = solicitarEntero("\n\nAhora ingrese el numero a buscar: ");

            if (c_ej2_pertenece(A, clave)){
                printf("\n\n La clave %d esta en el conjunto.\n", clave);
            } else {
                printf("\n\n La clave %d no esta en el conjunto.\n", clave);
            }
            system("pause");
            clearScreen();
            break;
        }

        }

    } while(opcion != 0);
 
  printf("\nComplejidad aproximada:\n");
    printf("Union: O(n+m)\n");
    printf("Interseccion: O(n*m)\n");
    printf("Diferencia: O(n*m)\n");
    //printf("Pertenencia: O(n*m)\n");
    printf("Pertenencia entre conjuntos: O(n*m)\n");
    printf("Pertenencia de numero a conjunto: O(1)\n");

    system("pause");
}

void ejecutar_TP5_EJ03(){

    clearScreen();

    Lista coleccion = l_crear();

    int cantidad = solicitarEnteroEntre(
        "Ingrese la cantidad de conjuntos: ",2,20);

    for(int i=1 ; i<=cantidad ; i++){

        printf("\n===================================\n");
        printf("CARGA DEL CONJUNTO %d\n",i);

        Conjunto C = cto_crear();

        cargarConjunto(C);

        TipoElemento X = te_crear_con_valor(i,C);

        l_agregar(coleccion,X);
    }

    int opcion;

    do{

        clearScreen();

        printf("===================================\n");
        printf("          EJERCICIO 3\n");
        printf("===================================\n\n");

        printf("1 - Union de la coleccion\n");
        printf("2 - Interseccion de la coleccion\n");
        printf("0 - Salir\n\n");

        opcion = solicitarEnteroEntre("Ingrese una opcion: ",0,2);

        switch(opcion){

        case 1:{

            Conjunto U = c_ej3_uniones(coleccion);

            printf("\nRESULTADO DE LA UNION\n\n");

            cto_mostrar(U);

            printf("\nComplejidad algoritmica: O(k*n)\n");
            printf("Se recorren los k conjuntos realizando la union.\n");

            system("pause");
            break;
        }

        case 2:{

            Conjunto I = c_ej3_intersecciones(coleccion);

            printf("\nRESULTADO DE LA INTERSECCION\n\n");

            cto_mostrar(I);

            printf("\nComplejidad algoritmica: O(k*n)\n");
            printf("Se recorren los k conjuntos realizando la interseccion.\n");

            system("pause");
            break;
        }

        }

    }while(opcion!=0);

}

void ejecutar_TP5_EJ04(){

    clearScreen();

    printf("=====================================\n");
    printf("          EJERCICIO 4\n");
    printf("=====================================\n\n");

    printf("Se verificara la propiedad de transitividad\n");
    printf("entre tres conjuntos.\n\n");

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();

    printf("CARGA DEL CONJUNTO A\n");
    cargarConjunto(A);

    printf("\nCARGA DEL CONJUNTO B\n");
    cargarConjunto(B);

    printf("\nCARGA DEL CONJUNTO C\n");
    cargarConjunto(C);

    clearScreen();

    printf("CONJUNTO A\n");
    cto_mostrar(A);

    printf("\nCONJUNTO B\n");
    cto_mostrar(B);

    printf("\nCONJUNTO C\n");
    cto_mostrar(C);

    printf("\n");

    if(c_ej4_transitividad(A,B,C)){
        printf("Se verifica la propiedad de transitividad.\n");
        printf("A es subconjunto de B.\n");
        printf("B es subconjunto de C.\n");
        printf("Por lo tanto A es subconjunto de C.\n");
    }
    else{
        printf("No se verifica la propiedad de transitividad.\n");
    }

    printf("\nComplejidad algoritmica: O(n)\n");
    printf("Se recorren como maximo los tres conjuntos una sola vez ");
    printf("para verificar la pertenencia de sus elementos.\n");

    system("pause");
}

void ejecutar_TP5_EJ05(){

    clearScreen();

    printf("=====================================\n");
    printf("          EJERCICIO 5\n");
    printf("=====================================\n\n");

    printf("Se obtendra la diferencia simetrica\n");
    printf("entre dos conjuntos.\n\n");

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();

    printf("CARGA DEL CONJUNTO A\n");
    cargarConjunto(A);

    printf("\nCARGA DEL CONJUNTO B\n");
    cargarConjunto(B);

    clearScreen();

    printf("CONJUNTO A\n");
    cto_mostrar(A);

    printf("\nCONJUNTO B\n");
    cto_mostrar(B);

    Conjunto resultado = c_ej5_dif_simetrica(A,B);

    printf("\nDIFERENCIA SIMETRICA\n");
    cto_mostrar(resultado);

    printf("\nComplejidad algoritmica: O(n)\n");
    printf("La diferencia simetrica se obtiene realizando dos ");
    printf("operaciones de diferencia y una operacion de union.\n");

    system("pause");
}

void ejecutar_TP5_EJ06(){

    clearScreen();

    printf("=====================================\n");
    printf("          EJERCICIO 6\n");
    printf("=====================================\n\n");

    printf("Se determinara si uno de los conjuntos\n");
    printf("es subconjunto propio del otro.\n\n");

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();

    printf("CARGA DEL CONJUNTO A\n");
    cargarConjunto(A);

    printf("\nCARGA DEL CONJUNTO B\n");
    cargarConjunto(B);

    clearScreen();

    printf("CONJUNTO A\n");
    cto_mostrar(A);

    printf("\nCONJUNTO B\n");
    cto_mostrar(B);

    printf("\n");

    if(c_ej6_subconjuntopropio(A,B)){
        printf("El conjunto A es subconjunto propio de B.\n");
    }
    else if(c_ej6_subconjuntopropio(B,A)){
        printf("El conjunto B es subconjunto propio de A.\n");
    }
    else{
        printf("Ninguno de los conjuntos es subconjunto propio del otro.\n");
    }

    printf("\nComplejidad algoritmica: O(n)\n");
    printf("Se recorre el conjunto de menor cardinalidad ");
    printf("verificando la pertenencia de sus elementos.\n");

    system("pause");
}

void ejecutar_TP5_EJ07(){

    clearScreen();

    printf("=====================================\n");
    printf("          EJERCICIO 7\n");
    printf("=====================================\n\n");

    printf("Se determinara si alguno de los\n");
    printf("tres conjuntos es subconjunto\n");
    printf("parcial o total de otro.\n\n");

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();

    printf("CARGA DEL CONJUNTO A\n");
    cargarConjunto(A);

    printf("\nCARGA DEL CONJUNTO B\n");
    cargarConjunto(B);

    printf("\nCARGA DEL CONJUNTO C\n");
    cargarConjunto(C);

    clearScreen();

    printf("CONJUNTO A\n");
    cto_mostrar(A);

    printf("\nCONJUNTO B\n");
    cto_mostrar(B);

    printf("\nCONJUNTO C\n");
    cto_mostrar(C);

    printf("\nRESULTADOS\n\n");

    c_ej7_subconjtotalparcial(A,B,C);

    printf("\nComplejidad algoritmica: O(n)\n");
    printf("Cada comparacion recorre una sola vez el conjunto ");
    printf("que se desea verificar. Como siempre se realizan ");
    printf("seis comparaciones, el factor es constante.\n");

    system("pause");
}

void ejecutar_TP5_EJ08(){

    clearScreen();

    printf("=====================================\n");
    printf("          EJERCICIO 8\n");
    printf("=====================================\n\n");

    printf("Se determinara si dos conjuntos\n");
    printf("son iguales sin importar el orden\n");
    printf("de sus elementos.\n\n");

    Conjunto A = cto_crear();
    Conjunto B = cto_crear();

    printf("CARGA DEL CONJUNTO A\n");
    cargarConjunto(A);

    printf("\nCARGA DEL CONJUNTO B\n");
    cargarConjunto(B);

    clearScreen();

    printf("CONJUNTO A\n");
    cto_mostrar(A);

    printf("\nCONJUNTO B\n");
    cto_mostrar(B);

    printf("\n");

    if(c_ej8_soniguales(A,B)){
        printf("Los conjuntos son iguales.\n");
    }
    else{
        printf("Los conjuntos son diferentes.\n");
    }

    printf("\nComplejidad algoritmica: O(n)\n");
    printf("Primero se compara la cantidad de elementos y luego ");
    printf("se recorre un conjunto verificando que todos sus ");
    printf("elementos pertenezcan al otro conjunto.\n");

    system("pause");
}

