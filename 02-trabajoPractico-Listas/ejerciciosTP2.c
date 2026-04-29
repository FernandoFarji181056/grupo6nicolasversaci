#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include "listas.h"
//#include "tipo_elemento.h"
#include "..\libs/listas/headers/listas.h"
#include "..\libs/tipoElemento/headers/tipo_elemento.h"
#include "..\libs/validaciones/headers/Validacion_datos.h"
#include "tp_2_listas.h"

bool cargarListasManual(Lista L, Lista L2);
bool esSublista(Lista L1, Lista L2);

void ejecutar_TP2_EJ02() {
    printf("Entraste a la funcion EJ02\n");
}

void ejecutar_TP2_EJ03() {
    printf("Entraste a la funcion EJ03\n");

    clearScreen();
  
		bool salida01=false;
		bool salida02=false;
		//int validacion1=0;
		bool validacion1=false;
		bool validacion2=false;
		bool listasVacias=false;
		int entero1;
		int entero2;
		char string1[1000];
		char string2[1000];
		//int longitud01;

		int i=0;
		TipoElemento X;
		Lista L;
		Lista L2;
		
		L =l_crear();
		L2 =l_crear();
		printf ("AHORA CARGAREMOS 2 LISTAS CON NUMEROS ENTEROS COMPRENDIDOS ENTRE 1 Y 1000,\n");
		printf ("LAS LISTA TIENEN QUE TENER EL MISMO TAMANIO Y NO PUEDE ESTAR VACIAS,\n");
		printf ("LUEGO SE INFORMARA SI LA SEGUNDA LISTA ES MULTIPLO DE LA PRIMERA Y SI ADEMAS ES ESCALAR,\n\n");
		printf ("INTRODUZCA NUMEROS ENTEROS PARA CREAR UNA LISTA (SOLO NUMEROS, sin espacio ni otro caracter),\n");
        printf("INGRESE 'x' SALIR\n");

		do{			
		
		printf ("\nIntroduzca un numero entero entre 1 y 1000 para agregar a la primera Lista o X para salir y cargar otra Lista: ");

		fgets(string1,1000,stdin); // pide por pantalla el ingreso
		int longitud1 = strlen(string1);
		string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
		longitud1=strlen(string1);
		validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
			salida01=true;
			}

		if( validacion1==false && salida01==false ) 
		 {printf("la entrada NO fue validada\n\n");}

		if (validacion1){
			entero1=(int) strtol(string1,NULL,10); //pasa string a entero
			 if (entero1 <1 || entero1 > 1000){
				printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
				salida01=false;
			 }
			 else{
			X = te_crear(entero1);
			l_agregar(L, X);
			//system ("cls");
			clearScreen();
			l_mostrar(L);
			 }
		}
		}while(!salida01);

		//system("pause");
		system ("cls");
		printf("AHORA CARGAMOS LA SEGUNDA LISTA\n");

				do{		
			
		printf ("\nIntroduzca un numero entre 1 y 1000 para agregar a la segunda Lista o X para salir: ");
		fgets(string2,1000,stdin); // pide por pantalla el ingreso
		int longitud2 = strlen(string2);
		string2[longitud2-1]='\0'; // quita el caracter \n que fgets agrega al final de string

		longitud2=strlen(string2);

		validacion2=validarEntero(string2); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string2[0] == 'X' || string2[0] == 'x') && longitud2==1   ){
			salida02=true;
			}

		if( validacion2==false && salida02==false ) 
		 {printf("la entrada NO fue validada\n\n");}

		if (validacion2){
			entero2=(int) strtol(string2,NULL,10); //pasa string a entero

			 if (entero2 < 1 || entero2 > 1000){
				printf("El numero ingresado NO cumple con los requisitos, intentelo nuevamente\n");
				salida01=false;
			 }
			 else{
			X = te_crear(entero2);
			l_agregar(L2, X);
			system ("cls");

			printf("Contenido de la primer Lista: \n");
			l_mostrar(L);

			printf("\nContenido de la segunda Lista: \n");
			l_mostrar(L2);
		

			}


		}


		}while(!salida02);

		system ("cls");
		printf("MOSTRAMOS AMBAS LISTAS\n\n");

		printf("Contenido de la primer Lista: \n");
		l_mostrar(L);

		printf("\nContenido de la segunda Lista: \n");
		l_mostrar(L2);
		printf("\n");

		if ( l_es_vacia (L) || l_es_vacia(L2) || l_longitud(L) != l_longitud(L2)){
			listasVacias=true;
			printf("NO PUEDE HABER LISTAS VACIAS Y LAS LISTAS TIENEN QUE TENER EL MISMO TAMANIO\n");
			printf("INTENELO NUEVAMENTE CUANDO QUIERA, GRACIAS\n");
			system("pause");}

			else {
				printf("ahora comparamos las listas\n");
				ResultadosMul resultado = multiplo(L, L2);

				if (resultado.esMultiplo) {
					printf("La segunda lista ES multiplo de la primera.\n");
				} else {
					printf("La segunda lista NO es multiplo de la primera.\n");
				}
			
				// Verificación de escalar
				if (resultado.escalar) {
					printf("Ademas, ES escalar. El numero escalar es: %d\n", resultado.numEscalar);
					//printf("El escalar es: %d", resultado.numEscalar);
				} else {
					printf("No es escalar.\n");
				}

			}



}

void ejecutar_TP2_EJ04() {
    printf("Entraste a la funcion EJ04\n");
}

void ejecutar_TP2_EJ05() {
    printf("Entraste a la funcion EJ05\n");

    //clearScreen_05();
    printf("EJERCICIO 5 - POLINOMIO\n\n");

    Lista poli = l_crear();
    char buffer[100];
    int grado;
    bool valido = false;

    //CARGA DEL POLINOMIO
    do {
        printf("Ingrese el grado del polinomio (entero >= 0): ");
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (validarEntero(buffer)) {
            grado = atoi(buffer);
            if (grado >= 0) {
                valido = true;
            } else {
                printf("El grado debe ser mayor o igual a 0.\n");
            }
        } else {
            printf("Entrada no valida. Ingrese un numero entero.\n");
        }
    } while (!valido);

    for (int i = 0; i <= grado; i++) {
        float* coef = malloc(sizeof(float));
        printf("Coeficiente para x^%d: ", i);
        fgets(buffer, 100, stdin);
        *coef = atof(buffer);

        TipoElemento te = te_crear_con_valor(i, coef);
        l_agregar(poli, te);
    }

    //clearScreen_05();
    printf("Polinomio cargado correctamente.\n");
    printf("Coeficientes (forma: [coef, exp]):\n");
    Iterador it = iterador(poli);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        printf("[%.2f, x^%d] ", *((float*)te->valor), te->clave);
    }
    printf("\n");

    // EVALUAR UN VALOR DE X 
    float x;
    printf("\nIngrese un valor de X para evaluar el polinomio: ");
    fgets(buffer, 100, stdin);
    x = atof(buffer);

    float resultado = evaluarPoliomio(poli, x);
    printf("F(%.2f) = %.2f\n", x, resultado);

    // RANGO DE VALORES 
    float desde, hasta, paso;
    printf("\nIngrese el valor inicial del rango: ");
    fgets(buffer, 100, stdin);
    desde = atof(buffer);

    printf("Ingrese el valor final del rango: ");
    fgets(buffer, 100, stdin);
    hasta = atof(buffer);

    printf("Ingrese el incremento (paso): ");
    fgets(buffer, 100, stdin);
    paso = atof(buffer);

    Lista resultados = calcularRango(poli, desde, hasta, paso);
    printf("\nResultados del polinomio en el rango:\n");

    Iterador it2 = iterador(resultados);
    float xi = desde;
    while (hay_siguiente(it2)) {
        TipoElemento te = siguiente(it2);
        float y = *((float*)te->valor);
        printf("F(%.2f) = %.2f\n", xi, y);
        xi += paso;
    }

    printf("\nPresione ENTER para continuar...");
    fgets(buffer, 100, stdin);




}

void ejecutar_TP2_EJ06() {

    

    printf("Entraste a la funcion EJ06\n");

    //TipoElemento X;
    Lista L1 = l_crear();
    Lista L2 = l_crear();
    bool sublista, resulCarga;
   
    resulCarga = cargarListasManual(L1, L2);

    if (resulCarga){

        printf("\n");

        if (esSublista(L1,L2)) {
            printf("Lista 2 es sublista de Lista 1 \n");
        } else {
            if (esSublista(L2,L1)){
                printf("Lista 1 es sublista de Lista 2 \n");
            } else {
                printf("No son sublistas \n");
            }
        }

        printf("\n");
        printf("la complejidad algoritmica de este ejercicio es cuadratica,\n");
        printf("ya que recorre Lista 2 con un while y en cada iteracion realiza un while de Lista 1\n");
        

        //system("pause");
    }   


system("pause");

}

// FUNCIONES

//Carga de listas
bool cargarListasManual(Lista L, Lista L2){	

    clearScreen();

    bool salida01=false;
    bool salida02=false;
    //int validacion1=0;
    bool validacion1=false;
    bool validacion2=false;
    bool listasVacias=false;
    int entero1;
    int entero2;
    char string1[1000];
    char string2[1000];
    //int longitud01;

    //int i=0;
    TipoElemento X;

    int min = 1;
    int max = 1000;

    printf ("AHORA CARGAREMOS 2 LISTAS CON NUMEROS ENTEROS COMPRENDIDOS ENTRE %d Y %d,\n", min, max);
    printf ("LAS LISTA NO PUEDEN ESTAR VACIAS,\n");
    printf ("LUEGO SE INFORMARA SI UNA LISTA ES SUBLISTA DE LA OTRA,\n\n");
    printf ("INTRODUZCA NUMEROS ENTEROS PARA CREAR UNA LISTA (SOLO NUMEROS, sin espacio ni otro caracter),\n");
    printf("INGRESE 'x' SALIR\n");

    do{			
        printf ("\nIntroduzca un numero entero entre %d y %d para agregar a la primera Lista o X para salir y cargar otra Lista: ", min, max);

        fgets(string1,1000,stdin); // pide por pantalla el ingreso
        int longitud1 = strlen(string1);
        string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
        longitud1=strlen(string1);
        validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

        if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
            salida01=true;
        }

        if( validacion1==false && salida01==false ) {
            printf("la entrada NO fue validada\n\n");
        }

        if (validacion1){
            entero1=(int) strtol(string1,NULL,10); //pasa string a entero
            if (entero1 < min || entero1 > max){
                printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
                salida01=false;
            } else{
                X = te_crear(entero1);
                l_agregar(L, X);
                //system ("cls");
                clearScreen();
                l_mostrar(L);
            }
        }
    }while(!salida01);

    //system("pause");
    system ("cls");
    printf("AHORA CARGAMOS LA SEGUNDA LISTA\n");

    do{		
        printf ("\nIntroduzca un numero entre %d y %d para agregar a la segunda Lista o X para salir: ", min, max);
        
        fgets(string2,1000,stdin); // pide por pantalla el ingreso
        int longitud2 = strlen(string2);
        string2[longitud2-1]='\0'; // quita el caracter \n que fgets agrega al final de string
        longitud2=strlen(string2);
        validacion2=validarEntero(string2); //valida el ingreso controlando que solo se hayan ingresado numeros

        if (  (string2[0] == 'X' || string2[0] == 'x') && longitud2==1   ){
            salida02=true;
        }

        if( validacion2==false && salida02==false ) {
            printf("la entrada NO fue validada\n\n");
        }

        if (validacion2){
            entero2=(int) strtol(string2,NULL,10); //pasa string a entero
            if (entero2 < min || entero2 > max){
                printf("El numero ingresado NO cumple con los requisitos, intentelo nuevamente\n");
                salida02=false;
            } else{
                X = te_crear(entero2);
                l_agregar(L2, X);
                system ("cls");

                printf("Contenido de la primer Lista: \n");
                l_mostrar(L);

                printf("\nContenido de la segunda Lista: \n");
                l_mostrar(L2);
            }
        }
    }while(!salida02);

    system ("cls");
    printf("MOSTRAMOS AMBAS LISTAS\n\n");

    printf("Contenido de la primer Lista: \n");
    l_mostrar(L);

    printf("\nContenido de la segunda Lista: \n");
    l_mostrar(L2);
    printf("\n");

    if ( l_es_vacia (L) || l_es_vacia(L2)){
        printf("NO PUEDE HABER LISTAS VACIAS Y LAS LISTAS TIENEN QUE TENER EL MISMO TAMANIO\n");
        printf("INTENELO NUEVAMENTE CUANDO QUIERA, GRACIAS\n");
        return false;
    }
    
    return true;
}
