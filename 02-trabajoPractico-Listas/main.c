#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../libs/validaciones/headers/Validacion_datos.h"
#include "main.h"
#include "tp_2_listas.h"



void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void main(){

    int opcion = 0;
    bool x = false;
   
    do{
        clearScreen();
        printf("\n");
        printf("--------TP01 Recursividad--------\n");
        printf("\n");
        //printf("Ejercicio 1: \n");
        printf("Ejercicio 2: \n");
        printf("Ejercicio 3: \n");
        printf("Ejercicio 4: \n");
        printf("Ejercicio 5: \n");
        printf("Ejercicio 6: \n");
        //printf("Ejercicio 7: \n");
        //printf("Ejercicio 8: \n");
        //printf("Ejercicio 9: \n");
        //printf("Ejercicio 10: \n");
        printf("Ingrese el ejercicio deseado o X para salir\n");
        printf("\n");

        opcion = ingresaEnteroTeclado(&x);
        while ((opcion < 2 || opcion > 6) && !x){
            printf("Ingreso invalido, intente nuevamente\n");
            opcion = ingresaEnteroTeclado(&x);
        }

        switch (opcion){
            /*
        case 1:
            printf("Elegiste la opcion 1\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ01();
            system("pause");
            break;
            */
        case 2:
            printf("Elegiste la opcion 2\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ02();
            system("pause");
            break;
        case 3:
            printf("Elegiste la opcion 3\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ03();
            system("pause");
            break;
        case 4:
            printf("Elegiste la opcion 4\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ04();
            system("pause");
            break;
        case 5:
            printf("Elegiste la opcion 5\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ05();
            system("pause");
            break;
        case 6:
            printf("Elegiste la opcion 6\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ06();
            system("pause");
            break;
/*
        case 7:
            printf("Elegiste la opcion 7\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ07();
            system("pause");
            break;

        case 8:
            printf("Elegiste la opcion 8\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ08();
            system("pause");
            break;

        case 9:
            printf("Elegiste la opcion 9\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ09();
            system("pause");
            break;

        case 10:
            printf("Elegiste la opcion 10\n");
            printf("Presiona ENTER para ir al ejercicio elegido\n");
            system("pause");
            ejecutar_TP2_EJ10();
            system("pause");
            break;


*/



        default:
            break;
        }

    } while (!x);

    printf("Saliendo de TP1\n");
    system("pause");
}

