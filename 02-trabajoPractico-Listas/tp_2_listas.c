#include <stdio.h>
#include <stdlib.h>
//#include "listas.h"
//#include "tipo_elemento.h"
//#include "libs/listas/headers/main_tp3.h"
#include "..\libs/listas/headers/listas.h"
//#include "libs/listas/headers/Tp_2_listas.h"
#include "..\libs/tipoElemento/headers/tipo_elemento.h"
#include "..\libs/validaciones/headers/Validacion_datos.h"



// EJERCICIO 2

// EJERCICIO 3

// EJERCICIO 4

// EJERCICIO 5

// EJERCICIO 6

// Función para determinar si ListaB es sublista de ListaA (sin importar el orden)
bool buscarElemento(Lista lista, int valor);

bool esSublista(Lista L1, Lista L2) {
    // este booleano lo uso para saber si L2 es sublista de L1
    // si termina como true significa que es sublista, si cambia a false no lo es y retornara false
    bool es_sub = true;
    Iterador I2 = iterador(L2);
    TipoElemento x1, x2;

    while (es_sub && hay_siguiente(I2))
    {
        x2 = siguiente(I2);
        es_sub = buscarElemento(L1, x2->clave);
    }
    
    return es_sub; // Si todos los elementos de ListaB se encontraron en ListaA
}

// Función para verificar si un elemento está presente en la lista


bool buscarElemento(Lista lista, int valor) {
    // esta variable booleana la uso para saber si el elemento esta en lista 1
    // será falsa mientras no encuentre el valor en la lista 1
    // si termina como falsa significa que no esta en lista, sino cambiará a true 
    bool esta_en_lista1 = false;
    Iterador I1 = iterador(lista);
    TipoElemento x1;
    // recorro mientras la lista tenga elementos o mientras esta_en_lista1 sea falso
    while(hay_siguiente(I1) && esta_en_lista1 == false)
    {
        x1 = siguiente(I1);
        if (x1->clave == valor)
        {
            
            esta_en_lista1 = true;
        }

    }

    return esta_en_lista1;
}