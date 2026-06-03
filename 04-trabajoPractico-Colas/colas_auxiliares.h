#ifndef COLAS_AUXILIARES_H
#define COLAS_AUXILIARES_H

#include <stdbool.h>
#include "../libs/colas/headers/colas.h"

Colas cargarColasManual(Cola C1, Cola C2);
void restaurarcola (Cola destino, Cola auxiliar);
int longitudcola (Cola c);
Pila cargarPilaManual (int min_pila, int max_pila);

#endif
