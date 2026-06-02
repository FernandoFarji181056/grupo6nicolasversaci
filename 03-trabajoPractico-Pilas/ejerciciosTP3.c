#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "../libs/pilas/headers/pilas.h"
#include "tp_3_pilas.h"
#include "pilasaux.h"
#include "../libs/validaciones/headers/validaciones.h"


/*  Esta función pertenece al ejercicio 2
    del TP de pilas
*/
void ejecutar_TP3_EJ02() {

    clearScreen();

    int min_pila = 1;
    int max_pila = 1000;

    printf("============================================\n");
    printf("           Elegiste el ejercicio 2\n");
    printf("vamos a hacer algunas funciones con una pila\n");
    printf("============================================\n");


    // Cargo la pila
    Pila P = cargarPilaManual(min_pila, max_pila);

    // Si el usuario no ingresó elementos salgo
    if (p_es_vacia(P)) {
        printf("La Pila esta vacia.\n");
        return;
    }


    printf("=====================================\n");
    printf("La pila que cargaste es la siguiente:\n");
    printf("=====================================\n");

    // muestro la pila ingresada
    p_mostrar(P);

    // Punto a: busco un elemento
    printf("\n=====================================\n");
    printf("A) Busco un elemento en la pila\n");
    printf("=====================================\n");


    // valido que la clave de búsqueda sea entero,
    // no valido si está fuera del rango, entra dentro de los no existentes
    int claveBuscar = solicitarEntero("Ingrese elemento a buscar (debe ser un entero): ");

    if (p_ej2_existeclave(P, claveBuscar)) {
        printf("El elemento %d EXISTE en la pila\n", claveBuscar);
    } else {
        printf("El elemento %d NO existe en la pila\n", claveBuscar);
    }


    // Punto b: inserto un elemento en la posición elegida
    printf("\n=====================================\n");
    printf("B) Inserto un elemento en la pila\n");
    printf("=====================================\n");


    // valido que el valor ingresado esté dentro del rango
    int valorInsertar = solicitarEnteroEntre("Ingrese valor a insertar (debe respetar el rango): "
                                             , min_pila, max_pila);
    // valido que la posición esté dentro de los valores existentes de la pila
    int posInsertar = solicitarEnteroEntre("Ingrese posición ordinal (entre 1 y cantidad de elementos): ",
                                           1, p_ej2_cantidadelementos(P)+1);

    P = p_ej2_colocarelemento(P, posInsertar, te_crear(valorInsertar));

    printf("\nPila luego de insertar:\n");
    p_mostrar(P);

    // Punto c: elimino un elemento


    printf("\n=====================================\n");
    printf("C) Elimino un elemento de la pila\n");
    printf("   (si no existe la pila no cambia\n");
    printf("=====================================\n");

    // valido que el ingreso sea entero dentro del rango
    int claveEliminar = solicitarEnteroEntre("Ingrese elemento a eliminar: ",
                                             min_pila, max_pila);


    P = p_ej2_eliminarclave(P, claveEliminar);
    printf("\nPila luego de eliminar:\n");
    p_mostrar(P);


    // Punto d: intercambiar posiciones

    printf("\n=====================================\n");
    printf("D) Intercambio posiciones\n");
    printf("=====================================\n");


    int pos1 = solicitarEnteroEntre("Ingrese posicion 1: ", 1, p_ej2_cantidadelementos(P));
    int pos2 = solicitarEnteroEntre("Ingrese posicion 2: ", 1, p_ej2_cantidadelementos(P));

    P = p_ej2_intercambiarposiciones(P, pos1, pos2);
    printf("\nPila luego del intercambio:\n");
    p_mostrar(P);


    // Punto e: duplicar pila

    printf("\n=====================================\n");
    printf("E) Duplico la pila\n");
    printf("=====================================\n");

    Pila duplicada = p_ej2_duplicar(P);

    printf("Pila original:\n");
    p_mostrar(P);

    printf("\nPila duplicada:\n");
    p_mostrar(duplicada);


    // Punto f: contar elementos

    printf("\n=====================================\n");
    printf("F) Cuento los elemetos de la pila\n");
    printf("=====================================\n");

    int cantidad = p_ej2_cantidadelementos(P);

    printf("Cantidad de elementos de la pila: %d\n", cantidad);

    printf("\n=====================================\n");
    printf("         FIN DEL EJERCICIO 2\n");
    printf("=====================================\n");

    return;


}

/*  Esta función pertenece al ejercicio 3
    del TP de pilas
*/
void ejecutar_TP3_EJ03() {

    clearScreen();

    int min_pila = 1;
    int max_pila = 1000;

    printf("================================================\n");
    printf("           Elegiste el ejercicio 3\n");
    printf("vamos a cargar 2 pilas y comparar si son iguales\n");
    printf("================================================\n");

    // cargo la primera pila

    printf("\n==============================\n");
    printf("Cargo la pila 1\n");
    printf("==============================\n");

    Pila p1 = cargarPilaManual(min_pila, max_pila);

    // cargo la segunda pila

    printf("\n==============================\n");
    printf("Cargo la pila 2\n");
    printf("==============================\n");

    Pila p2 = cargarPilaManual(min_pila, max_pila);

    // muestro las pilas

    printf("\n==============================\n");
    printf("Tus pilas ingresadas son:\n");
    printf("==============================\n");

    printf("\nPila 1: ");
    p_mostrar(p1);

    printf("\nPila 2: ");
    p_mostrar(p2);

    // comparo las pilas

    bool iguales = p_ej3_iguales(p1, p2);

    printf("\n==============================\n");
    printf("          Resultado:\n");
    printf("==============================\n");

    if (iguales) {

        printf("\nLas pilas son iguales\n");

    } else {

        printf("\nLas pilas NO son iguales\n");
    }

    // -------------------------
    // verificar que no se destruyeron
    // -------------------------

    printf("\n=======================================\n");
    printf("Compruebo que las pilas no se destruyeron\n");
    printf("=======================================\n");

    printf("\nPila 1: ");
    p_mostrar(p1);

    printf("\nPila 2: ");
    p_mostrar(p2);

    printf("\n=======================================\n");
    printf("Complejidad del algoritmo:\n");
    printf("La complejidad algorítmica de la función es lineal\n");
    printf("porque recorro ambas pilas una sola vez\n");
    printf("para comparar y otra para restaurarlas.\n");
    printf("La complejidad espacial también es lineal ya que uso\n");
    printf("una pila auxiliar para almacenar temporalmente los elementos.\n");
    printf("=======================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 3\n");
    printf("=====================================\n");

    return;

}

/*  Esta función pertenece al ejercicio 4
    del TP de pilas
*/
void ejecutar_TP3_EJ04() {

    clearScreen();

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 4\n");
    printf("vas a ingresar un numero decimal y una base entre 2 y 16\n");
    printf("y vamos a convertir ese numero decimal a la base\n");
    printf("======================================================\n");

    int numero;
    int base;

    numero = solicitarEntero("Primero ingresa un numero decimal: ");

    base = solicitarEnteroEntre("Ahora ingresa la base (2-16): ",2, 16);

    char* resultado = p_ej4_cambiarbase(numero, base);


    printf("===========================================================\n");
    printf("                 Resultado:\n");
    printf("Tu numero %d convertido a la base %d es: %s\n",numero, base, resultado);
    printf("===========================================================\n");

    printf("\n==================================================\n");
    printf("Complejidad del algoritmo:\n");
    printf("La complejidad algorítmica de la función es O(log n)\n");
    printf("porque la cantidad de divisiones necesarias\n");
    printf("depende de la base destino.\n");
    printf("La complejidad espacial también es O(log n)\n");
    printf("debido al almacenamiento de los restos en una pila auxiliar\n.");
    printf("====================================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 4\n");
    printf("=====================================\n");

    free(resultado);

    return;

}


/*  Esta función pertenece al ejercicio 5
    del TP de pilas
*/
void ejecutar_TP3_EJ05() {

    clearScreen();

    printf("========================================================\n");
    printf("           Elegiste el ejercicio 5\n");
    printf("vas a ingresar una pila\n");
    printf("y vamos a retornar esa pila en forma invertida\n");
    printf("======================================================\n");

    int min_pila = 1;
    int max_pila = 1000;

    // cargo la pila original

    printf("\n==============================\n");
    printf("Cargo la pila:\n");
    printf("==============================\n");

    Pila p = cargarPilaManual(min_pila, max_pila);

    // muestro la pila cargada

    printf("\nTu pila cargada es: ");

    p_mostrar(p);

    // invierto la pila y la muestro

    Pila invertida = p_ej5_invertir(p);


    printf("\nTu pila invertida es: ");

    p_mostrar(invertida);

    // demuestro que la pila original no se perdiò

    printf("\nTu pila original no se perdio, es: ");

    p_mostrar(p);

    printf("\n==================================================\n");
    printf("Complejidad del algoritmo:\n");
    printf("La complejidad algorítmica de la función es O(n)\n");
    printf("porque se recorren todos los elementos de la pila\n");
    printf("una cantidad constante de veces.\n");
    printf("La complejidad espacial también es O(n)\n");
    printf("se usan pilas auxiliares para conservar la pila original\n");
    printf("y generar la invertida.\n.");
    printf("====================================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 5\n");
    printf("=====================================\n");

    return;

}


void ejecutar_TP3_EJ06() {

    clearScreen();

    int min_pila = 0;
    int max_pila = 1000;

    printf("============================================\n");
    printf("           Elegiste el ejercicio 6\n");
    printf("============================================\n");

    Pila p = p_crear();
    
    int cantidad;
    int valor;
    int eliminar;
    
    cantidad = solicitarEnteroEntre("Ingrese cantidad de elementos: ", min_pila, max_pila);
    
    for (int i = 0; i < cantidad; i++) {

        valor = solicitarEnteroEntre( "Ingrese valor: ", min_pila, max_pila );
        
        p_apilar(p, te_crear(valor));
    }
    
    printf("\nPila original:\n");
    
    p_mostrar(p);

    eliminar = solicitarEnteroEntre( "\nIngrese clave a eliminar: ", min_pila, max_pila );

    Pila nuevaIterativa = p_ej6_eliminarclave(p, eliminar);
    
    printf("\nNueva pila (iterativa):\n");
    
    p_mostrar(nuevaIterativa);
    
    Pila nuevaRecursiva = p_ej6_eliminarclaverecursiva(p, eliminar);
    
    printf("\nNueva pila (recursiva):\n");
    
    p_mostrar(nuevaRecursiva);

    printf("\n=====================================\n");

    printf("Complejidad del algoritmo:\n\n");

    printf("Resolucion iterativa:\n");
    printf("Complejidad temporal: O(n)\n");
    printf("Complejidad espacial: O(n)\n\n");

    printf("Resolucion recursiva:\n");
    printf("Complejidad temporal: O(n)\n");
    printf("Complejidad espacial: O(n)\n");

    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 6\n");
    printf("=====================================\n");

    return;
}

void ejecutar_TP3_EJ07() {

    clearScreen();

    int min_pila = 0;
    int max_pila = 1000;

    printf("============================================\n");
    printf("           Elegiste el ejercicio 7\n");
    printf("============================================\n");
    
    Pila p1 = p_crear(); 
    
    Pila p2 = p_crear(); 
    
    int cantidad1; 
    int cantidad2; 
    int valor; 

    cantidad1 = solicitarEnteroEntre( "Cantidad elementos pila 1: ", min_pila, max_pila );

    
    for (int i = 0; i < cantidad1; i++) { 

        valor = solicitarEnteroEntre( "Ingrese valor: ", min_pila, max_pila );
        
        p_apilar(p1, te_crear(valor)); 
    } 
    

    cantidad2 = solicitarEnteroEntre( "\nCantidad elementos pila 2: ", min_pila, max_pila );
    
    for (int i = 0; i < cantidad2; i++) { 
        valor = solicitarEnteroEntre( "Ingrese valor: ", min_pila, max_pila );
        p_apilar(p2, te_crear(valor)); 
    } 
    
    printf("\nPila 1:\n"); 
    
    p_mostrar(p1); 
    
    printf("\nPila 2:\n"); 
    
    p_mostrar(p2); 
    
    Pila comunes = p_ej7_elementoscomunes(p1, p2); 
    
    printf("\nElementos comunes:\n"); 
    
    p_mostrar(comunes); 
    
    printf("\nPilas originales conservadas:\n"); 
    
    printf("\nPila 1:\n"); 
    
    p_mostrar(p1); 
    
    printf("\nPila 2:\n"); 
    
    p_mostrar(p2);

    printf("\n=====================================\n");
    printf("Complejidad del algoritmo:\n");
    printf("Complejidad temporal: O(n * m)\n");
    printf("porque para cada elemento de una pila\n");
    printf("se recorre la otra pila.\n\n");
    printf("Complejidad espacial: O(n)\n");
    printf("por el uso de pilas auxiliares.\n");

    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 7\n");
    printf("=====================================\n");

    return;
}

void ejecutar_TP3_EJ08() {

    clearScreen();

    int min_pila = 0;
    int max_pila = 1000;

    printf("============================================\n");
    printf("           Elegiste el ejercicio 8\n");
    printf("============================================\n");

    printf("Ejercicio 8 \n");
    
    Pila p = p_crear();
    
    int cantidad;
    int valor;

    cantidad = solicitarEnteroEntre( "Cantidad de elementos: ", min_pila, max_pila );
    
    for (int i = 0; i < cantidad; i++) {
        valor = solicitarEnteroEntre( "Ingrese valor: ", min_pila, max_pila );
        
        p_apilar(p, te_crear(valor));
    }
    
    printf("\nPila original:\n");
    
    p_mostrar(p);
    
    Pila resultado = p_ej8_sacarrepetidos(p);
    
    printf("\nValores unicos y cantidades:\n");
    
    Pila aux = p_crear();
    
    while (!p_es_vacia(resultado)) {
        TipoElemento x = p_desapilar(resultado);
        
        int cantidad = *((int*)x->valor);
        
        printf("%d : %d\n", x->clave, cantidad);
        
        p_apilar(aux, x);
    }
    
    while (!p_es_vacia(aux)) {
        p_apilar(resultado, p_desapilar(aux));
    }
    
    printf("\nPila original conservada:\n");
    
    p_mostrar(p);

    printf("\n=====================================\n");
    
    printf("Complejidad del algoritmo:\n");

    printf("Complejidad temporal: O(n^2)\n");

    printf("porque para cada elemento\n");

    printf("se vuelve a recorrer la pila.\n\n");
    
    printf("Complejidad espacial: O(n)\n");
    
    printf("por las pilas auxiliares utilizadas.\n");
    
    printf("=====================================\n");

    printf("\n=====================================\n");
    printf("        FIN DEL EJERCICIO 8\n");
    printf("=====================================\n");

    return;

}

