#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "listas.h"
//#include "tipo_elemento.h"
//#include "libs/listas/headers/main_tp3.h"
#include "..\libs/listas/headers/listas.h"
//#include "libs/listas/headers/Tp_2_listas.h"
#include "..\libs/tipoElemento/headers/tipo_elemento.h"
#include "..\libs/validaciones/headers/Validacion_datos.h"
#include "tp_2_listas.h"



// EJERCICIO 2
/*  Esta función recibe 2 listas,
    retorna una nueva lista con los elementos que se encuentran
    en la primera pero no en la segunda
*/
Lista verElementosQueNoSeRepiten(Lista L1, Lista L2) {
    Lista resultado = l_crear();
    Iterador it = iterador(L1);
    TipoElemento x;

    while (hay_siguiente(it)) {
        x = siguiente(it);

        if (l_buscar(L2, x->clave) == NULL) {
            if (l_buscar(resultado, x->clave) == NULL) { // evita duplicados
                l_agregar(resultado, te_crear(x->clave));
            }
        }
    }

    return resultado;
}

/*  Esta funciòn recibe 2 listas
    retorna una nueva lista con los elementos
    que se encuentran en ambas listas
*/
Lista verElementosRepetidos(Lista L1, Lista L2) {
    Lista resultado = l_crear();
    Iterador it = iterador(L1);
    TipoElemento x;

    while (hay_siguiente(it)) {
        x = siguiente(it);

        if (l_buscar(L2, x->clave) != NULL) {
            if (l_buscar(resultado, x->clave) == NULL) { // evita duplicados
                l_agregar(resultado, te_crear(x->clave));
            }
        }
    }

    return resultado;
}

/*  Esta funciòn recibe una lista
    retorna un float con el promedio de esa lista
*/
float promedio(Lista L) {
    if (l_es_vacia(L)) return 0;

    int suma = 0;

    for (int i = 1; i <= l_longitud(L); i++) {
        suma += l_recuperar(L, i)->clave;
    }

    return (float)suma / l_longitud(L);
}

/*  Esta funciòn recibe 2 listas
    retorna un struct de tipo ResultadoValorMinimo
    conteniendo el valor mínimo y su posición de cada lista
*/
ResultadoValorMinimo valorMinimo(Lista L1, Lista L2) {
    ResultadoValorMinimo r = {0, 0, 0, 0};

    if (!l_es_vacia(L1)) {
        r.valor = l_recuperar(L1, 1)->clave;
        r.pos = 1;

        for (int i = 2; i <= l_longitud(L1); i++) {
            TipoElemento x = l_recuperar(L1, i);

            if (x->clave < r.valor) {
                r.valor = x->clave;
                r.pos = i;
            }
        }
    }

    if (!l_es_vacia(L2)) {
        r.valor_2 = l_recuperar(L2, 1)->clave;
        r.pos_2 = 1;

        for (int i = 2; i <= l_longitud(L2); i++) {
            TipoElemento x = l_recuperar(L2, i);

            if (x->clave < r.valor_2) {
                r.valor_2 = x->clave;
                r.pos_2 = i;
            }
        }
    }

    return r;
}

// EJERCICIO 3

ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul res;
    res.esMultiplo=true;
    res.escalar=true;
    res.numEscalar=1000;

    int longit=l_longitud(l1);
    printf("la longitud de ambas listas es de %d: \n\n",longit);

    bool esMultiplo=true;
    int valor1;
    int valor2;
    int resto;
    int escalar01=0;
    int escalar02=0;
   // float multiplo01;
    TipoElemento X;


			for (int i=1;i<=longit;i++){
				
				X = l_recuperar(l1, i);			
				valor1=X->clave;
				//printf("igreso L1: %d \n",valor1);

				X = l_recuperar(l2, i);				
				valor2=X->clave;
				//printf("ingreso L2: %d \n",valor2);

                resto = valor2 % valor1;

                 if (resto!=0){
                    //bool esMultiplo=false;
                    res.esMultiplo=false;
                    res.escalar=false;

                }
                if (resto==0){
                    if (i == 1){
                        escalar01=valor2/valor1;
                        escalar02=escalar01;
                        res.numEscalar=escalar01;
                    }

                    
         
                    if (i != 1){
                        escalar01=valor2/valor1;
                        if (escalar01!=escalar02){
                            res.escalar=false;
                        }

                    }
                }
          
            }
            

    return res;
}





// EJERCICIO 4
int CompararListas(Lista l1, Lista l2) {

    int mayoresL1 = 0;
    int mayoresL2 = 0;

    int long1 = l_longitud(l1);
    int long2 = l_longitud(l2);

    // Tomamos la menor longitud para evitar errores
    int min = (long1 < long2) ? long1 : long2;

    TipoElemento e1, e2;

    for (int i = 1; i <= min; i++) {

        e1 = l_recuperar(l1, i);
        e2 = l_recuperar(l2, i);

        if (e1->clave > e2->clave) {
            mayoresL1++;
        } else if (e1->clave < e2->clave) {
            mayoresL2++;
        }
    }

    if (mayoresL1 > mayoresL2) {
        return 1; // L1 > L2
    } else if (mayoresL2 > mayoresL1) {
        return 2; // L1 < L2
    } else {
        return 0; // iguales
    }
}
// EJERCICIO 5

float evaluarPoliomio(Lista list, float x) {
    float resultado = 0;
    Iterador it = iterador(list);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        int exp = te->clave;
        float coef = *((float*)te->valor);
        resultado += coef * powf(x, exp);
    }
    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double paso) {
    Lista listaResultados = l_crear();
    for (double i = x; i <= y + 0.0001; i += paso) {  // +0.0001 para incluir y por precisión
        float* resultado = malloc(sizeof(float));
        *resultado = evaluarPoliomio(list, (float)i);
        TipoElemento te = te_crear_con_valor(0, resultado); // clave no se usa acá
        l_agregar(listaResultados, te);
    }
    return listaResultados;
}




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
