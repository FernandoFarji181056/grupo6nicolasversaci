#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//Ejercicio 9
/*9. Escribir una función recursiva que implemente el método que se describe para saber si 
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica 
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente, 
hasta que el resultado obtenido sea un número menor a 70. El número original será 
múltiplo de 7 si el resultado da cero o múltiplo de 7. 
Ejemplos:
32291 -> 1x2=2. 
3229 - 2 = 
3227 -> 7x2=14. 
322 - 14 = 
308 -> 8x2=16 
30 - 16 = 
14 -> Múltiplo de 7 
divisiblePor7 (32291) => verdadero

110 -> 0 x 2 = 0 
11 – 0 = 
11 -> No múltiplo de 7 
divisiblePor7 (110) => falso
*/

bool divisiblePor7(int n){
        
        // CASO BASE: si n no es mayor que b
        if (n < 70) {
            if (n%7==0){return true;}
            else{return false;}   
            }
            else{
            n=(n/10)-(2*(n%10));
            //printf("\nahora el numero es: %d\n",n);
            return divisiblePor7(n);

            }



    //bool esDivisible=false;
    //printf("El numero ingresado es: %d\n",n);
    //return esDivisible;
}