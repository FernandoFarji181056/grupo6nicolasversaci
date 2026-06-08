#ifndef COLAS_AUXILIARES_H
#define COLAS_AUXILIARES_H

#include <stdbool.h>
#include "../libs/colas/headers/colas.h"
//#include "../libs/pilas/headers/pilas.h"

Cola cargarColaManual(int min_cola, int max_cola);
Pila cargarPilaManual(int min_pila, int max_pila);
void restaurarcola(Cola destino, Cola auxiliar);

#endif
