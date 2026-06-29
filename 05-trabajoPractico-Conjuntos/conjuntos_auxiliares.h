#ifndef CONJUNTOS_AUXILIARES_H
#define CONJUNTOS_AUXILIARES_H

#include <stdbool.h>
#include "../libs/conjuntos/headers/conjuntos.h"


bool cargarConjuntos(Conjunto A, Conjunto B);
void verificarSubconjunto(Conjunto A, Conjunto B, char nombreA, char nombreB);
#endif
