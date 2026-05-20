#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"

//EJERCICIO 2

//EJERCICIO 3

//Ejercicio 4

//Ejercicio 5 

// EJERCICIO 6

/*  Esta función recibe una pila original
y una pila auxiliar.
Retorna la pila original restaurada
con todos sus elementos.
*/
static void restaurarPila(Pila original, Pila auxiliar) {

```
while (!p_es_vacia(auxiliar)) {

    p_apilar(original, p_desapilar(auxiliar));
}
```

}

/*  Esta función recibe una pila y una clave.
Retorna true si la clave existe en la pila,
caso contrario retorna false.
La pila original no se pierde.
*/
static bool existeClave(Pila p, int clave) {

```
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
```

}

/*  Esta función recibe una pila y una clave.
Retorna una nueva pila sin todas las
ocurrencias de la clave recibida.
La pila original no se pierde.
*/
Pila p_ej6_eliminarclave(Pila p, int clave) {

```
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
```

}

// EJERCICIO 7

/*  Esta función recibe dos pilas.
Retorna una nueva pila con los
elementos que ambas pilas tienen
en común sin repetir elementos.
Las pilas originales no se pierden.
*/
Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {

```
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
```

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

```
Pila resultado = p_crear();

Pila aux = p_crear();

while (!p_es_vacia(p)) {

    TipoElemento actual = p_desapilar(p);

    p_apilar(aux, actual);

    if (!existeClave(resultado, actual->clave)) {

        int contador = 0;

        Pila aux2 = p_crear();

        while (!p_es_vacia(aux)) {

            TipoElemento x = p_desapilar(aux);

            p_apilar(aux2, x);

            if (x->clave == actual->clave) {

                contador++;
            }
        }

        restaurarPila(aux, aux2);

        int* cantidad = malloc(sizeof(int));

        *cantidad = contador;

        TipoElemento nuevo =
            te_crear_con_valor(actual->clave, cantidad);

        p_apilar(resultado, nuevo);
    }
}

restaurarPila(p, aux);

return resultado;
```

}





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
```

}

