#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "../libs/pilas/headers/pilas.h"
#include "tp_3_pilas.h"



void ejecutar_TP3_EJ02() {

    printf("EJERCICIO 2\n\n");
 
}
void ejecutar_TP3_EJ03() {
    printf("Entraste a la funcion EJ03\n");

    clearScreen();

}

void ejecutar_TP3_EJ04() {

    printf("EJERCICIO 4 \n\n");

}

void ejecutar_TP3_EJ05() {
    
    printf("Entraste a la funcion EJ05\n");


}

void ejecutar_TP3_EJ06() {
    

    printf("Ejercicio 6 \n");

    Pila p = p_crear();
    
    int cantidad;
    int valor;
    int eliminar;
    
    printf("Ingrese cantidad de elementos: ");
    scanf("%d", &cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese valor: ");
        scanf("%d", &valor);
        
        p_apilar(p, te_crear(valor));
    }
    
    printf("\nPila original:\n");
    
    p_mostrar(p);
    
    printf("\nIngrese clave a eliminar: ");
    scanf("%d", &eliminar);
    
    Pila nueva = p_ej6_eliminarclave(p, eliminar);
    
    printf("\nNueva pila:\n");
    
    p_mostrar(nueva);
    
    printf("\nPila original conservada:\n");
    
    p_mostrar(p);

}

void ejecutar_TP3_EJ07() {
    

    printf("Ejercicio 7 \n");
    
    Pila p1 = p_crear(); 
    
    Pila p2 = p_crear(); 
    
    int cantidad1; 
    int cantidad2; 
    int valor; 
    
    printf("Cantidad elementos pila 1: "); 
    scanf("%d", &cantidad1); 
    
    for (int i = 0; i < cantidad1; i++) { 
        printf("Ingrese valor: "); 
        scanf("%d", &valor); 
        
        p_apilar(p1, te_crear(valor)); 
    } 
    
    printf("\nCantidad elementos pila 2: "); 
    scanf("%d", &cantidad2); 
    
    for (int i = 0; i < cantidad2; i++) { 
        printf("Ingrese valor: "); 
        scanf("%d", &valor); 
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
}

void ejecutar_TP3_EJ08() {
    

    printf("Ejercicio 8 \n");
    
    Pila p = p_crear();
    
    int cantidad;
    int valor;
    
    printf("Cantidad de elementos: ");
    scanf("%d", &cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese valor: ");
        scanf("%d", &valor);
        
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

}

