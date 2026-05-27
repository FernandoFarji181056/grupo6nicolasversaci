#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "pilasaux.h"
#include "../libs/validaciones/headers/validaciones.h"


// Funciones auxiliares
/*  Esta función recibe 2 parámetros
    P es una pila vacía y Paux es la pila con datos
    desapila de Paux y apila en P
    ejemplo: ingresa Paux con 3 2 1
             sale P con 1 2 3 y Paux vacía
*/
void p_intercambiar(Pila P, Pila Paux) {

    while (!p_es_vacia(Paux)) {

        TipoElemento x = p_desapilar(Paux);

        p_apilar(P, x);
    }
}

/*  Esta función es para cargar una pila en forma manual
    recibe 2 parámetros, números enteros que definen el rango
    de los números que puedo ingresar en la pila
    arma la pila con los valores ingresados dentro del rango
    retorna la pila
*/
Pila cargarPilaManual(int min_pila, int max_pila) {

    // controlo que el rango ingresado sea válido
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

        /*  la función pedirEnteroRango puede devolver 3 estados
            si es 1 el valor ingresado es válido y lo apila
            si es 0 el usuario ingresó x, por lo tanto termina el ingreso de valores
            si es -1 significa que es un valor inválido
        */
        estado = pedirEnteroRango(min_pila, max_pila, &numero);

        if (estado == 1) {

            p_apilar(P, te_crear(numero));
        }
    }

    return P;
}

//EJERCICIO 2

/*  Esta función es para el punto a del ejercicio 2 del tp de pilas
    Recibe la pila y un entero
    retorna true si el valor se encuentra en la pila o false si no
*/
bool p_ej2_existeclave(Pila P, int clave) {
    Pila aux = p_crear();
    bool encontrado = false;

    while (!p_es_vacia(P)) {

        TipoElemento x = p_desapilar(P);

        if (x->clave == clave) {
            encontrado = true;
        }

        p_apilar(aux, x);
    }

    // restauro la pila
    p_intercambiar(P, aux);

    return encontrado;
}

/*  Esta función es para el punto b del ejercicio 2 del tp de pilas
    recibe como parámetros una pila, un tipoElemento y un entero con la posición
    al salir el nuevo dato de tipoElemento queda ingresado en la posicion
*/
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x) {

    int cantidad = p_ej2_cantidadelementos(p);

    // valido posición
    if (posicionordinal < 1 ||
        posicionordinal > cantidad + 1) {

        return p;
    }

    Pila aux = p_crear();

    int i = 1;

    while (!p_es_vacia(p) && i < posicionordinal) {

        p_apilar(aux, p_desapilar(p));

        i++;
    }

    p_apilar(p, x);

    p_intercambiar(p, aux);

    return p;
}


/*  esta función es para el punto c del ejercicio 2 del tp de pilas
    recibe como parámetros una pila y un entero a borrar
    retorna la pila modificada
*/
Pila p_ej2_eliminarclave(Pila p, int clave) {

    Pila aux = p_crear();

    bool eliminado = false;

    while (!p_es_vacia(p)) {

        TipoElemento x = p_desapilar(p);

        if (x->clave == clave &&
            !eliminado) {

            eliminado = true;

        } else {

            p_apilar(aux, x);
        }
    }

    p_intercambiar(p, aux);

    return p;
}


/*  Esta función es para el punto d del ejercicio 2 del tp de pilas
    recibe una pila y 2 valores, que son las posiciones a cambiar
    retorna la pila modificada
*/
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
    if (pos1 == pos2) {
        return p;
    }

    int cantidad = p_ej2_cantidadelementos(p);

    // valido posiciones
    if (pos1 < 1 || pos2 < 1 || pos1 > cantidad || pos2 > cantidad) {
        return p;
    }

    Pila aux = p_crear();

    TipoElemento elem1 = NULL;
    TipoElemento elem2 = NULL;

    int pos = 1;

    // desapilo y busco posiciones
    while (!p_es_vacia(p)) {

        TipoElemento x = p_desapilar(p);

        if (pos == pos1) {

            elem1 = x;

        } else if (pos == pos2) {

            elem2 = x;
        }

        p_apilar(aux, x);

        pos++;
    }

    pos--;

    // reconstruyo intercambiando
    while (!p_es_vacia(aux)) {

        TipoElemento x = p_desapilar(aux);

        if (pos == pos1) {

            p_apilar(p, elem2);

        } else if (pos == pos2) {

            p_apilar(p, elem1);

        } else {

            p_apilar(p, x);
        }

        pos--;
    }
    return p;
}


/*  Esta función es para el punto e del ejercicio 2 del tp pilas
    recibe como parámetro una pila
    retorna una pila que es el duplicado de la inicial
*/
//Pila duplicarPila(Pila P) {
Pila p_ej2_duplicar(Pila p) {
    Pila aux = p_crear();
    Pila duplicada = p_crear();

    // muevo original a auxiliar
    p_intercambiar(aux, p);

    // restauro original
    // y hago primera copia
    while (!p_es_vacia(aux)) {

        TipoElemento x = p_desapilar(aux);

        // restauro original
        p_apilar(p, x);

        // primera copia
        p_apilar(duplicada, te_crear(x->clave));
    }

    // vuelvo a mover original a auxiliar
    p_intercambiar(aux, p);

    // restauro original
    // y hago segunda copia
    while (!p_es_vacia(aux)) {

        TipoElemento x = p_desapilar(aux);

        // restauro original
        p_apilar(p, x);

        // segunda copia
        p_apilar(duplicada, te_crear(x->clave));
    }

    return duplicada;
}


/*  Esta función es para el punto f del ejercicio 2 del tp de pilas
    recibe como parámetro una pila
    retorna un entero con la cantidad de elementos
*/
//int contarElementosPila(Pila P) {
int p_ej2_cantidadelementos(Pila P) {
    Pila aux = p_crear();
    int contador = 0;

    while (!p_es_vacia(P)) {

        p_apilar(aux, p_desapilar(P));

        contador++;
    }

    p_intercambiar(P, aux);

    return contador;
}


//EJERCICIO 3

/*  Esta función es para el ejercicio 3 del tp de pilas
    recibe como parámetros 2 pilas, que compara elemento a elemento
    si son iguales retorna true, si no lo son retorna false
*/
bool p_ej3_iguales(Pila p1, Pila p2) {

    Pila aux = p_crear();

    bool iguales = true;

    // -------------------------
    // comparo ambas pilas
    // -------------------------

    while (!p_es_vacia(p1) && !p_es_vacia(p2) && iguales) {

        TipoElemento x1 = p_desapilar(p1);
        TipoElemento x2 = p_desapilar(p2);

        // comparo claves
        if (x1->clave != x2->clave) {

            iguales = false;
        }

        // guardo ambos elementos
        p_apilar(aux, x1);
        p_apilar(aux, x2);
    }

    // -------------------------
    // si una quedó vacía
    // y la otra no
    // no son iguales
    // -------------------------

    if (!p_es_vacia(p1) || !p_es_vacia(p2)) {

        iguales = false;
    }

    // -------------------------
    // restauro pilas originales
    // -------------------------

    while (!p_es_vacia(aux)) {

        TipoElemento x2 = p_desapilar(aux);
        TipoElemento x1 = p_desapilar(aux);

        p_apilar(p2, x2);
        p_apilar(p1, x1);
    }

    return iguales;
}

//Ejercicio 4

/*  Esta función es para el ejercicio 4 del tp de pilas
    recibe como parámetros 2 enteros
    el primero es un número decimal,
    el segundo es la base a convertir ese decimal (2 a 16)
    retorna un string (char*)
*/
char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase) {

    // valido la base

    if (nrootrabase < 2 || nrootrabase > 16) {

        // asigno 20 de memoria, me aseguro que sobrará para un int
        char* resultado = malloc(20);

        // esta instrucción la uso para cambiar int a string
        sprintf(resultado, "%d", nrobasedecimal);

        return resultado;
    }

    // caso especial: 0

    if (nrobasedecimal == 0) {

        char* resultado = malloc(2);

        resultado[0] = '0';
        resultado[1] = '\0';

        return resultado;
    }

    Pila p = p_crear();

    int resto;

    // si todo está bien inicio la conversion

    while (nrobasedecimal > 0) {

        resto = nrobasedecimal % nrootrabase;

        p_apilar(p, te_crear(resto));

        nrobasedecimal = nrobasedecimal / nrootrabase;
    }

    // reservo memoria resultado, para eso utilizo la función
    // de contar del ejercicio 2

    int cantidad = p_ej2_cantidadelementos(p);

    char* resultado = malloc(cantidad + 1);

    int i = 0;

    // armo el string final

    while (!p_es_vacia(p)) {

        TipoElemento x = p_desapilar(p);

        if (x->clave < 10) {

            resultado[i] = x->clave + '0';

        } else {

            resultado[i] = (x->clave - 10) + 'A';
        }

        i++;
    }

    resultado[i] = '\0';

    return resultado;
}

//Ejercicio 5

/*  Esta función es para el ejercicio 5 del tp de pilas
    recibe como parámetro una pila
    retorna una pila invertida, sin destruir la pila original
*/
Pila p_ej5_invertir(Pila p) {

    Pila aux = p_crear();

    Pila invertida = p_crear();

    // paso la pila original a la auxiliar

    while (!p_es_vacia(p)) {

        TipoElemento x = p_desapilar(p);

        p_apilar(aux, x);

        // ya queda invertida
        p_apilar(invertida, te_crear(x->clave));
    }

    // restauro la original

    while (!p_es_vacia(aux)) {

        p_apilar(p, p_desapilar(aux));
    }

    return invertida;
}

// EJERCICIO 6

/*  Esta función recibe una pila original
y una pila auxiliar.
Retorna la pila original restaurada
con todos sus elementos.
*/
static void restaurarPila(Pila original, Pila auxiliar) {


while (!p_es_vacia(auxiliar)) {

    p_apilar(original, p_desapilar(auxiliar));
}


}

/*  Esta función recibe una pila y una clave.
Retorna true si la clave existe en la pila,
caso contrario retorna false.
La pila original no se pierde.
*/
static bool existeClave(Pila p, int clave) {


Pila aux = p_crear();

bool existe = false;

while (!p_es_vacia(p)) {

    TipoElemento x = p_desapilar(p);

    if (x->clave == clave) {

        existe = true;
    }

    p_apilar(aux, x);
}

restaurarPila(p, aux);

return existe;

}

/*  Esta función recibe una pila y una clave.
Retorna una nueva pila sin todas las
ocurrencias de la clave recibida.
La pila original no se pierde.
*/
Pila p_ej6_eliminarclave(Pila p, int clave) {
    
    Pila aux = p_crear();
    
    Pila resultado = p_crear();
    
    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        
        p_apilar(aux, x);
        
        if (x->clave != clave) {
            
            p_apilar(resultado, x);
        }
    }

restaurarPila(p, aux);

Pila final = p_crear();

while (!p_es_vacia(resultado)) {

    p_apilar(final, p_desapilar(resultado));
}

return final;

}

/*  Esta funcion resuelve el ejercicio 6
    de forma recursiva.
    Elimina todas las ocurrencias de una clave
    sin perder la pila original.
*/
Pila p_ej6_eliminarclaverecursiva(Pila p, int clave) {

    Pila resultado = p_crear();

    if (p_es_vacia(p)) {

        return resultado;
    }

    TipoElemento x = p_desapilar(p);

    resultado =
        p_ej6_eliminarclave_recursivo(p, clave);

    p_apilar(p, x);

    if (x->clave != clave) {

        p_apilar(resultado, te_crear(x->clave));
    }

    return resultado;
}

// EJERCICIO 7

/*  Esta función recibe dos pilas.
Retorna una nueva pila con los
elementos que ambas pilas tienen
en común sin repetir elementos.
Las pilas originales no se pierden.
*/
Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {


Pila resultado = p_crear();

Pila aux1 = p_crear();

while (!p_es_vacia(p1)) {

    TipoElemento x = p_desapilar(p1);

    p_apilar(aux1, x);

    if (existeClave(p2, x->clave) &&
        !existeClave(resultado, x->clave)) {

        p_apilar(resultado, te_crear(x->clave));
    }
}

restaurarPila(p1, aux1);

return resultado;


}

// EJERCICIO 8

/*  Esta función recibe una pila con
valores repetidos.
Retorna una nueva pila con las claves
únicas y la cantidad de veces que
aparecen en la pila original.
La pila original no se pierde.
*/

Pila p_ej8_sacarrepetidos(Pila p) {

    Pila resultado = p_crear();

    Pila aux = p_crear();

    while (!p_es_vacia(p)) {

        TipoElemento x = p_desapilar(p);

        p_apilar(aux, x);
    }

    while (!p_es_vacia(aux)) {

        TipoElemento actual = p_desapilar(aux);

        p_apilar(p, actual);

        if (!existeClave(resultado, actual->clave)) {

            int contador = 0;

            Pila aux2 = p_crear();

            while (!p_es_vacia(p)) {

                TipoElemento x = p_desapilar(p);

                p_apilar(aux2, x);

                if (x->clave == actual->clave) {

                    contador++;
                }
            }

            restaurarPila(p, aux2);

            int* cantidad = malloc(sizeof(int));

            *cantidad = contador;

            TipoElemento nuevo =
                te_crear_con_valor(actual->clave, cantidad);

            p_apilar(resultado, nuevo);
        }
    }

    return resultado;
}
