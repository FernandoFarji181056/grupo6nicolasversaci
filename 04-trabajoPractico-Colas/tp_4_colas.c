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

//Ejercicio 2
bool c_ej2_existeclave(Cola c, int clave){

}


Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){

}


Cola c_ej2_sacarelemento(Cola c, int clave){

}


int c_ej2_contarelementos(Cola c){

}


Cola c_ej2_copiar(Cola c){

}

Cola c_ej2_invertir(Cola c){
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
    
    e2 = c_desencolar(auxiliar);
    c_encolar(c2, e2);
  }

  return iguales;
}


//Ejercicio 4 

Cola  c_ej4_colanorepetidos(Cola c){
}

//Ejercicio 5 

cola c_ej5_divisortotal(Cola c){
}

//Ejercicio 6
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
}

//Ejercicio 7 
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
}


