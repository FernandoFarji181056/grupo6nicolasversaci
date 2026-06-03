#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "tp_4_colas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "colas_auxiliares.h"

/*  Esta función es para cargar una pila en forma manual
    recibe 2 parámetros, números enteros que definen el rango
    de los números que puedo ingresar en la pila
    arma la pila con los valores ingresados dentro del rango
    retorna la pila
*/

Pila cargarPilaManual(int min_pila, int max_pila) {

    // controlo que el rango ingresado sea valido
    if (min_pila > max_pila) {

        printf("Error: rango invalido\n");

        return p_crear();
    }

    Pila P = p_crear();

    int numero;
    int estado = 1;

    printf("Vamos a armar nuestra pila:\n");
    printf("Ingrese numeros entre %d y %d\n", min_pila, max_pila);
    printf("Ingrese x para terminar\n\n");

    while (estado != 0) {

        printf("-> ");

        estado = pedirEnteroRango(min_pila, max_pila, &numero);

        /*
            estado == 1 -> numero valido
            estado == 0 -> salir
            estado == -1 -> invalido
        */

        if (estado == 1) {

            p_apilar(P, te_crear(numero));
        }
    }

    return P;
}

/*  Esta función es para cargar una cola en forma manual
    recibe 2 parámetros, números enteros que definen el rango
    de los números que puedo ingresar en la cola
    arma la pila con los valores ingresados dentro del rango
    retorna la cola
*/

Cola cargarColaManual(int min_cola, int max_cola) {

    // controlo que el rango ingresado sea valido
    if (min_cola > max_cola) {

        printf("Error: rango invalido\n");

        return c_crear();
    }

    Cola C = c_crear();

    int numero;
    int estado = 1;

    printf("Vamos a armar nuestra cola:\n");
    printf("Ingrese numeros entre %d y %d\n", min_cola, max_cola);
    printf("Ingrese x para terminar\n\n");

    while (estado != 0) {

        printf("-> ");

        estado = pedirEnteroRango(min_cola, max_cola, &numero);

        /*
            estado == 1 -> numero valido
            estado == 0 -> salir
            estado == -1 -> invalido
        */

        if (estado == 1) {

            c_encolar(C, te_crear(numero));
        }
    }

    return C;
}

//Esta función permite restaurar la cola original

void restaurarcola(Cola destino, Cola auxiliar) {

    TipoElemento x;

    while (!c_es_vacia(auxiliar)) {

        x = c_desencolar(auxiliar);

        c_encolar(destino, x);
    }
}

//Ejercicio 2

// EJERCICIO 2.a
/*  Esta funcion recibe una cola y una clave.
    Retorna true si la clave existe en la cola,
    caso contrario retorna false.
    La cola original no debe destruirse.
*/

bool c_ej2_existeclave(Cola c, int clave){

    Cola auxiliar = c_crear();

    TipoElemento x;

    bool existe = false;

    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        if (x->clave == clave) {

            existe = true;
        }

        c_encolar(auxiliar, x);
    }

    restaurarcola(c,auxiliar);

    return existe;

}

// EJERCICIO 2.b
/*  Esta funcion recibe una cola,
    una posicion ordinal y un elemento.
    Inserta el elemento en la posicion indicada.
    Retorna la nueva cola.
*/

Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    
    Cola auxiliar = c_crear();

    TipoElemento actual;

    int posicion = 1;

    int longitud = c_ej2_contarelementos(c);

    if (posicionordinal < 1 || posicionordinal > longitud + 1) {

        return c;
    }

    while (!c_es_vacia(c)) {

        if (posicion == posicionordinal) {

            c_encolar(auxiliar, X);
        }

        actual = c_desencolar(c);

        c_encolar(auxiliar, actual);

        posicion++;
    }

    if (posicionordinal == longitud + 1) {

        c_encolar(auxiliar, X);
    }

    restaurarcola(c,auxiliar);
    
    return c;
}

// EJERCICIO 2.c
/*  Esta funcion recibe una cola y una clave.
    Elimina todas las apariciones de esa clave.
    Retorna la cola sin esos elementos.
*/

Cola c_ej2_sacarelemento(Cola c, int clave){

    Cola auxiliar = c_crear();

    TipoElemento x;

    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        // solo guardar distintos
        if (x->clave != clave) {

            c_encolar(auxiliar, x);
        }
    }

    restaurarcola(c,auxiliar);
    
    return c;
}

// EJERCICIO 2.d
/*  Esta funcion recibe una cola
    y retorna la cantidad de elementos
    que contiene.
    La cola original no debe destruirse.
*/

int c_ej2_contarelementos(Cola c){
    Cola auxiliar = c_crear();

    TipoElemento x;

    int contador = 0;

    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        contador++;

        c_encolar(auxiliar, x);
    }

    restaurarcola(c,auxiliar);

    return contador;
}

// EJERCICIO 2.e
/*  Esta funcion recibe una cola
    y retorna una copia exacta de la misma.
    La cola original no debe destruirse.
*/

Cola c_ej2_copiar(Cola c){

    Cola copia = c_crear();
    Cola auxiliar = c_crear();

    TipoElemento x;

    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        c_encolar(copia, te_crear(x->clave));

        c_encolar(auxiliar, x);
    }

    restaurarcola(c,auxiliar);

    return copia;

}

// EJERCICIO 2.f
/*  Esta funcion recibe una cola
    y retorna otra cola con los elementos
    en orden invertido.
    La cola original no debe destruirse.
*/

Cola c_ej2_invertir(Cola c){
    
    Cola auxiliar = c_crear();
    Cola invertida = c_crear();

    Pila p = p_crear();

    TipoElemento x;

    // pasar cola a pila
    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        p_apilar(p, x);

        c_encolar(auxiliar, x);
    }

    restaurarcola(c,auxiliar);

    while (!p_es_vacia(p)) {

        x = p_desapilar(p);

        c_encolar(invertida, te_crear(x->clave));
    }

    return invertida;    
}

//Ejercicio 3 
/*  Esta función recibe 2 colas,
    determina si sus contenidos son iguales
    tanto en posicion como en clave,
    sin destruir las colas originales
*/

bool c_ej3_iguales(Cola c1, Cola c2){
  
  Cola auxiliar = c_crear();
  
  bool iguales = true;
  
  TipoElemento e1;
  TipoElemento e2;
  
  while (!c_es_vacia(c1) && !c_es_vacia(c2)) {
    
    e1 = c_desencolar(c1);
    e2 = c_desencolar(c2);
    
    if (e1->clave != e2->clave) {
      iguales = false;
    }
    
    c_encolar(auxiliar, e1);
    c_encolar(auxiliar, e2);   
  }
  
  if (!c_es_vacia(c1) || !c_es_vacia(c2)) {
    iguales = false;
  }
  
  while (!c_es_vacia(auxiliar)) {
      e1 = c_desencolar(auxiliar);
      c_encolar(c1, e1);
      
      if (!c_es_vacia(auxiliar)) {
        e2 = c_desencolar(auxiliar);
        c_encolar(c2, e2);
    }
  }

  return iguales;
}


//Ejercicio 4 
/*  Esta funcion recibe una cola de numeros enteros
    y retorna una nueva cola con los elementos
    que NO se repiten en la cola original.
    La cola original no debe destruirse y debe
    quedar en su estado inicial.
*/
Cola  c_ej4_colanorepetidos(Cola c){

    Cola resultado = c_crear();
    Cola auxiliar = c_crear();

    TipoElemento x;
    TipoElemento y;

    int contador;
    int longitud = 0;

    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        c_encolar(auxiliar, x);

        longitud++;
    }


    while (!c_es_vacia(auxiliar)) {

        x = c_desencolar(auxiliar);

        c_encolar(c, x);
    }

    
    for (int i = 0; i < longitud; i++) {

        x = c_desencolar(c);

        contador = 0;

        for (int j = 0; j < longitud; j++) {

            y = c_desencolar(c);

            if (x->clave == y->clave) {

                contador++;
            }

            c_encolar(c, y);
        }

        if (contador == 1) {

            c_encolar(resultado, te_crear(x->clave));
        }

        c_encolar(c, x);
    }

    return resultado;
}

//Ejercicio 5 

/*  Esta funcion recibe una cola de numeros enteros
    no repetidos y mayores o iguales a 2.
    Retorna una nueva cola con los divisores
    totales y parciales de la cola original.
*/
Cola c_ej5_divisortotal(Cola c){
    
    Cola resultado = c_crear();
    Cola auxiliar = c_crear();

    TipoElemento x;
    TipoElemento y;

    int longitud = 0;

    //calcular longitud sin destruir cola
    while (!c_es_vacia(c)) {

        x = c_desencolar(c);

        c_encolar(auxiliar, x);

        longitud++;
    }
    //restaurar cola original

    while (!c_es_vacia(auxiliar)) {

        x = c_desencolar(auxiliar);

        c_encolar(c, x);
    }

    for (int i = 0; i < longitud; i++) {

        x = c_desencolar(c);

        int divisibles = 0;

        for (int j = 0; j < longitud; j++) {

            y = c_desencolar(c);

            if (y->clave % x->clave == 0) {

                divisibles++;
            }

            c_encolar(c, y);
        }

        if (divisibles == longitud) {

            bool* esTotal = malloc(sizeof(bool));

            *esTotal = true;

            c_encolar(resultado,
                te_crear_con_valor(x->clave, esTotal));
        }

        else if (divisibles >= (longitud / 2.0)) {

            bool* esTotal = malloc(sizeof(bool));

            *esTotal = false;

            c_encolar(resultado,
                te_crear_con_valor(x->clave, esTotal));
        }

 
        c_encolar(c, x);
    }

    return resultado;
}
    
//Ejercicio 6
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    
    Lista resultado = l_crear();

    Pila pauxiliar = p_crear();
    Cola cauxiliar = c_crear();

    TipoElemento xPila;
    TipoElemento xCola;

    int posPila = 0;
    int posCola;

    while (!p_es_vacia(p)) {

        xPila = p_desapilar(p);

        posPila++;

        p_apilar(pauxiliar, xPila);

        posCola = 0;

        while (!c_es_vacia(c)) {

            xCola = c_desencolar(c);

            posCola++;

            if (xPila->clave == xCola->clave) {

                char* texto = malloc(50 * sizeof(char));

                sprintf(texto, "%d:%d", posPila, posCola);

                TipoElemento nuevo =
                    te_crear_con_valor(xPila->clave, texto);

                l_agregar(resultado, nuevo);
            }

            c_encolar(cauxiliar, xCola);
        }

        restaurarcola(c, cauxiliar);
    }

    // restaurar pila original
    while (!p_es_vacia(pauxiliar)) {

        xPila = p_desapilar(pauxiliar);

        p_apilar(p, xPila);
    }

    return resultado;
}
   
//Ejercicio 7 
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
}


