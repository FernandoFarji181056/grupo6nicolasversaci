#include <stdio.h>
#include <stdlib.h>
//#include "listas.h"
//#include "tipo_elemento.h"
//#include "libs/listas/headers/main_tp3.h"
#include "..\libs/listas/headers/listas.h"
//#include "libs/listas/headers/Tp_2_listas.h"
#include "..\libs/tipoElemento/headers/tipo_elemento.h"
#include "..\libs/validaciones/headers/Validacion_datos.h"
#include "tp_2_listas.h"



// EJERCICIO 2

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