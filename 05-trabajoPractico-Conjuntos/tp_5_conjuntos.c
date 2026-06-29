#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "tp_5_conjuntos.h"
#include "../libs/conjuntos/headers/conjuntos.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "conjuntos_auxiliares.h"
#include "../libs/listas/headers/listas.h"

//Funciones Auxiliares
/*  Esta función permite cargar un conjunto en forma manual.
    Recibe como parámetro un conjunto vacío.
    Solicita el ingreso de números enteros hasta que el usuario
    ingrese 'X' para finalizar la carga.
    Agrega automáticamente los elementos al conjunto evitando
    repetidos (propiedad del TAD).
    Retorna true si el conjunto contiene al menos un elemento,
    o false si el conjunto quedó vacío.
*/

bool cargarConjunto(Conjunto A){

    clearScreen();

    bool salir = false;
    bool valido = false;
    int numero;
    char cadena[100];

    TipoElemento X;

    printf("CARGA DEL CONJUNTO\n");
    printf("Ingrese numeros enteros.\n");
    printf("Ingrese X para finalizar la carga.\n\n");

    do{

        printf("Ingrese un numero o X para salir: ");

        fgets(cadena,100,stdin);

        cadena[strcspn(cadena,"\n")] = '\0';

        valido = validarEntero(cadena);

        if((cadena[0]=='X' || cadena[0]=='x') && strlen(cadena)==1){
            salir = true;
        }
        else if(!valido){
            printf("La entrada no es valida.\n\n");
        }
        else{

            numero = (int)strtol(cadena,NULL,10);

            X = te_crear(numero);

            if(cto_agregar(C,X)){
                printf("Elemento agregado correctamente.\n");
            }
            else{
                printf("El elemento ya pertenece al conjunto.\n");
            }
        }

    }while(!salir);

    if(cto_es_vacio(C)){
        printf("\nEl conjunto no puede estar vacio.\n");
        return false;
    }

    return true;
}


/*  Esta función determina la relación entre dos conjuntos.
    Recibe dos conjuntos y sus nombres.
    Imprime si el primero es subconjunto total o parcial del segundo.
*/
void verificarSubconjunto(Conjunto A, Conjunto B, char nombreA, char nombreB){

    int comunes = 0;
    TipoElemento X;

    for(int i = 1; i <= cto_cantidad_elementos(A); i++){

        X = cto_recuperar(A,i);

        if(cto_pertenece(B,X->clave)){
            comunes++;
        }
    }

    if(comunes == cto_cantidad_elementos(A)){
        printf("%c es subconjunto total de %c.\n",nombreA,nombreB);
    }
    else if(comunes >= (cto_cantidad_elementos(A)+1)/2){
        printf("%c es subconjunto parcial de %c.\n",nombreA,nombreB);
    }
}

//Ejercicio 2 

//2.union
/*  Esta función verifica la operación de unión entre dos conjuntos.
    Recibe dos conjuntos como parámetros.
    Obtiene la unión utilizando la función del TAD.
    Comprueba que la cantidad de elementos del conjunto obtenido
    sea al menos igual a la del conjunto con mayor cantidad de elementos.
    Retorna el conjunto unión.
*/

Conjunto c_ej2_union(Conjunto A, Conjunto B){

    Conjunto U = cto_union(A,B);

    int mayor = cto_cantidad_elementos(A);

    if(cto_cantidad_elementos(B) > mayor) {
        mayor = cto_cantidad_elementos(B);
    }  

    if(cto_cantidad_elementos(U) >= mayor) {
        return U;
    }

    printf("Error al realizar la union.\n");

    return cto_crear();
}

//2.interseccion
/*  Esta función verifica la operación de intersección entre dos conjuntos.
    Recibe dos conjuntos como parámetros.
    Obtiene la intersección utilizando las funcion del TAD.
    Comprueba que todos los elementos del conjunto resultante
    pertenezcan a ambos conjuntos.
    Retorna el conjunto intersección.
*/
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){

    Conjunto I = cto_interseccion(A,B);

    bool correcto = true;

    for(int i=1; i<=cto_cantidad_elementos(I) && correcto; i++){

        TipoElemento X = cto_recuperar(I,i);

        if(!cto_pertenece(A,X->clave) || !cto_pertenece(B,X->clave)){
            correcto = false;
        }
    }

    if(correcto){
        return I;
    }

    printf("Error al realizar la interseccion.\n");

    return cto_crear();
}

//2.diferencia
/*  Esta función verifica la operación de diferencia entre dos conjuntos.
    Recibe dos conjuntos como parámetros.
    Obtiene la diferencia A-B utilizando la funcion del TAD.
    Comprueba que los elementos obtenidos pertenezcan al conjunto A
    y no pertenezcan al conjunto B.
    Retorna el conjunto diferencia.
*/
Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){

    Conjunto D = cto_diferencia(A,B);

    bool correcto = true;

    for(int i=1; i<=cto_cantidad_elementos(D) && correcto; i++){

        TipoElemento X = cto_recuperar(D,i);

        if(!cto_pertenece(A,X->clave) || cto_pertenece(B,X->clave)){
            correcto = false;
        }
    }

    if(correcto){
        return D;
    }

    printf("Error al realizar la diferencia.\n");

    return cto_crear();
}

//2.pertenencia 
/*  Esta función verifica la pertenencia entre dos conjuntos.
    Recibe dos conjuntos como parámetros.
    Comprueba qué elementos del primer conjunto
    pertenecen al segundo conjunto.
    Retorna un conjunto con los elementos que cumplen
    la condición de pertenencia.
*/
Conjunto c_ej2_pertenencia(Conjunto A, Conjunto B){

    Conjunto P = cto_crear();

    for(int i = 1; i <= cto_cantidad_elementos(A); i++){

        TipoElemento X = cto_recuperar(A, i);

        if(cto_pertenece(B, X->clave)){
            cto_agregar(P, te_crear(X->clave));
        }
    }

    return P;
}

//Ejercicio 3 
//Union
/*  Esta función realiza la unión de una colección de conjuntos.
    Recibe una lista cuyos elementos contienen conjuntos.
    Obtiene la unión de todos los conjuntos de la colección.
    Retorna el conjunto resultante.
*/

Conjunto c_ej3_uniones(Lista l_de_conjuntos){

    if(l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }

    TipoElemento X = l_recuperar(l_de_conjuntos,1);

    Conjunto resultado = (Conjunto) X->valor;

    for(int i=2 ; i<=l_longitud(l_de_conjuntos) ; i++){

        X = l_recuperar(l_de_conjuntos,i);

        resultado = cto_union(resultado,(Conjunto)X->valor);
    }

    return resultado;
}
//Interseccion
/*  Esta función realiza la intersección de una colección de conjuntos.
    Recibe una lista cuyos elementos contienen conjuntos.
    Obtiene la intersección de todos los conjuntos de la colección.
    Retorna el conjunto resultante.
*/
Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){

    if(l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }

    TipoElemento X = l_recuperar(l_de_conjuntos,1);

    Conjunto resultado = (Conjunto) X->valor;

    for(int i=2 ; i<=l_longitud(l_de_conjuntos) ; i++){

        X = l_recuperar(l_de_conjuntos,i);

        resultado = cto_interseccion(resultado,(Conjunto)X->valor);
    }

    return resultado;
}

//Ejercicio 4 
/*  Esta función verifica la propiedad de transitividad entre tres conjuntos.
    Recibe tres conjuntos como parámetros.
    Comprueba si A es subconjunto de B y si B es subconjunto de C.
    Si ambas condiciones se cumplen, verifica que A sea subconjunto de C.
    Retorna true si se demuestra la propiedad de transitividad,
    o false en caso contrario.
*/
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){

    bool AsubB = true;
    bool BsubC = true;
    bool AsubC = true;

    TipoElemento X;

    // Verificar A ⊆ B
    for(int i = 1; i <= cto_cantidad_elementos(A) && AsubB; i++){

        X = cto_recuperar(A,i);

        if(!cto_pertenece(B,X->clave)){
            AsubB = false;
        }
    }

    // Verificar B ⊆ C
    for(int i = 1; i <= cto_cantidad_elementos(B) && BsubC; i++){

        X = cto_recuperar(B,i);

        if(!cto_pertenece(C,X->clave)){
            BsubC = false;
        }
    }

    // Si no se cumplen las hipótesis, no hay transitividad
    if(!AsubB || !BsubC){
        return false;
    }

    // Verificar A ⊆ C
    for(int i = 1; i <= cto_cantidad_elementos(A) && AsubC; i++){

        X = cto_recuperar(A,i);

        if(!cto_pertenece(C,X->clave)){
            AsubC = false;
        }
    }

    return AsubC;
}
//Ejercicio 5
/*  Esta función obtiene la diferencia simétrica entre dos conjuntos.
    Recibe dos conjuntos como parámetros.
    Calcula la diferencia de A respecto de B y la diferencia
    de B respecto de A.
    Luego realiza la unión de ambos resultados.
    Retorna el conjunto correspondiente a la diferencia simétrica.
*/
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){

    Conjunto diferenciaAB;
    Conjunto diferenciaBA;
    Conjunto resultado;

    diferenciaAB = cto_diferencia(A,B);

    diferenciaBA = cto_diferencia(B,A);

    resultado = cto_union(diferenciaAB,diferenciaBA);

    return resultado;
}
 //EJERCICIO 6
/*  Esta función determina si un conjunto es subconjunto propio
    del otro.
    Recibe dos conjuntos como parámetros.
    Comprueba si todos los elementos del primer conjunto
    pertenecen al segundo y que ambos conjuntos no sean iguales.
    Retorna true si el primer conjunto es subconjunto propio
    del segundo, o false en caso contrario.
*/
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){

    bool esSubconjunto = true;
    TipoElemento X;

    // Si A tiene igual o mayor cantidad de elementos,
    // no puede ser subconjunto propio de B.
    if(cto_cantidad_elementos(A) >= cto_cantidad_elementos(B)){
        return false;
    }

    for(int i = 1; i <= cto_cantidad_elementos(A) && esSubconjunto; i++){

        X = cto_recuperar(A,i);

        if(!cto_pertenece(B,X->clave)){
            esSubconjunto = false;
        }
    }

    return esSubconjunto;
}


//Ejercicio 7 
/*  Esta función determina si alguno de tres conjuntos
    es subconjunto total o parcial de otro.
    Recibe tres conjuntos como parámetros.
    Compara todas las combinaciones posibles entre ellos.
    Imprime el resultado.
*/
void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){

    verificarSubconjunto(A,B,'A','B');
    verificarSubconjunto(A,C,'A','C');

    verificarSubconjunto(B,A,'B','A');
    verificarSubconjunto(B,C,'B','C');

    verificarSubconjunto(C,A,'C','A');
    verificarSubconjunto(C,B,'C','B');
}

//Ejercicio 8 
/*  Esta función determina si dos conjuntos son iguales.
    Recibe dos conjuntos como parámetros.
    Comprueba que ambos tengan la misma cantidad de elementos
    y que todos los elementos del primer conjunto pertenezcan
    al segundo conjunto.
    Retorna true si ambos conjuntos son iguales,
    o false en caso contrario.
*/
bool c_ej8_soniguales(Conjunto A, Conjunto B){

    TipoElemento X;

    if(cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){
        return false;
    }

    for(int i = 1; i <= cto_cantidad_elementos(A); i++){

        X = cto_recuperar(A,i);

        if(!cto_pertenece(B,X->clave)){
            return false;
        }
    }

    return true;
}







